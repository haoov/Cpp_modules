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

		int getRawBits() const;
		void setRawBits(const int raw);
		float toFloat() const;
		int toInt() const;

	private :

		int rawBits;
		static const int fractBitsNb = 8;

};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif