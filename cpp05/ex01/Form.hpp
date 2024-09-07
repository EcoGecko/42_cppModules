/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:30:11 by heda-sil          #+#    #+#             */
/*   Updated: 2023/12/26 14:58:04 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form {

private:
	std::string const _name;
	bool			  _signed;
	int const		  _gradeSign;
	int const		  _gradeExecute;

public:
	Form(void);
	Form(Form const &obj);
	Form(std::string const name, int gradeSign, int gradeExecute);

	Form &operator=(Form const &obj);

	~Form(void);

	std::string const &getName(void) const;
	bool const		  &getSigned(void) const;
	int const		  &getGradeSign(void) const;
	int const		  &getGradeExecute(void) const;
	void			   beSigned(Bureaucrat const &obj);

	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, Form const &obj);

#endif
