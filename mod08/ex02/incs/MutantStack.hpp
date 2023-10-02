#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <vector>
#include <iterator>
#include <cstddef>

template <typename T>
class MutantStack : public std::stack<T> {
	public :
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename MutantStack::stack stack;

		MutantStack();
		MutantStack(const MutantStack &);
		~MutantStack();

		MutantStack &operator=(const MutantStack &);

		iterator begin();
		iterator end();
};

#endif //MUTANTSTACK_HPP