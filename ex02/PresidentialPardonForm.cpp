#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() {
   std::cout << "Default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name) {
   std::cout << "Parameterized constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) {
   std::cout << "Copy constructor called." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
   std::cout << "Destructor called." << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
   if (this != &rhs) {}
   return *this;
}
