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

AForm *Intern::makeForm(const std::string& nameForm, const std::string& targetForm) {
    // robotomy request, shrubbery creation, presidential pardon
    std::cout << " : " << nameForm << std::endl;
    AForm *obj = new ShrubberyCreationForm(targetForm);
    return obj;
}
