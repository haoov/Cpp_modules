#include "../incs/PmergeMe.hpp"

/*------------------------------------*/
/*    Constructors and destructor     */
/*------------------------------------*/

template <template <typename, typename> class C>
PmergeMe<C>::PmergeMe(const char *str) : _str(str) {
	if (_str.empty())
		throw Error("no argument");
	_odd = false;
	parseArg();
	std::clock_t start = std::clock();
	sort();
	if (_c.size() > 1)
		insert();
	_time = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);
}

template <template <typename, typename> class C>
PmergeMe<C>::PmergeMe(const PmergeMe &other) {
	*this = other;
}

template <template <typename, typename> class C>
PmergeMe<C>::~PmergeMe() {}

/*------------------------------------*/
/*              Operators             */
/*------------------------------------*/

template <template <typename, typename> class C>
PmergeMe<C> &PmergeMe<C>::operator=(const PmergeMe<C> &other) {
	static_cast<void>(other);
	return *this;
}

/*------------------------------------*/
/*              Methods               */
/*------------------------------------*/

template <template <typename, typename> class C>
void PmergeMe<C>::parseArg() {
	std::string str;
	std::stringstream ss(_str);
	while (std::getline(ss, str, ' ')) {
		for (size_t i = 0; i < str.size(); ++i) {
			if (!::isdigit(str[i]))
				throw Error("invalid argument: " + str);
		}
		int val = ::atoi(str.c_str());
		_c.push_back(val);
	}
}

template <template <typename, typename> class C>
void PmergeMe<C>::sort() {
	//handle special case for one number
	if (_c.size() == 1)
		return (_main.push_back(*_c.begin()));
	//check if base chain has an odd number of values
	_odd = (_c.size() % 2);
	//loop through the chain and divide it by pair Bn, An with Bn < An
	it_t end = (_odd ? _c.end() - 1 : _c.end());
	for (it_t it = _c.begin(); it != end; it += 2) {
		if (*it > *(it + 1))
			std::iter_swap(it, it + 1);
		_pair.push_back(int_pair_t(*it, *(it + 1)));
	}
	//store the last number if there is one
	if (_odd)
		_last = *(_c.end() - 1);
	//sort the pairs by highest values
	std::sort(_pair.begin(), _pair.end(), highCompare);
	//create the main chain
	for (int_pair_cont_it_t it = _pair.begin(); it != _pair.end(); ++it)
		_main.push_back(it->second);
}

template <template <typename, typename> class C>
void PmergeMe<C>::insert() {
	size_t j;
	int_pair_cont_it_t it = _pair.begin();
	int_pair_cont_it_t it2 = it;
	it_t insertPoint;
	//insert first at begining of the main chain
	_main.insert(_main.begin(), _pair.begin()->first);
	//check if we have a valid jacobsthal number
	for (int i = 3; (j = jacobsthal(i)) < _pair.size(); ++i) {
		//if we do insert from the jacobsthal index (it2) to the current index (it)
		for (it2 = _pair.begin() + j; it2 != it; --it2) {
			insertPoint = std::upper_bound(_main.begin(), _main.end(), it2->first);
			_main.insert(insertPoint, it2->first);
		}
		//move current index to the jacobsthal index
		it = _pair.begin() + j;
	}
	//if there is pending numbers insert them starting from the end
	for (it2 = _pair.end() - 1; it2 != it && it != _pair.end(); --it2) {
		insertPoint = std::upper_bound(_main.begin(), _main.end(), it2->first);
		_main.insert(insertPoint, it2->first);
	}
	//if we have a last odd index insert it
	if (_odd) {
		insertPoint = std::upper_bound(_main.begin(), _main.end(), _last);
		_main.insert(insertPoint, _last);
	}
}

//return jaconsthal number at index n
template <template <typename, typename> class C>
size_t PmergeMe<C>::jacobsthal(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

template <template <typename, typename> class C>
bool PmergeMe<C>::highCompare(int_pair_t p1, int_pair_t p2) {
	return (p1.second < p2.second);
}

template <template <typename, typename> class C>
void PmergeMe<C>::printChain() {
	for (size_t i = 0; i < _main.size(); ++i) {
		std::cout << _main[i] << " ";
		if (i == _main.size() - 1)
			std::cout << std::endl;
	}
}

template <template <typename, typename> class C>
double PmergeMe<C>::getTime() const throw() {
	return _time;
}

/*------------------------------------*/
/*              Exception             */
/*------------------------------------*/

template <template <typename, typename> class C>
PmergeMe<C>::Error::Error(std::string what) : _what("Error: " + what) {}

template <template <typename, typename> class C>
PmergeMe<C>::Error::~Error() throw() {}

template <template <typename, typename> class C>
const char *PmergeMe<C>::Error::what() const throw() {
	return _what.c_str();
}