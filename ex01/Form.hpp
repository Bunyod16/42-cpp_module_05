#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		// Constructors
		Form(std::string name, int sign_grade, int execute_grade);
		Form(const Form &copy);
		
		// Destructor
		~Form();
		
		// Operators
		Form & operator=(const Form &assign);
		
		std::string	getName( void ) const;
		bool		isSigned( void ) const;
		int			getSignGrade( void ) const;
		int			getExecuteGrade( void ) const;
		void		beSigned(Bureaucrat bur);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what () const throw()
				{
					return ("Form grade is too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what () const throw()
				{
					return ("Form grade is too low");
				}
		};

	private:
		std::string	const	_name;
		int	const			_sign_grade;
		int	const			_execute_grade;
		bool				_is_signed;


		
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif