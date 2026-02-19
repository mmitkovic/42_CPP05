#include "Form.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Generic Bureaucrat"), is_signed(false), grade_sign(150), grade_exec(150) {
    std::cout << "[c]Form" << std::endl;
}
AForm::AForm(const AForm &src) : Bureaucrat(), _name(src._name), is_signed(src.is_signed), grade_sign(src.grade_sign), grade_exec(src.grade_exec) {
    std::cout << "[c][c]Form" << std::endl;
}
AForm& AForm::operator=(const AForm &src) {
    std::cout << "[c][a][o]Form" << std::endl;
    if (this != &src) {
        this->is_signed = src.is_signed;
    }
    return *this;
}
AForm::~AForm() { std::cout << "~Form" << std::endl; }

// --- Methods

std::string AForm::getName() const { return this->_name; }
bool AForm::getIsSigned() const { return this->is_signed; }

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > this->grade_sign)
        throw AForm::GradeTooLowException();
    this->is_signed = true;
}

