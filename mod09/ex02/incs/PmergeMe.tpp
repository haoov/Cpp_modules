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
	_pair = binarySort(_pair, highCompare);
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
	int insertedNb = 1;
	//while we have a valid jacobsthal number
	for (int i = 3; (j = jacobsthal(i) - 1) < _pair.size(); ++i) {
		//insert from the jacobsthal number index (it2) to current index (it)
		for (it2 = _pair.begin() + j; it2 != it; --it2) {
			insertPoint = binarySearch(_main, 0, j - 1 + insertedNb, it2->first, compare);
			_main.insert(insertPoint, it2->first); ++insertedNb;
		}
		//move current index to the jacobsthal index
		it = _pair.begin() + j;
	}
	//if there is pending numbers insert them starting from the end
	int i = 0;
	for (it2 = _pair.end() - 1; it2 != it && it != _pair.end(); --it2) {
		insertPoint = binarySearch(_main, 0, _pair.size() - i + insertedNb, it2->first, compare);
		_main.insert(insertPoint, it2->first); ++insertedNb; ++i;
	}
	//if we have a last odd index insert it
	if (_odd) {
		insertPoint = binarySearch(_main, 0, _main.size(), _last, compare);
		_main.insert(insertPoint, _last);
	}
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
/*              Utilitys              */
/*------------------------------------*/

template <typename T, template <typename, typename> class C>
C<T, std::allocator<T> > binarySort(C<T, std::allocator<T> > &cont, bool (*comp)(T, T)) {
	size_t i, j;
	C<T, std::allocator<T> > sortedCont;
	typename C<T, std::allocator<T> >::iterator pos;
	/*take the first element of the container as a sorted container and insert
	from the second one to the last one using binary search*/
	sortedCont.insert(sortedCont.begin(), cont[0]);
	for (i = 1; i < cont.size(); ++i) {
		j = i - 1;
		T key = cont[i];
		pos = binarySearch(sortedCont, 0, j, key, comp);
		sortedCont.insert(pos, key);
	}
	return sortedCont;
}

/**
 * @brief function to recursively search for the next greater value in a range.
 * 
 * @param cont a reference to the container
 * @param start,end respectivly starting point and ending point of the range
 * @param key the key value we want to compare
 * @param comp the function used to compare values
 * 
 * @return a iterator on the next greater value in the container
*/
template <typename T, template <typename, typename> class C>
typename C<T, std::allocator<T> >::iterator binarySearch(C<T, std::allocator<T> > &cont, size_t start, size_t end, T key, bool (*comp)(T, T)) {
	//first iterator of container
	typename C<T, std::allocator<T> >::iterator first = cont.begin();
	//low range iterator
	typename C<T, std::allocator<T> >::iterator low = first + start;
	/*if range size is 1 we compare the values*/
	if (end <= start)
		return (comp(key, *low) ? low : low + 1);
	//else compute the mid range dist
	size_t midDst = (start + end) / 2;
	//if key is equal to midDst range value we return mid range (first + midDst)
	if (!comp(*(first + midDst), key) && !comp(key, *(first + midDst))) 
		return (first + midDst);
	//if it is greater we launch a search in the greater part of the range
	if (comp(*(first + midDst), key))
		return binarySearch(cont, midDst + 1, end, key, comp);
	//if it is smaller we launch a search in the smaller part of the range
	return binarySearch(cont, start, (midDst == 0 ? midDst : midDst - 1), key, comp);
}

//return jaconsthal number at index n
size_t jacobsthal(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

bool compare(int a, int b) {
	return (a < b);
}

bool highCompare(std::pair<int, int> p1, std::pair<int, int> p2) {
	return (p1.second < p2.second);
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