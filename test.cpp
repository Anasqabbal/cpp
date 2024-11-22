#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    std::cout << "you enter n" << n;
    
    std::cout << "enter again :";
    std::cin >> n;
    std::cout << "your new value is " << n;
}