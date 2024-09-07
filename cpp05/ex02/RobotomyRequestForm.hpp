/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 20:50:04 by heda-sil          #+#    #+#             */
/*   Updated: 2023/12/26 20:57:05 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {

private:
	std::string const _target;

public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm const &obj);
	RobotomyRequestForm(std::string const target);

	RobotomyRequestForm &operator=(RobotomyRequestForm const &obj);

	~RobotomyRequestForm(void);

	void formAction(void) const;
};

#endif
