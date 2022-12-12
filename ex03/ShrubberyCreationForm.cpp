#include "ShrubberyCreationForm.hpp"
#include <fstream>
// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :AForm("ShrubberyCreationForm", 145, 137), _target(target) 
{
	std::cout << "\e[0;33mDefault Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = copy._target;
	std::cout << "\e[0;33mCopy Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}


// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\e[0;31mDestructor called of ShrubberyCreationForm\e[0m" << std::endl;
}


// Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	_target = assign._target;
	return *this;
}

void	ShrubberyCreationForm::action( void ) const
{
	std::string tree = "       _-_						\n"
						"    /~~   ~~\\					\n"
						" /~~         ~~\\				\n"
						"{               }				\n"
						" \\  _-     -_  /				\n"
						"   ~   \\ /  ~					\n"
						"_- -   | | _- _				\n"
						"  _ -  | |   -_				\n"
						"       / \\					\n";

	std::ofstream MyFile(_target + "_shrubbery");

	MyFile << tree;	
	
	MyFile.close();
}
