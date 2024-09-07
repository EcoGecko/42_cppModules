#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

private:
	std::string const _target;

public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm const &obj);
	PresidentialPardonForm(std::string const target);

	PresidentialPardonForm &operator=(PresidentialPardonForm const &obj);

	~PresidentialPardonForm(void);

	void formAction(void) const;
};

#endif
