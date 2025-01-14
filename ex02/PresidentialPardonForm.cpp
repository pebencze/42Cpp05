#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {
   std::cout << "Default presidential constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
   std::cout << "Parameterized presidential constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm("PresidentialPardonForm", 25, 5) {
   this->_target = src._target;
   std::cout << "Copy presidential constructor called." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
   std::cout << "Presidential destructor called." << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
   if (this != &rhs) {
      this->_target = rhs._target;
   }
   return *this;
}
