/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:30:11 by heda-sil          #+#    #+#             */
/*   Updated: 2024/01/23 15:06:36 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {

private:
	std::string const _name;
	bool			  _signed;
	int const		  _gradeSign;
	int const		  _gradeExecute;

public:
	AForm(void);
	AForm(AForm const &obj);
	AForm(std::string const name, int gradeSign, int gradeExecute);

	AForm &operator=(AForm const &obj);

	virtual ~AForm(void);

	/* Getters && Setters */
	std::string const &getName(void) const;
	bool const		  &getSigned(void) const;
	int const		  &getGradeSign(void) const;
	int const		  &getGradeExecute(void) const;
	void			  setSigned(bool const &value);

	/* Others */
	void		 beSigned(Bureaucrat const &obj);
	void		 execute(Bureaucrat const &executor) const;
	virtual void formAction(void) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		const char *what() const throw();
	};

	class BureaucratGradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, AForm const &obj);

#endif
