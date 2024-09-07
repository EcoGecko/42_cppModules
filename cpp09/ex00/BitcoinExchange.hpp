

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# define MAX 1000
# define BAD_FILE "Error: could not open file."
# define BAD_INPUT "Error: bad input"
# define BAD_RATES "Error: could not open database file"
# define BAD_NUMBER "Error: not a positive number."
# define BAD_MAX "Error: too large a number."
# define INPUT_DATA "data.csv"

#include <map>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>

class BitcoinExchange {
public:
	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const &rhs);
	BitcoinExchange &operator=(BitcoinExchange const &rhs);
	~BitcoinExchange(void);

	bool convert(char const *input);
	void printDatabase(void);

private:
	std::map<std::string, float> database;

	bool loadRates(void);
	float findClosestDate(std::string const &date) const;
	bool getTokens(std::string const &line, std::string &date, float &value);
	bool validateDate(std::string const &date) const;
};

#endif
