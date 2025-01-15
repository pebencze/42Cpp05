/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:22:55 by pbencze           #+#    #+#             */
/*   Updated: 2025/01/15 13:04:18 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::cout << "\e[1;37mTESTING INTERN" << std::endl;
	try
	{
		Intern randomIntern;
		AForm *form1;
		AForm *form2;
		AForm *form3;
		AForm *form4;

		std::cout << "\e[1;36m\nRobotomyRequestForm:\n";
		form1 = randomIntern.makeForm("RobotomyRequestForm", "aliens");
		std::cout << *form1;
		delete form1;
		std::cout << "\e[1;35m\nShrubberyCreationForm:\n";
		form2 = randomIntern.makeForm("ShrubberyCreationForm", "teachers");
		std::cout << *form2;
		delete form2;
		std::cout << "\e[1;34m\nPresidentialPardonForm:\n";
		form3 = randomIntern.makeForm("PresidentialPardonForm", "judges");
		std::cout << *form3;
		delete form3;
		std::cout << "\e[1;33m\nNotExistingForm:\n";
		form4 = randomIntern.makeForm("visa", "citizens");
		std::cout << *form4;
		delete form4;
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception occurred: "
			<< e.what() << std::endl;
	}
	return (0);
}
