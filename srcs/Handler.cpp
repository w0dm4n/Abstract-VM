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

void Handler::Salope(std::vector<std::string> line)
{
	std::cout << "Bonjour ! je veux push une valeur" << std::endl;
}

void Handler::initActions()
{
	this->actions.push_back(new Action("push", &Handler::Salope));
}

void Handler::Process(std::vector<std::string> line)
{
	std::string action = line[0];
	std::cout << action << std::endl;
	for (int i = 0; i < this->actions.size(); i++)
	{
		if (action == this->actions[i]->name) {
			this->actions[i]->func(line);
		}
	}
}
