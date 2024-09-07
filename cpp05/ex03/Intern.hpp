/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:20:23 by heda-sil          #+#    #+#             */
/*   Updated: 2023/12/27 15:58:11 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H

#include "AForm.hpp"
#include <iostream>
#include <string>

class Intern {

private:

public:
	Intern(void);
	Intern(Intern const &obj);

	Intern &operator=(Intern const &obj);

	~Intern(void);

	AForm *makeForm(std::string name, std::string target);

	class	FormNotFoundException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

#endif
