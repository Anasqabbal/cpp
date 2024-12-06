#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string.h>
#include <unistd.h>

class Contact
{
private:
	std::string		firstname;
	std::string 	lastname;
	std::string 	nickname;
	std::string 	phone_number;
	std::string 	darkest_secret;
	std::string		index;
public :
	const char		*get_values(char ind);
	int				set_the_values(std::string str, char ind);
	void			set_index_value(int index);
};

class PhoneBook
{
private :
	Contact contacts[8];
	int		i;

public :
	int			get_i_value(void);
	void		set_i_value(int val);
	Contact		*get_values(void);
	const char 	*get_contact_value(Contact *contacts, int index, int ind);
	void		set_values(Contact *contact, int index, char ind, int inde);
	void		ft_add(Contact *contacts, int i, const std::string str, int ind);
	void		ft_read(int ind, Contact *contacts, int ft_index);
	void		ft_search(Contact *contacts, int ft_index, int ii, int max);
	void		print_all_contacts(PhoneBook ph);
	int			print_specific_contact(PhoneBook ph, int index, int *flag);
};

void	print_the_world(const char *str, int len);

# endif