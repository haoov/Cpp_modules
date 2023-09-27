#include "Point.hpp"
#include "Fixed.hpp"

Fixed det(const Point p, const Point a, const Point b);

bool bsp(const Point a, const Point b, const Point c, const Point p) {
	Fixed lr[3];
	lr[0] = det(p, a, b);
	lr[1] = det(p, b, c);
	lr[2] = det(p, c, a);

	if ((lr[0] > 0 && lr[1] > 0 && lr[2] > 0) || (lr[0] < 0 && lr[1] < 0 && lr[2] < 0)) {
		return (true);
	}
	else {
		return (false);
	}
}

Fixed det(const Point p, const Point a, const Point b) {
	Point pa, pb;
	pa.setx(a.getx() - p.getx());
	pa.sety(a.gety() - p.gety());
	pb.setx(b.getx() - p.getx());
	pb.sety(b.gety() - p.gety());

	Fixed det = pa.getx() * pb.gety() - pa.gety() * pb.getx();
	return (det);
}