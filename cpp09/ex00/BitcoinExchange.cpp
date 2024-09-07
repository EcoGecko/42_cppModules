

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &rhs) {
	*this = rhs;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	if (this == &rhs) {
		return (*this);
	}
	this->database = rhs.database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {
}

bool BitcoinExchange::convert(const char *input) {
	if (!this->loadRates()) {
		return (false);
	}

	std::ifstream inFile;

	inFile.open(input, std::ios::in);
	if (inFile.fail()) {
		return (false);
	}

	std::string   line, date;
	float         value, finalValue;

	std::getline(inFile, line);
	while (!inFile.eof()) {
		std::getline(inFile, line);
		if (line.empty() || !this->getTokens(line, date, value)) {
			continue;
		}
		if (this->database.find(date) == this->database.end()) {
			finalValue = this->findClosestDate(date) * value;
		} else {
			finalValue = this->database[date] * value;
		}
		std::cout << date + " => " << value << " = " << finalValue << std::endl;
	}
	return (true);
}

bool BitcoinExchange::loadRates(void) {
	std::ifstream rates;
	std::string   date, value;

	rates.open(INPUT_DATA, std::ios::in);
	if (rates.fail()) {
		std::cerr << BAD_RATES << std::endl;
		return (false);
	}
	std::getline(rates, date);
	while (true) {
		std::getline(rates, date, ',');
		std::getline(rates, value);
		if (rates.eof()) {
			rates.close();
			return (true);
		}
		this->database[date] = std::strtof(value.c_str(), NULL);
	}
}

void BitcoinExchange::printDatabase(void) {
	std::cout << "Database:" << std::endl;
	for (std::map<std::string, float>::iterator it = this->database.begin();
		 it != this->database.end(); ++it) {
		std::cout << it->first << " => " << it->second << std::endl;
	}
}

float BitcoinExchange::findClosestDate(const std::string &date) const {
	std::map<std::string, float>::const_iterator it, itp;

	it  = this->database.begin();
	itp = this->database.begin();
	it++;
	while (it != this->database.end()) {
		if (it->first > date) {
			return (itp->second);
		}
		itp = it;
		it++;
	}
	return (itp->second);
}

bool BitcoinExchange::getTokens(std::string const &line, std::string &date, float &value) {
	std::istringstream stream(line);
	std::string        separator;

	if (!(stream >> date >> separator >> value)) {
		std::cerr << BAD_INPUT << " => " << line << std::endl;
		return (false);
	}
	if (!this->validateDate(date)) {
		std::cerr << BAD_INPUT << " => " << line << std::endl;
		return (false);
	}
	if (value < 0) {
		std::cerr << BAD_NUMBER << std::endl;
		return (false);
	}
	if (value > MAX) {
		std::cerr << BAD_MAX << std::endl;
		return (false);
	}
	return (true);
}

bool BitcoinExchange::validateDate(std::string const &date) const {
	std::istringstream stream(date);
	char               separator;
	int                year, month, day;

	if (date.length() != 10) {
		return (false);
	}
	if (!(stream >> year >> separator >> month >> separator >> day)) {
		return (false);
	}
	if (year < 1970 || year > 2970) {
		return (false);
	}
	if (month < 1 || month > 12) {
		return (false);
	}
	if (day < 1 || day > 31) {
		return (false);
	}
	if (month == 2) {
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
			return (day <= 29);
		} else {
			return (day <= 28);
		}
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		return (false);
	}
	return (true);
}
