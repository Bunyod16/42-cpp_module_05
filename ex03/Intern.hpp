#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class Intern
{
	public:
		// Constructors
		Intern();
		Intern(const Intern &copy);
		
		// Destructor
		~Intern();
		class BadFormNameException : public std::exception
		{
			public:
				virtual const char * what () const throw()
				{
					return ("Form name must be either of `shrubbery form` `robotomy request` `presidential pardon`");
				}
		};
		// Operators
		Intern & operator=(const Intern &assign);
		AForm	*makeForm(std::string form_name, std::string target);
	private:
		
};

#endif