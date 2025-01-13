/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:22:55 by pbencze           #+#    #+#             */
/*   Updated: 2025/01/13 14:44:10 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "\e[1;33mTESTING CONSTRUCTORS" << std::endl;
	try
	{
		Form	Parameterized("Form", 150, 1);

		std::cout << Parameterized;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------\n";
	std::cout << "\e[1;36mTESTING HIGH GRADE" << std::endl;
	try
	{
		Form	Certificate("Certificate", -1, -2);

		std::cout << Certificate;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------\n";
	std::cout << "\e[1;35mTESTING LOW GRADE" << std::endl;
	try
	{
		Form	Certificate("Certificate", 151, 180);

		std::cout << Certificate;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------\n";
	std::cout << "\e[1;34mTESTING SIGN FUNCTION" << std::endl;
	try
	{
		Bureaucrat	John("John", 23);
		Form		Contract("Contract", 23, 12);

		std::cout << John;
		std::cout << Contract;
		John.signForm(Contract);
		John.setGrade(78);
		John.signForm(Contract);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
