#include <iostream>

int even_bits_count(int value) {
    unsigned mask = 1;
    size_t count = 0;
    while (value > 0) {
        if ((mask & value) > 0) {
            count++;
        }
        value >>= 2;
    }
    return count;
}

int main() {
    int value = 0;
    std::cin >> value;
    std::cout << even_bits_count(value) << std::endl;
    return 0;
}