#include "Account.hpp"
#include <iostream>

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

void	Account::displayStatus( void ) const
{
    std::cout<<"index:"<<_accountIndex;
    std::cout<<";amount:"<<_amount;
    std::cout<<";deposits:"<<_nbDeposits;
    std::cout<<";withdrawals:"<<_nbWithdrawals << std::endl;
}
void	Account::displayAccountsInfos( void )
{
    /* to display times temp */
    std::cout.write("accounts:", 9);
    std::cout << getNbAccounts();
    std::cout.write(";total:", 7);
    std::cout << getTotalAmount();
    std::cout.write(";deposits:", 10);
    std::cout << getNbDeposits();
    std::cout.write(";withdrawals:", 13);
    std::cout << getNbWithdrawals() << std::endl;
}

int Account::_nbAccounts = 0;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account( int initial_deposit )
{
    static int index;
    _nbAccounts = index + 1;
    _nbDeposits = 0;
    _amount = initial_deposit;
    _nbWithdrawals = 0;
    _accountIndex = index;
    _totalAmount += initial_deposit;
    std::cout << "index:" << index << ";amount:" << initial_deposit << ";created\n";
    index++;

}

// void    Account::displayStatus(void)
// {

// }
// void	Account::displayAccountsInfos( void )
// {
//     std::cout.write(";withdrawals:", 13);
//     std::cout << _totalNbWithdrawals;
// }

// void	Account::_displayTimestamp( void )
// {

// }

/*

            INITIALISATION IN C++
    -1) copy initialization ----> var_name = value;
    -1) parenthese initialization ----> var_name(value);
    -1) braces initialization ----> var_name{value};

            VECTORS
    DEFINE AND CREATE ONE
    -1) first include the specific header for vector #include<vector>
    -2) std::vector<int>   var_name; // 


    BASIC_FUNCTIONS
    ADD TO BACK =+>  .push_back();
    EDIT AT INDEX =+> .at(index_num);
    REMOVE THE LAST ONE =+> pop_back();

    ITERATING
    we can iterate through the objects using the loops (while, for, ...)
    and in c++ there is also another iterator we can use to iterate over our container like iterator


*/


// static variables cannot initialised inside constructors
