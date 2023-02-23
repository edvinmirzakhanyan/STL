String::String ()
{
    m_cap = 1;
    m_size = 0;
    m_arr = new char[m_cap];
    m_arr[0] = '\0';
}

String::String (const char* str)
{
    m_size = 0;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        ++m_size;
    }

    m_cap = m_size + 1;
    m_arr = new char[m_cap];
    int i = 0;
    for (i = 0; i < m_size; ++i)
    {
        m_arr[i] = str[i];
    }
    m_arr[i] = '\0';

}

String::String (const String& str)
{
    m_size = str.m_size;
    m_cap = str.m_cap;
    m_arr = new char[m_cap];

    for (int i = 0; i < m_size + 1; ++i)
    {
        m_arr[i] = str.m_arr[i];
    }
}

String::String (String&& str)
{
    m_size = str.m_size;
    m_cap = str.m_cap;
    m_arr = str.m_arr;
    str.m_size = 0;
    str.m_cap = 0;
    str.m_arr = nullptr;
}

String::~String () 
{
    delete[] m_arr;
} 

String& String::operator = (String&& str)
{
    if (this != &str)
    {
        delete[] m_arr;
        m_arr = str.m_arr;
        m_size = str.m_size;
        m_cap = str.m_cap;
        str.m_arr = nullptr;
        str.m_size = 0;
        str.m_cap = 0; 
    }

    return *this;
}

String& String::operator = (const String& str)
{
    if (this != &str)
    {
        delete[] m_arr;
        m_cap = str.m_cap;
        m_size = str.m_size;
        m_arr = new char[m_cap];

        for (int i = 0; i < m_size + 1; ++i)
        {
            m_arr[i] = str.m_arr[i];
        }        
    }

    return *this;
}

String String::operator + (const String& str)
{
    String tmp;
    tmp.m_size = m_size + str.m_size;
    tmp.m_cap = m_cap + str.m_cap;
    tmp.m_arr = new char[tmp.m_cap];
    int i = 0;

    for (i; i < m_size; ++i)
    {
        tmp.m_arr[i] = m_arr[i]; 
    }
    for (int j = 0; i < tmp.m_size + 1; ++i,++j)
    {
        tmp.m_arr[i] = str.m_arr[j];
    }

    return tmp;
}

int String::length ()
{
    int count = 0;
    for (int i = 0; m_arr[i] != '\0'; ++i)
    {
        ++count;
    }

    return count;
}

void String::push_back (char elem)
{
    if (m_size == m_cap - 1)
    {
        m_cap *= 2;
        char* tmp = new char[m_cap];

        for (int i = 0; i < m_size; ++i)
        {
            tmp[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = tmp;
    }
    m_arr[m_size++] = elem;
}

String String::substr(int index, int count)
{
    if (index >= m_size || index < 0) { return "Incorrect index"; }
    String tmp;
    tmp.m_size = count;
    tmp.m_cap = count + 1;
    tmp.m_arr = new char[tmp.m_cap];

    for (int i = index, j = 0; count != 0; --count, ++i, ++j)
    {
        if (m_arr[i] == '\0') { break;} 
        tmp.m_arr[j] = m_arr[i];      
    }
    tmp.m_arr[m_size] = '\0';

    return tmp;
}

std::ostream& operator << (std::ostream& out, const String str)
{
    for (int i = 0; i < str.m_size; ++i)
    {
        out << str.m_arr[i];
    }
    return out;
}
