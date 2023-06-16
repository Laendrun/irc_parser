/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IrcParser.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:06:02 by saeby             #+#    #+#             */
/*   Updated: 2023/06/16 16:42:32 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRCPARSER_HPP
# define IRCPARSER_HPP
# include "Request.hpp"
# include <iostream>

class Request;

class IrcParser
{
	public : 
		IrcParser(void);

		Request		parse(std::string message);

	private:
		std::string	_parsePrefix(std::string message, Request& req);
		std::string	_parseCmd(std::string messsage, Request& req);
		std::string	_parseParams(std::string message, Request& req);
		std::string	_parseMiddle(std::string message, Request& req);
};

#endif