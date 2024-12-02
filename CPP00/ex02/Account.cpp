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

void    Account::Account( int initial_deposit )
{
    _amount = initial_deposit;
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


*/




int main()
{
    
    // t   Account[8];/
    std::cout<<"nothing to see here" << std::endl;
}