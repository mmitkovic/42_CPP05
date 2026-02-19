/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:46:33 by mmitkovi          #+#    #+#             */
/*   Updated: 2026/02/19 20:56:49 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

Form::Form() : _name("Generic Bureaucrat"), is_signed(false), grade_sign(150), grade_exec(150) 
{
    std::cout << "[c]Form" << std::endl;
}
Form::Form(const Form &src) : _name(src._name), is_signed(src.is_signed), grade_sign(src.grade_sign), grade_exec(src.grade_exec) 
{
    std::cout << "[c][c]Form" << std::endl;
}
Form& Form::operator=(const Form &src) 
{
    std::cout << "[c][a][o]Form" << std::endl;
    if (this != &src) {
        this->is_signed = src.is_signed;
    }
    return *this;
}
Form::~Form() 
{ 
	std::cout << "~Form" << std::endl; 
}

// --- 

std::string Form::getName() const { return this->_name; }
bool Form::getIsSigned() const { return this->is_signed; }
int Form::getSign() const { return this->grade_sign; }
int Form::getExec() const { return this->grade_sign; }

void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > this->grade_sign)
        throw Form::GradeTooLowException();
    this->is_signed = true;
}

std::ostream &operator<<(std::ostream &out, const Form& src)
{
	out << "Form name: " <<  src.getName() 
	<< " with grade sign: " << src.getSign()
	<< " with grade exec: " << src.getExec();
	return out;
}

