#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& src);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
    virtual ~ShrubberyCreationForm();

    class FileOpenException : public std::exception {
        virtual const char* what() const throw() {
            return "Shrubbery can not open the file.";
        }
    };
    virtual void execute(Bureaucrat const & executor) const;

};

#endif
