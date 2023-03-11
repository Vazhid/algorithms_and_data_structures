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

    while (tmp.right < tmp.left) {
        middle = (tmp.right + tmp.left) / 2;
        arr[middle] >= value ? tmp.right = middle : tmp.left = middle + 1; 
    }

    return tmp.right;
}

void run() {
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

void test_program() {
    {
        borders test;
        int A[3] = {1, 2, 3};
        int B[3] = {-1, -10, 8};
        int exp_result[3] = {0, 0, 3};
        bool flag = true;
        for (size_t i = 0; i < 3; i++) {
            test = exp_search(A, 3, B[i]);
            exp_result[i] == bin_search(A, 3, test, B[i]) ? flag = true : flag = false;
        }
        assert(flag == true);
    }

    {
        borders test;
        int A[3] = {1, 2, 3};
        int B[4] = {4, 0, 0, 2};
        int exp_result[4] = {3, 0, 0, 1};
        bool flag = true;
        for (size_t i = 0; i < 4; i++) {
            test = exp_search(A, 3, B[i]);
            exp_result[i] == bin_search(A, 3, test, B[i]) ? flag = true : flag = false;
        }
        assert(flag == true);
    }

    {
        borders test;
        int A[4] = {2, 4, 5, 7};
        int B[3] = {4, 6, 1};
        int exp_result[3] = {1, 3, 0};
        bool flag = true;
        for (size_t i = 0; i < 3; i++) {
            test = exp_search(A, 4, B[i]);
            exp_result[i] == bin_search(A, 4, test, B[i]) ? flag = true : flag = false;
        }
        assert(flag == true);
    }

    {
        borders test;
        int A[1] = {1};
        int B[1] = {1};
        int exp_result[1] = {0};
        bool flag = true;
        for (size_t i = 0; i < 1; i++) {
            test = exp_search(A, 1, B[i]);
            exp_result[i] == bin_search(A, 1, test, B[i]) ? flag = true : flag = false;
        }
        assert(flag == true);
    }

    {
        borders test;
        int A[1] = {1};
        int B[1] = {10};
        int exp_result[1] = {1};
        bool flag = true;
        for (size_t i = 0; i < 1; i++) {
            test = exp_search(A, 1, B[i]);
            exp_result[i] == bin_search(A, 1, test, B[i]) ? flag = true : flag = false;
        }
        assert(flag == true);
    }

    {
        borders test;
        int A[1] = {1};
        int B[1] = {-1};
        int exp_result[1] = {0};
        bool flag = true;
        for (size_t i = 0; i < 1; i++) {
            test = exp_search(A, 1, B[i]);
            exp_result[i] == bin_search(A, 1, test, B[i]) ? flag = true : flag = false;
        }
        assert(flag == true);
    }

        {
        borders test;
        int A[8] = {-15, -2, 1, 2 , 3, 10, 57, 89};
        int B[6] = {-1, 10, 33, 0, 2, 89};
        int exp_result[6] = {2, 5, 6, 2, 3, 7};
        bool flag = true;
        for (size_t i = 0; i < 6; i++) {
            test = exp_search(A, 8, B[i]);
            exp_result[i] == bin_search(A, 8, test, B[i]) ? flag = true : flag = false;
        }
        assert(flag == true);
    }

}

int main() {
    test_program();
    // run();
}