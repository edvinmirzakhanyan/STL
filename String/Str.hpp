class String
{
    public:
        String ();
        String (const char*);
        String (const String&);
        String (String&&);
        ~String ();
        String& operator = (String&&);
        String& operator = (const String&);
        String operator + (const String&);
        int length ();
        void push_back (char);
        String substr (int, int);
        friend std::ostream& operator << (std::ostream&,const String);
    private:
    int m_size;
    int m_cap;
    char* m_arr;
};