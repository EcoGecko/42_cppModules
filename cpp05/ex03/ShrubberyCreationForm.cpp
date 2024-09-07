/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:26:50 by heda-sil          #+#    #+#             */
/*   Updated: 2024/01/23 15:55:45 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("shurubbery creation", 145, 137),
													 _target("Default target") {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("shurubbery creation", 145, 137),
																		 _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &obj) : AForm(obj),
																				 _target(obj._target) {
	*this = obj;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj) {

	if (this == &obj) {
		return (*this);
	}
	this->setSigned(obj.getSigned());
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {

}

void	ShrubberyCreationForm::formAction(void) const {
	std::ofstream file;

	file.open((this->_target + "_shrubbery").c_str());
	file << "            .        +          .      .          ." << std::endl;
	file << "     .            _        .                    ." << std::endl;
	file << "  ,              /;-._,-.____        ,-----.__" << std::endl;
	file << " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
	file << "  `                 |   _|`'=:_::.`.);	| __ / / " << std::endl;
	file << "                      ,    `./  |:. `.   )==-'  ." << std::endl;
	file << "    .      ., ,-=-.  ,|, +#./`   |:.  / /           ." << std::endl;
	file << ".           |/:/`-' , ,| '` ` `   ): , /_  -o" << std::endl;
	file << "       .    /:+- - + +- : :- + + -:'  /(o-) |)     ." << std::endl;
	file << "  .      ,=':  |    ` `/` ' , , ,:' `'--'.--'---._/`7" << std::endl;
	file << "   `.   (    |: |,-._` ` + '|, ,' _, --._, -- -':.__/" << std::endl;
	file << "              |:  `  X` _| _,|/'   .-'" << std::endl;
	file << ".               ' :._ :`|____ / :'  /      .           ." << std::endl;
	file << "                    |::.  :|/:'  /              +" << std::endl;
	file << "   .                 `.:.  /:'  }      ." << std::endl;
	file << "           .           ):_(:;   |           ." << std::endl;
	file << "                      |:. _| ,  |" << std::endl;
	file << "                   . (|::.     ,`                  ." << std::endl;
	file << "     .                |::.    ~|'" << std::endl;
	file << "                      |::.|  | `." << std::endl;
	file << "                      |:::(|    |" << std::endl;
	file << "              O       |:::/{ }  |                  (o" << std::endl;
	file << "               )  ___/#|::`/ (O '==._____   O, (O  /`" << std::endl;
	file << "          ~~~w/w~'~~,| `:/,-(~`'~~~~~~~'~o~|~/~w|/~" << std::endl;
	file << "      ~~~~~~~~~~~~~~~~~~~~~~~||W~~~~~~~~~~~~|||~~" << std::endl;
	file << "    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	file.close();
}
