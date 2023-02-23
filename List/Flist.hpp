struct Node
{
    int data;
    Node* next;
};

class Forward_list
{
    public:
        Forward_list ();
        Forward_list (int, int);
        Forward_list (const Forward_list&);
        Forward_list (Forward_list&&);
        ~Forward_list ();
        Forward_list& operator = (const Forward_list&);
        Forward_list& operator = (Forward_list&&);
        Forward_list operator + (const Forward_list&);
        void insert_after (int, int);
        void push_front (int);
        void erase_after (int);
        friend std::ostream& operator << (std::ostream&, const Forward_list);
    private:
        Node* m_head;
        Node* m_tail;
};