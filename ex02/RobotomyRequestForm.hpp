#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>

class RobotomyRequestForm {
    public:
        RobotomyRequestForm(); //default constructor
        RobotomyRequestForm(const std::string &target); //parameterized constructor
        RobotomyRequestForm(const RobotomyRequestForm &src); //copy constructor
        ~RobotomyRequestForm(); //destructor

        RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs); //operator overload

    private:
        std::string _target;
};
#endif
