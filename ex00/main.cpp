/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:16:45 by pbencze           #+#    #+#             */
/*   Updated: 2025/01/10 17:42:25 by pbencze          ###   ########.fr       */
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
        Jim.setGrade(1);
        std::cout << Jim;
        Jim.increment(10);
        std::cout << Jim;
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
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "--------------------------------------------------------\n";
    try
    {
        Bureaucrat  Sophie("Sophie", 0);
        std::cout << Sophie;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "--------------------------------------------------------\n";
    return (0);
}