/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IrcParser.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:07:01 by saeby             #+#    #+#             */
/*   Updated: 2023/06/16 17:45:51 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IrcParser.hpp"

IrcParser::IrcParser(void) {}

// <message> ::= [':' <prefix> <SPACE>] <command> <params> <crlf>
// <prefix> ::= <servername> | <nick> ['!' <user>] ['@'<host>]
// <command> ::= <letter> {<letter>} | <number> <number> <number>
// <SPACE> ::= ' ' {' '}
// <params> ::= <SPACE> [':' <trailing> | <middle> <params>]
// <middle> ::= <Any *non-empty* sequence of octets not including SPACE or NUL or CR or LF, the first of which may not be ':'>
// <trailing> ::= <Any, possibly *empty*, sequence of octets not including NUL or CR or LF>

Request IrcParser::parse(std::string message)
{
	std::cout << "Parsing: " << message << std::endl;

	Request	req;
	int		i = 0;

	req.og = message;
	if (message.back() == '\r')
		message.erase(message.end() - 1);

	if (message[i] == ' ' || !message[i])
	{
		req.valid = false;
		return (req);
	}

	// prefix before cmd
	if (message[i] == ':')
		message = this->_parsePrefix(message, req);
	
	message = this->_parseCmd(message, req);
	message = this->_parseParams(message, req);

	return (req);
}

// <prefix> ::= <servername> | <nick> ['!' <user>] ['@'<host>]
std::string	IrcParser::_parsePrefix(std::string message, Request& req)
{
	std::string	ret = "";
	int			i = 0;

	message.erase(message.begin());
	while (message[i] != ' ')
		i++;
	req.prefix = message.substr(0, i);
	ret = message.substr(i + 1, message.length());
	return (ret);
}

// <command> ::= <letter> {<letter>} | <number> <number> <number>
std::string IrcParser::_parseCmd(std::string message, Request& req)
{
	std::string	ret = "";
	int			i = 0;

	while (message[i] != ' ')
		i++;
	req.cmd = message.substr(0, i);
	ret = message.substr(i + 1, message.length());
	return (ret);
}

// <params> ::= <SPACE> [':' <trailing> | <middle> <params>]
std::string	IrcParser::_parseParams(std::string message, Request& req)
{
	int	i = 0, j = 0;

	// <SPACE>
	while (message[i] && message[i] == ' ')
		i++;

	while (message[i] && message[i] != ':')
	{
		while (message[i] && message[i] == ' ')
			i++;
		j = i;
		while (message[i] && message[i] != ' ')
			i++;
		if (message[j] && i <= (int) message.length())
		{
			req.params.push_back(message.substr(j, i - j));
			req.param_count++;
		}
		i++;
	}
	if (message[i] == ':')
	{
		message.erase(message.begin());
		req.trailing = message.substr(i, message.length());
	}

	return (message);
}
