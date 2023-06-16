/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:17:32 by saeby             #+#    #+#             */
/*   Updated: 2023/06/16 14:54:56 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IrcParser.hpp"

int main(void)
{
	IrcParser	parser;
	Request		req;

	req = parser.parse(":laendrun!laendrun@localhost JOIN #bar");
	
	if (req.valid)
		std::cout << req.cmd << std::endl;
	else
		std::cerr << "Invalid request" << std::endl;
}


// :laendrun!laendrun@localhost 