// Реализовать очередь с динамическим зацикленным буфером.
// Обрабатывать команды push back и pop front.

#include <iostream>
#include <cassert>

class queue {
public:
    queue() : buffer(nullptr), buffer_size(0), real_size(0), head(-1) {}
    ~queue() { delete[] buffer; }
    int size() const { return real_size; }
    void push_back(int element);
    int pop_front();

private:
    int buffer_size;
    int head;
    int real_size;
    int default_initial_size = 1;
    int *buffer;
    void grow();
};

void queue::grow() {
    int new_buffer_size = std::max(buffer_size * 2, default_initial_size);
    int* new_buffer = new int[new_buffer_size];
    for (int i = 0; i < real_size; i++) {
        new_buffer[i] = buffer[(head + i) % buffer_size];
    }
    delete[] buffer;
    buffer = new_buffer;
    new_buffer = nullptr;
    buffer_size = new_buffer_size;
}

void queue::push_back(int element) {
    if (real_size == buffer_size) {
        grow();
        head = 0;
    }
    buffer[(real_size++ + head) % buffer_size] = element;
}

int queue::pop_front() {
    int remove_element = buffer[head];
    head = ++head % buffer_size;
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
    
    std::cout << (flag ? "YES" : "NO");

    return 0;
}