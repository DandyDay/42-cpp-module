/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhchoi <jinhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 10:50:31 by jinhchoi          #+#    #+#             */
/*   Updated: 2023/08/27 16:22:01 by jinhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::_nbAccounts = 0;
Account::_totalAmount = 0;
Account::_totalNbDeposits = 0;
Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return 0;
}

int Account::getTotalAmount(void)
{
	return 0;
}

int Account::getNbDeposits(void)
{
	return 0;
}

int Account::getNbWithdrawals(void)
{
	return 0;
}

void Account::displayAccountsInfos(void)
{
}

Account::Account(int initial_deposit)
{
}

Account::~Account(void)
{
}

void Account::makeDeposit(int deposit)
{
}

bool Account::makeWithdrawal(int withdrawal)
{
	return false;
}

int Account::checkAmount(void) const
{
	return 0;
}

void Account::displayStatus(void) const
{
}

void Account::_displayTimestamp(void)
{
}
