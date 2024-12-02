#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string.h>
#include <unistd.h>

class Contact
{
public :
	std::string		firstname;
	std::string 	lastname;
	std::string 	nickname;
	std::string 	phone_number;
	std::string 	darkest_secret;
	std::string		index;
};

class PhoneBook
{
public :
	Contact contacts[8];
	int		i;

	void ft_add(Contact *contacts, int i, const std::string str, int ind);
	void ft_read(int ind, Contact *contacts,  int ft_index);
	void ft_search(Contact *contacts, int ft_index, int ii, int max);
};

	int		ft_contdisplay(PhoneBook ph, int index);
	void	ft_fulldisplays(PhoneBook ph);
	void	print_the_world(const char *str, int len);
	int		print_full_information(PhoneBook ph, int index, int *flag);

# endif