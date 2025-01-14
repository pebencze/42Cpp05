#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm {
    public:
        ShrubberyCreationForm(); //default constructor
        ShrubberyCreationForm(const std::string &target); //parameterized constructor
        ShrubberyCreationForm(const ShrubberyCreationForm &src); //copy constructor
        ~ShrubberyCreationForm(); //destructor

        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs); //operator overload

        void performAction() const;

    private:
        std::string _target;
};
#endif
