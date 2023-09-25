#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

void DisplayCurrentTime();

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	this->_accountIndex = Account::_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	DisplayCurrentTime();
	std::cout	<< " index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";created" << std::endl;
}

Account::~Account() {
	DisplayCurrentTime();
	std::cout	<< " index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";closed" << std::endl;
}

void Account::displayAccountsInfos() {
	DisplayCurrentTime();
	std::cout	<< " accounts:" << Account::_nbAccounts
				<< ";total:" << Account::_totalAmount
				<< ";deposits:" << Account::_totalNbDeposits
				<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::displayStatus() const {
	DisplayCurrentTime();
	std::cout	<< " index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
	int PreviousAmount = this->_amount;
	this->_amount += deposit;
	++this->_nbDeposits;
	++Account::_totalNbDeposits;
	DisplayCurrentTime();
	std::cout	<< " index:" << this->_accountIndex
				<< ";p_amount:" << PreviousAmount
				<< ";deposit:" << deposit
				<< ";amount:" << this->_amount
				<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	int PreviousAmount = this->_amount;
	DisplayCurrentTime();
	std::cout	<< " index:" << this->_accountIndex
				<< ";p_amount:" << PreviousAmount;
	if (withdrawal > this->_amount) {
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	++this->_nbWithdrawals;
	++Account::_totalNbWithdrawals;
	std::cout	<< ";withdrawal:" << withdrawal
				<< ";amount:" << this->_amount
				<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int Account::getNbAccounts() {
	return (Account::_nbAccounts);
}

int Account::getTotalAmount() {
	return (Account::_totalAmount);
}

int Account::getNbDeposits() {
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals() {
	return (Account::_totalNbWithdrawals);
}

void DisplayCurrentTime() {
	time_t RawTime;
	struct tm *CurrentTime;
	time(&RawTime);
	CurrentTime = localtime(&RawTime);
	std::cout	<< "[" << CurrentTime->tm_year + 1900
				<< std::setfill('0') << std::setw(2) << CurrentTime->tm_mon
				<< std::setfill('0') << std::setw(2) << CurrentTime->tm_wday
				<< "_" << std::setfill('0') << std::setw(2) << CurrentTime->tm_hour
				<< std::setfill('0') << std::setw(2) << CurrentTime->tm_min
				<< std::setfill('0') << std::setw(2) << CurrentTime->tm_sec
				<< "]";
}