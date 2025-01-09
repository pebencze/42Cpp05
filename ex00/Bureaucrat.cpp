#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
   std::cout << "Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name){
   std::cout << "Parameterized constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& src){
   std::cout << "Copy constructor called." << std::endl;
}

Bureaucrat::~Bureaucrat(){
   std::cout << "Destructor called." << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const& rhs){
   if (this != &rhs){}
   return *this;
}
