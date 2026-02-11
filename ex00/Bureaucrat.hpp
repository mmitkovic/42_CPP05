#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade );
    Bureaucrat(const Bureaucrat& src);
    Bureaucrat& operator=(const Bureaucrat& src);
    ~Bureaucrat();
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw() {
            return "Grade is too high";
        }
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw() {
            return "Grade is too low";
        }
    };
    
    std::string getName() const;
    int getGrade() const;

    void setGrade(int grade);
    void incrementGrade();
    void decrementGrade();

};
std::ostream &operator<<(std::ostream &out, const Bureaucrat& src);
void checkGrade( int grade );

#endif