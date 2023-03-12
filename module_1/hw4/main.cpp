#include <iostream>

template <class T>
class heap {
private:
    int size = 0;
    int buffer_size = 3;
    T* arr = new T[3];

    void sift_down(int ind) {
        int largest = 0;
        int left = 0;
        int right = 0;

        while (1) {
            largest = ind;
            left = 2 * ind + 1;
            right = 2 * ind + 2;

            if (left <= size - 1 && arr[left] < arr[ind])
                largest = left;
            
            if (right <= size - 1 && arr[right] < arr[largest])
                largest = right;
            
            if (largest != ind) {
                std::swap(arr[ind], arr[largest]);
                ind = largest;
            } else {
                return;
            }
        }
    }
    
    void grow_buffer() {
        buffer_size *= 3;
        T *arr_copy = new T[buffer_size];
        std::copy(arr, arr + size, arr_copy);
        delete[] arr;
        arr = arr_copy;
        arr_copy = nullptr;
    }
    

    void sift_up(int ind) {
        int parent;
        while (ind > 0) {
            parent = (ind - 1)/2;
            if (arr[ind] < arr[parent]) {
                std::swap(arr[ind], arr[parent]);
            }
            ind = parent;
        }
    }


public:
    heap() = default;
    heap(const heap&) = delete;
    heap& operator=(const heap& h) = delete;
    ~heap() {
        delete[] arr;
    }

    int get_size () {
        return size;
    }
    
    void add_element(const T& elem) {
        if (size >= buffer_size) {
            grow_buffer();
        }
        arr[size] = elem;
        sift_up(size);
        ++size;
    }
    
    T extract_min() {
        T min = arr[0];
        arr[0] = arr[size - 1];
        sift_down(0);
        --size;
        return min;
    }

    void print_heap() {
        for (size_t i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        
    }
};

int main() {
    heap <int> hp;
    int amount;
    int elem;
    int arr_size;
    std::cin >> amount;

    for (size_t i = 0; i < amount; i++) {
        std::cin >> arr_size;
        for (size_t j = 0; j < arr_size; j++) {
            std::cin >> elem;
            hp.add_element(elem);
        }   
    }

    amount = hp.get_size();

    for (size_t i = 0; i < amount; i++) {
        std::cout << hp.extract_min() << " ";
    }
    

    return 0;
}