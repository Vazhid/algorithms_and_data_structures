// Реализовать очередь с динамическим зацикленным буфером.
// Обрабатывать команды push back и pop front.

#include <iostream>
#include <cassert>

class queue {
public:
    queue() : buffer( 0 ), buffer_size( 0 ), real_size( 0 ) {}
    ~queue() { delete[] buffer; }

    int size() const { return real_size; }

    void push_back( int element );
    int pop_front();

private:
    int buffer_size;
    int real_size;
    int *buffer;
    int default_initial_size = 2;
    void grow();
};

void queue::grow() {
    int new_buffer_size = std::max( buffer_size * 2, default_initial_size );
    int* new_buffer = new int[new_buffer_size];

    for( int i = 0; i < real_size; ++i) {
        new_buffer[i] = buffer[i];
    }
    
    delete[] buffer;
    buffer = new_buffer;
    buffer_size = new_buffer_size;
}

void queue::push_back( int element ) {
    if( real_size == buffer_size) {
        grow();
    }
    assert( real_size < buffer_size && buffer != 0 );
    buffer[real_size++] = element;
}

int queue::pop_front() {
    if (real_size == 0) {
        return -1;
    }

    int remove_element = buffer[0];

    for( int i = 1; i < real_size; ++i) {
            buffer[i-1] = buffer[i];
    }
    --real_size;

    return remove_element;

}

int main() {
    int n;
    int command;
    int in_value;
    int out_value;
    bool flag = true;
    queue q;

    std::cin >> n;
    for (size_t i = 0; i < n; i++) {
        std::cin >> command >> in_value;
        if (command == 3) {
            q.push_back(in_value);
        }
        if (command == 2) {
            if (q.size() == 0) {
                out_value = -1;
            } else {
                out_value = q.pop_front();
            }
            if (out_value != in_value) {
                flag = false;
            }
        } 
    }
    
    flag ? std::cout << "YES" : std::cout << "NO";

    return 0;
}