#include "../incs/MutantStack.tpp"
#include <iostream>
#include <algorithm>
#include <list>

int main()
{
	{
		MutantStack<int> test;
		test.push(1);
		test.push(20);
		std::cout << "COPY" << std::endl;
		MutantStack<int> copy(test);
		copy.push(955);
		MutantStack<int>::iterator i = copy.begin();
		while (i != copy.end()) {
			std::cout << *i << std::endl;
			++i;
		}
		std::cout << std::endl;
		std::cout << "TEST" << std::endl;
		test = copy;
		i = test.begin();
		while (i != test.end()) {
			std::cout << *i << std::endl;
			++i;
		}
		std::cout << std::endl;
		std::cout << "MUTANTSTACK" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
		std::cout << std::endl;
	}
	{
		std::cout << "LIST" << std::endl;
		std::list<int> list;
		list.push_back(5);
		list.push_back(17);
		std::cout << list.back() << std::endl;
		list.pop_back();
		std::cout << list.size() << std::endl;
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::list<int> s(list);
	}
	return (0);
}