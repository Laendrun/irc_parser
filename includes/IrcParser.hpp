/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IrcParser.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:06:02 by saeby             #+#    #+#             */
/*   Updated: 2023/06/24 19:06:39 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRCPARSER_HPP
# define IRCPARSER_HPP
# include "Request.hpp"
# include <vector>
# include <iostream>

class Request;

class IrcParser
{
	public : 
		IrcParser(void);

		std::vector<Request>		parse(std::string message);
		std::vector<std::string>	split(std::string& og_message);

	private:
		std::string	_parsePrefix(std::string message, Request& req);
		std::string	_parseCmd(std::string messsage, Request& req);
		std::string	_parseParams(std::string message, Request& req);
		std::string	_parseMiddle(std::string message, Request& req);
};

#endif