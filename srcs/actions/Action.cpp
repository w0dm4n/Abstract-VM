/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Action.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:17:49 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/13 15:17:51 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions/Action.hpp"

Action::Action ()
{
	return ;
}

Action::Action(std::string name, void(*foo)(std::vector<std::string>))
{
	this->name = name;
	this->func = foo;
}

Action::Action ( Action const & src )
{
	*this = src;
}

Action &				Action::operator=( Action const & rhs )
{
	return (*this);
}

Action::~Action ()
{
	return ;
}

std::ostream &				operator<<(std::ostream & o, Action const & i)
{
	return (o);
}
