/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:25:14 by mmitkovi          #+#    #+#             */
/*   Updated: 2026/02/19 20:40:36 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Generic Bureaucrat"), _grade(150) 
{ 
	std::cout << "[c]Bureaucrat" << std::endl; 
}
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
Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) 
{ 
	std::cout << "[c][c]Bureaucrat" << std::endl; 
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) 
{
    std::cout << "[c][a][o]Bureaucrat" << std::endl;
    if (this != &src) {
        this->_grade = src._grade;
    }
    return *this;
}
Bureaucrat::~Bureaucrat() 
{ 
	std::cout << "~Bureaucrat" << std::endl; 
}
// ---
void Bureaucrat::checkGrade(const int grade )
{
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}
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