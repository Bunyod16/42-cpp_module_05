#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"



class ShrubberyCreationForm: public AForm
{
	public:
		// Constructors
		ShrubberyCreationForm( void );
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		// Destructor
		virtual ~ShrubberyCreationForm();
		
		// Operators
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &assign);
		void	action( void ) const;

		
	private:
		std::string	_target;
		
};

#endif