/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:01:03 by heda-sil          #+#    #+#             */
/*   Updated: 2023/09/21 13:26:16 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iomanip>
# include <iostream>
# include <limits>
# include <sstream>

# define NBR_CONTACTS 8
# define FWIDTH 10
# define NOIDX "The inputed value does not correspont to any contact please try again. Or input 'q' to exit search"
# define BADNBR "That is not a valid number. Try again or input 'q' to exit search"
# define SEARCH "Insert the index of the contact you wish to open or `q` to go back: "

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);

	void addContact(void);
	void searchContacts(void) const;

private:

	std::string _truncate(std::string str, size_t width) const;
	void		_addText(const std::string field);
	void		_addNames(const std::string field);
	void		_addNbr(const std::string field);
	void		_listContacts(void) const;
	bool		_validString(const std::string &str) const;
	bool		_validNumber(const std::string &str) const;
	bool		_validNickname(const std::string &str) const;

	Contact _contact[NBR_CONTACTS];
	int		_nbrElements;
	int		_idx;
};

#endif
