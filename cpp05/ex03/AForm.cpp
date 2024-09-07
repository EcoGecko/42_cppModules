/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 14:30:07 by heda-sil          #+#    #+#             */
/*   Updated: 2024/01/23 15:47:01 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("Default"),
					 _signed(false),
					 _gradeSign(150),
					 _gradeExecute(150) {

}

AForm::AForm(std::string const name, int gradeSign, int gradeExecute) : _name(name),
																		_signed(false),
																		_gradeSign(gradeSign),
																		_gradeExecute(gradeExecute) {
	if (gradeSign < 1 || gradeExecute < 1) {
		throw AForm::GradeTooHighException();
	} else if (gradeSign > 150 || gradeExecute > 150) {
		throw AForm::GradeTooLowException();
	}
}


AForm::AForm(AForm const &obj) : _name(obj.getName()),
								 _gradeSign(obj.getGradeSign()),
								 _gradeExecute(obj.getGradeExecute()) {
	*this = obj;
}

AForm &AForm::operator=(AForm const &obj) {
	if (this == &obj) {
		return (*this);
	}
	this->_signed = obj.getSigned();
	return (*this);
}

AForm::~AForm(void) {

}

std::string const &AForm::getName(void) const {
	return (this->_name);
}

bool const &AForm::getSigned(void) const {
	return (this->_signed);
}

int const &AForm::getGradeSign(void) const {
	return (this->_gradeSign);
}

int const &AForm::getGradeExecute(void) const {
	return (this->_gradeExecute);
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeSign) {
		throw AForm::GradeTooLowException();
	}
	this->_signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const {
	if (!this->getSigned()) {
		throw AForm::FormNotSignedException();
	} else if (executor.getGrade() > this->getGradeExecute()) {
		throw AForm::BureaucratGradeTooLowException();
	}
	this->formAction();
}

void AForm::setSigned(bool const &value) {
	this->_signed = value;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("\nThe grade is too high\n");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("\nThe grade is too low\n");
}

const char *AForm::FormNotSignedException::what() const throw() {
	return ("\nThe form is not signed\n");
}

const char *AForm::BureaucratGradeTooLowException::what() const throw() {
	return ("\nThe bureaucrat grade is to low to execute\n");
}

std::ostream &operator<<(std::ostream &os, AForm const &obj) {
	std::string signedStr =	obj.getSigned() ? " YES" : " NO";

	os << obj.getName() << ", form grade to sign " << obj.getGradeSign()
	<< ", form grade to execute " << obj.getGradeExecute() << ", signed:" << signedStr;
	return (os);
}
