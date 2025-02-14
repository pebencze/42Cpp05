/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:23:00 by pbencze           #+#    #+#             */
/*   Updated: 2025/01/14 12:29:13 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signed(0), _signGrade(0), _execGrade(0) {
   std::cout << "Default form constructor called." << std::endl;
}

AForm::AForm(const std::string &name, int signGrade, int execGrade) : _name(name), _signed(0), _signGrade(signGrade), _execGrade(execGrade) {
   if (_signGrade > 150 || _execGrade > 150)
      throw AForm::GradeTooLowException();
   if (_signGrade < 1 || _execGrade < 1)
      throw AForm::GradeTooHighException();
   std::cout << "Parameterized form constructor called." << std::endl;
}

AForm::AForm(const AForm &src) : _name("Default"), _signed(0), _signGrade(0), _execGrade(0) {
   this->_signed = src._signed;
   std::cout << "Copy form constructor called." << std::endl;
}

AForm::~AForm() {
   std::cout << "Form destructor called." << std::endl;
}

AForm & AForm::operator=(const AForm &rhs) {
   if (this != &rhs) {
      this->_signed = rhs._signed;
   }
   return *this;
}

int AForm::getSignGrade() const {
	return(_signGrade);
}

int AForm::getExecGrade() const {
	return(_execGrade);
}

std::string AForm::getName() const {
	return(_name);
}

bool AForm::getSigned() const {
	return(_signed);
}

void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() <= _signGrade)
		_signed = true;
	else
		throw GradeTooLowException();
}

void AForm::performAction() const {
	return ;
}

void AForm::execute(Bureaucrat const &executor) const {
	std::string gradeLow;
	std::string notSigned;
	
	notSigned = "Cannot execute form, because it has not been signed.";
	gradeLow = "Cannot execute form, because the executor's grade is too low.";
	if (_signed != true)
		throw std::runtime_error(notSigned);
	else if (executor.getGrade() > _execGrade)
		throw std::runtime_error(gradeLow);
	else
	{
		performAction();
	}
}

std::ostream &operator<<(std::ostream &out, const AForm &rhs) {
	out << "Form " << rhs.getName()
	<< " requires " << rhs.getExecGrade() << " to execute it, "
	<< rhs.getSignGrade() << " to sign it, ";

	if (rhs.getSigned() == true)
		out << "and it has already been signed.";
	else
		out << "and it has not been signed yet.";

	out << std::endl;
	return (out);
}


