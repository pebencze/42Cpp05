#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Form {
    public:
        Form(); //default constructor
        Form(std::string &name, int &signGrade, int &execGrade); //parameterized constructor
        Form(const Form &src); //copy constructor
        ~Form(); //destructor

        Form &operator=(Form const &rhs); //operator overload

        class GradeTooHighException : public std::exception {
            virtual const char* what() const throw() {
                return "Grade is too high.";
            }
        };
        class GradeTooLowException : public std::exception {
            virtual const char* what() const throw() {
                return "Grade is too low.";
            }
        };

    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _execGrade;
};
#endif
