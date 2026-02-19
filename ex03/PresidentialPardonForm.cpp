#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() {
    std::cout << "[c]Presidential" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("Presidential Pardon", target, 25, 5){
    std::cout << "[p][c]Presidential" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src) {
    std::cout << "[c][c]Presidential" << std::endl;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
    std::cout << "[c][a][o]Presidential" << std::endl;
    if (this != &src) {
        AForm::operator=(src);
    }
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "~Presidential" << std::endl;
}

// ---
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (!this->getIsSigned())
        throw AForm::FormNotSigned();
    if (executor.getGrade() > 5)
        throw PresidentialPardonForm::GradeTooLowException();
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
