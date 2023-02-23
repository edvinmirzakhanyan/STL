Forward_list::Forward_list ()
{
    m_head = nullptr;
    m_tail = nullptr;
}

Forward_list::Forward_list (int size, int value)
{
    m_head = nullptr;
    m_tail = nullptr;

    if (size > 0)
    {
        m_head = new Node;
        m_head -> data = value;
        m_tail = m_head;

    for (int i = 1; i < size; ++i)
    {
        m_tail -> next = new Node;
        m_tail = m_tail -> next;   
        m_tail -> data = value;
           

    }
    m_tail -> next = nullptr;
    }
}

Forward_list::Forward_list (const Forward_list& ls)
{
    if (ls.m_head != nullptr)
    {
        m_head = new Node;
        m_head -> data = ls.m_head -> data;
        m_tail = m_head; 
        Node* tmp = ls.m_head;

    while (tmp -> next != nullptr)
    {
        m_tail -> next = new Node;
        m_tail = m_tail -> next;
        tmp = tmp -> next;
        m_tail -> data = tmp -> data;
    }
    m_tail -> data = ls.m_tail -> data;
    }
}

Forward_list::Forward_list (Forward_list&& ls)
{
    m_head = ls.m_head;
    m_tail = ls.m_tail;
    ls.m_head = nullptr;
    ls.m_tail = nullptr;
}

Forward_list::~Forward_list ()
{
    while (m_head != nullptr)
    {
        m_tail = m_head -> next;
        delete m_head;
        m_head = m_tail;
    }
}

Forward_list& Forward_list::operator = (const Forward_list& ls)
{
    
    if (this != &ls)
    {
    Node* tmp;
    while (m_head != nullptr)
    {
        tmp = m_head -> next;
        delete m_head;
        m_head = tmp;
    }
    if (ls.m_head != nullptr)
    {
        m_head = new Node;
        m_head -> data = ls.m_head -> data;
        m_tail = m_head; 
        tmp = ls.m_head -> next;

    while (tmp != nullptr)
    {
        m_tail -> next = new Node;
        m_tail = m_tail -> next;
        m_tail -> data = tmp -> data;
        tmp = tmp -> next;
    }
    }
    }
    return *this;
}

Forward_list& Forward_list::operator = (Forward_list&& ls)
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

Forward_list Forward_list::operator + (const Forward_list& ls)
{
    Forward_list tmp;
    if (ls.m_head != nullptr && m_head != nullptr)
    {
        m_tail -> next = ls.m_head;
        tmp.m_head = m_head;
        tmp.m_tail = ls.m_tail;
    }
    return tmp;
}

void Forward_list::insert_after (int index, int value)
{
    if (this != nullptr)
    {
    Node* tmp = m_head;
    Node* tmp1;

    for (int i = 0; tmp != nullptr; ++i)
    {
        tmp1 = tmp -> next;
        if (i == index)
        {
            tmp -> next = new Node;
            tmp = tmp -> next;
            tmp -> data = value;
            tmp -> next = tmp1;
            break;
        }
        tmp = tmp -> next;
    }
    }
}

void Forward_list::push_front(int value)
{
    Node* tmp = new Node;
    tmp -> data = value;
    tmp -> next = m_head;
    m_head = tmp;
}

void Forward_list::erase_after (int index)
{
    if (m_head != nullptr)
    {
    Node* tmp = m_head;
    Node* tmp1;
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

std::ostream& operator << (std::ostream& out, const Forward_list ls)
{
    if (ls.m_head != nullptr)
    {
        Node* tmp = ls.m_head;

        while (tmp != nullptr)
        {
            out << tmp -> data << ' ';
            tmp = tmp -> next;
        }
    }
    return out;
}