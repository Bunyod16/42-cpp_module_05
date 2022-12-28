#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>


class Bureaucrat
{
	public:
		// Constructors
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		
		// Destructor
		~Bureaucrat();
		
		// Operators
		Bureaucrat &operator=(const Bureaucrat &assign);
		std::string &operator<<(const Bureaucrat &assign);
    	// throw an instance of MyException

		int			getGrade( void ) const;
		std::string getName( void ) const;
		void		IncrementGrade( void );
		void		DecrementGrade( void );

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what () const throw()
				{
					return ("Bureaucrat's grade is too high");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what () const throw()
				{
					return ("Bureaucrat's grade is too low");
				}
		};

	private:
		std::string const _name;
		int	_grade;
		
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif