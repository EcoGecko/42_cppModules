/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:30:07 by heda-sil          #+#    #+#             */
/*   Updated: 2024/01/23 14:51:29 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("Default"),
				   _signed(false),
				   _gradeSign(150),
				   _gradeExecute(150) {

}

Form::Form(std::string const name, int gradeSign, int gradeExecute) : _name(name),
																	  _signed(false),
																	  _gradeSign(gradeSign),
																	  _gradeExecute(gradeExecute) {
	if (gradeSign < 1 || gradeExecute < 1) {
		throw Form::GradeTooHighException();
	} else if (gradeSign > 150 || gradeExecute > 150) {
		throw Form::GradeTooLowException();
	}
}


Form::Form(Form const &obj) : _name(obj.getName()),
							  _gradeSign(obj.getGradeSign()),
							  _gradeExecute(obj.getGradeExecute()) {
	*this = obj;
}

Form &Form::operator=(Form const &obj) {
	if (this == &obj) {
		return (*this);
	}
	this->_signed = obj._signed;
	return (*this);
}

Form::~Form(void) {

}

std::string const &Form::getName(void) const {
	return (this->_name);
}

bool const &Form::getSigned(void) const {
	return (this->_signed);
}

int const &Form::getGradeSign(void) const {
	return (this->_gradeSign);
}

int const &Form::getGradeExecute(void) const {
	return (this->_gradeExecute);
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeSign) {
		throw Form::GradeTooLowException();
	}
	this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("\nThe grade is too high\n");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("\nThe grade is too low\n");
}

std::ostream &operator<<(std::ostream &os, Form const &obj) {
	std::string signedStr =	obj.getSigned() ? " YES" : " NO";

	os << obj.getName() << ", form grade to sign " << obj.getGradeSign() << ", form grade to execute " << obj.getGradeExecute() << ", signed:" << signedStr;
	return (os);
}
