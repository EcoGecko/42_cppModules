/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:26:46 by heda-sil          #+#    #+#             */
/*   Updated: 2023/12/26 17:41:46 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"
#include <iostream>
#include <string>

class ShrubberyCreationForm : public AForm {

private:
	std::string const _target;

public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm const &obj);
	ShrubberyCreationForm(std::string const target);

	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &obj);

	void formAction(void) const;
	~ShrubberyCreationForm(void);
};

#endif
