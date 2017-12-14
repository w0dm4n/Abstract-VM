/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handler.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:26:59 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/13 15:27:01 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Handler.hpp"

Handler::Handler()
{
	this->initActions();
}

Handler::Handler ( Handler const & src )
{
	*this = src;
}

Handler &				Handler::operator=( Handler const & rhs )
{
	return (*this);
}

Handler::~Handler ()
{
	for (int i = 0; i < this->actions.size(); i++)
		delete this->actions[i];
}

std::ostream &				operator<<(std::ostream & o, Handler const & i)
{
	return (o);
}

void Handler::initActions()
{
	this->actions.push_back(new Action("push", &Push::Handle));
	this->actions.push_back(new Action("pop", &Pop::Handle));
	this->actions.push_back(new Action("dump", &Dump::Handle));
}

void Handler::Process(std::vector<std::string> line)
{
	std::string	action = line[0];
	bool		handler_found = false;
	for (int i = 0; i < this->actions.size(); i++)
	{
		if (action == this->actions[i]->name) {
			handler_found = true;
			this->actions[i]->func(line, this);
		}
	}
	if (!handler_found)
		throw UnknownInstructionGiven();
}
