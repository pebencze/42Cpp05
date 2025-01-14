#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    public:
        PresidentialPardonForm(); //default constructor
        PresidentialPardonForm(const std::string &target); //parameterized constructor
        PresidentialPardonForm(const PresidentialPardonForm &src); //copy constructor
        ~PresidentialPardonForm(); //destructor

        PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs); //operator overload

        void performAction() const;

    private:
        std::string _target;
};
#endif
