/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:16:45 by pbencze           #+#    #+#             */
/*   Updated: 2025/01/15 13:00:24 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "--------------------------------------------------------\n";
    try
    {
        Bureaucrat  Jim("Jim", 20);
        std::cout << Jim;
		std::cout << "Setting grade...\n";
        Jim.setGrade(8);
        std::cout << Jim;
        Jim.increment(10);
        std::cout << Jim;
		Jim.increment(3);
        std::cout << Jim;
		std::cout << "Exiting try block.\n";
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------------------------------------\n";
    try
    {
        Bureaucrat  Alice("Alice", 10);

        std::cout << Alice;
        Alice.decrement(170);
        std::cout << Alice;
        Alice.decrement(20);
        std::cout << Alice;
		std::cout << "Exiting try block.\n";
    }
    catch(const std::exception& e)
    {
		std::cout << "Entering catch block.\n";
        std::cerr << e.what() << '\n';
    }
    std::cout << "--------------------------------------------------------\n";
    try
    {
        Bureaucrat  Sophie("Sophie", 0);
        std::cout << Sophie;
		std::cout << "Exiting try block.\n";
    }
    catch(const std::exception& e)
    {
		std::cout << "Entering catch block.\n";
        std::cerr << e.what() << '\n';
    }
    std::cout << "--------------------------------------------------------\n";
    return (0);
}
