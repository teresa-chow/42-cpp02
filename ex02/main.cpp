/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <tchow-so@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:35:20 by tchow-so          #+#    #+#             */
/*   Updated: 2025/09/12 09:37:41 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

	std::cout << "--- Test shown in subject: ---\n";
	Fixed	a;
	Fixed	const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "\n\n-------- Other tests: --------\n";
	// parametrized constructors
	Fixed c(3.14f);
	Fixed d(2);
	// copy constructor
	Fixed e(d);
	std::cout << "Values:\n";
	std::cout << "\tc: " << c << "\n\td: " << d << "\n\te (copy of c): " << e << "\n\n";
	// comparison op overload
	if (c > d) { std::cout << "c (" << c << ") \033[0;36mis greater than\033[0m d (" << d << ")\n"; }
	if (d < c) { std::cout << "d (" << d << ") \033[0;36mis smaller than\033[0m c (" << c << ")\n"; }
	if (c >= d) { std::cout << "c (" << c << ") \033[0;36mis greater than or equal to\033[0m d (" << d << ")\n"; }
	if (d <= c) { std::cout << "d (" << d << ") \033[0;36mis smaller than or equal to\033[0m c (" << c << ")\n"; }
	if (d == e) { std::cout << "d (" << d << ") \033[0;36mis equal to\033[0m e (" << e << ")\n"; }
	if (d != c) { std::cout << "d (" << d << ") \033[0;36mis not equal to\033[0m c (" << c << ")\n\n"; }
	// arithmetic op overload
	std::cout << "c (" << c << ") \033[0;36mplus\033[0m d (" << d << ") \033[0;36mis equal to\033[0m " << c + d << "\n";
	std::cout << "c (" << c << ") \033[0;36mminus\033[0m d (" << d << ") \033[0;36mis equal to\033[0m " << c - d << "\n";
	std::cout << "c (" << c << ") \033[0;36mtimes\033[0m d (" << d << ") \033[0;36mis equal to\033[0m " << c * d << "\n";
	std::cout << "c (" << c << ") \033[0;36mdivided by\033[0m d (" << d << ") \033[0;36mis equal to\033[0m " << c / d << "\n\n";
	// inc ++ and dec -- op overload
	std::cout << "\033[0;36mvalue at start:\033[0m c = " << c << "\n\033[0;36mvalue returned:\033[0m ++c = \033[0;33m"
		<< ++c << "\033[0m\n\033[0;36mvalue after increment:\033[0m c = \033[0;33m" << c << "\033[0m\n\n";
	std::cout << "\033[0;36mvalue at start:\033[0m c = \033[0;33m" << c << "\033[0m\n\033[0;36mvalue returned:\033[0m c++ = \033[0;33m"
		<< c++ << "\033[0m\n\033[0;36mvalue after increment:\033[0m c = " << c << "\n\n";
	std::cout << "\033[0;36mvalue at start:\033[0m d = " << d << "\n\033[0;36mvalue returned:\033[0m --d = \033[0;33m"
		<< --d << "\033[0m\n\033[0;36mvalue after decrement:\033[0m d = \033[0;33m" << d << "\033[0m\n\n";
	std::cout << "\033[0;36mvalue at start:\033[0m d = \033[0;33m" << d << "\033[0m\n\033[0;36mvalue returned:\033[0m d-- = \033[0;33m"
		<< d-- << "\033[0m\n\033[0;36mvalue after decrement:\033[0m d = " << d << "\n\n";
	return 0;
}