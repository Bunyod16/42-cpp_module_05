#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
	std::cout << "\e[0;33mDefault Constructor called of Bureaucrat\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	_grade = copy.getGrade();
	// _name = copy.getName();
	std::cout << "\e[0;33mCopy Constructor called of Bureaucrat\e[0m" << std::endl;
}


// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called of Bureaucrat\e[0m" << std::endl;
}


// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
{
	_grade = assign.getGrade();
	// _name = assign.getName();

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
  os << (obj.getName() + ", bureaucrat grade " + std::to_string(obj.getGrade()));
  return os;
}

int Bureaucrat::getGrade( void ) const
{
	return (_grade);
}

std::string Bureaucrat::getName( void ) const
{
	return (_name);
}

void Bureaucrat::DecrementGrade( void )
{
	int temp;

	temp = _grade + 1;
	if (temp > 150)
		throw GradeTooHighException();
	_grade = temp;
}

void Bureaucrat::IncrementGrade( void )
{
	int temp;

	temp = _grade - 1;
	if (temp < 1)
		throw GradeTooLowException();
	_grade = temp;
}

void	Bureaucrat::signForm(Form form)
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << *this << " could not sign " << form << " because " << e.what() << std::endl;
	}
}
