#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		// Constructors
		AForm(std::string name, int sign_grade, int execute_grade);
		AForm(const AForm &copy);
		
		// Destructor
		virtual ~AForm();
		
		// Operators
		AForm & operator=(const AForm &assign);
		
		std::string		getName( void ) const;
		bool			isSigned( void ) const;
		int				getSignGrade( void ) const;
		int				getExecuteGrade( void ) const;
		void			beSigned(Bureaucrat bur);
		void			execute(Bureaucrat const & executor) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what () const throw()
				{
					return ("AForm grade is too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what () const throw()
				{
					return ("AForm grade is too low");
				}
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char * what () const throw()
				{
					return ("AForm has not been signed!");
				}
		};

	private:
		std::string _name;
		bool		_is_signed;
		int			_sign_grade;
		int			_execute_grade;
		virtual void	action( void ) const;

		
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif