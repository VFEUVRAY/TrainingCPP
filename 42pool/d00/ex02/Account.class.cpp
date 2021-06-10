/*
** ETNA PROJECT, 10/06/2021 by feuvra_v
** Account.class
** File description:
**      account class tingy
*/

#include "Account.class.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalNbDeposits = 0;

static const char *display_time(int time)
{
    if (time < 10)
        return ("0");
    return ("");
}

void Account::_displayTimestamp( void )
{
    std::time_t timer = std::time(NULL);
    struct tm *mytime = gmtime(&timer);
    std::cout<<'['<<mytime->tm_year+1900
    <<display_time(mytime->tm_mon+1)<<mytime->tm_mon+1
    <<display_time(mytime->tm_mday)<<mytime->tm_mday
    <<'_'
    <<display_time((mytime->tm_hour+2)%24)<<(mytime->tm_hour+2)%24
    <<display_time(mytime->tm_min)<<mytime->tm_min
    <<display_time(mytime->tm_sec)<<mytime->tm_sec<<"] ";
}

Account::Account(int desposit)
{
    _accountIndex = _nbAccounts;
    _amount = desposit;
    _nbDeposits = 0;
    _totalAmount += _amount;
    _nbWithdrawals = 0;
    _nbAccounts++;
    Account::_displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";amount:"<<desposit<<";created"<<std::endl;
}

void Account::makeDeposit(int deposit)
{
    _nbDeposits++;
    _totalNbDeposits++;
    Account::_displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount<<";deposit:"<<deposit<<";amount:"<<_amount+deposit<<";nb_deposit:"<<_nbDeposits<<std::endl;
    _amount += deposit;
    _totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount<<";withdrawal:";
    if (_amount < withdrawal){
        std::cout<<"refused"<<std::endl;
        return (false);
    }
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout<<withdrawal<<";amount:"<<_amount<<";withdrawals:"<<_nbWithdrawals<<std::endl;
    return (1);
}

int Account::checkAmount( void ) const
{
    _checkCount++;
    return (_amount);
}

void Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";deposits:"<<_nbDeposits<<";withdrawals:"<<_nbWithdrawals<<std::endl;
}

int Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout<<"accounts:"<<_nbAccounts<<";total:"<<_totalAmount<<";deposits:"<<_totalNbDeposits<<";withdrawals:"<<_totalNbWithdrawals<<std::endl;
}

Account::Account( void )
{
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _checkCount = 0;
}

Account::~Account(void)
{
    Account::_displayTimestamp();
    std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";closed"<<std::endl;
    _totalAmount -= _amount;
    _nbAccounts -= 1;
    _totalNbDeposits -= _nbDeposits;
    _totalNbWithdrawals -= _nbWithdrawals;
}