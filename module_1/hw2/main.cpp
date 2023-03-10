#include <iostream>

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
    int middle = 0;

    if(tmp.left == 0 && tmp.right == 0) {
        return value <= arr[0] ? 0 : amount;
    }

    while (tmp.right < tmp.left) {
        middle = (tmp.right + tmp.left) / 2;
        std::cout << middle << " ";
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

    // borders tmp;
    // tmp = exp_search(A, n, B[2]);
    // std::cout << tmp.left << " " << tmp.right;

    for (size_t i = 0; i < m; i++) {
        std::cout << bin_search(A, n, exp_search(A, n, B[i]), B[i]) << " ";
    }

    delete[] A;
    delete[] B;
    return 0;
}