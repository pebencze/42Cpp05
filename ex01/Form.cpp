/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:23:00 by pbencze           #+#    #+#             */
/*   Updated: 2025/01/13 13:33:31 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _signed(0), _signGrade(0), _execGrade(0) {
   std::cout << "Default constructor called." << std::endl;
}

Form::Form(const std::string &name, int signGrade, int execGrade) : _name(name), _signed(0), _signGrade(signGrade), _execGrade(execGrade) {
   if (_signGrade > 150 || _execGrade > 150)
      throw Form::GradeTooLowException();
   if (_signGrade < 1 || _execGrade < 1)
      throw Form::GradeTooHighException();
   std::cout << "Parameterized constructor called." << std::endl;
}

Form::Form(const Form &src) : _name("Default"), _signed(0), _signGrade(0), _execGrade(0) {
   this->_signed = src._signed;
   std::cout << "Copy constructor called." << std::endl;
}

Form::~Form() {
   std::cout << "Destructor called." << std::endl;
}

Form & Form::operator=(const Form &rhs) {
   if (this != &rhs) {
      this->_signed = rhs._signed;
   }
   return *this;
}

int Form::getSignGrade() const {
	return(_signGrade);
}

int Form::getExecGrade() const {
	return(_execGrade);
}

std::string Form::getName() const {
	return(_name);
}

bool Form::getSigned() const {
	return(_signed);
}

void Form::beSigned(Bureaucrat b) {
	if (b.getGrade() <= _signGrade)
		_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &rhs) {
	out << "Form " << rhs.getName()
	<< " requires " << rhs.getExecGrade() << " to execute it, "
	<< rhs.getSignGrade() << " to sign it, ";

	if (rhs.getSigned() == true)
		out << " and it has already been signed";
	else
		out << " and it has not yet been signed";

	out << std::endl;
	return (out);
}


