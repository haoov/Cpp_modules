#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
	public :
		Array() : m_size(10) {
			this->array = new T[this->m_size];
		}
		Array(int n) : m_size(n) {
			this->array = new T[n];
			for (int i = 0; i < n; ++i) {
				this->array[i] = 0;
			}
		}
		Array(const Array &other) : m_size(other.size()) {
			this->array = new T[other.size()];
			*this = other;
		}
		~Array() {
			delete [] this->array;
		}

		Array &operator=(const Array &other) {
			for (int i = 0; i < other.size() && i < this->m_size; ++i) {
				this->array[i] = other.array[i];
			}
			return (*this);
		}
		T &operator[](int index) {
			if (index < 0 || index >= this->m_size) {
				throw std::exception();
			}
			return (this->array[index]);
		}

		int size() const {
			return (this->m_size);
		}
	private :
		int m_size;
		T *array;
};

#endif