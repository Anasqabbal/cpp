#include "phonebook.hpp"
#include <stdio.h>


int main()
{
    const char	*str;
    std::string strl;
    const char  *res;
    std::string      line;
    PhoneBook   ph;
    int         index;
    int         i;
    int         flag;
    bool        isnum;

    i = 0;
    index = 0;
    ph.i = -1;
    (void)res;
    while(1)
    {
        flag = 0;
        std::cin >> strl;
        str = strl.c_str();
        if (!str)
            std::cout.write("zefan 3abid, segfault w ghyrhm lkatir, 7adari oba ba ba ba ba\n", 23);
        if (str && !strcmp(str, "ADD"))
        {
            ph.ft_read(0, ph.contacts, index);
            ph.ft_read(1, ph.contacts, index);
            ph.ft_read(2, ph.contacts, index);
            ph.ft_read(3, ph.contacts, index);
            ph.ft_read(4, ph.contacts, index);
            ph.contacts[index % 8].index = ((index % 8) + 48);
            if (ph.i < 7)
                ph.i++;
            index++;
        }
        else if (str && !strcmp(str, "SEARCH"))
        {
			ft_fulldisplays(ph);
			std::cin.ignore();
            while(1 && ph.i != -1)
            {
                if (!flag)
			        write(1, "enter index number: ", 20);
                else
                    write(1, "your index out of the range, try another one: ", 46);
                fflush(NULL);
                std::getline(std::cin, line, '\n');
                res = line.c_str();
				if (std::cin.eof())
            		exit(0);
                if (!res)
                    break ;
                if (++i && (!strcmp(res, "")))
                    continue ;
                isnum = std::all_of(line.begin(), line.end(), ::isdigit);
				if (isnum &&  print_full_information(ph, atoi(res), &flag))
					break ;
            }
        }
        else if (str && !strcmp(str, "EXIT"))
            exit(0);
    }
    return (0);
}