/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgejno <vgejno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:39:54 by vgejno            #+#    #+#             */
/*   Updated: 2023/08/24 18:00:40 by vgejno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define  EASYFIND_HPP

#include <array>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <exception>

class ElementNotFoundException : public std::exception {
	
	public:
	
		const char* what() const throw() {
			
			return "Element not found in container";
		}
};

template< typename T > //container of integers
void easyfind( T &container, int num ) {
	
	typename T::iterator it = std::find( container.begin(), container.end(), num ); 
		
	if( it != container.end()) {
		
		std::cout << "Element found: " << num << std::endl;
		return;
	} else {
		
		throw ElementNotFoundException();
		// std::cout << "Element " << num << " not found" << std::endl; 
	}
};


#endif
