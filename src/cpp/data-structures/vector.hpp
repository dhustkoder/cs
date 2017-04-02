#ifndef CS_DATA_STRUCTURES_VECTOR_HPP_
#define CS_DATA_STRUCTURES_VECTOR_HPP_
#include <exception>
#include <limits>
#include <utility>


template<class T>
class Vector
{
public:
	Vector() : 
		m_data(nullptr),
		m_size(0),
		m_cap(0)
	{
	
	}


	~Vector()
	{
		delete[] m_data;
	}



	const T& operator[](int idx) const
	{
		return m_data[idx];
	}


	T& operator[](int idx)
	{
		return static_cast<const Vector<T>&>(*this)[idx];
	}

	
	int size() const
	{
		return m_size;
	}

	int capacity() const
	{
		return m_cap;
	}


	const T* begin() const
	{
		return m_data;
	}

	const T* end() const
	{
		return m_data + size();
	}


	T* begin()
	{
		return const_cast<T*>(static_cast<const Vector<T>&>(*this)->begin());
	}

	T* end()
	{
		return const_cast<T*>(static_cast<const Vector<T>&>(*this)->end());
	}

	void resize(unsigned long long need)
	{
		unsigned long long total = capacity() + need;

		if (total >= std::numeric_limits<int>::max())
			throw std::runtime_error("Can't resize vector");

		T* newbuf = new T[total];

		try {
			for (int i = 0; i < size(); ++i)
				newbuf[i] = m_data[i];
		} catch (...) {
			delete[] newbuf;
			throw;
		}

		delete[] m_data;
		m_data = newbuf;
		m_cap = static_cast<int>(need);
	}

	
	void reserve(int need)
	{
		if (need > capacity())
			resize(need - capacity());
	}


	void push_back(T elem)
	{
		if (size() >= capacity())
			resize(size() / 2);

		m_data[m_size++] = std::move(elem);
	}

private:
	T* m_data;
	int m_size;
	int m_cap;
};

#endif

