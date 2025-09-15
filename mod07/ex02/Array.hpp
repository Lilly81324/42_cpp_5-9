/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:25:36 by sikunne           #+#    #+#             */
/*   Updated: 2025/09/15 19:24:47 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
 #define ARRAY_HPP

#include <unistd.h>
#include <iostream>

template<typename T>
class Array
{
	private:
		unsigned int length;
	public:
		Array(void): length(0), content(NULL)
		{
		};
		Array(unsigned int n): length(0), content(NULL)
		{
			this->length = n;
			if (n == 0)
				this->content = NULL;
			else
				this->content = new T[n];
		};
		Array(const Array &other): length(0), content(NULL)
		{
			*this = other;
		};
		~Array(void)
		{
			if (this->content != NULL)
				delete [] (this->content);
			this->length = 0;
		};
		class IndexOutOfBounds: std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		Array &operator=(const Array &other)
		{
			unsigned int	i = 0;

			this->length = other.size();
			if (this->content != NULL)
				delete [] this->content;
			this->content = new T[this->length];
			while (i < this->length)
			{
				this->content[i] = other.content[i];
				i++;
			}
			return (*this);
		};
		T &operator[](int index)
		{
			if (index < 0 || index > static_cast<int>(this->size()) - 1)
				throw (Array::IndexOutOfBounds());
			return (this->content[index]);
		};
		unsigned int size(void) const
		{
			return (this->length);
		};
		T *content;
};

template<typename T>
const char *Array<T>::IndexOutOfBounds::what() const throw()
{
	return ("Custom Segmentation Fault");
}

#endif