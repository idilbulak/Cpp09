#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include <map>

#define MAX	2147483647

class Bitcoin {

    public:
        Bitcoin(char *file);
        Bitcoin (const Bitcoin& btc);
        Bitcoin &operator=(const Bitcoin& btc);
        virtual ~Bitcoin (void);

		std::map<std::string, double> getData();

        void readData();
        void checkInput(char *file);
        double findRate(std::string date);

    private:
		std::map<std::string, double> _data;

};
		void printMap(const std::map<std::string, double>& myMap);
        std::string moveDateBackOneDay(const std::string& date);

#endif