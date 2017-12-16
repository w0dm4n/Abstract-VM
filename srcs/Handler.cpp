/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handler.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:26:59 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/15 09:57:15 by dmoureu-         ###   ########.fr       */
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
	this->actions.push_back(new Action("add", &Add::Handle));
	this->actions.push_back(new Action("sub", &Sub::Handle));
	this->actions.push_back(new Action("mul", &Mul::Handle));
	this->actions.push_back(new Action("div", &Div::Handle));
	this->actions.push_back(new Action("mod", &Mod::Handle));
	this->actions.push_back(new Action("assert", &Assert::Handle));
	this->actions.push_back(new Action("print", &Print::Handle));
	this->actions.push_back(new Action("mov", &Mov::Handle));
	this->actions.push_back(new Action("swap", &Swap::Handle));
}

void Handler::Process(std::vector<std::string> line)
{
	std::string	action = line[0];
	if (action.length() == 0)
		return ;
	bool		handler_found = false;
	for (int i = 0; i < this->actions.size(); i++)
	{
		if (action == this->actions[i]->name) {
			handler_found = true;
			this->actions[i]->func(line, this);
		}
		else if (action == EOP)
			exit(0);
	}
	if (!handler_found)
		throw UnknownInstructionGiven();
}
