#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {
   std::cout << "Default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name) {
   std::cout << "Parameterized constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) {
   std::cout << "Copy constructor called." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
   std::cout << "Destructor called." << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
   if (this != &rhs) {}
   return *this;
}
