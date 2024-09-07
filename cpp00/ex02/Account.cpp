/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:34:58 by heda-sil          #+#    #+#             */
/*   Updated: 2023/08/24 10:51:57 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),
										_amount(initial_deposit),
										_nbDeposits(0),
										_nbWithdrawals(0) {

	Account::_totalAmount += this->_amount;
	Account::_nbAccounts++;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void) {

	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(void) {

	return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {

	return Account::_totalAmount;
}

int Account::getNbDeposits(void) {

	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void) {

	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {

	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit) {

	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "withdrawal:";

	if (withdrawal > this->_amount) {
		std::cout << "refused" << std::endl;
		return (false);
	} else {
		std::cout << withdrawal << ";";
	}

	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	this->_amount -= withdrawal;

	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	Account::_totalAmount -= withdrawal;
	return (true);
}

int Account::checkAmount(void) const {

	return (this->_amount);
}

void Account::displayStatus(void) const {

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {

	std::time_t t = std::time(NULL);
	std::tm		tm = *std::localtime(&t);

	std::cout << std::setfill('0') << "[" << tm.tm_year + 1900; //Year
	std::cout << std::setw(2) << tm.tm_mon + 1; //Month
	std::cout << std::setw(2) << tm.tm_mday << "_"; //Day
	std::cout << std::setw(2) << tm.tm_hour; //Hour
	std::cout << std::setw(2) << tm.tm_min; //Minute
	std::cout << std::setw(2) << tm.tm_sec << "] "; //Seconds
}
