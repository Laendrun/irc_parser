/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IrcParser.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:06:02 by saeby             #+#    #+#             */
/*   Updated: 2023/06/16 14:49:34 by saeby            ###   ########.fr       */
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

		Request	parse(std::string message);
};

#endif