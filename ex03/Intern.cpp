#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
   std::cout << "Default intern constructor called." << std::endl;
}

// Intern::Intern(const std::string &name) {
//    std::cout << "Parameterized constructor called." << std::endl;
// }

// Intern::Intern(const Intern &src) {
//    std::cout << "Copy constructor called." << std::endl;
// }

Intern::~Intern() {
   std::cout << "Intern destructor called." << std::endl;
}

// Intern & Intern::operator=(const Intern &rhs) {
//    if (this != &rhs) {}
//    return (*this);
// }

AForm *Intern::makeForm(const std::string &name, const std::string &target) {
   
   AForm *Form = NULL;
   std::string errorMsg;
   std::string arr[3] = {"RobotomyRequestForm", "ShrubberyCreationForm", "PresidentialPardonForm"};
   int i;

   errorMsg = "Intern could not create form, because form " + name + " does not exist.";
   for (i = 0; i < 3; i++) {
      if (name == arr[i])
         break ;
   }

   switch (i)
   {
      case (ROBOTOMY):
         Form = new RobotomyRequestForm(target);
         break;
      case (SHRUBBERY):
         Form = new ShrubberyCreationForm(target);
         break;
      case (PRESIDENT):
         Form = new PresidentialPardonForm(target);
         break;
      default:
         throw std::runtime_error(errorMsg);
   }
   std::cout << "Intern creates " << name << std::endl;
   return (Form);
}

