#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Constructors
Intern::Intern()
{
	std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
}


// Destructor
Intern::~Intern()
{
	std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}


// Operators
Intern & Intern::operator=(const Intern &assign)
{
	(void) assign;
	return *this;
}

AForm	*createShrubbery( std::string target )
{
	return (new ShrubberyCreationForm(target));
}

AForm	*createRobotomy( std::string target )
{
	return (new RobotomyRequestForm(target));
}

AForm	*createPresidential( std::string target )
{
	return (new PresidentialPardonForm(target));
}


AForm	*Intern::makeForm(std::string form_name, std::string target)
{
	AForm *(*functions[3])( std::string target ) = {createShrubbery, createRobotomy, createPresidential};
	std::string names[3] = {"shrubbery form", "robotomy request", "presidential pardon"};
	int i;

	i = -1;
	while (++i < 3)
	{
		if (names[i] == form_name)
			return ((functions[i])(target));
	}
	throw Intern::BadFormNameException();
}
