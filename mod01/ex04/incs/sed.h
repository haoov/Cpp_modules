#ifndef SED_H
#define SED_H

#include <iostream>
#include <fstream>

std::string readFile(char *file);
void replace(std::string &content, char *pattern, char *replacement);
void writeFile(std::string &content, std::string file);

#endif //SED_H