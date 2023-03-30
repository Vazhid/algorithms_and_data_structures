// Имеется лог-файл, в котором хранятся пары для N пользователей (Идентификатор пользователя, посещаемость сайта).
// Напишите программу, которая выбирает K пользователей, которые чаще других заходили на сайт, и выводит их в порядке возрастания посещаемости.
// Количество заходов и идентификаторы пользователей не повторяются. 

#include <iostream>

struct Pair {
    int id;
    int quantity;

    bool operator< (const Pair& p) const {
        return this->quantity < p.quantity;
    }
};

template<typename T>
bool is_less(const T &l, const T &r) {
    return l < r;
}

template <typename T>
class Heap {
private:
    int size = 0;
    int buffer_size = 3;
    T* arr = new T[3];

    void sift_down(int ind, bool (*is_less)(const T&, const T&)) {
        int largest = 0;
        int left = 0;
        int right = 0;

        while (1) {
            largest = ind;
            left = 2 * ind + 1;
            right = 2 * ind + 2;

            if (left <= size - 1 && is_less(arr[left], arr[ind]))
                largest = left;
            
            if (right <= size - 1 && is_less(arr[right], arr[largest]))
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
    

    void sift_up(int ind, bool (*is_less)(const T&, const T&)) {
        int parent;
        while (ind > 0) {
            parent = (ind - 1)/2;
            if (is_less(arr[ind], arr[parent])) {
                std::swap(arr[ind], arr[parent]);
            }
            ind = parent;
        }
    };
    
public:
    Heap() = default;
    Heap(const Heap&) = delete;
    Heap& operator=(const Heap& h) = delete;
    ~Heap() {
        delete[] arr;
    }

    int get_size () const {
        return size;
    }
    
    void add_element(const T& elem) {
        if (size >= buffer_size) {
            grow_buffer();
        }
        arr[size] = elem;
        sift_up(size, is_less);
        ++size;
    }
    
    T extract_min() {
        T min = arr[0];
        arr[0] = arr[size - 1];
        sift_down(0, is_less);
        --size;
        return min;
    }
};

int main() {
    Heap <Pair> hp;
    Pair pr;
    int N;
    int K;

    std::cin >> N >> K;

    for (size_t i = 0; i < N; i++) {
        std::cin >> pr.id >> pr.quantity;
        hp.add_element(pr);
        if (hp.get_size() == K+1) {
            hp.extract_min();
        }
    }

    for (size_t i = 0; i < K; i++) {
        std::cout << hp.extract_min().id << " ";
    }

    return 0;
}