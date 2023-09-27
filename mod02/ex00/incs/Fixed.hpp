#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {

	public :

		Fixed();
		Fixed(const Fixed &other);
		~Fixed();
		Fixed &operator=(const Fixed &other);

		int getRawBits() const;
		void setRawBits(const int raw);

	private :

		int rawBits;
		static const int fractBitsNb = 8;

};

#endif