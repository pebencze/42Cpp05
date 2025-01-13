/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:22:55 by pbencze           #+#    #+#             */
/*   Updated: 2025/01/13 14:58:51 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"

int	main(void)
{
	std::cout << "\e[1;33mTESTING CONSTRUCTORS" << std::endl;
	try
	{
		AForm	Parameterized("Form", 150, 1);

		std::cout << Parameterized;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------\n";


	return (0);
}
