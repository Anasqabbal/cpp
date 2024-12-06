#include "phonebook.hpp"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    const char 			*str;
    std::string			strl;
    const char 			*res;
    std::string			line;
    PhoneBook  			ph;
    int					index;
    int					flag;
    // bool				isnum;

    index = 0;
    ph.set_i_value(index - 1);
    (void)res;
    while(1)
    {
        flag = 0;
        std::cin >> strl;
        str = strl.c_str();
        if (!str)
            std::cout.write("7adari oba ba ba ba ba\n", 23);
        if (str && !strcmp(str, "ADD"))
        {
            ph.ft_read(0, ph.get_values(), index);
            ph.ft_read(1, ph.get_values(), index);
            ph.ft_read(2, ph.get_values(), index);
            ph.ft_read(3, ph.get_values(), index);
            ph.ft_read(4, ph.get_values(), index);
			ph.set_values(ph.get_values(), index % 8, 0, index);
	        if (ph.get_i_value() < 7)
                ph.set_i_value(index % 8);
            index++;
        }
        else if (str && !strcmp(str, "SEARCH"))
        {
			ph.print_all_contacts(ph);
			std::cin.ignore();
            while(1 && ph.get_i_value() != -1)
            {
                if (!flag)
			        write(1, "enter index number: ", 20);
                else
                    write(1, "your index out of the range, try another one: ", 46);
                std::getline(std::cin, line, '\n');
                res = line.c_str();
				if (std::cin.eof())
            		_exit(0);
                if (!res)
                    break ;
                if ((!strcmp(res, "")))
                    continue ;
                // isnum = std::all_of(line.begin(), line.end(), ::isdigit);
				// if (isnum &&  ph.print_specific_contact(ph, atoi(res), &flag))
				// 	break ;
                 if (ph.print_specific_contact(ph, atoi(res), &flag))
                    break;
            }
        }
        else if (str && !strcmp(str, "EXIT"))
            _exit(0);
    }
    return (0);
}