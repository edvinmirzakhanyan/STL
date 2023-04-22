template <typename T>
class Forward_list
{
    public:
        Forward_list ();
        Forward_list (int, T);
        Forward_list (const Forward_list&);
        Forward_list (Forward_list&&);
        ~Forward_list ();
        Forward_list& operator = (const Forward_list&);
        Forward_list& operator = (Forward_list&&);
        Forward_list operator + (const Forward_list&);
        void insert_after (int, T);
        void push_front (T);
        void erase_after (int);
        template <typename O>
        friend std::ostream& operator << (std::ostream&, const Forward_list<O>&);
    private:
        template <typename N>
        struct Node
        {
            Node<N>* next;
            N data;
        };
        Node<T>* m_head;
        Node<T>* m_tail;
};

template <typename T>
Forward_list<T>::Forward_list ()
{
    m_head = nullptr;
    m_tail = nullptr;
}

template <typename T>
Forward_list<T>::Forward_list (int size, T value)
{
    m_head = nullptr;
    m_tail = nullptr;

    if (size > 0)
    {
        m_head = new Node<T>;
        m_head -> data = value;
        m_tail = m_head;

    for (int i = 1; i < size; ++i)
    {
        m_tail -> next = new Node<T>;
        m_tail = m_tail -> next;   
        m_tail -> data = value;
           

    }
    m_tail -> next = nullptr;
    }
}

template <typename T>
Forward_list<T>::Forward_list (const Forward_list<T>& ls)
{
    if (ls.m_head != nullptr)
    {
        m_head = new Node<T>;
        m_head -> data = ls.m_head -> data;
        m_tail = m_head; 
        Node<T>* tmp = ls.m_head;

    while (tmp -> next != nullptr)
    {
        m_tail -> next = new Node<T>;
        m_tail = m_tail -> next;
        tmp = tmp -> next;
        m_tail -> data = tmp -> data;
    }
    m_tail -> data = ls.m_tail -> data;
    }
}

template <typename T>
Forward_list<T>::Forward_list (Forward_list<T>&& ls)
{
    m_head = ls.m_head;
    m_tail = ls.m_tail;
    ls.m_head = nullptr;
    ls.m_tail = nullptr;
}

template <typename T>
Forward_list<T>::~Forward_list ()
{
    while (m_head != nullptr)
    {
        m_tail = m_head -> next;
        delete m_head;
        m_head = m_tail;
    }
}

template <typename T>
Forward_list<T>& Forward_list<T>::operator = (const Forward_list<T>& ls)
{
    
    if (this != &ls)
    {
    Node<T>* tmp;
    while (m_head != nullptr)
    {
        tmp = m_head -> next;
        delete m_head;
        m_head = tmp;
    }
    if (ls.m_head != nullptr)
    {
        m_head = new Node<T>;
        m_head -> data = ls.m_head -> data;
        m_tail = m_head; 
        tmp = ls.m_head -> next;

    while (tmp != nullptr)
    {
        m_tail -> next = new Node<T>;
        m_tail = m_tail -> next;
        m_tail -> data = tmp -> data;
        tmp = tmp -> next;
    }
    }
    }
    return *this;
}

template <typename T>
Forward_list<T>& Forward_list<T>::operator = (Forward_list<T>&& ls)
{
    if (m_head != nullptr)
    {
    m_tail = m_head -> next;
    while (m_head != nullptr)
    {
        m_tail = m_head -> next;
        delete m_head;
        m_head = m_tail;
    }
    }
    m_head = ls.m_head;
    m_tail = ls.m_tail;
    ls.m_head = nullptr;
    ls.m_tail = nullptr;

    return *this;
}

template <typename T>
Forward_list<T> Forward_list<T>::operator + (const Forward_list<T>& ls)
{
    Forward_list<T> tmp;
    if (ls.m_head != nullptr && m_head != nullptr)
    {
        m_tail -> next = ls.m_head;
        tmp.m_head = m_head;
        tmp.m_tail = ls.m_tail;
    }
    return tmp;
}

template <typename T>
void Forward_list<T>::insert_after (int index, T value)
{
    if (this->m_head != nullptr) {
        Node<T>* tmp = m_head;
        Node<T>* tmp1;

        for (int i = 0; tmp != nullptr; ++i)
        {
            tmp1 = tmp -> next;
            if (i == index)
            {
                tmp -> next = new Node<T>;
                tmp = tmp -> next;
                tmp -> data = value;
                tmp -> next = tmp1;
                break;
            }
            tmp = tmp -> next;
        }
    } else if(m_head == nullptr) {
        std::cout << "List is empty" << std::endl;
    }
}

template <typename T>
void Forward_list<T>::push_front(T value)
{
    Node<T>* tmp = new Node<T>;
    tmp -> data = value;
    tmp -> next = m_head;
    m_head = tmp;
    if (m_tail == nullptr) {
        m_tail = m_head;
    }
}

template <typename T>
void Forward_list<T>::erase_after (int index)
{
    if (m_head != nullptr)
    {
    Node<T>* tmp = m_head;
    Node<T>* tmp1;
    for (int i = 0; tmp -> next != nullptr; ++i)
    {
        tmp1 = tmp -> next; 
        if (i == index)
        {
            tmp1 = tmp1 -> next;
            delete tmp -> next;
            tmp -> next = tmp1;
            break;
        }
        tmp = tmp -> next;
    }
    }
}

template <typename O>
std::ostream& operator << (std::ostream& out, const Forward_list<O>& ls)
{
    if (ls.m_head != nullptr)
    {
        typename Forward_list<O>::template Node<O>* tmp = ls.m_head;

        while (tmp != nullptr)
        {
            out << tmp -> data << ' ';
            tmp = tmp -> next;
        }
    } 
    return out;
}