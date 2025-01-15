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
        ~Intern(); //destructor

        AForm *makeForm(const std::string &name, const std::string &target);

	private:
        Intern(void *parameter); //parameterized constructor
        Intern(const Intern &src); //copy constructor
        Intern &operator=(const Intern &rhs); //operator overload

};
#endif
