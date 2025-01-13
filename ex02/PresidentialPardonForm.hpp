#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>

class PresidentialPardonForm {
    public:
        PresidentialPardonForm(); //default constructor
        PresidentialPardonForm(const std::string &name); //parameterized constructor
        PresidentialPardonForm(const PresidentialPardonForm &src); //copy constructor
        ~PresidentialPardonForm(); //destructor

        PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs); //operator overload

};
#endif
