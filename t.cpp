#include <vector>
#include <iostream>



int main()
{
    // std::vector<int> vls = { 1, 2, 3, 4, 5 };
    std::vector<int> vls = {1, 2, 3, 4, 5};

    for (int i = 0; i < vls.size(); i++)
        std::cout << vls[i] << std::endl;
}