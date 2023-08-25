/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 19:19:18 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/25 14:56:03 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>

Span::Span() : _maxElements(0) {}

Span::Span( unsigned int N ) : _maxElements(N) {}

Span::~Span() {}

Span::Span( const Span& other ) {
	
	this->_maxElements = other._maxElements;
}

Span& Span::operator=( const Span& other) {

	if( this != &other ) {
		
		this->_maxElements = other._maxElements;
	}
	return *this;
}

//fill list, if max elements N already stored, throw exception
void Span::addNumber( int num ) {

	if( numVector.size() >= _maxElements ) {

		throw Span::MaxNumberVectorException();
	}
	
	numVector.push_back( num );
}

//no nnumbers or only one throw exception
unsigned int Span::shortestSpan(){
	
	if( numVector.size() <= 1 ) {

		throw Span::SpanException();
	}
	std::vector<unsigned int>::iterator it;
	std::vector<unsigned int>::iterator next = it;

	std::advance( next, 1 );
	std::swap( next, it );

	
	// for( it = numVector.begin(); it != numVector.end(); ++it ) {
		
	// 	for( next = it + 1; next != numVector.end(); ++next ) {
			
	// 		if( *next < *it ) {

	// 			std::swap( *next, *it );
	// 		}
	// 	}
	// }

	unsigned int minSpan = numVector[1] - numVector[0];
	
	for( it = numVector.begin() + 1; it != numVector.end(); ++it ) {
		
		minSpan = std::min<unsigned int>( minSpan, *(it + 1) - *it);
	}
	
	return minSpan;
}

unsigned int Span::longestSpan() {

	if( numVector.size() <= 1 ) {

		throw Span::SpanException();
	}
	
	unsigned int maxElement = *std::max_element(numVector.begin(), numVector.end() );
	unsigned int minElement = *std::min_element(numVector.begin(), numVector.end() );

	return maxElement - minElement;
}

const std::vector<unsigned int>& Span::getNumVector() {

	return numVector;
}

// void Span::swapValues( std::vector<unsigned int>::iterator it1, std::vector<unsigned int>::iterator it2 ) {

// 	std::swap( *it1, it2 );
// }


std::ostream& operator<<( std::ostream& os, Span& rhs ) {

	// std::vector<unsigned int>::iterator it;
	const std::vector<unsigned int>& numVector = rhs.getNumVector();
	for (size_t i = 0; i < numVector.size(); ++i) {
        os << numVector[i];
        if (i < numVector.size() - 1) {
            os << ' ';
        }
    }
    return os;
}



//   std::cout << "The contents of fifth are: ";
//   for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
//     std::cout << *it << ' ';