/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:23:03 by pbencze           #+#    #+#             */
/*   Updated: 2025/01/13 13:38:49 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat {
    public:
        Bureaucrat(); //default constructor
        Bureaucrat(const std::string &name, int grade); //parameterized constructor
        Bureaucrat(Bureaucrat const &src); //copy constructor
        ~Bureaucrat(); //destructor

        Bureaucrat & operator=(Bureaucrat const &rhs); //operator overload

        int getGrade() const;
        void setGrade(int newGrade);
        std::string getName() const;
        //setName(); not in use because of const variable
        void decrement(int amount);
        void increment(int amount);
		void signForm(Form &f) const;

        class GradeTooHighException : public std::exception { //custom exception, nested class
            public:
                virtual const char* what() const throw() {
                    return ("Grade is too high.");
                }
        };
        class GradeTooLowException : public std::exception { //custom exception, nested class
            public:
                virtual const char* what() const throw() {
                    return ("Grade is too low.");
                }
        };

    private:
        const std::string _name;
        int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif
