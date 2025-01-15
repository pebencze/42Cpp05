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

void RobotomyRequestForm::performAction() const {
   srand(static_cast<unsigned>(time(0)));
   std::cout << "DRRRRRRRRRRR...DRRRRRRR...DRRRR...\n";
   if (rand() % 2)
      std::cout << _target << " has been robotomized successfully 50%% of the time.\n";
   else
      std::cout << "Robotomy failed.\n";
}
