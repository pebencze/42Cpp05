/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbencze <pbencze@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:23:05 by pbencze           #+#    #+#             */
/*   Updated: 2025/01/15 13:01:44 by pbencze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default") {
   std::cout << "Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
   if (grade < 1)
   {
      std::cerr << "Error during construction. ";
      throw Bureaucrat::GradeTooHighException();
   }
   else if (grade > 150)
   {
      std::cerr << "Error during construction. ";
      throw Bureaucrat::GradeTooLowException();
   }
   std::cout << "Parameterized constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name("Default") {
   *this = src;
   std::cout << "Copy constructor called." << std::endl;
}

Bureaucrat::~Bureaucrat() {
   std::cout << "Destructor called." << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &rhs) {
   if (this != &rhs){
      this->_grade = rhs._grade;
   }
   return (*this);
}

int Bureaucrat::getGrade() const {
   return (_grade);
}

void Bureaucrat::setGrade(int newGrade) {
   try {
      if (newGrade < 1)
         throw Bureaucrat::GradeTooHighException();
      else if (newGrade > 150)
         throw Bureaucrat::GradeTooLowException();
      else
         _grade = newGrade;
   }
   catch (std::exception &e){
      std::cerr << "Did not change grade: " << e.what() << std::endl;
      return ;
   }
}

std::string Bureaucrat::getName() const {
   return (_name);
}

void Bureaucrat::increment(int amount) {
   std::cout << "Incrementing..." << std::endl;
   setGrade(_grade - amount);
}

void Bureaucrat::decrement(int amount) {
   std::cout << "Decrementing..." << std::endl;
   setGrade(_grade + amount);
}

void Bureaucrat::signForm(Form &f) const {
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << ".";
	}
	catch (std::exception &e)
	{
		std::cerr << _name << " couldn't sign " << f.getName() << " because " << e.what();
	}
	std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs) {
   out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".\n";
   return (out);
}
