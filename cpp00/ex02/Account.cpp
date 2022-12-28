/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:12:38 by sguilher          #+#    #+#             */
/*   Updated: 2022/12/28 19:17:37 by sguilher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts),
										_amount(initial_deposit),
										_nbDeposits(0), _nbWithdrawals(0) {
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" \
			<< "amount:" << this->_amount << ";created" << std::endl;
	return ;
}

Account::Account(void) : _accountIndex(Account::_nbAccounts), _amount(0),
						_nbDeposits(0), _nbWithdrawals(0) {
	Account::_nbAccounts++;
	return ;
}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" \
			<< "amount:" << this->_amount << ";closed" << std::endl;
	Account::_nbAccounts -= 1;
	Account::_totalAmount -= this->_amount;
	return ;
}

int	Account::getNbAccounts(void) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";" \
			<< "total:" << Account::_totalAmount << ";" \
			<< "deposits:" << Account::_totalNbDeposits << ";" \
			<< "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" \
			<< "p_amount:" << this->_amount << ";" \
			<< "deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << "amount:" << this->_amount << ";" \
			<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" \
			<< "p_amount:" << this->_amount << ";";
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ";" \
			<< "amount:" << this->_amount << ";" \
			<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount(void) const {
	return (this->_amount);
}

void	Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";" \
			<< "amount:" << this->_amount << ";" \
			<< "deposits:" << this->_nbDeposits << ";" \
			<< "withdrawals:" << this->_nbWithdrawals << std::endl;
	return ;
}

void	Account::_displayTimestamp(void) {
	std::time_t	timetoday;
	std::tm 	*timestamp;

	std::time(&timetoday);
	timestamp = std::localtime(&timetoday);
	std::cout << "[" << 1900 + timestamp->tm_year << timestamp->tm_mon \
			<< timestamp->tm_mday << "_" << timestamp->tm_hour \
			<< timestamp->tm_min << timestamp->tm_sec << "] ";
}
