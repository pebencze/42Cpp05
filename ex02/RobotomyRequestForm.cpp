#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default"){
   std::cout << "Default robotomy constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
   std::cout << "Parameterized robotomy constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm("RobotomyRequestForm", 72, 45) {
   this->_target = src._target;
   std::cout << "Copy robotomy constructor called." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
   std::cout << "Robotomy destructor called." << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
   if (this != &rhs) {
      this->_target = rhs._target;
   }
   return *this;
}
