#ifndef BTC_HPP
#define BTC_HPP

#include <map>
#include <iostream>
#include <fstream>

typedef std::pair<std::string, float> str_float;
typedef std::map<std::string, float> str_float_map;

typedef enum errnum {
	badInput = -1,
	wrongDate = -2
} errnum;

void analyseInput(const char *inputFile, str_float_map date_currency);

#endif