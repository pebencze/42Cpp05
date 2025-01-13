/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:22:55 by pbencze           #+#    #+#             */
/*   Updated: 2025/01/13 13:39:40 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "--------------------------------------------------------\n";
	try
	{
		Form	Default;
		Form	Parameterized("Form", 150, 1);
		Form	Copy(Parameterized);

		std::cout << Default;
		std::cout << Parameterized;
		std::cout << Copy;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------\n";
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
	std::cout << "--------------------------------------------------------\n";

	return (0);
}
