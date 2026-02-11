#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Generic Bureaucrat"), is_signed(false), grade_sign(150), grade_exec(150) {
    std::cout << "[c]Form" << std::endl;
}
Form::Form(const Form &src) : Bureaucrat(), _name(src._name), is_signed(src.is_signed), grade_sign(src.grade_sign), grade_exec(src.grade_exec) {
    std::cout << "[c][c]Form" << std::endl;
}
Form& Form::operator=(const Form &src) {
    std::cout << "[c][a][o]Form" << std::endl;
    if (this != &src) {
        this->is_signed = src.is_signed;
    }
    return *this;
}
Form::~Form() { std::cout << "~Form" << std::endl; }

// --- Methods

std::string Form::getName() const { return this->_name; }
bool Form::getIsSigned() const { return this->is_signed; }

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > this->grade_sign)
        throw Form::GradeTooLowException();
    this->is_signed = true;
}

