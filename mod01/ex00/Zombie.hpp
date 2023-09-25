#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	public :
	Zombie(std::string name);
	~Zombie();
	void annouce() const;
	private :
	std::string name;
};

#endif //ZOMBIE_HPP