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

void testLowGradeException()
{
    Bureaucrat Boss("Sam", 555);
}

void testHighGradeException()
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
        testHighGradeException();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "END" << std::endl;
}