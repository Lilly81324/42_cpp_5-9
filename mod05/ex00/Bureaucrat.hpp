/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:33:58 by sikunne           #+#    #+#             */
/*   Updated: 2025/07/31 18:19:35 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

#define DEF_GRADE 150
#define DEF_NAME "John Bureaucrat"

class Bureaucrat
{
	private:
		const std::string name;
		int	grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name);
		Bureaucrat(int grade);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		std::string	getName(void) const;
		int			getGrade(void) const;
		int			setGrade(int grade);
		void		increment(void);
		void		decrement(void);
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

std::ostream &operator<<(std::ostream &out, const Bureaucrat& subject);

#endif