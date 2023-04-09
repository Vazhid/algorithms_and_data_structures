#include <iostream>
#include <algorithm>  

struct Pair {
    int coordinate;
    bool flag;

    bool operator< (const Pair& p) const {
        return this->coordinate < p.coordinate;
    }
};

template <typename T>
struct DefaultComparator {
    bool operator()(const T& l, const T& r) const {
        return l < r;
    }
};

template<typename T>
void merge_sort(T* arr, int amount) {
    T* aux = new T[amount];
    int mid = amount / 2;
    if (amount % 2 == 1)
        mid++;
    int h = 1;
    int step;
    while (h < amount) {
        step = h;
        int i = 0;  
        int j = mid;
        int k = 0; 
        while (step <= mid) {
            while ((i < step) && (j < amount) && (j < (mid + step))) {
                if (arr[i] < arr[j]) {
                    aux[k] = arr[i];
                    i++; k++;
                } else {
                    aux[k] = arr[j];
                    j++; k++;
                }
            }
            while (i < step) {
                aux[k] = arr[i];
                i++; k++;
            }
            while ((j < (mid + step)) && (j < amount)) {
                aux[k] = arr[j];
                j++; k++;
            }
            step = step + h;
        }
        h = h * 2;
        for (i = 0; i < amount; i++)
            arr[i] = aux[i];
    }
    delete[] aux;
}

int main() {
    int amount;
    std::cin >> amount;
    amount *= 2;
    Pair* array = new Pair[amount];
    for (int i = 0; i < amount; i++) {
        std::cin >> array[i].coordinate;
        array[i].flag = (i % 2 == 0 ? true : false);
    }

    std::sort(array, array + amount); // ?

    int coord;
    int count = 0;
    int sum = 0;
    for (int i = 0; i < amount; i++) {
        array[i].flag ? ++count : --count;
        if (count == 1 && array[i].flag) {
            coord = array[i].coordinate;
        } else if (count == 0 && !array[i].flag) {
            sum += array[i].coordinate - coord;
        }
    }

    std::cout << sum;

    delete[] array;
}