/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mov.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:54:12 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/16 14:54:33 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions/Mov.hpp"
#include "Handler.hpp"

void Mov::Handle(std::vector<std::string> line, Handler *handler)
{
	if (line.size() == 2)
	{
		size_t value = std::stoi(line[1]);
		if (value < handler->stack.size())
		{
			for (size_t i = 0; i < value; i++)
				handler->stack.pop();
		}
		else
			throw WrongValueOnMovInstruction();
	}
	else
		throw WrongValueOnMovInstruction();
}
