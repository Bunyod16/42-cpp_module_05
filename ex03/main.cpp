#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{
    Intern  someRandomIntern;
    AForm*   rrf;
    Bureaucrat Boss("Boss", 1);
    rrf = someRandomIntern.makeForm("shrubbery form", "Bender");
    Boss.signForm(*rrf);
    (*rrf).execute(Boss);
    delete(rrf);
}