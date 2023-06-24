/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:17:32 by saeby             #+#    #+#             */
/*   Updated: 2023/06/24 19:14:40 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IrcParser.hpp"

int main(void)
{
	IrcParser				parser;
	std::vector<Request>	reqs;

	// req = parser.parse(":laendrun!laendrun@localhost JOIN #bar,#foo another param :some trailing action going on\r\n");
	// req = parser.parse("JOIN #bar maybe :trailing action\r\n");
	// reqs = parser.parse("USER amy * * :Amy Pond\r\n");
	reqs = parser.parse("CAP LS\r\nNICK laendrun\r\nUSER laendrun laendrun localhost :Simon Aeby\r\n");

	for (unsigned int i = 0; i < reqs.size(); i++)
		std::cout << reqs[i] << std::endl;

}


// :laendrun!laendrun@localhost 