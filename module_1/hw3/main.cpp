// Реализовать очередь с динамическим зацикленным буфером.
// Обрабатывать команды push back и pop front.

#include <iostream>
#include <cassert>

class array {
public:
    array() : buffer( 0 ), buffer_size( 0 ), real_size( 0 ) {}
    ~array() { delete[] buffer; }

    int size() const { return real_size; }

    int get_at( int index ) const;
    int operator[]( int index ) const { return get_at( index ); }

    void add( int element );

    int remove_at( int index );
    int pop_front();

private:
    int buffer_size;
    int real_size;
    int *buffer;
    int default_initial_size = 1;
    void grow();
};

int array::get_at( int index ) const {
    assert( index >= 0 && index < real_size && buffer != 0 );
    return buffer[index];
}

void array::grow() {
    int new_buffer_size = std::max( buffer_size * 2, default_initial_size );
    int* new_buffer = new int[new_buffer_size];

    for( int i = 0; i < real_size; ++i) {
        new_buffer[i] = buffer[i];
    }
    
    delete[] buffer;
    buffer = new_buffer;
    buffer_size = new_buffer_size;
}

void array::add( int element ) {
    if( real_size == buffer_size) {
        grow();
    }
    assert( real_size < buffer_size && buffer != 0 );
    buffer[real_size++] = element;
}

int array::remove_at( int index ) {
    assert( index >= 0 && index < real_size && buffer != 0 );
    int remove_element  = buffer[index];

    int j = 0;
    for( int i = 0; i < real_size; ++i) {
        if (i != index) {
            buffer[j] = buffer[i];
            ++j;
        }
    }
    --real_size;

    return remove_element;
}

int array::pop_front() {
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

class queue {
public:
    void push_back( int element ) { arr.add(element); }
    int pop_front() { return arr.pop_front(); }
    int size() const { return arr.size(); }
private:
    array arr;
};


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