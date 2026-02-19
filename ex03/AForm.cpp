#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Generic Bureaucrat"), is_signed(false), _grade_sign(150), _grade_exec(150) {
    std::cout << "[c]Form" << std::endl;
}
AForm::AForm(const std::string &name, const std::string &target, const int grade_sign, const int grade_exec) : _name(name), _target(target), is_signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec) {
    if (_grade_sign < 1 || _grade_exec < 1)
        throw AForm::GradeTooHighException();
    if (_grade_sign > 150 || _grade_exec > 150)
        throw AForm::GradeTooLowException();
    std::cout << "[p][c]Form created successfully" << std::endl;
}
AForm::AForm(const AForm &src) : _name(src._name), _target(src._target), is_signed(src.is_signed), _grade_sign(src._grade_sign), _grade_exec(src._grade_exec)
{
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

std::string AForm::getName() const { return this->_name; }
std::string AForm::getTarget() const { return this->_target; }
bool AForm::getIsSigned() const { return this->is_signed; }
int AForm::getGradeSign() const { return this->_grade_sign; }
int AForm::getGradeExec() const { return this->_grade_exec; }
void AForm::setIsSigned(const bool is) { this->is_signed = is; }
void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > this->getGradeSign())
        throw AForm::GradeTooLowException();
    this->is_signed = true;
}
