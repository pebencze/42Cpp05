#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    public:
        RobotomyRequestForm(); //default constructor
        RobotomyRequestForm(const std::string &target); //parameterized constructor
        RobotomyRequestForm(const RobotomyRequestForm &src); //copy constructor
        ~RobotomyRequestForm(); //destructor

        RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs); //operator overload

        void performAction() const;

    private:
        std::string _target;
};
#endif
