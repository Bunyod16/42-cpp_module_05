#include "AForm.hpp"
#include <iostream>

// Constructors
AForm::AForm(std::string name, int sign_grade, int execute_grade) : _name(name)
{
	if (sign_grade > 150 || execute_grade > 150)
		throw GradeTooLowException();
	else if (sign_grade < 1 || execute_grade < 1)
		throw GradeTooHighException();
	_is_signed = false;
	_sign_grade = sign_grade;
	_execute_grade = execute_grade;
	std::cout << "\e[0;33mDefault Constructor called of AForm\e[0m" << std::endl;
}

AForm::AForm(const AForm &copy)
{
	_name = copy.getName();
	_is_signed = copy.isSigned();
	_sign_grade = copy.getSignGrade();
	_execute_grade = copy.getExecuteGrade();
	std::cout << "\e[0;33mCopy Constructor called of AForm\e[0m" << std::endl;
}


// Destructor
AForm::~AForm()
{
	std::cout << "\e[0;31mDestructor called of AForm\e[0m" << std::endl;
}


// Operators
AForm & AForm::operator=(const AForm &assign)
{
	_name = assign.getName();
	_is_signed = assign.isSigned();
	_sign_grade = assign.getSignGrade();
	_execute_grade = assign.getExecuteGrade();
	return *this;
}

std::string	AForm::getName( void ) const
{
	return (_name);
}

bool	AForm::isSigned( void ) const
{
	return (_is_signed);
}

int			AForm::getSignGrade( void ) const
{
	return (_sign_grade);
}

int			AForm::getExecuteGrade( void ) const
{
	return (_execute_grade);
}

const char * BoolToString(bool b)
{
  return b ? "true" : "false";
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
  os << (obj.getName() + ", is signed: " + BoolToString(obj.isSigned()) + ". Grade to sign: " + std::to_string(obj.getSignGrade()) + ". Grade to execute: " + std::to_string(obj.getExecuteGrade()) + ".");
  return os;
}

void	AForm::beSigned(Bureaucrat bur)
{
	if (bur.getGrade() <= _sign_grade)
		_is_signed = true;
	else
		throw AForm::GradeTooLowException();
}


void	AForm::execute(Bureaucrat const & executor) const
{
	if (_is_signed == false)
		throw AForm::FormNotSignedException();
	else if (executor.getGrade() > _execute_grade)
		throw AForm::GradeTooHighException();
	action();
}

void	AForm::action( void ) const
{
	std::cout << "Default action, this shouldnt happen" << std::endl;
}
