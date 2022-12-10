#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void testFormSuccess()
{
    Form standard("school form", 80, 50);
    Bureaucrat principal("Principal", 30);

    principal.signForm(standard);
}

void testFormLevelHigh()
{
    Form standard("school form", 25, 50);
    Bureaucrat principal("Principal", 30);

    principal.signForm(standard);
}

void testFormError()
{
    Form standard("school form", 151, 50);
    Bureaucrat principal("Principal", 30);

    principal.signForm(standard);
}

int main(void)
{

    try
    {
        testFormSuccess();
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