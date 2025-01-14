#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {
   std::cout << "Default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) {
   std::cout << "Parameterized constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) {
   std::cout << "Copy constructor called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
   std::cout << "Destructor called." << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
   if (this != &rhs) {}
   return *this;
}
