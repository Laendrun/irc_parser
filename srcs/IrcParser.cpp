/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IrcParser.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:07:01 by saeby             #+#    #+#             */
/*   Updated: 2023/06/24 19:15:03 by saeby            ###   ########.fr       */
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


// should return a list of Request(s)
std::vector<Request> IrcParser::parse(std::string message)
{
	std::vector<Request>	ret_vec;

	// split the request on /r/n and loop over the given number of messages
	std::vector<std::string>	messages = this->split(message);

	for (unsigned int i = 0; i < messages.size(); i++)
	{
		Request	req;
		int		j = 0;

		req.og = messages[i];
		if (messages[i].back() == '\r')
			messages[i].erase(messages[i].end() - 1);

		if (messages[i][j] == ' ' || !messages[i][j])
		{
			req.valid = false;
			ret_vec.push_back(req);
			continue;
		}

		// prefix before cmd
		if (messages[i][j] == ':')
			messages[i] = this->_parsePrefix(messages[i], req);

		messages[i] = this->_parseCmd(messages[i], req);
		messages[i] = this->_parseParams(messages[i], req);
		ret_vec.push_back(req);
	}

	return (ret_vec);
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

std::vector<std::string> IrcParser::split(std::string& og_message)
{
	std::vector<std::string>	ret_vec;
	std::string					delim = "\r\n";
	size_t						pos = 0;

	std::string token;
	while ((pos = og_message.find(delim)) != std::string::npos) {
		token = og_message.substr(0, pos);
		ret_vec.push_back(token);
		og_message.erase(0, pos + delim.length());
	}
	return (ret_vec);
}
