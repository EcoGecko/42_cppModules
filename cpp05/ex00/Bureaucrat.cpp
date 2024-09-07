/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:02:41 by heda-sil          #+#    #+#             */
/*   Updated: 2024/01/23 13:47:13 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj) : _name(obj._name) {
	*this = obj;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &obj) {
	if (this == &obj) {
		return (*this);
	}
	this->_grade = obj._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {
}

void	Bureaucrat::incrementGrade(void) {
	if (this->_grade == 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void) {
	if (this->_grade == 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade++;
}

std::string const &Bureaucrat::getName(void) const {
	return (this->_name);
}

int const &Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (os);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("\nThe Grade is too high\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("\nThe Grade is too low\n");
}
