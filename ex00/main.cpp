#include <iostream>
#include "Bureaucrat.hpp"

void testIncrementException()
{
    Bureaucrat Boss("Sam", 150);
    Boss.IncrementGrade();
}

void testDecrementException()
{
    Bureaucrat Boss("Sam", 1);
    Boss.DecrementGrade();
}

void testHighException()
{
    Bureaucrat Boss("Sam", 555);
}

void testLowException()
{
    Bureaucrat Boss("Sam", -15);
}

void testLeftShiftOverload()
{
    Bureaucrat Boss("Sam", 15);
    std::cout << Boss << std::endl;
}

int main(void)
{

    try
    {
        testLeftShiftOverload();
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch  (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "END" << std::endl;
}