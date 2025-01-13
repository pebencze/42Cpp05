/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:22:58 by pbencze           #+#    #+#             */
/*   Updated: 2025/01/13 15:54:43 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat; //forward declaration

class AForm {
    public:
        AForm(const std::string &name, int signGrade, int execGrade); //parameterized constructor
        virtual ~AForm(); //destructor

        AForm &operator=(AForm const &rhs); //operator overload

		int getSignGrade() const;
		int getExecGrade() const;
		std::string getName() const;
		bool getSigned() const;

		void beSigned(const Bureaucrat &b);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade is too high.";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade is too low.";
				}
		};

    private:
        AForm(); //default constructor
        AForm(const AForm &src); //copy constructor

        const std::string	_name;
        bool				_signed;
        const int			_signGrade;
        const int			_execGrade;
};

std::ostream &operator<<(std::ostream &out, const AForm &rhs);

#endif
