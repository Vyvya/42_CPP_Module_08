/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:39:16 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/25 17:51:32 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "Color.hpp"
#include <vector>

int main() {
	
	std::cout << GR << "	# Test 42 #	" << std::endl << std::endl;
	
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	std::cout << YL << "	# Test Span random #	" << std::endl << std::endl;

	Span y = Span(100000);

	srand( time(NULL));
	for( int i = 0; i < 100000; i++ ) {
		
		y.addNumber( rand() );
	}
	
	std::cout << y.shortestSpan() << std::endl;
	std::cout << y.longestSpan() << std::endl;
	
	return 0;
}
