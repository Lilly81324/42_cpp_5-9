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
		void	clear(void);
		void	operand(int number);
		bool	operater(char op);
		int		getResult(std::string &error);
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

		int					handle(const char *input);
		const std::string	getError(void);
		void				clear();
};

#endif