#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

	public :

		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int nb);
		Fixed(const float nb);
		~Fixed();
		
		Fixed &operator=(const Fixed &other);
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		Fixed operator+(const Fixed &other);
		Fixed operator-(const Fixed &other);
		Fixed operator*(const Fixed &other);
		Fixed operator/(const Fixed &other);
		Fixed operator++(int);
		Fixed &operator++();
		Fixed operator--(int);
		Fixed &operator--();

		int getRawBits() const;
		void setRawBits(const int raw);
		float toFloat() const;
		int toInt() const;
		static Fixed &min(Fixed &obj1, Fixed &obj2);
		static const Fixed &min(const Fixed &obj1, const Fixed &obj2);
		static Fixed &max(Fixed &obj1, Fixed &obj2);
		static const Fixed &max(const Fixed &obj1, const Fixed &obj2);

	private :

		int rawBits;
		static const int fractBitsNb = 8;

};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif