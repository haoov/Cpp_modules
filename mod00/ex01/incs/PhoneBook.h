#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>

#define PRINTCMDS() (std::cout	<< "Use ADD to add a contact" << std::endl\
								<< "Use SEARCH to search for a specified contact" << std::endl\
								<< "Use EXIT to exit the PhoneBook (warning : all contacts will be lost)" << std::endl)

std::string	GetEntry(const std::string &msg);
std::string Trunc10(const std::string &str);
bool IsOnlyNum(const std::string &str);

#endif