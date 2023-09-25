#include <iostream>

int main() {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout	<< "string address : " << &str << std::endl
				<< "ptr stored value : " << stringPTR << std::endl
				<< "ref stored value : " << &stringREF << std::endl << std::endl;
	std::cout	<< "string value : " << str << std::endl
				<< "value pointed by ptr : " << *stringPTR << std::endl
				<< "value pointed by ref : " << stringREF << std::endl;
}