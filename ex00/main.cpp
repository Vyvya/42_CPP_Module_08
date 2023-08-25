/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:39:16 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/24 18:57:56 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "Color.hpp"

int main() {

	std::cout << GR << "	# Test Array #	" << std::endl << std::endl;
	
	std::array<int, 5> numbers1 = {1, 2, 3, 4, 5};

	try {
		
		easyfind(numbers1, 6);
	} catch ( const ElementNotFoundException& e ) {
		
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::array<int, 5> numbers2 = {1, 2, 3, 4, 5};

	try {
		
		easyfind(numbers2, 3);
	} catch ( const ElementNotFoundException& e ) {
		
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout  << std::endl;
	std::cout << BL << "	# Test Vector #	" << std::endl << std::endl;

	std::vector<int> vectorNumbers1;

	for( unsigned int i = 0; i < 20; i++ ) {
		
		vectorNumbers1.push_back(i);
	}

	for( unsigned int i = 0; i < 20; i++ ) {
		
		std::cout << vectorNumbers1[i] << " ";
	}
	std::cout  << std::endl;

	try {
		
		easyfind(vectorNumbers1, 4);
		
	} catch ( const ElementNotFoundException& e ) {
		
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	std::cout  << std::endl;
	std::cout << YL << "	# Test List #	" << std::endl << std::endl;
	
	std::list<int> listNumbers1;
	std::list<int>::iterator it;

	for( unsigned int i = 0; i < 10; i++ ) {
		
		listNumbers1.push_back(i);
	}
	for( it = listNumbers1.begin() ; it != listNumbers1.end(); it++ ) {
		
		std::cout << *it << " ";
	}

	std::cout  << std::endl;
	
	try {
		
		easyfind(numbers1, 6);
	} catch ( const ElementNotFoundException& e ) {
		
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	return 0;
}

