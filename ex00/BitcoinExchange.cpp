#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin(char *file) {readData(); checkInput(file);}
Bitcoin::Bitcoin( const Bitcoin& btc ) {*this = btc;}
Bitcoin::~Bitcoin( void ) {}
Bitcoin& Bitcoin::operator=( const Bitcoin& btc ) {this->_data = btc._data; return *this;}

void Bitcoin::readData() {
	std::ifstream file("data.csv");
    std::string line;
    // Skip first line
    std::getline(file, line);
    // Read data from file and insert into map
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, rate;
        std::getline(ss, date, ',');
        std::getline(ss, rate, ',');
        _data[date] = std::stod(rate);
    }
}

void Bitcoin::checkInput(char *file) {
	// check if file exists
	std::ifstream inputFile(file);
    if (!inputFile) {
        std::cerr << "Error: Failed to open file." << std::endl;
        exit(1);
    }
	// check the first line
    std::string firstLine;
    std::getline(inputFile, firstLine);
    if (firstLine.compare("date | value")) {
        std::cerr << "Error: First line of file is not 'date | value'." << std::endl;
        exit(1);
    }
    // Parse the rest
    std::string line;
    // std::getline(inputFile, line);
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string date;
        std::string value;
        char seperator;
        if(!(iss >> date >> seperator >> value) || seperator != '|')
			std::cout << "Error: bad input => " << date << std::endl;
		else if(stod(value) < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if(stod(value) > MAX)
			std::cout << "Error: too large a number." << std::endl;
		else {
			double mult = stod(value) * findRate(date);
			std::cout << date << " => " << value << " = " << mult << std::endl;
		}
    }
    inputFile.close();
}

double Bitcoin::findRate(std::string date) {
	std::map<std::string, double>::iterator it = _data.find(date);
    if (it != _data.end()) {
        return it->second;
    } else {
        std::string previousDay = moveDateBackOneDay(date);
        return findRate(previousDay);
    }
}

std::string moveDateBackOneDay(const std::string& date) {
    // Extract the year, month, and day from the input date
    int year, month, day;
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
    // Compute the date one day earlier
    int prev_day = day - 1;
    int prev_month = month;
    int prev_year = year;
    if (prev_day == 0) {
        // If we've gone back to the previous month, set the day to the last day of the previous month
        prev_month = month - 1;
        if (prev_month == 0) {
            prev_month = 12;
            prev_year = year - 1;
        }
        switch (prev_month) {
            case 2:
                // Handle leap years for February
                if (prev_year % 4 == 0 && (prev_year % 100 != 0 || prev_year % 400 == 0)) {
                    prev_day = 29;
                } else {
                    prev_day = 28;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                prev_day = 30;
                break;
            default:
                prev_day = 31;
        }
    }
    // Format the previous date as a string and return it
    char prev_date[11];
    snprintf(prev_date, 11, "%04d-%02d-%02d", prev_year, prev_month, prev_day);
    return std::string(prev_date);
}

void printMap(const std::map<std::string, double>& map) {
    std::map<std::string, double>::const_iterator it;
    for (it = map.begin(); it != map.end(); ++it) {
        std::cout << it->first << "=" << it->second << " ";
    }
    std::cout << std::endl;
}

std::map<std::string, double> Bitcoin::getData() {
	return _data;
}

// double& Converter::getValued( void ) {
// 	return _valued;
// }

// float& Converter::getValuef( void ) {
// 	return _valuef;
// }

// int& Converter::getValuei( void ) {
// 	return _valuei;
// }

// int& Converter::getType( void ) {
// 	return _type;
// }
	