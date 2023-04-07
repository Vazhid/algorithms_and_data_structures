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

template <typename T>
struct DefaultComparator {
    bool operator()(const T& l, const T& r) const {
        return l < r;
    }
};

template <typename T, typename Comparator = DefaultComparator<T>>
class Heap {
private:
    int size;
    int buffer_size;
    T* arr = new T[buffer_size];
    Comparator comp;

    void sift_down(int ind, Comparator comp = Comparator()) {
        int largest = 0, left = 0, right = 0;

        while (1) {
            largest = ind;
            left = 2 * ind + 1;
            right = 2 * ind + 2;

            if (left <= size - 1 && comp(arr[left], arr[ind]))
                largest = left;
            
            if (right <= size - 1 && comp(arr[right], arr[largest]))
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
    

    void sift_up(int ind, Comparator comp = Comparator()) {
        int parent;
        while (ind > 0) {
            parent = (ind - 1)/2;
            if (comp(arr[ind], arr[parent])) {
                std::swap(arr[ind], arr[parent]);
            }
            ind = parent;
        }
    };
    
public:
    Heap(Comparator comp = Comparator()) : comp(comp), buffer_size(3), size(0) {}
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