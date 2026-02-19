#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>
class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    const std::string _target;
    bool is_signed; // at construction, is not
    const int _grade_sign;
    const int _grade_exec;
public:
    AForm();
    AForm(const std::string& name, const std::string& target, int grade_sign, int grade_exec );
    AForm(const AForm& src);
    AForm& operator=(const AForm& src);
    virtual ~AForm();
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
    class FormNotSigned : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Form not signed";
        }
    };
    std::string getName() const;
    std::string getTarget() const;
    bool getIsSigned() const;
    int getGradeSign() const;
    int getGradeExec() const;
    void setIsSigned(const bool is);
    void beSigned(const Bureaucrat& b);
    virtual void execute(Bureaucrat const & executor) const = 0;
};

#endif
