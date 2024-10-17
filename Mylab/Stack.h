#include "../Mylab/Vector.h"
#include <iostream>

using namespace std;
template <typename T>
class Stack {
private:
    T* stackArray;  // 动态数组来模拟栈
    int topIndex;   // 栈顶索引
    int capacity;   // 栈的容量

public:
    Stack(int cap = 10) : capacity(cap), topIndex(-1) {
        stackArray = new T[capacity];
    }

    ~Stack() {
        delete[] stackArray;
    }

    // 入栈操作
    void push(T value) {
        if (topIndex == capacity - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        stackArray[++topIndex] = value;
    }

    // 出栈操作
    void pop() {
        if (empty()) {
            cout << "Stack underflow" << endl;
            return;
        }
        topIndex--;
    }

    // 返回栈顶元素
    T top() const {
        if (empty()) {
            throw runtime_error("Stack is empty");
        }
        return stackArray[topIndex];
    }

    // 检查栈是否为空
    bool empty() const {
        return topIndex == -1;
    }

    // 返回栈的大小
    int size() const {
        return topIndex + 1;
    }
};

