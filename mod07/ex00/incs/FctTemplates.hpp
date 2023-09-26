#ifndef FCTTEMPLATES_HPP
#define FCTTEMPLATES_HPP

template <typename T>
void swap(T a, T b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T a, T b) {
	if (a < b) {
		return (a);
	}
	else {
		return (b);
	}
}

template <typename T>
T max(T a, T b) {
	if (a > b) {
		return (a);
	}
	else {
		return (b);
	}
}

#endif