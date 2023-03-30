// Дано множество целых чисел из [0..10^9] размера n.
// Используя алгоритм поиска k-ой порядковой статистики,
// требуется найти следующие параметры множества:
//  - 10%  перцентиль
//  - медиана
//  - 90%  перцентиль
// Реализуйте стратегию выбора опорного элемента “медиана трех”.
// Функцию Partition реализуйте методом прохода двумя итераторами от конца массива к началу.

#include <iostream>
#include <cassert>

template<class T>
bool is_less(const T &l, const T &r) {
    return l < r;
}

template <class T>
int *median_of_three(T *first, T *second, T *third) {
	if (first < second) {
		if (second < third) {
			return second;
		} else if (first < third) {
			return third;
		} else{
			return first;
		}
	} else {
		if (first < third) {
			return first;
		} else if (second < third) {
			return third;
		} else {
			return third;
		}
	}
}

template<class T>
int partition(T* arr, const int left, const int right, bool (is_less)(const T &l, const T &r)) {

    int *median = median_of_three(&arr[left], &arr[(right - left) / 2 + left], &arr[right]);

    std::swap(*median, arr[right]);

    int i = right, j = right;

    while (j > left) {
        while (!is_less(arr[left], arr[j]) && is_less(left, j))
            --j;
        while (is_less(arr[left], arr[j]) && is_less(left, j))
            std::swap(arr[j--], arr[i--]);
    }

    std::swap(arr[left], arr[i]);

    return i;
}


template<class T>
int k_stat(T* arr, const int k, const int size, bool (is_less)(const T &l, const T &r)) {
    int left = 0;
    int right = size - 1;
    int t = -1;

    while (t != k) {
        t = partition(arr, left, right, is_less);
        t < k ? left = t + 1 : right = t - 1;
    }
    return arr[t];
}

void test() {
    {
        int size = 20;
        int med = size/2;
        int p10 = size/10;
        int p90 = size*9/10;
        int arr[20] = {1, 10, 15, 17, 20, 22, 40, 50, 65, 77, 80, 90, 531, 801, 1000, 1001, 1002, 1467, 2000, 2023};
        assert(k_stat(arr, p10, size, is_less) == 15);
        assert(k_stat(arr, med, size, is_less) == 80);
        assert(k_stat(arr, p90, size, is_less) == 2000);
    }
    {
        int size = 10;
        int med = size/2;
        int p10 = size/10;
        int p90 = size*9/10;
        int arr[10] = {1, 10, 17, 20, 40, 80, 90, 1000, 1001, 1002};
        assert(k_stat(arr, p10, size, is_less) == 10);
        assert(k_stat(arr, med, size, is_less) == 80);
        assert(k_stat(arr, p90, size, is_less) == 1002);
    }
    {
        int size = 2;
        int med = size/2;
        int p10 = size/10;
        int p90 = size*9/10;
        int arr[2] = {1, 10};
        assert(k_stat(arr, p10, size, is_less) == 1);
        assert(k_stat(arr, med, size, is_less) == 10);
        assert(k_stat(arr, p90, size, is_less) == 10);
    }
    {
        int size = 1;
        int med = size/2;
        int p10 = size/10;
        int p90 = size*9/10;
        int arr[1] = {1};
        assert(k_stat(arr, p10, size, is_less) == 1);
        assert(k_stat(arr, med, size, is_less) == 1);
        assert(k_stat(arr, p90, size, is_less) == 1);
    }
    {
        int size = 5;
        int med = size/2;
        int p10 = size/10;
        int p90 = size*9/10;
        int arr[5] = {0, 1, 2, 3, 4};
        assert(k_stat(arr, p10, size, is_less) == 0);
        assert(k_stat(arr, med, size, is_less) == 2);
        assert(k_stat(arr, p90, size, is_less) == 4);
    }

    {
        int size = 5;
        int med = size/2;
        int p10 = size/10;
        int p90 = size*9/10;
        int arr[5] = {0, 1, 1, 1, 4};
        assert(k_stat(arr, p10, size, is_less) == 0);
        assert(k_stat(arr, med, size, is_less) == 1);
        assert(k_stat(arr, p90, size, is_less) == 4);
    }
    {
        int size = 5;
        int med = size/2;
        int p10 = size/10;
        int p90 = size*9/10;
        int arr[5] = {0, 1, 1, 1, 1};
        assert(k_stat(arr, p10, size, is_less) == 0);
        assert(k_stat(arr, med, size, is_less) == 1);
        assert(k_stat(arr, p90, size, is_less) == 1);
    }
}

int main() {
    test();
    // int size;
    // std::cin >> size;
    // int *arr = new int[size];
    // for (int i = 0; i < size; ++i) {
    //     std::cin >> arr[i];
    // }

    // int med = size/2;
    // int p10 = size/10;
    // int p90 = size*9/10;

    // std::cout << k_stat(arr, p10, size, is_less) << "\n";
    // std::cout << k_stat(arr, med, size, is_less) << "\n";
    // std::cout << k_stat(arr, p90, size, is_less) << "\n";

    // delete[] arr;
    // return 0;
}
