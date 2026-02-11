#include "Bureaucrat.hpp"

void checkGrade(const int grade )
{
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat() : _name("Generic Bureaucrat"), _grade(150) { std::cout << "[c]Bureaucrat" << std::endl; }
Bureaucrat::Bureaucrat(const std::string& name, const int grade ) : _name(name), _grade(grade)
{
    std::cout << "[p][c]Bureaucrat" << std::endl;
    try {
        checkGrade(grade);
    } catch (const Bureaucrat::GradeTooLowException& ex) {
        std::cerr << ex.what() << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& ex) {
        std::cerr << ex.what() << std::endl;
    }
}
Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) { std::cout << "[c][c]Bureaucrat" << std::endl; }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
    std::cout << "[c][a][o]Bureaucrat" << std::endl;
    if (this != &src) {
        this->_grade = src._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() { std::cout << "~Bureaucrat" << std::endl; }

// getters - setters
std::string Bureaucrat::getName() const { return this->_name; }
int Bureaucrat::getGrade() const { return this->_grade; }
void Bureaucrat::setGrade(const int grade) {
    const int tmp_val = _grade;
    try {
        checkGrade(grade);
        this->_grade = grade;
    } catch (const Bureaucrat::GradeTooLowException& ex) {
        this->_grade = tmp_val;
        std::cerr << "Error: " << ex.what() << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& ex) {
        this->_grade = tmp_val;
        std::cerr << "Error: " << ex.what() << std::endl;
    }
}

// increment and decrement grades
void Bureaucrat::decrementGrade() {
    std::cout << "Decrement grade of " << this->getName() << std::endl;
    try {
        this->_grade++;
        checkGrade(this->_grade);
    } catch (const Bureaucrat::GradeTooLowException& ex) {
        this->_grade--;
        std::cerr << "Error: " << ex.what() << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& ex) {
        this->_grade--;
        std::cerr << "Error: " << ex.what() << std::endl;
    }
}
void Bureaucrat::incrementGrade() {
    std::cout << "Increment grade of " << this->getName() << std::endl;
    try {
        this->_grade--;
        checkGrade(this->_grade);
    } catch (const Bureaucrat::GradeTooLowException& ex) {
        this->_grade++;
        std::cerr << "Error: " << ex.what() << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& ex) {
        this->_grade++;
        std::cerr << "Error: " << ex.what() << std::endl;
    }
}

// ostream
std::ostream &operator<<(std::ostream &out, const Bureaucrat& src)
{
    out << src.getName() << ", bureaucrat grade " << src.getGrade();
    return out;
}

//-----------------------------------------------------------
// Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
// {
//     std::cout << "[c][a][o]Bureaucrat" << std::endl;
//     if (this != &src)
//     {
//         std::string* tmp_n = const_cast<std::string*>(&_name);
//         int* tmp_g = const_cast<int*>(&_grade);
//         *tmp_n = src._name;
//         *tmp_g = src._grade;
//     }
//     return *this;
// }