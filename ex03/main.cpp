#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <ctime>
#include <cstdlib>
#include "Intern.hpp"

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
        Bureaucrat r("R", 1);
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            std::cout << rrf->getTarget() << std::endl;
            std::cout << rrf->getGradeSign() <<  std::endl;
            delete rrf;
        }
    }
}