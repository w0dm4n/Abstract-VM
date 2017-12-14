/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pop.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:02:35 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/14 16:02:43 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions/Pop.hpp"
#include "Handler.hpp"

void Pop::Handle(std::vector<std::string> line, Handler *handler)
{
	if (!handler->stack.empty())
	{
		handler->stack.pop();
	}
	else {
		throw PopOnEmptyStack();
	}
}
