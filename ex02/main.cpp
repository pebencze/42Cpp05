/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:22:55 by pbencze           #+#    #+#             */
/*   Updated: 2025/01/15 13:04:51 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <unistd.h>

int	main(void)
{
	std::cout << "\e[1;33mTESTING PRESIDENTIAL FORM" << std::endl;
	std::cout << "REQUIRED: SIGN 25, EXEC 5" << std::endl;
	try
	{
		PresidentialPardonForm FormOfficer("Officer");
		PresidentialPardonForm FormPriest("Priest");
		Bureaucrat President("President", 5);

		std::cout << FormOfficer
				<< FormPriest
				<< President;

		FormOfficer.beSigned(President);
		President.executeForm(FormOfficer);
		President.decrement(10);
		FormPriest.beSigned(President);
		President.executeForm(FormPriest);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception occurred: "
			<< e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------\n";
	std::cout << "\e[1;35mTESTING SHRUBBERY FORM" << std::endl;
	std::cout << "REQUIRED: SIGN 145, EXEC 137" << std::endl;
	try
	{
		ShrubberyCreationForm Shrubbery("Garden");
		ShrubberyCreationForm Home("Home");
		Bureaucrat VicePresident("VicePresident", 101);

		std::cout << VicePresident
			<< Home
			<< Shrubbery;

		Shrubbery.beSigned(VicePresident);
		VicePresident.executeForm(Shrubbery);
		VicePresident.executeForm(Home);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception occurred: "
			<< e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------\n";
	std::cout << "\e[1;32mTESTING ROBOTOMY FORM" << std::endl;
	std::cout << "REQUIRED: SIGN 72, EXEC 45" << std::endl;
	try
	{
		RobotomyRequestForm RepairForm("RepairForm");
		Bureaucrat Robot("R2D2", 35);

		std::cout << Robot
			<< RepairForm;

		RepairForm.beSigned(Robot);
		Robot.executeForm(RepairForm);
		sleep(1);
		Robot.executeForm(RepairForm);
		sleep(1);
		Robot.executeForm(RepairForm);
		sleep(1);
		Robot.executeForm(RepairForm);
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception occurred: "
			<< e.what() << std::endl;
	}
	return (0);
}
