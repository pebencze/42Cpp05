#include "Form.hpp"

Form::Form() : _name("Default"), _signGrade(0), _execGrade(0), _signed(0) {
   std::cout << "Default constructor called." << std::endl;
}

Form::Form(std::string &name, int &signGrade, int &execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(0){
   if (_signGrade > 150 || _execGrade > 150)
      throw Form::GradeTooLowException();
   if (_signGrade < 1 || _execGrade < 1)
      throw Form::GradeTooHighException();
   std::cout << "Parameterized constructor called." << std::endl;
}

Form::Form(const Form &src) : _name("Default"), _signGrade(0), _execGrade(0), _signed(0){
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
