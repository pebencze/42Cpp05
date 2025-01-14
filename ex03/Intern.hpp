#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

enum e_form {
    ROBOTOMY,
    SHRUBBERY,
    PRESIDENT
};

class Intern {
    public:
        Intern(); //default constructor
        //Intern(); //parameterized constructor
        //Intern(const Intern &src); //copy constructor
        ~Intern(); //destructor

        //Intern &operator=(const Intern &rhs); //operator overload
        AForm *makeForm(const std::string &name, const std::string &target);
};
#endif
