#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    // success
    {
        srand(time(0));
        Bureaucrat b("B", 1);
        RobotomyRequestForm robo("B-Target");
        b.signForm(robo);
        b.executeForm(robo);
    }
    {
        Bureaucrat s("S", 1);
        ShrubberyCreationForm shrubbery("S-Target");
        s.signForm(shrubbery);
        s.executeForm(shrubbery);
    }
    {
        Bureaucrat p("P", 1);
        PresidentialPardonForm president("P-Target");
        p.signForm(president);
        p.executeForm(president);
    }
    // unsigned
    {
        Bureaucrat b("B", 1);
        RobotomyRequestForm robo("B-Target");
        b.executeForm(robo);
    }
    // grade to low
    {
        Bureaucrat p("P", 6);
        PresidentialPardonForm president("P-Target");
        p.signForm(president);
        p.executeForm(president);
    }
    {
        Bureaucrat b("B", 150);
        RobotomyRequestForm robo("B-Target");
        b.signForm(robo);
        b.executeForm(robo);
    }
    {
        Bureaucrat b("B", 70);
        RobotomyRequestForm robo("B-Target");
        b.signForm(robo);
        b.executeForm(robo);
    }
}