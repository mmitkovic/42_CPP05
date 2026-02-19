#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <ostream>
class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool is_signed; // at construction, is not
    const int grade_sign;
    const int grade_exec;
public:
    Form();
    Form(const Form& src);
    Form& operator=(const Form& src);
    ~Form();

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw() {
            return "Form grade is too high";
        }
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw() {
            return "Form grade is too low";
        }
    };
    std::string getName() const;
    bool getIsSigned() const;
	int getSign() const;
	int getExec() const;
    void beSigned(const Bureaucrat& b);
};
std::ostream &operator<<(std::ostream &out, const Form& src);

#endif

