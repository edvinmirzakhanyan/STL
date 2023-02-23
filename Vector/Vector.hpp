Vector::Vector () 
{
	m_capacity = 0;
	m_size = 0;
	m_arr = nullptr;
}

Vector::Vector (int capacity)
{	
	if (capacity > 0)
	{
		m_capacity = capacity;
		m_size = 0;
		m_arr = new int[m_capacity];
	}
}

Vector::Vector (int capacity,int num)
{
	if (capacity > 0)
	{
		m_capacity = capacity;
		m_size = m_capacity;
		m_arr = new int[m_capacity];
	
		for(int i = 0; i < m_size; ++i)
		{
			m_arr[i] = num;
		}	
	}
}

Vector::Vector (const Vector& v)
{
	m_capacity = v.m_capacity;
	m_size = v.m_size;
	m_arr = new int[m_capacity];

	for (int i = 0; i < m_size; ++i)
	{
		m_arr[i] = v.m_arr[i];
	}
}

Vector::~Vector () { delete m_arr; }

Vector& Vector::operator =  (const Vector& obj)
{
	if (this == &obj) { return *this; }
	
	delete [] m_arr;
	m_capacity = obj.m_capacity;
	m_size = obj.m_size;
	m_arr = new int[m_capacity];

	for (int i = 0; i < m_size; ++i)
	{
		m_arr[i] = obj.m_arr[i];
	}

	return *this;
}

Vector Vector::operator + (const Vector& obj)
{
	Vector tmp;
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
			
Vector& Vector::operator += (const Vector& obj)
{
	*this = *this + obj;

	return *this;
}

int& Vector::operator [] (int index)
{
	if (index >= 0 && index < m_size)
	{
		return m_arr[index];
	}
	
	std::cout << "Incorrect index" << std::endl;
}

void Vector::push_back (int num)
{
	if (0 == m_capacity) 
	{
		++m_capacity;
		m_arr = new int;
	}
	
	if (m_size == m_capacity)
	{
		m_capacity *= 2;
		int* tmp = new int[m_capacity];

		for (int i = 0; i < m_size; ++i)
		{
			tmp[i] = m_arr[i];

		}
		delete [] m_arr;
		m_arr = tmp;
	}

	m_arr[m_size++] = num;
}

void Vector::insert (int index, int num)
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
		int* tmp = new int[m_capacity];

		for (int i = 0,j = 0; i < m_size; ++i)
		{
			if (i == index)
			{
				tmp[i] = num;
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
				m_arr[i] = num;
				break;
			}
			m_arr[i] = m_arr[i - 1];
		}
	}
}		

int Vector::find_by_value (int num)
{
	for (int i = 0; i < m_size; ++i)
	{
		if (m_arr[i] == num)
		{
			return i;
		}
	}
	std::cout << "Not found" << std::endl;
	return -1;
}

void Vector::remove_by_value (int num)
{
	for (int i = 0; i < m_size; ++i)
	{
		if (m_arr[i] == num)
		{
			for (int j = i + 1; j < m_size; ++j)
			{
				m_arr[j - 1] = m_arr[j];
			}
			--m_size;
			break;
		}
	}
}

std::ostream& operator << (std::ostream& out,const Vector& v)
{
	for (int i = 0; i < v.m_size; ++i)
	{
		out << v.m_arr[i] << ' ';
	}
	return out;
}

	














