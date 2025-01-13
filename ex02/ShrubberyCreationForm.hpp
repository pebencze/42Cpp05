#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>

class ShrubberyCreationForm {
    public:
        ShrubberyCreationForm(); //default constructor
        ShrubberyCreationForm(const std::string &name); //parameterized constructor
        ShrubberyCreationForm(const ShrubberyCreationForm &src); //copy constructor
        ~ShrubberyCreationForm(); //destructor

        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs); //operator overload

};
#endif
