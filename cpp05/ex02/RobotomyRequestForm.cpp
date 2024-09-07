/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:50:11 by heda-sil          #+#    #+#             */
/*   Updated: 2024/01/23 15:56:41 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("robotomy request", 72, 45),
												 _target("Default target") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("robotomy request", 72, 45),
																	 _target(target) {

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &obj) : AForm(obj),
																		   _target(obj._target) {
	*this = obj;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &obj) {
	if (this == &obj) {
		return (*this);
	}
	this->setSigned(obj.getSigned());
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

void RobotomyRequestForm::formAction(void) const {
	std::srand(time(NULL));

	std::cout << "* Drilling noises *" << std::endl;
	if (std::rand() % 2 == 0) {
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy failed!" << std::endl;
	}
}
