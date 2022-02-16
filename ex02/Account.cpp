/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 19:38:49 by coder             #+#    #+#             */
/*   Updated: 2022/02/16 21:22:19 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
	
Account::Account( void )
{
}

Account::Account( int initial_deposit )
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";" << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";" << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "p_amount:" << _amount - deposit << ";";
	std::cout << "deposit:" << deposit << ";" << "amount:" << _amount << ";" << "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "p_amount:" << _amount << ";";
	if (_amount >= withdrawal)
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << _amount << ";" << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (true);
	}
	std::cout << "withdrawal:refused" << std::endl;
	return (false);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";";;
	std::cout << "deposits:" << _nbDeposits << ";" << "withdrawals:" << _nbWithdrawals << std::endl;
}


void	Account::_displayTimestamp( void )
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);

    std::cout << "[";
	std::cout << (now->tm_year + 1900);
	std::cout << std::setw(2) << std::setfill('0') << (now->tm_mon + 1);
	std::cout << std::setw(2) << std::setfill('0') <<  now->tm_mday;
	std::cout << "_";
	std::cout << std::setw(2) << std::setfill('0') << (now->tm_hour);
	std::cout << std::setw(2) << std::setfill('0') << (now->tm_min);
	std::cout << std::setw(2) << std::setfill('0') <<  now->tm_sec;
	std::cout << "] ";
}
