/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:39:54 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/25 14:43:40 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define  SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>

class Span {

	private:

		Span();
		unsigned int _maxElements;
		std::vector<unsigned int> numVector;
		// void swapValues( std::vector<unsigned int>::iterator it1, std::vector<unsigned int>::iterator it2 );

	public:

		Span( unsigned int N );
		~Span();

		Span( const Span& other );
		Span& operator=( const Span& other);

		void addNumber( int num );
		unsigned int shortestSpan();
		unsigned int longestSpan();

		const std::vector<unsigned int>& getNumVector();
		
		class MaxNumberVectorException : public std::exception {
			
			public:
			
				const char* what() const throw() {
					return "Maximum numbers of elements in the vector reached";
				}
		};
		
		class SpanException : public std::exception {
			
			public:
			
				const char* what() const throw() {
					return "Minimum of 2 elements in the vector expected";
				}
		};
};

std::ostream& operator<<( std::ostream os, Span& rhs );

template <typename T>
void my_swap( T &a, T &b) {
	
	T temp = a;
	const_cast<T&>(a) = b;
	const_cast<T&>(b) = temp; 
}

#endif
