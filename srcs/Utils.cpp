/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:42:59 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/12 15:43:01 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include "interfaces/IOperand.hpp"

Utils::Utils ()
{
	return ;
}

Utils::Utils ( Utils const & src )
{
	*this = src;
}

Utils &				Utils::operator=( Utils const & rhs )
{
	(void)rhs;
	return (*this);
}

Utils::~Utils ()
{
	return ;
}

std::ostream &				operator<<(std::ostream & o, Utils const & i)
{
	(void)i;
	return (o);
}

template<typename Out>
void Utils::split(const std::string &s, char delim, Out result) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}

std::vector<std::string> Utils::split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	Utils::split(s, delim, std::back_inserter(elems));
	return elems;
}
