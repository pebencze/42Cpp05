#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat {
    public:
        Bureaucrat(); //default constructor
        Bureaucrat(std::string name); //parameterized constructor
        Bureaucrat(Bureaucrat const& src); //copy constructor
        ~Bureaucrat(); //destructor

        Bureaucrat & operator=(Bureaucrat const& rhs); //operator overload

    private:
};
#endif
