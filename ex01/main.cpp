/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:20:05 by mmitkovi          #+#    #+#             */
/*   Updated: 2026/02/25 14:37:16 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    Form b;
	std::cout << b << std::endl;

	Form a(5);
	std::cout << a << std::endl;

	Bureaucrat bure;
	std::cout << bure << std::endl;

	a.beSigned(bure);
	
	
}