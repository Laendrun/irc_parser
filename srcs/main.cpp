/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:17:32 by saeby             #+#    #+#             */
/*   Updated: 2023/06/16 17:44:02 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IrcParser.hpp"

int main(void)
{
	IrcParser	parser;
	Request		req;

	// req = parser.parse(":laendrun!laendrun@localhost JOIN #bar,#foo another param :some trailing action going on\r");
	// req = parser.parse("JOIN #bar maybe :trailing action\r");
	req = parser.parse("USER amy * * :Amy Pond");
	
	if (req.valid)
		std::cout << req << std::endl;
	else
		std::cerr << "Invalid request" << std::endl;

}


// :laendrun!laendrun@localhost 