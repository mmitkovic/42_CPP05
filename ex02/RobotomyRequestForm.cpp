#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() {
    std::cout << "[c]Robotomy" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy", target, 72, 45) {
    std::cout << "[p][c]Robotomy" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :AForm(src) {
    std::cout << "[c][c]Robotomy" << std::endl;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
    std::cout << "[c][a][o]Robotomy" << std::endl;
    if (this != &src) {
        // this->setIsSigned(src.getIsSigned());
        AForm::operator=(src);
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "~Robotomy" << std::endl;
}

// ---
void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw AForm::FormNotSigned();
    if (executor.getGrade() > 45)
        throw RobotomyRequestForm::GradeTooLowException();
    const int randNum = rand() % 2;
    std::cout << "Drrrrrrrrilling noises..." << std::endl;
    if (randNum != 0)
        std::cout << "Robotomy on " << this->getTarget() << " failed" << std::endl;
    else
        std::cout << "Robotomy on " << this->getTarget() << " is successful" << std::endl;
}
