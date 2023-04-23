#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <cstddef>

template <typename T>
class Doubly_List {
public:
    Doubly_List() = default;
    Doubly_List(const Doubly_List<T>& other) noexcept;
    Doubly_List(Doubly_List<T>&& other) noexcept;
    ~Doubly_List();
public:
    Doubly_List<T>& operator=(const Doubly_List<T>&) noexcept;
    Doubly_List<T>& operator=(Doubly_List<T>&&) noexcept;
    Doubly_List<T> operator+(const Doubly_List<T>&) const noexcept;
    Doubly_List<T>& operator+=(const Doubly_List<T>&) noexcept;
public:
    bool empty() const noexcept;
    void push_back(T) noexcept;
    void push_front(T) noexcept;
    void pop_back() noexcept;
    void pop_front() noexcept;
    std::size_t size() const noexcept;
    T* front();
    T* back();
    template <typename O>
    friend std::ostream& operator<<(std::ostream&, const Doubly_List<O>&);
private:
    template <typename N>
    struct Node {
        Node<N>* prev = nullptr;
        Node<N>* next = nullptr;
        T data;
    };
    Node<T>* m_head = nullptr;
    Node<T>* m_tail = nullptr;
    std::size_t m_length = 0;
};

template<typename T>
Doubly_List<T>::Doubly_List(const Doubly_List<T>& ls) noexcept {
    Node<T>* tmp = ls.m_head;

    while (tmp != nullptr) {
        push_back(tmp->data);
        tmp = tmp->next;
    }
}

template <typename T>
Doubly_List<T>::Doubly_List(Doubly_List<T>&& ls) noexcept {
        m_head = ls.m_head;
        m_tail = ls.m_tail;
        ls.m_head = nullptr;
        ls.m_tail = nullptr;
}

template<typename T>
Doubly_List<T>::~Doubly_List() {
    Node<T>* tmp;
    while (m_head != nullptr) {
        tmp = m_head;
        m_head = m_head->next;
        delete tmp;
    }
    m_tail = nullptr;
    m_length = 0;
}

template<typename T>
Doubly_List<T>& Doubly_List<T>::operator=(const Doubly_List<T>& ls) noexcept {
    if (this != &ls) {
        Doubly_List<T> tmp(ls);
        m_head = tmp.m_head;
        m_tail = tmp.m_tail;
        m_length = tmp.m_length;
        tmp.head_ = nullptr;
        tmp.tail_ = nullptr;
        tmp.size_ = 0;
    }
    return *this;
}

template<typename T>
Doubly_List<T>& Doubly_List<T>::operator=(Doubly_List<T>&& ls) noexcept {
    if (this != &ls) { 
        Node<T> tmp; 
        while (m_head != nullptr) {
            tmp = m_head;
            m_head = m_head->next;
            delete tmp;
        }
        m_head = ls.head_;
        m_tail = ls.tail_;
        m_length = ls.m_length;
        ls.m_head = nullptr;
        ls.m_tail = nullptr;
        ls.m_length = 0;
    }
    return *this;
}

template <typename T>
Doubly_List<T> Doubly_List<T>::operator+(const Doubly_List<T>& ls) const noexcept {
    Doubly_List<T> tmp(*this);

    for (Node<T>* i = ls.m_head; i != nullptr; i = i->next) {
        tmp.push_back(i->data);
    }
    return tmp;
}

template<typename T>
Doubly_List<T>& Doubly_List<T>::operator+=(const Doubly_List<T>& ls) noexcept {
    for (Node<T>* i = ls.m_head; i != nullptr; i = i->next) {
        push_back(i->data);
    }
    return *this;
}

template<typename T>
bool Doubly_List<T>::empty() const noexcept {
    return m_length == 0;
}

template <typename T>
void Doubly_List<T>::push_back(T data) noexcept {
    Node<T>* tmp = new Node<T>;
    tmp->data = data;
    
    if (empty()) {
        m_head = tmp;
        m_tail = tmp;
    }
    else {
        tmp->prev = m_tail;
        m_tail->next = tmp;
        m_tail = tmp;
    }
    ++m_length;
}

template<typename T>
void Doubly_List<T>::push_front(T data) noexcept {
    Node<T>* tmp = new Node<T>;
    tmp->data = data;
    if (empty()) {
        m_head = tmp;
        m_tail = tmp;
    }
    else {
        tmp->next = m_head;
        m_head->prev = tmp;
        m_head = tmp;
    }
    ++m_length;
}

template<typename T>
void Doubly_List<T>::pop_back() noexcept {
    if (empty()) {
        return;
    }
    else if (m_head == m_tail) {
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
    }
    else {
        Node<T>* tmp = m_tail;
        m_tail = m_tail->prev;
        m_tail->next = nullptr;
        delete tmp;
    }
    --m_length;
}

template<typename T>
void Doubly_List<T>::pop_front() noexcept {
    if (empty()) {
        return;
    }
    else if (m_head == m_tail) {
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
    }
    else {
        Node<T>* tmp = m_head;
        m_head = m_head->next;
        m_head->prev = nullptr;   
        delete tmp;
    }
    --m_length;
}

template<typename T>
std::size_t Doubly_List<T>::size() const noexcept {
    return m_length;
}

template<typename T>
T* Doubly_List<T>::front() {
    return m_head;
}

template<typename T>
T* Doubly_List<T>::back() {
    return m_tail;
}

template <typename O>
std::ostream& operator << (std::ostream& out, const Doubly_List<O>& ls) {
    if (ls.m_head != nullptr)
    {
        typename Doubly_List<O>::template Node<O>* tmp = ls.m_head;

        while (tmp != nullptr)
        {
            out << tmp -> data << ' ';
            tmp = tmp -> next;
        }
    } 
    return out;
}

#endif //DOUBLY_LINKED_LIST_H
