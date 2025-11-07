/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:15:32 by sikunne           #+#    #+#             */
/*   Updated: 2025/11/07 19:31:14 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <deque>

#define OPERATORS "+-*/"

class Rpn
{
	private:

		// Actual Container used
		std::stack<int, std::deque<int> > stack;

	public:

				Rpn(void);
				Rpn(const Rpn &other);
				~Rpn(void);

		void	clear(void);
		bool	operand(int number);
		bool	operater(char op);
		int		getResult(std::string &error);

		Rpn 	&operator=(const Rpn &other);
};

class RpnCaller
{
	private:
		Rpn rpn;

		// Utility
		int curNum;
		bool hasNum;
		char lastOperator;
		std::string error;
		
		// Util functions for handle()
		bool				givenDigit(char c);
		bool				givenSpace();
		bool				givenOperator(char c);

	public:
							RpnCaller(void);
							RpnCaller(const RpnCaller &other);
							~RpnCaller(void);

		int					handle(const char *input);
		const std::string	getError(void);
		void				clear();
		RpnCaller 			&operator=(const RpnCaller &other);
};

#endif