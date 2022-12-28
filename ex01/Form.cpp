#include "Form.hpp"
#include <iostream>

// Constructors
Form::Form(std::string name, int sign_grade, int execute_grade) : _name(name), _sign_grade(sign_grade), _execute_grade(execute_grade), _is_signed(false)
{
	if (sign_grade > 150 || execute_grade > 150)
		throw GradeTooLowException();
	else if (sign_grade < 1 || execute_grade < 1)
		throw GradeTooHighException();
	std::cout << "\e[0;33mDefault Constructor called of Form\e[0m" << std::endl;
}

Form::Form(const Form &copy) : _name(copy.getName()), _sign_grade(copy.getSignGrade()), _execute_grade(copy.getExecuteGrade()), _is_signed(copy.isSigned())
{
	std::cout << "\e[0;33mCopy Constructor called of Form\e[0m" << std::endl;
}


// Destructor
Form::~Form()
{
	std::cout << "\e[0;31mDestructor called of Form\e[0m" << std::endl;
}


// Operators
Form & Form::operator=(const Form &assign)
{
	_is_signed = assign.isSigned();
	return *this;
}

std::string	Form::getName( void ) const
{
	return (_name);
}

bool	Form::isSigned( void ) const
{
	return (_is_signed);
}

int			Form::getSignGrade( void ) const
{
	return (_sign_grade);
}

int			Form::getExecuteGrade( void ) const
{
	return (_execute_grade);
}

const char * BoolToString(bool b)
{
  return b ? "true" : "false";
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
  os << (obj.getName() + ", is signed: " + BoolToString(obj.isSigned()) + ". Grade to sign: " + std::to_string(obj.getSignGrade()) + ". Grade to execute: " + std::to_string(obj.getExecuteGrade()) + ".");
  return os;
}

void	Form::beSigned(Bureaucrat bur)
{
	if (bur.getGrade() <= _sign_grade)
		_is_signed = true;
	else
		throw GradeTooHighException();
}
