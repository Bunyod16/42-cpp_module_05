#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testSuccessShrubbery( void )
{
    ShrubberyCreationForm ShrubForm("Shrub");
    Bureaucrat Bureau("Bossman", 1);

    try
    {
        ShrubForm.beSigned(Bureau);
        ShrubForm.execute(Bureau);
        std::cout << "created a file" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "END" << std::endl;
}

void testSuccessRobotomy( void )
{
    RobotomyRequestForm RobotomyForm("RobotomyForm");
    Bureaucrat Bureau("Bossman", 1);

    try
    {
        RobotomyForm.beSigned(Bureau);
        RobotomyForm.execute(Bureau);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "END" << std::endl;
}

void testSuccessPresidential( void )
{
    PresidentialPardonForm PardonForm("Alcapone");
    Bureaucrat Bureau("Bossman", 1);

    try
    {
        PardonForm.beSigned(Bureau);
        PardonForm.execute(Bureau);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "END" << std::endl;
}

void testFailShrubbery( void )
{
    ShrubberyCreationForm ShrubForm("Shrub");
    Bureaucrat Bureau("Bossman", 150);

    try
    {
        ShrubForm.beSigned(Bureau);
        ShrubForm.execute(Bureau);
        std::cout << "created a file" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "END" << std::endl;
}

void testFailRobotomy( void )
{
    RobotomyRequestForm RobotomyForm("RobotomyForm");
    Bureaucrat Bureau("Bossman", 150);

    try
    {
        RobotomyForm.beSigned(Bureau);
        RobotomyForm.execute(Bureau);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "END" << std::endl;
}

void testFailPresidential( void )
{
    PresidentialPardonForm PardonForm("Alcapone");
    Bureaucrat Bureau("Bossman", 150);

    try
    {
        PardonForm.beSigned(Bureau);
        PardonForm.execute(Bureau);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "END" << std::endl;
}

void testNoSignShrubbery( void )
{
    ShrubberyCreationForm ShrubForm("Shrub");
    Bureaucrat Bureau("Bossman", 1);

    try
    {
        ShrubForm.execute(Bureau);
        std::cout << "created a file" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "END" << std::endl;
}

void testNoSignRobotomy( void )
{
    RobotomyRequestForm RobotomyForm("RobotomyForm");
    Bureaucrat Bureau("Bossman", 1);

    try
    {
        RobotomyForm.execute(Bureau);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "END" << std::endl;
}

void testNoSignPresidential( void )
{
    PresidentialPardonForm PardonForm("Alcapone");
    Bureaucrat Bureau("Bossman", 1);

    try
    {
        PardonForm.execute(Bureau);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "END" << std::endl;
}

void testLowSignShrubbery( void )
{
    ShrubberyCreationForm ShrubForm("Shrub");
    Bureaucrat Bureau("Bossman", 1);
    Bureaucrat Commoner("Commoner", 150);

    try
    {
        Commoner.signForm(ShrubForm);
        ShrubForm.execute(Commoner);
        std::cout << "created a file" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "END" << std::endl;
}

void testLowSignRobotomy( void )
{
    RobotomyRequestForm RobotomyForm("RobotomyForm");
    Bureaucrat Bureau("Bossman", 1);
    Bureaucrat Commoner("Commoner", 150);

    try
    {
        Commoner.signForm(RobotomyForm);
        RobotomyForm.execute(Commoner);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "END" << std::endl;
}

void testLowSignPresidential( void )
{
    PresidentialPardonForm PardonForm("Alcapone");
    Bureaucrat Bureau("Bossman", 1);
    Bureaucrat Commoner("Commoner", 150);

    try
    {
        Commoner.signForm(PardonForm);
        PardonForm.execute(Commoner);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "END" << std::endl;
}

void testLowExecuteShrubbery( void )
{
    ShrubberyCreationForm ShrubForm("Shrub");
    Bureaucrat Bureau("Bossman", 1);
    Bureaucrat Commoner("Commoner", 150);

    try
    {
        Bureau.signForm(ShrubForm);
        ShrubForm.execute(Commoner);
        std::cout << "created a file" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "END" << std::endl;
}

void testLowExecuteRobotomy( void )
{
    RobotomyRequestForm RobotomyForm("RobotomyForm");
    Bureaucrat Bureau("Bossman", 1);
    Bureaucrat Commoner("Commoner", 150);

    try
    {
        Bureau.signForm(RobotomyForm);
        RobotomyForm.execute(Commoner);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "END" << std::endl;
}

void testLowExecutePresidential( void )
{
    PresidentialPardonForm PardonForm("Alcapone");
    Bureaucrat Bureau("Bossman", 1);
    Bureaucrat Commoner("Commoner", 150);

    try
    {
        Bureau.signForm(PardonForm);
        PardonForm.execute(Commoner);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "END" << std::endl;
}

int main(void)
{
    testSuccessShrubbery();
    testSuccessRobotomy();
    testSuccessPresidential();
    testFailShrubbery();
    testFailRobotomy();
    testFailPresidential();
    testNoSignShrubbery();
    testNoSignRobotomy();
    testNoSignPresidential();
    testLowSignShrubbery();
    testLowSignRobotomy();
    testLowSignPresidential();
    testLowExecuteShrubbery();
    testLowExecuteRobotomy();
    testLowExecutePresidential();
}