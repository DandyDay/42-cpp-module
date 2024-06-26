#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T> class Array
{
public:
	Array() : arr(new T[0]), len(0)
	{
	}
	Array(unsigned int n) : arr(new T[n]), len(n)
	{
	}
	Array(const Array &other) : arr(new T[other.len]), len(other.len)
	{
		for (unsigned int i = 0; i < len; i++)
			arr[i] = other.arr[i];
	}
	Array &operator=(const Array &other)
	{
		if (this != *other)
		{
			delete[] arr;
			arr = new T[other.len];
			len = other.len;
			for (unsigned int i = 0; i < len; i++)
				arr[i] = other.arr[i];
		}
		return *this;
	}
	~Array()
	{
		delete[] arr;
	};

	T &operator[](unsigned int idx)
	{
		if (idx >= len)
			throw std::out_of_range("index out of range");
		else
			return arr[idx];
	}
	unsigned int size()
	{
		return len;
	}

private:
	T *arr;
	unsigned int len;
};

#endif
