#include "AForm.hpp"
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {
    std::cout << "[c]Intern" << std::endl;
}
Intern::Intern(const Intern &src) {
    (void)src;
}
Intern &Intern::operator=(const Intern &src) {
    (void)src;
    return *this;
}
Intern::~Intern() {
    std::cout << "~Intern" << std::endl;
}

AForm* Intern::makeForm(const std::string& nameForm, const std::string& targetForm) 
{
	std::string forms[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	int i = 0;
	while (i < 3)
	{
		if (nameForm == forms[i])
		{
			switch (i)
			{
				case 0:
				{
					AForm* form = new RobotomyRequestForm(targetForm);
					return form;
				}
				case 1:
				{
					AForm* form = new ShrubberyCreationForm(targetForm);
					return form;
				}
				case 2:
				{
					AForm* form = new PresidentialPardonForm(targetForm);
					return form;
				}
			};
		}
		i++;
	}
	std::cout << "There is no form with this name" << std::endl;
	return NULL;
}
