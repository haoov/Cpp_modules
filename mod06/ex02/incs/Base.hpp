#ifndef BASE_HPP
#define BASE_HPP

class Base {
	public :
		virtual ~Base();

		Base *generate() const;
		void identify(Base *) const;
		void identify(Base &) const;
};

#endif