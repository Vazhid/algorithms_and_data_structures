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
    if ((first > second || first > third) && (first < second || first < third))
        return first;
    else if ((second > first || second > third) && (second < first || second < third))
        return second;
    else
        return third;
}

template<class T>
int partition(T* arr, const int left, const int right, bool (is_less)(const T &l, const T &r)) {

    int *median = median_of_three(&arr[left], &arr[(right - left) / 2 + left], &arr[right]);

    std::swap(*median, arr[right]);
    const int& pivot = right;

    int i = right - 1, j = right - 1;
    while (j != left) {
        if (is_less(arr[pivot], arr[j])) {
            std::swap(arr[i], arr[j]);
            --i;
            --j;
        } else {
            --j;
        }
    }

    std::swap(arr[i + 1], arr[pivot]);

    return i + 1;
}


template<class T>
int k_stat(T* arr, const int k, const int size, bool (is_less)(const T &l, const T &r)) {
    assert(arr != nullptr);
    
    int left = 0;
    int right = size - 1;
    int t;

    while (1) {
        // std::cout << "в ";
        // for (int i = left; i <= right; ++i) {
        //     std::cout << arr[i] << " ";
        // }
        // std::cout << "\n";
        t = partition(arr, left, right, is_less);
        // std::cout << t << "\n";
        // std::cout << "из ";
        // for (int i = left; i <= right; ++i) {
        //     std::cout << arr[i] << " ";
        // }
        // std::cout << "\n";

        if (k == t) {
            return arr[t];
        } else if (is_less(k, t)) {
            std::cout << left << " " << right << "\n";
            right = t;
        } else {
            left = t;
        }
    }
}


int main() {
    int size;
    std::cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    // int a = partition(arr, 0, size - 1, is_less);
    
    // std::cout << a << std::endl; 

    int med = size/2;
    int p10 = size/10;
    int p90 = size*9/10;

    
    std::cout << k_stat(arr, p10, size, is_less) << "\n";
    std::cout << k_stat(arr, med, size, is_less) << "\n";
    std::cout << k_stat(arr, p90, size, is_less) << "\n";

    // for (int i = 0; i < size; ++i) {
    //     std::cout << arr[i] << " ";
    // }

    delete[] arr;
    return 0;
}
