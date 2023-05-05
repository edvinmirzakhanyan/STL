#ifndef STACK_H
#define STACK_H
#include <vector>

template<class T>
class Stack {
    public:
        void push(T);
        T pop();
        bool isEmpty();
        T peek();
    private:
        std::vector<T> vec;
};

template<class T>
void Stack<T>::push(T val) {
    vec.push_back(val);
}

template<class T>
T Stack<T>::pop() {
    if (vec.empty()) {
        std::cout << "Stack is empty" << std::endl;
        return T();
    }
    else {
        T val = vec[vec.size() - 1];
        vec.pop_back();
        return val;
    }
}

template<class T>
bool Stack<T>::isEmpty() {
    return vec.empty();
}

template<class T>
T Stack<T>::peek() {
    if (vec.empty()) {
        std::cout << "Stack is Empty" << std::endl;
        return T();
    }
    else {
        T val = vec[vec.size() - 1];
        return val;
    }
}

#endif //STACK_H