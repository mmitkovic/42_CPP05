#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& src);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
    virtual ~PresidentialPardonForm();
    virtual void execute(Bureaucrat const & executor) const;
};

#endif
