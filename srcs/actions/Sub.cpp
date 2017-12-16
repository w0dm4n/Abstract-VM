/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 02:39:07 by dmoureu-          #+#    #+#             */
/*   Updated: 2017/12/15 08:08:11 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions/Sub.hpp"
#include "OperandFactory.hpp"
#include "Handler.hpp"

void Sub::Handle(std::vector<std::string> line, Handler *handler)
{
	if (handler->stack.size() < 2)
		throw SubStackTooSmall("Trying to substract a too small stack");

	OperandFactory factory;

	IOperand const *first = handler->stack.top().get();
	IOperand const *clearFirst = factory.createOperand(first->getType(), first->toString());
	handler->stack.pop();

	IOperand const *second = handler->stack.top().get();
	IOperand const *clearSecond = factory.createOperand(second->getType(), second->toString());
	handler->stack.pop();

	IOperand const *result = *clearFirst - *clearSecond;

	handler->stack.push(std::shared_ptr<const IOperand>(result));
}
