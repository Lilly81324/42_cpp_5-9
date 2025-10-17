/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:41:52 by sikunne           #+#    #+#             */
/*   Updated: 2025/10/17 16:18:40 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main( void )
{
	{
		// Mandatory:
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	// {
	// 	// Extra
	// 	char a = 'A';
	// 	char b = 'B';
	// 	::swap(a, b);
	// 	std::cout << "a = " << a << ", b = " << b << std::endl;
	// 	std::cout << ::max(::min(a, b), ::max(::min(a, b), min(a, 'C'))) << std::endl;
	// }
	// {
	// 	// Invalid
	// 	char a = 'A';
	// 	int b = 3;
	// 	::swap(a, b);
	// 	::min(a, b);
	// 	::max(a, b);
	// 	char smol[2];
	// 	char big[5];
	// 	::swap(smol, big);
	// 	::min(smol, big);
	// 	::max(smol, big);
	// }
	return 0;
}