// Дан отсортированный массив целых чисел A[0..n-1] и массив целых чисел B[0..m-1]. Для каждого элемента массива B[i] 
// найдите минимальный индекс k минимального элемента массива A, 
// равного или превосходящего B[i]: A[k] >= B[i]. Если такого элемента нет, выведите n. 
// Время работы поиска k для каждого элемента B[i]: O(log(k)). n, m ≤ 10000.

#include <iostream>
#include <cassert>

struct borders {
    int right;
    int left;
};

borders exp_search(int *arr, int amount, int number) {
    borders tmp;
    tmp.right = 0;
    tmp.left = 0;
    
    if (arr[0] >= number) {
        return tmp;
    } 

    if (arr[amount - 1] < number) {
        return tmp;
    }
    
    int i = 1;
    while (arr[i] < number) {
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

int bin_search(int *arr, int amount, borders tmp, int value) {
    if(tmp.left == 0 && tmp.right == 0) {
        return value <= arr[0] ? 0 : amount;
    }

    int middle = 0;

    while (tmp.right > tmp.left) {
        middle = (tmp.right + tmp.left) / 2;
        arr[middle] >= value ? tmp.right = middle : tmp.left = middle + 1; 
    }

    return tmp.right;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    int * A = new int[n];
    int * B = new int[m];
    
    for (size_t i = 0; i < n; i++) {
        std::cin >> A[i];
    }
    
    for (size_t i = 0; i < m; i++) {
        std::cin >> B[i];
    }

    borders tmp;

    for (size_t i = 0; i < m; i++) {
        tmp = exp_search(A, n, B[i]);
        std::cout << bin_search(A, n, tmp, B[i]) << " ";
    }

    delete[] A;
    delete[] B;
}