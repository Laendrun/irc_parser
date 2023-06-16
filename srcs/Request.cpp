/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:16:15 by saeby             #+#    #+#             */
/*   Updated: 2023/06/16 17:15:22 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Request.hpp"

Request::Request(void) : valid(true), og(""), prefix(""), cmd(""), params(), param_count(0), middle(""), trailing("") {}

std::ostream& operator<<(std::ostream &o, const Request &r)
{
	o << "===========================" << std::endl;
	o << "OG: " << r.og << std::endl;
	o << "VALID: " << (r.valid ? "true" : "false") << std::endl;
	if (!r.prefix.empty())
		o << "PREFIX:" << r.prefix << std::endl;
	o << "COMMAND: " << r.cmd << std::endl;
	for (int i = 0; i < r.param_count; i++)
		o << "PARAM #" << i << ": " << r.params[i] << std::endl;
	if (!r.middle.empty())
		o << "MIDDLE: " << r.middle << std::endl;
	if (!r.trailing.empty())
		o << "TRAILING: " << r.trailing << std::endl;
	o << "===========================";
	return (o);
}
