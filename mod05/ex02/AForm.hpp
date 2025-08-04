/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:33:58 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/04 17:55:53 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

# define	FO_DEF_NAME "Blank  Form"
# define	FO_DEF_SIGN_GRADE 150
# define	FO_DEF_EX_GRADE 150
# define	FO_DEF_SIGN false
# define	DEF_TARGET "[Your Target here]"

class AForm
{
	protected:
		const std::string	name;
		bool				is_signed;
		const int			sign_grade;
		const int			exec_grade;
	public:
		AForm();
		AForm(const std::string name, const int sign_g, const int exec_g);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		std::string	getName(void) const;
		int			getSiGrade(void) const;
		int			getExGrade(void) const;
		bool		getSign(void) const;
		bool		beSigned(const Bureaucrat& signer);
		virtual bool	execute(Bureaucrat const &executor) const = 0;
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

std::ostream &operator<<(std::ostream &out, const AForm& subject);

#endif