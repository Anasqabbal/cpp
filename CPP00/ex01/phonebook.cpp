#include "phonebook.hpp"


/* UNFORMATED AND FORMATED IO operations 
	UNFORMATED I/O operations,
		unformated input operations, 


	FORMATED I/O operation
		is read  / write from / to the stream in a specified format to control the appearance
	and interpretation of data 
	(char, int, float ...).


 */
	



using namespace std;

void print_the_world(const char *str, int len)
{
	int	rest;
	int	i = -1;
	int  j = -1;

	rest = 10 - len;
	if (rest > 0)
	{
		while(++i < rest)
			write(1, " ", 1);
	}
	else
		i = 0;
	while(i < 10)
	{
		if (i < 9)
		{
			write(1, &str[++j], 1);
			i++;
		}
		if (i == 9)
		{
			if (i < (len - 1))
				write(1, ".", 1);
			else
				write(1, &str[++j], 1);
			i++;
			break ;
		}
	}
	if (i == 10)
		write(1, "|", 1);
}

int	print_full_information(PhoneBook ph, int index, int *flag)
{
	const char *str;

	if (index > 8 || index > ph.i || index < 0)
		return ( *flag = 1, 0);
	{
		str = ph.contacts[index].firstname.c_str();	
		write(1, "firstname: ", 11);
		write(1 ,str , strlen(str));
		write(1, "\n", 1);
		str = ph.contacts[index].lastname.c_str();
		write(1, "lastname: ", 10);
		write(1 ,str , strlen(str));
		write(1, "\n", 1);
		str = ph.contacts[index].lastname.c_str();
		write(1, "nickname: ", 10);
		write(1 ,str , strlen(str));
		write(1, "\n", 1);
		str = ph.contacts[index].phone_number.c_str();
		write(1, "phonenumber: ", 13);
		write(1 ,str , strlen(str));
		write(1, "\n", 1);
		str = ph.contacts[index].darkest_secret.c_str();
		write(1, "darket secret: ", 15);
		write(1 ,str , strlen(str));
		write(1, "\n", 1);
	}
	return (1);
}

void PhoneBook::ft_search(Contact *contacts, int ft_index, int ii, int max)
{
	const char	*to_display; 	/* convert the string object to char * */
	int			ind; 			/* to loop around the menmbers of the struct */
	// int			j = -1;		/* to loop around the indexes */

	(void)ii;
	(void)max;
	int i = 0; /* to write 10 characters */
	ind = -1;
	while(++ind < 4)
	{
		if (ind == 0)
			to_display = contacts[ft_index].index.c_str();
		else if (ind == 1)
			to_display = contacts[ft_index].firstname.c_str();
		else if (ind == 2)
			to_display = contacts[ft_index].lastname.c_str();
		else if (ind == 3)
			to_display = contacts[ft_index].nickname.c_str();
		i = -1;
		print_the_world(to_display, strlen(to_display));
	}
	write(1, "\n", 1);
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
			continue ;
		ft_add(contacts, ft_index, line, ind);
		break ;
	}
	if (e == 5)
		e = 0;
}

void	ft_fulldisplays(PhoneBook ph)
{
	int i  = -1;
	write(1, "--------------------------------------------\n", 45);
	print_the_world("index", 5);
	print_the_world("firstname", 9);
	print_the_world("lastname", 8);
	print_the_world("nickname", 8);
	write(1, "\n", 1);
	write(1, "|------------------------------------------|\n", 45);
	while(i++ < ph.i)
		ph.ft_search(ph.contacts, i, ph.i, ph.i);
}