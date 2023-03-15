#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include <map>

#define MAX	2147483647

double findRate(std::string date, std::map<std::string, double> data);
void checkInput(char *file, std::map<std::string, double> data);
std::map<std::string, double> readData();
void printMap(const std::map<std::string, double>& myMap);
std::string moveDateBackOneDay(const std::string& date);
bool ifValidDate(const std::string& date);
bool ifValidValue(const std::string& value);

#endif