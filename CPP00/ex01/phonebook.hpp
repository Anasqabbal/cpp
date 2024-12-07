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
	std::string		get_values(char ind);
	int				set_the_values(std::string str, char ind);
	void			set_index_value(int index);
};

class PhoneBook
{
private :
	Contact contacts[8];
	int		i;
	std::string		get_contact_value(Contact *contacts, int index, int ind);

public :
	int			get_i_value(void);
	void		set_i_value(int val);
	Contact		*get_values(void);
<<<<<<< HEAD
	void		set_value_to_index(Contact *contact, int index, int inde);
	void		add_to_contact(int ind, Contact *contacts, int ft_index);
	void		print_basic_info(Contact *contacts, int ft_index);
=======
	const char *get_contact_value(Contact *contacts, int index, int ind);
	void		set_values(Contact *contact, int index, char ind, int inde);
	void		ft_add(Contact *contacts, int i, const std::string str, int ind);
	void		ft_read(int ind, Contact *contacts, int ft_index);
	void		ft_search(Contact *contacts, int ft_index, int ii, int max);
>>>>>>> 1f7c0d83ee65aa4612009a78f80bddfe4c19508b
	void		print_all_contacts(PhoneBook ph);
	int			print_specific_contact(PhoneBook ph, int index);
};

<<<<<<< HEAD
void	print10_right_alighed(std::string str, int len);
=======
void	print_the_world(std::string str, int len);
>>>>>>> 1f7c0d83ee65aa4612009a78f80bddfe4c19508b

# endif