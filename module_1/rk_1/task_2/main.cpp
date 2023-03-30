// ВНИМАНИЕ! Для решения данной задачи нужно использовать структуру данных стек!
// Дана последовательность, состоящая из символов '(' и ')'. 
// Требуется определить, является ли данная последовательность правильной скобочной последовательностью. 
// Длина исходной последовательности ≤ 800000.

// Формат ввода
// Строка, содержащая символы '(' и ')'.


#include <iostream>
#include <string.h>

class Stack {
private:
    int buffer_size;
    char* buffer;
    int tail;

public:
    int stack_size;

    void realloc_buffer() {
        int new_buffer_size = buffer_size * 2;
        char *new_buffer = new char[new_buffer_size];
        delete[] buffer;
        buffer = new_buffer;
        buffer_size = new_buffer_size;
    }

    void push(char ch) {
        if (tail == buffer_size) {
            realloc_buffer();
        }
        if (stack_size == 0) {
            buffer[0]=ch;
            tail=0;
            stack_size++;
        } else {
            tail++;
            buffer[tail]=ch;
            stack_size++;
        }
    }

    char pop() {
        char result;
        if (stack_size != 0) {
            result = buffer[tail];
            tail--;
            stack_size--;
        }
        return result;
    }

    Stack () { buffer_size=2; stack_size=0; buffer = new char[buffer_size];}
    ~Stack() { delete[] buffer; }
};

int main() {
    std::string str;
    bool flag = true;
    std::cin >> str;

    Stack stack = Stack();
    
    for (int i = 0; i < str.size(); ++i) {
        char ch = str[i];
        if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            stack.stack_size == 0 ? flag = false : stack.pop();
        }
    }
    
    if (stack.stack_size !=0 )
        flag = false;   

    flag ? std::cout << "YES" : std::cout << "NO";
}
