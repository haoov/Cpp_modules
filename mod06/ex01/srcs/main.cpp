#include "../incs/Data.hpp"
#include "../incs/Serialize.hpp"
#include <iostream>

int main() {
	Data *dataObj = new Data();
	std::cout << dataObj->value << std::endl;
	Serialize ser;
	uintptr_t uintptr = ser.serialize(dataObj);
	Data *dataObj2 = ser.deserialize(uintptr);
	std::cout << dataObj2->value << std::endl;
	static_cast<void>(uintptr);
	static_cast<void>(dataObj2);
	delete dataObj;
}