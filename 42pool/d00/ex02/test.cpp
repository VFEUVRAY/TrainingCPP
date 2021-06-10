/*
** ETNA PROJECT, 10/06/2021 by feuvra_v
** test
** File description:
**      test file for Account class
*/

#include "Account.class.hpp"
#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <vector>

int main()
{
    typedef std::vector<int> int_v;
    const int size(8);
    const int_v initial_values = {42, 54, 957, 432, 1234, 0, 754, 16576};
    const int_v deposits = {5, 765, 564, 2, 87, 23, 9, 20};
    const int_v withdrawals = {50, 34, 657, 4, 76, 30, 657, 7654};
    Account *tab[size];
    for (int i = 0 ; i != size ; i++)
        tab[i] = new Account(initial_values[i]);
    Account::displayAccountsInfos();
    for (int i = 0 ; i != size ; i++)
        tab[i]->checkAmount();
    for (int i = 0 ; i != size ; i++)
        tab[i]->makeDeposit(deposits[i]);
    Account::displayAccountsInfos();
    for (int i = 0 ; i != size ; i++)
        tab[i]->makeWithdrawal(withdrawals[i]);
    Account::displayAccountsInfos();
    for (int i = 0 ; i != size ; i++)
        tab[i]->displayStatus();
    for (int i = 0 ; i != size ; i++)
        delete (tab[i]);
    /*
    Account *test = new Account(42);
    Account *test2 = new Account(54);
    Account *test3 = new Account(957);
    Account *test4 = new Account(432);
    Account *test5 = new Account(1234);
    Account *test6 = new Account(0);
    Account *test7 = new Account(754);
    Account *test8 = new Account(16576);
    Account::displayAccountsInfos();
    delete(test);
    */
    return 1;
}