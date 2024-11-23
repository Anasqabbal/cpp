#include "phonebook.hpp"

using namespace std;

void PhoneBook::ft_search(Contact *contacts, int ft_index, int ii)
{
	const char	*to_display;
	int			ind;

	ind = -1;
	if (ft_index == 0)
	{
		puts("the index can't start from 0");
		return ;
	}
	else if (ft_index > 8)
	{
		puts("your index is out of the range");
		return ;
	}
	else
	{
		if (ft_index > ii)
		{
			printf("your have only %d at this time\n", ii);  /*remove this printf*/
			return ;
		}
		int i = 0;
		while(++ind < 4)
		{
			if (ind == 0)
				to_display = contacts[ft_index - 1].index.c_str();
			else if (ind == 1)
				to_display = contacts[ft_index - 1].firstname.c_str();
			else if (ind == 2)
				to_display = contacts[ft_index - 1].lastname.c_str();
			else if (ind == 3)
				to_display = contacts[ft_index - 1].nickname.c_str();
			i = -1;
			while(++i < 10)
			{
				if (i < 10 && i < (int)strlen(to_display))
				{
					if (i == 9 && strlen(to_display) > 10)
						write(1, ".", 1);
					else
						write(1, &to_display[i], 1);
				}
				else if (i < 10)
					write(1, " ", 1);
			}
			if (i == 10 && ind <= 2)
				write(1, "|", 1);
		}
		write(1, "\n", 1);
	}
}

void PhoneBook::ft_add(Contact *contacts, int i, std::string str, int ind)
{
	if (ind == 0)
		contacts[i % 8].firstname = str;
	else if (ind == 1)
		contacts[i % 8].lastname = str;
	else if (ind == 2)
		contacts[i % 8].nickname = str;
	else if (ind == 3)
		contacts[i % 8].phone_number = str;
	else if (ind == 4)
		contacts[i % 8].darkest_secret = str;
}


void PhoneBook::ft_read(int ind, Contact *contacts,  int ft_index)
{
	std::string line;
	const char	*res;
	const char	*input;
	int			i;
	static int	e;

    if (std::cin.eof())
            exit(0);
	if (e++ == 0)
		std::getline(std::cin, line, '\n');
	if (ind == 0)
		input = "firstname: ";
	else if (ind == 1)
		input = "lastname: ";
	else if (ind == 2)
		input = "nickname: ";
	else if (ind == 3)
		input = "phonenumber: ";
	else if (ind == 4)
		input = "darkest secret: ";
	i = 0;
	std::cin.clear();
	while(1)
	{
		std::cout << input;
		std::getline(std::cin, line, '\n');
		if (std::cin.eof() && write(1, "\n", 1))
            return ;
		res = line.c_str();
		if (!res)
            return ;
		if (++i && (!strcmp(res, "")))
			continue;
		ft_add(contacts, ft_index, line, ind);
		break ;
	}
	if (e == 5)
		e = 0;
}

int main()
{
    const char        *str;
    std::string strl;
    const char  *res;
    std::string      line;
    PhoneBook   ph;
    int         index;
    int         i;

    i = 0;
    index = 0;
    ph.i = 0;

    (void)res;
    while(1)
    {
        std::cin >> strl;
        str = strl.c_str();
        std::cout << "string style in c ";
        std::cout << str;
        // if (std::cin.eof()) /* why you try to exit the program */
        //     exit(0);
        if (!str)
            printf("7adari obababababababab\n");
        if (str && !strcmp(str, "ADD"))
        {
            ph.ft_read(0, ph.contacts, index);
            ph.ft_read(1, ph.contacts, index);
            ph.ft_read(2, ph.contacts, index);
            ph.ft_read(3, ph.contacts, index);
            ph.ft_read(4, ph.contacts, index);
            ph.contacts[index % 8].index = ((index % 8) + 48) + 1;
            if (ph.i < 7)
                ph.i++;
            index++;
        }
        else if (str && !strcmp(str, "SEARCH"))
        {
            while(1)
            {
                getline(cin, line, '\n');
                res = line.c_str();
                if (!res)
                    break ;
                if (++i && (!strcmp(res, "")))
                    continue;
                ph.ft_search(ph.contacts, atoi(res), (ph.i));
                    break ;
            }
        }
        else if (str && !strcmp(str, "EXIT"))
            exit(0);
    }
    return 0;
}