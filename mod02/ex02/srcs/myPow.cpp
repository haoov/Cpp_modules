int myPow(const int nb, const int exp) {
	if (exp == 0) {
		return (1);
	}
	int res = nb;
	for (int i = 1; i < exp; ++i) {
		res *= nb;
	}
	return (res);
}