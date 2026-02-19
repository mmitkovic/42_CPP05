/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitkovi <mmitkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:25:45 by mmitkovi          #+#    #+#             */
/*   Updated: 2026/02/19 19:27:55 by mmitkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    
    Bureaucrat b("B", -1);
    Bureaucrat v("V", 1);
   	std::cout << v << std::endl;
    v.setGrade(1000);
    std::cout << v << std::endl;
}