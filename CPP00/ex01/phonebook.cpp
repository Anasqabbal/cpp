#include "phonebook.hpp"
#include <iomanip>
#include <stdio.h>


/* UNFORMATED AND FORMATED IO operations 
	UNFORMATED I/O operations,
		unformated input operations, 


	FORMATED I/O operation
		is read  / write from / to the stream in a specified format to control the appearance
	and interpretation of data 
	(char, int, float ...).


 */

int	Contact::set_the_values(std::string str, char ind)
{
	if (ind == 0)
		firstname = str;
	else if (ind == 1)
		lastname = str;
	else if (ind == 2)
		nickname = str;
	else if (ind == 3)
		phone_number = str;
	else if (ind == 4)
		darkest_secret = str;
	return (0);
}

void Contact::set_index_value(int i)
{
	index = ((i % 8) + 48);
}

std::string	Contact::get_values(char ind)
{
	if (ind == 0)
		return (firstname);
	else if (ind == 1)
		return (lastname);
	else if (ind == 2)
		return (nickname);
	else if (ind == 3)
		return (phone_number);
	else if (ind == 4)
		return (darkest_secret);
	return (index.c_str());
}

Contact *PhoneBook::get_values(void)
{
	return (contacts);
}

void	PhoneBook::set_values(Contact *contact, int index, char ind, int inde)
{
	if (ind == 0)
		contact[index].set_index_value(inde);
}

int	PhoneBook::get_i_value(void)
{
	return (i);
}

void PhoneBook::set_i_value(int val)
{
	i = val;
}

const char *PhoneBook::get_contact_value(Contact *contacts, int index, int ind)
{
	return (contacts[index].get_values(ind).c_str());
}

void print_the_world(std::string str, int len)
{
	if (len <= 10)
	{
		std::cout << std::setw(10) << std::right << str.substr(0.10);
	}
	else
	{
		std::cout << std::setw(9) << std::right << str.substr(0, 9);
		std::cout << '.';
	}
	std::cout << '|';
	fflush(NULL);
}

// void print_the_world(const char *str, int len)
// {
// 	int	rest;
// 	int	i = -1;
// 	int  j = -1;

// 	rest = 10 - len;
// 	if (rest > 0)
// 	{
// 		while(++i < rest)
// 			write(1, " ", 1);
// 	}
// 	else
// 		i = 0;
// 	while(i < 10)
// 	{
// 		if (i < 9)
// 		{
// 			write(1, &str[++j], 1);
// 			i++;
// 		}
// 		if (i == 9)
// 		{
// 			if (i < (len - 1))
// 				write(1, ".", 1);
// 			else
// 				write(1, &str[++j], 1);
// 			i++;
// 			break ;
// 		}
// 	}
// 	if (i == 10)
// 		write(1, "|", 1);
// }

int	PhoneBook::print_specific_contact(PhoneBook ph, int index, int *flag)
{
	const char *str;

	if (index > 8 || index > ph.get_i_value() || index < 0)
		return ( *flag = 1, 0);
	{
		str = ph.get_contact_value(ph.get_values(), index, 0);
		write(1, "firstname: ", 11);
		write(1 ,str , strlen(str));
		write(1, "\n", 1);
		str = ph.get_contact_value(ph.get_values(), index, 1);
		write(1, "lastname: ", 10);
		write(1 ,str , strlen(str));
		write(1, "\n", 1);
		str = ph.get_contact_value(ph.get_values(), index, 2);
		write(1, "nickname: ", 10);
		write(1 ,str , strlen(str));
		write(1, "\n", 1);
		str = ph.get_contact_value(ph.get_values(), index, 3);
		write(1, "phonenumber: ", 13);
		write(1 ,str , strlen(str));
		write(1, "\n", 1);
		str = ph.get_contact_value(ph.get_values(), index, 4);
		write(1, "darket secret: ", 15);
		write(1 ,str , strlen(str));
		write(1, "\n", 1);
	}
	return (1);
}

void PhoneBook::ft_search(Contact *contacts, int ft_index, int ii, int max)
{
	std::string to_display;	/* convert the string object to char * */
	int			ind; 			/* to loop around the menmbers of the struct */

	(void)ii;
	(void)max;

	ind = -1;
	while(++ind < 4)
	{
		if (ind == 0)
			to_display = contacts[ft_index].get_values(5);
		else if (ind == 1)
			to_display = contacts[ft_index].get_values(0);
		else if (ind == 2)
			to_display = contacts[ft_index].get_values(1);
		else if (ind == 3)
			to_display = contacts[ft_index].get_values(2);
		print_the_world(to_display, strlen(to_display.c_str()));
	}
	write(1, "\n", 1);
	fflush(NULL);
}

void PhoneBook::ft_add(Contact *contacts, int i, std::string str, int ind)
{
	contacts[i % 8].set_the_values(str, ind);
}

void PhoneBook::ft_read(int ind, Contact *contacts,  int ft_index)
{
	std::string line;
	const char	*res;
	const char	*input;
	int			i;
	static int	e;

    if (std::cin.eof())
            _exit(0);
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

void	PhoneBook::print_all_contacts(PhoneBook ph)
{
	int i  = -1;
	write(1, "--------------------------------------------\n", 45);
	print_the_world("index", 5);
	print_the_world("firstname", 9);
	print_the_world("lastname", 8);
	print_the_world("nickname", 8);
	write(1, "\n", 1);
	write(1, "|------------------------------------------|\n", 45);
	while(i++ < ph.get_i_value())
		ph.ft_search(ph.get_values(), i, ph.get_i_value(), ph.get_i_value());
}