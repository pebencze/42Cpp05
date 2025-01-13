#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form {
    public:
        Form(); //default constructor
        Form(std::string &name, int &signGrade, int &execGrade); //parameterized constructor
        Form(const Form &src); //copy constructor
        ~Form(); //destructor

        Form &operator=(Form const &rhs); //operator overload

		const int getSignGrade() const;
		const int getExecGrade() const;
		const std::string getName() const;
		bool getSigned() const;

		void beSigned(Bureaucrat b);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade is too high.";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade is too low.";
				}
		};

    private:
        const std::string	_name;
        bool				_signed;
        const int			_signGrade;
        const int			_execGrade;
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);

#endif
