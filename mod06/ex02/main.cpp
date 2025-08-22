/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:39:31 by sikunne           #+#    #+#             */
/*   Updated: 2025/08/22 19:51:40 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "It is an A!" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "It is an B!" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "It is an C!" << std::endl;
	else
		std::cout << "It is an abomination!" << std::endl;
}

Base *generate(void)
{
	int	choice = 0;
	struct timeval timer;

	gettimeofday(&timer, NULL);
	choice = timer.tv_usec % 3;
	switch (choice)
	{
		case 0:
			return(new A());
		case 1:
			return(new B());
		case 2:
			return(new C());
		default:
			return (NULL);
	}
	return (NULL);
}

int main(void)
{
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	identify(generate());
	
	return (0);
}
