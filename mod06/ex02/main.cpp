/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:39:31 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/28 18:12:10 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

# define MSG_A "It is an  A\n"
# define MSG_B "It is an  B\n"
# define MSG_C "It is an  C\n"
# define MSG_WRONG "It is an abomination!\n"

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << MSG_A;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << MSG_B;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << MSG_C;
	else
		std::cout << MSG_WRONG;
}

void	identify(Base& p)
{

	int i;

	i = 0;
	while (i < 3)
	{
		try
		{
			switch (i)
			{
				case 0:
					dynamic_cast<A&>(p);
					std::cout << MSG_A;
					return ;
				case 1:
					dynamic_cast<B&>(p);
					std::cout << MSG_B;
					return ;
				case 2:
					dynamic_cast<C&>(p);
					std::cout << MSG_C;
					return ;
				default:
					std::cout << MSG_WRONG;
					return ;
			}
		}
		catch(const std::exception& e)
		{
			i++;
		}
	}
}

Base *generate(void)
{
	int	choice = 0;
	struct timeval timer;

	gettimeofday(&timer, NULL);
	choice = timer.tv_usec % 3;
	std::cout << "Generated ";
	switch (choice)
	{
		case 0:
			std::cout << "A." << std::endl;
			return(new A());
		case 1:
			std::cout << "B." << std::endl;
			return(new B());
		case 2:
			std::cout << "C." << std::endl;
			return(new C());
		default:
			std::cout << "Nonsense!" << std::endl;
			return (NULL);
	}
	return (NULL);
}

void attempt(void)
{
	std::cout << "--========--" << std::endl;
	Base *obj;
	obj = generate();
	identify(*obj);
	identify(obj);
	delete(obj);
}

int main(void)
{
	for (int i = 0; i < 10; i++)
		attempt();
	return (0);
}
