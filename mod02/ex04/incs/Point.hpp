#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {

	public :

		Point();
		Point(Fixed x, Fixed y);
		Point(const Point &other);
		~Point();

		Point &operator=(const Point &other);

		Fixed getx() const;
		Fixed gety() const;
		void setx(Fixed x);
		void sety(Fixed y);

	private :

		Fixed x;
		Fixed y;
};

#endif