/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:12:55 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/12 15:12:57 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser ()
{
	return ;
}

Parser::Parser ( Parser const & src )
{
	*this = src;
}

Parser &				Parser::operator=( Parser const & rhs )
{
	return (*this);
}

Parser::~Parser ()
{
	return ;
}

std::ostream &				operator<<(std::ostream & o, Parser const & i)
{
	return (o);
}

void Parser::ParseEntry(std::vector<std::string> lines)
{
	std::vector<std::string>		datas;
	Handler							handler;
	for (int i = 0; i < lines.size(); i++)
	{
		datas = Utils::split(lines[i], ESCAPE_CHAR);
		if (datas.size() > 0) {
			handler.Process(datas);
		}
		else {
			// throw error
		}
	}
}
