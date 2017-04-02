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
		return const_cast<T&>(static_cast<const Vector<T>&>(*this)[idx]);
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
		if (need >= std::numeric_limits<int>::max())
			throw std::runtime_error("Can't resize vector");

		T* newbuf = new T[need];

		try {
			const int limit = static_cast<int>(need) > size()
			                  ? size()
			                  : static_cast<int>(need);

			for (int i = 0; i < limit; ++i)
				newbuf[i] = m_data[i];

		} catch (...) {
			delete[] newbuf;
			throw;
		}

		delete[] m_data;
		m_data = newbuf;
		m_cap = static_cast<int>(need);

		if (m_cap < m_size)
			m_size = m_cap;
	}

	
	void reserve(unsigned long long need)
	{
		if (need > static_cast<unsigned long long>(capacity()))
			resize(need + (size() / 2));
	}


	void push_back(T elem)
	{
		ensure_capacity(size() + 1);
		m_data[m_size++] = std::move(elem);
	}


private:
	void ensure_capacity(unsigned long long need)
	{
		if (need > static_cast<unsigned long long>(capacity()))
			reserve(need + (need / 2));
	}


private:
	T* m_data;
	int m_size;
	int m_cap;
};

#endif

