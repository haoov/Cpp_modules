#include "../incs/PmergeMe.hpp"

/*------------------------------------*/
/*    Constructors and destructor     */
/*------------------------------------*/

//template <typename _C>
PmergeMe::PmergeMe(const char *str) : _str(str) {
	_odd = false;
}

//template <typename _C>
PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

//template <typename _C>
PmergeMe::~PmergeMe() {}

/*------------------------------------*/
/*              Operators             */
/*------------------------------------*/

//template <typename _C>
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	static_cast<void>(other);
	return *this;
}

/*------------------------------------*/
/*              Methods               */
/*------------------------------------*/

//template <typename _C>
void PmergeMe::parseArg() {
	std::string str;
	std::stringstream ss(_str);
	while (std::getline(ss, str, ' ')) {
		for (size_t i = 0; i < str.size(); ++i) {
			if (!::isdigit(str[i]))
				throw Error("invalid argument");
		}
		int val = ::atoi(str.c_str());
		_c.push_back(val);
	}
}

//template <typename _C>
void PmergeMe::sort() {
	_odd = (_c.size() % 2);
	for (size_t i = 0; i + 1 < _c.size(); i += 2) {
		if (_c[i] > _c[i + 1]) {
			int tmp = _c[i + 1];
			_c[i + 1] = _c[i];
			_c[i] = tmp;
		}
		_v.push_back(t_int_pair(_c[i], _c[i + 1]));
	}
	if (_odd)
		_last = _c[_c.size() - 1];
	//sort the pairs by highest values
	std::sort(_v.begin(), _v.end(), highCompare);
	for (size_t i = 0; i < _v.size(); ++i) {
		_pen.push_back(_v[i].first);
		_main.push_back(_v[i].second);
	}
}

//template <typename _C>
void PmergeMe::insert() {
	std::vector<int> j_seq = jacobsthalSequence();
	_main.insert(_main.begin(), _pen[0]);
	size_t pi = 1;
	for (size_t ji = 0; ji < j_seq.size(); ++ji) {
		for (size_t ni = j_seq[ji]; ni > pi; --ni)
			insertValue(_pen[ni]);
		pi = j_seq[ji];
	}
	for (size_t ni = _pen.size() - 1; ni > pi; --ni)
		insertValue(_pen[ni]);
	if (_odd)
		insertValue(_last);
}

//template <typename _C>
void PmergeMe::insertValue(int val) {
	size_t loc = binarySearch(_main, val, 0, _main.size());
	std::vector<int>::iterator insertPoint = _main.begin();
	std::advance(insertPoint, loc);
	_main.insert(insertPoint, val);
}

//template <typename _C>
void PmergeMe::binarySort(std::vector<int> &c) {
	for (size_t i = 1; i < c.size(); ++i) {
		int sel = c[i];
		size_t j = i - 1;
		size_t loc = binarySearch(_pen, sel, 0, j);
		std::vector<int>::iterator insertPoint = _main.begin();
		std::advance(insertPoint, loc);
		c.insert(insertPoint, sel);
	}
}

//template <typename _C>
size_t PmergeMe::binarySearch(std::vector<int> c, int val, int min, int max) {
	if (val > c[max - 1])
		return max;
	if (max < min) {
		if (val > c[min])
			return (min + 1);
		else
			return min;
	}
	int mid = (min + max) / 2;
	if (val == c[mid])
		return (mid + 1);
	if (val > c[mid])
		return binarySearch(c, val, mid + 1, max);
	return binarySearch(c, val, min, mid - 1);
}

//template <typename _C>
std::vector<int> PmergeMe::jacobsthalSequence() {
	std::vector<int> j_seq;
	size_t j_index = 3;
	while (static_cast<size_t>(jacobsthal(j_index)) < _pen.size() - 1) {
		j_seq.push_back(jacobsthal(j_index));
		++j_index;
	}
	return j_seq;
}

//template <typename _C>
int PmergeMe::jacobsthal(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

bool PmergeMe::highCompare(t_int_pair p1, t_int_pair p2) {
	return (p1.second < p2.second);
}

//template <typename _C>
std::vector<int> PmergeMe::getMain() const {
	return _main;
}

void PmergeMe::printMain() {
	for (size_t i = 0; i < _main.size(); ++i) {
		std::cout << _main[i] << " ";
		if (i == _main.size() - 1)
			std::cout << std::endl;
	}
}

/*------------------------------------*/
/*              Exception             */
/*------------------------------------*/

//template <typename _C>
PmergeMe::Error::Error(std::string what) : _what("Error: " + what) {}

//template <typename _C>
PmergeMe::Error::~Error() throw() {}

//template <typename _C>
const char *PmergeMe::Error::what() const throw() {
	return _what.c_str();
}