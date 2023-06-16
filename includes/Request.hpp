/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:10:00 by saeby             #+#    #+#             */
/*   Updated: 2023/06/16 16:40:27 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REQUEST_HPP
# define REQUEST_HPP
# include <iostream>
# include <vector>

class Request
{
	public:
		Request(void);

		bool						valid;
		std::string					og;
		std::string					prefix;
		std::string					cmd;
		std::vector<std::string>	params;
		int							param_count;
		std::string					middle;
		std::string					trailing;
};

std::ostream	&operator<<(std::ostream& o, const Request& req);

#endif