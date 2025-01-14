#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberycreationForm", 145, 137), _target("default_target") {
   std::cout << "Default shrubbery constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberycreationForm", 145, 137), _target(target) {
   std::cout << "Parameterized shrubbery constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm("ShrubberycreationForm", 145, 137) {
   this->_target = src._target;
   std::cout << "Copy shrubbery constructor called." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
   std::cout << "Shrubbery destructor called." << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
   if (this != &rhs) {
      this->_target = rhs._target;
   }
   return (*this);
}

void ShrubberyCreationForm::performAction() const {
   std::string filename;

   filename = this->_target + "_shrubbery";
   std::ofstream ofs(filename, std::ios::out);

   if (!ofs.is_open()) {
      std::cerr << "Failed to open file: " << filename << std::endl;
      return;
   }

   ofs << "  (())          /\\\n";
   ofs << " (())()         /\\\n";
   ofs << "((()()))       /  \\\n";
   ofs << "   ||          /  \\\n";
   ofs << "   ||         /    \\\n";
   ofs << "   ||           ||\n";
   ofs << "---------------------------";

   std::cout << "Created file " << filename << std::endl;
   //ofs.close(); //not necessary, file closes automatically when out of scope
}
