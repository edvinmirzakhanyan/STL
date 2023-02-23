class Vector
{
	public:
		Vector ();
		Vector (int);
		Vector (int,int);
		Vector (const Vector&);
		~Vector ();
		Vector& operator = (const Vector&);
    		Vector operator + (const Vector&);
    		Vector& operator += (const Vector&);
    		int& operator [] (int);
		void push_back (int);
		void insert (int,int);
		int find_by_value (int);
		void remove_by_value (int);
		friend std::ostream& operator << (std::ostream&, const Vector&);

	private:
		int m_capacity;
		int m_size;
		int* m_arr;
};
