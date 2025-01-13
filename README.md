# 42Cpp05
Repetition and exceptions.

## Exceptions
~: a way of handling errors in C++. Related terms: try, catch, throw, if-else.

### Why Exceptions? - Cons of Return Values.
- return codes do not work well with constructors
- makes functions look long and messy
- user has to deduce what the error code means
- if the function has to return integers, what shall it return on error?

## Pros and Cons of Exceptions:
### Pros
- especialy useful when the stack contains several function calls between the function that detects and the one that handles the error. In C we ususally return -1,-2,-3 etc. in case of an error, but this is a tedious way of error handling. Or we set a global variable with an error code that the user may have to retrieve after every function call.
- unhandled exceptions quit the program (std::terminate is invoked if no matching catch block is found) -> forces the code to handle errors
- clean separation of handling (catch) and detecting (throw)
- objects are destroyed in the scope between throw and catch when there is an exception (so-called "stack unwinding")
### Cons
- use exceptions "exceptionally", because it is resource consuming (however, if no exception is thrown, the cost is minimal)


## Guide
- use exceptions if an error might occur e.g. arguments that user gives (external error); use assertions `assert` if something always has to be true or false (your programming error)
- use error-codes in performance-critical loops
- use execptions when there is many intervening function calls between error and handling
- THROW BY VALUE, CATCH BY REFERENCE
- exceptions should not escape destruction or deallocation functions

- many system functions like new or stringstreams can throw an exception

## Exception Mechanism
(source: https://learn.microsoft.com/en-us/cpp/cpp/exceptions-and-stack-unwinding-in-cpp?view=msvc-170 (9.1.2025))
### Try and No Exception
"Control reaches the try statement by normal sequential execution. The guarded section in the try block is executed.
If no exception is thrown during execution of the guarded section, the catch clauses that follow the try block are not executed. Execution continues at the statement after the last catch clause that follows the associated try block."
### Exception and No Matching Catch
"If an exception is thrown during execution of the guarded section or in any routine that the guarded section calls either directly or indirectly, an exception object is created from the object that is created by the throw operand. (This implies that a copy constructor may be involved.) At this point, the compiler looks for a catch clause in a higher execution context that can handle an exception of the type that is thrown, or for a catch handler that can handle any type of exception. The catch handlers are examined in order of their appearance after the try block. If no appropriate handler is found, the next dynamically enclosing try block is examined. This process continues until the outermost enclosing try block is examined.
If a matching handler is still not found, or if an exception occurs during the unwinding process but before the handler gets control, the predefined run-time function terminate is called. If an exception occurs after the exception is thrown but before the unwind begins, terminate is called."
### Exception and Catch, Stack Unwinding
"If a matching catch handler is found, and it catches by value, its formal parameter is initialized by copying the exception object. If it catches by reference, the parameter is initialized to refer to the exception object. After the formal parameter is initialized, the process of unwinding the stack begins. This involves the destruction of all automatic objects that were fully constructed—but not yet destructed—between the beginning of the try block that is associated with the catch handler and the throw site of the exception. Destruction occurs in reverse order of construction. The catch handler is executed and the program resumes execution after the last handler—that is, at the first statement or construct that is not a catch handler."

## <stdexcept> Header File of the Standard Library
defines classes to report exceptions within the 2 basic types of errors: </b>
- runtime_error
- - overflow_error
- - range_error
- - underflow_error
- logic_error
- - domain_error
- - invalid_argument
- - length_error
- - out_of_range

### Base Exception Class of <stdexcept>
```c++
class exception {
   public:
   exception();
   exception(const char* const &message);
   exception(const char* const &message, int);
   exception(const exception &right);
   exception& operator=(const exception &right);
   virtual ~exception();
   virtual const char *what() const;
};
```

## General vs. Custom Exceptions
```c++
void test1()
{
    try
    {
        //do stuff
        if (exception occurs)
        {
            throw std::exception();
        }
        else
        {
            //do stuff
        }
    }
    catch (std::exception e)
    {
        //handle error
    }
};

void test2()
{
    //do stuff
    if (exception occurs)
    {
        throw std::exception();
    }
    else
    {
        //do stuff
    }
}

void test3()
{
    try
    {
        test2();
    }
    catch (std::exception &e)
    {
        //handle error
    }
}

/*
	•	Shows Polymorphic Behavior: How derived exceptions can be caught using a base class pointer or reference. Since MyException is derived from std::exception, it can be caught by the catch (std::exception &e) block if the catch (MyException &e) block were absent.
	•	The example emphasizes the importance of the order of catch blocks, as placing the more general std::exception block first would prevent the MyException block from ever being executed
*/
void test4()
{
    class MyException : public std::exception //custom exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("This is my problem.");
            }
    }
    try
    {
        test3();
    }
    catch (MyException &e)
    {
        //handle my custom exception
    }
    catch (std::exception &e)
    {
        //handle other types of exception
    }
}
```

## Random Things to Remember
1. String reference has to be const in a parameterized constructor, to
avoid the following error: "no known conversion from 'const char [9]' to 'std::string &' (aka 'basic_string<char> &'"
```c++
Form(const std::string &name, int signGrade, int execGrade);
```
2. Use of forward declaration to avoid circular dependencies.

```c++
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat; //forward declaration

class Form {...};
```
