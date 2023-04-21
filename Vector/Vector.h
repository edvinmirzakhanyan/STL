#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector
{
	public:
		Vector ();
		Vector (int);
		Vector (int, T);
		Vector (const Vector&);
		~Vector ();
	public:
		void push_back (T);
		void insert (int, T);
		int find_by_value (T);
		void remove_by_value (T);
		Vector& operator = (const Vector<T>&);
    	Vector operator + (const Vector<T>&);
    	Vector& operator += (const Vector<T>&);
    	T& operator [] (int);
		template <typename O> 
		friend std::ostream& operator << (std::ostream&, const Vector<O>&);
	private:
		int m_capacity;
		int m_size;
		T* m_arr;
};

template <typename T>
Vector<T>::Vector () 
{
	m_capacity = 0;
	m_size = 0;
	m_arr = nullptr;
}

template <typename T>
Vector<T>::Vector (int capacity)
{	
	if (capacity > 0)
	{
		m_capacity = capacity;
		m_size = 0;
		m_arr = new T[m_capacity];
	}
}

template <typename T>
Vector<T>::Vector (int capacity, T val) 
{
	if (capacity > 0)
	{
		m_capacity = capacity;
		m_size = m_capacity;
		m_arr = new T[m_capacity];
	
		for(int i = 0; i < m_size; ++i)
		{
			m_arr[i] = val;
		}	
	}
}

template <typename T>
Vector<T>::Vector (const Vector<T>& v)
{
	m_capacity = v.m_capacity;
	m_size = v.m_size;
	m_arr = new T[m_capacity];

	for (int i = 0; i < m_size; ++i)
	{
		m_arr[i] = v.m_arr[i];
	}
}

template <typename T>
Vector<T>::~Vector () { 
	delete[] m_arr; 
}

template <typename T>
Vector<T>& Vector<T>::operator =  (const Vector<T>& obj)
{
	if (this == &obj) { return *this; }
	
	delete [] m_arr;
	m_capacity = obj.m_capacity;
	m_size = obj.m_size;
	m_arr = new T[m_capacity];

	for (int i = 0; i < m_size; ++i)
	{
		m_arr[i] = obj.m_arr[i];
	}

	return *this;
}

template <typename T>
Vector<T> Vector<T>::operator + (const Vector<T>& obj)
{
	Vector<T> tmp;
	for (int i = 0; i < m_size; ++i)
	{
		tmp.push_back(m_arr[i]);
	}
	for (int i = 0;i < obj.m_size; ++i)
	{ 
		tmp.push_back(obj.m_arr[i]);
	}
	return tmp;
}
			
template <typename T>
Vector<T>& Vector<T>::operator += (const Vector<T>& obj)
{
	*this = *this + obj;

	return *this;
}

template <typename T>
T& Vector<T>::operator [] (int index)
{
		if (index >= 0 && index < m_size)
		{
			return m_arr[index];
		}
}

template <typename T>
void Vector<T>::push_back (T val)
{
	if (0 == m_capacity) 
	{
		++m_capacity;
		m_arr = new T[m_capacity];
	}
	
	if (m_size == m_capacity)
	{
		m_capacity *= 2;
		T* tmp = new T[m_capacity];

		for (int i = 0; i < m_size; ++i)
		{
			tmp[i] = m_arr[i];

		}
		delete [] m_arr;
		m_arr = tmp;
	}

	m_arr[m_size++] = val;
}

template <typename T>
void Vector<T>::insert (int index, T val)
{
	if (index < 0 || index > m_size) 
	{
		std::cout << "Incorrect index" << std::endl;
		return;
	}
	if (0 == m_capacity) 
	{
		++m_capacity;
		m_arr = new int[m_capacity];
	}
	if (m_size == m_capacity) 
	{
		++m_size;
		m_capacity *= 2;
		int* tmp = new T[m_capacity];

		for (int i = 0,j = 0; i < m_size; ++i)
		{
			if (i == index)
			{
				tmp[i] = val;
				continue;
			}
			tmp[i] = m_arr[j];
			++j;
		}
		delete[] m_arr;
		m_arr = tmp;
	}
	else
	{
		++m_size;
		for (int i = m_size - 1; i >= 0; --i)
		{
			if (i == index)
			{
				m_arr[i] = val;
				break;
			}
			m_arr[i] = m_arr[i - 1];
		}
	}
}		

template <typename T>
int Vector<T>::find_by_value (T val)
{
	for (int i = 0; i < m_size; ++i)
	{
		if (m_arr[i] == val)
		{
			return i;
		}
	}

	return -1;
}

template <typename T>
void Vector<T>::remove_by_value (T val)
{
	for (int i = 0; i < m_size; ++i)
	{
		if (m_arr[i] == val)
		{
			for (int j = i + 1; j < m_size; ++j)
			{
				m_arr[j - 1] = m_arr[j];
			}
			--m_size;
			return;
		}
	}
}

template <typename T>
std::ostream& operator << (std::ostream& out,const Vector<T>& v)
{
	for (int i = 0; i < v.m_size; ++i)
	{
		out << v.m_arr[i] << ' ';
	}
	return out;
}

#endif //VECTOR_H