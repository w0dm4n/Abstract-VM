/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:10:13 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/16 15:10:31 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions/Swap.hpp"
#include "Handler.hpp"

void Swap::Handle(std::vector<std::string> line, Handler *handler)
{
	std::stack <std::shared_ptr<const IOperand>> new_stack;
	while (!handler->stack.empty())
	{
		std::shared_ptr<const IOperand> top = handler->stack.top();
		new_stack.push(top);
		handler->stack.pop();
	}
	handler->stack.swap(new_stack);
}
