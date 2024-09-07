/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:02:37 by heda-sil          #+#    #+#             */
/*   Updated: 2024/01/23 13:36:40 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

# include <string>
# include <iostream>

class Bureaucrat {

private:
	std::string const _name;
	int	_grade;

public:
    Bureaucrat(void);
    Bureaucrat(std::string const name, int grade); // grade must be between 1 & 150;
	Bureaucrat(Bureaucrat const &obj);

	Bureaucrat &operator=(Bureaucrat const &obj);

	~Bureaucrat(void);

	std::string const &getName(void) const;
	int	const &getGrade(void) const;

	/* Increments/Decrements */
	void	incrementGrade(void);
	void	decrementGrade(void);

	class GradeTooHighException : public std::exception {
		public:
			const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &obj);

#endif
