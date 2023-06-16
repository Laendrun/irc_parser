/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IrcParser.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:07:01 by saeby             #+#    #+#             */
/*   Updated: 2023/06/16 15:09:58 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IrcParser.hpp"

IrcParser::IrcParser(void) {}

Request IrcParser::parse(std::string message)
{
	Request	req;
	int		i = 0, j = 0;


	if (message[i] == ' ' || !message[i])
	{
		req.valid = false;
		return (req);
	}

	while (message[i])
	{
		if (message[i] == ' ')
		{
			req.params.push_back(message.substr(j, i - j));
			while (message[i] == ' ')
				i++;
			j = i;
		}
		if (message[i] == ':')
		{
			req.params.push_back(message.substr(i + 1, message.length() - i));
			req.cmd = req.params[0];
			req.params.erase(req.params.begin());
			return (req);
		}
		i++;
	}

	if (i && message[j])
		req.params.push_back(message.substr(j, i - j));
	req.cmd = req.params[0];
	req.params.erase(req.params.begin());
	return (req);
}