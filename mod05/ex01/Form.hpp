/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:33:58 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/01 18:03:09 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

# define	FO_DEF_NAME "Blank  Form"
# define	FO_DEF_SIGN_GRADE 150
# define	FO_DEF_EX_GRADE 150
# define	FO_DEF_SIGN false

class Form
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			sign_grade;
		const int			exec_grade;
	public:
		Form();
		Form(const std::string name, const int sign_g, const int exec_g);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		std::string	getName(void) const;
		int			getSiGrade(void) const;
		int			getExGrade(void) const;
		bool		getSign(void) const;
		bool		beSigned(const Bureaucrat& signer);
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form& subject);

#endif