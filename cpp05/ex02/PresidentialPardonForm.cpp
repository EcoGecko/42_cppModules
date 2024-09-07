#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("presidential pardon", 25, 5),
													   _target("Default target") {
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("presidential pardon", 25, 5),
																		   _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj) : AForm(obj),
																					_target(obj._target) {
	*this = obj;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &obj) {
	if (this == &obj) {
		return (*this);
	}
	this->setSigned(obj.getSigned());
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
}

void PresidentialPardonForm::formAction(void) const {
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
