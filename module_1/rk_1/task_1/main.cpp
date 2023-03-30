// Дан массив, который получен путем нескольких циклических сдвигов исходного отсортированного массива. 
// Нужно найти индекс элемента, с которого начинался исходный массив.
// Примеры:
// [12, 14, 16, 17, 1, 3, 5, 7] (исходный массив [1, 3, 5, 7, 12, 14, 16, 17])
// Ответ: 4
// [5, 5, 5, 1] (исходный массив [1, 5, 5, 5])
// Ответ: 3
// Требование: сложность O(logN)

#include <iostream>
#include <cassert>

struct borders {
    int right;
    int left;
};

borders exp_search(int *arr, int amount) {
    borders tmp;
    tmp.right = 0;
    tmp.left = 0;

    int i = 1;

    while (1) {
        if (arr[i / 2] > arr[i]) {
            break;
        }
        i *= 2;
    }
    tmp.right = i;
    tmp.left = i / 4;
    
    if (tmp.right >= amount) {
        tmp.right = amount - 1;
    }

    return tmp;
}

int bin_search(int *arr, borders tmp) {
    if(tmp.left == tmp.right) {
        return tmp.left;
    }

    int middle = 0;

    while (tmp.right > tmp.left) {
        middle = (tmp.right + tmp.left) / 2;
        if (arr[middle] > arr[middle + 1]) {
            return middle + 1;
        } 
        if (arr[middle] < arr[middle - 1]) {
            return middle;
        } 
        if (arr[middle] <= arr[middle + 1]) {
            tmp.left = middle + 1;
        }
        if (arr[middle] >= arr[middle - 1]) {
            tmp.right = middle;
        } 
    }

    return tmp.left+1;
}


int main() {
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    borders tmp;

    tmp = exp_search(arr, n);

    // std::cout << tmp.left << " " << tmp.right << std::endl;

    int a = bin_search(arr, tmp);

    std::cout << a << std::endl;
    
}