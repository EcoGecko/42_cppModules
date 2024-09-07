/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:02:25 by heda-sil          #+#    #+#             */
/*   Updated: 2023/09/21 13:41:40 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#define FNAME "First name: "
#define LNAME "Last name: "
#define NICK "Nickname: "
#define PHONE "Phone number: "
#define SECRET "Dark secrect: "
#include <string>
# include <iostream>

class Contact {

public:

	Contact(void);
	~Contact(void);

	void		setValues(std::string new_value, std::string field);
	std::string getValues(std::string field) const;
	void		printContactInfo(int idx) const;

private:

	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNbr;
	std::string _darkSecret;
};

#endif
