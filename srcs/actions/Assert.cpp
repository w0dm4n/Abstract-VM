/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Assert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 08:22:17 by dmoureu-          #+#    #+#             */
/*   Updated: 2017/12/15 09:12:57 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions/Assert.hpp"
#include "OperandFactory.hpp"
#include "Handler.hpp"

void Assert::Int8(std::vector<std::string> number, Handler *handler)
{
	OperandFactory factory;
	IOperand const *operand = factory.createOperand(eOperandType::Int8, number[0]);
  	//handler->stack.push(std::shared_ptr<const IOperand>(operand));

	IOperand const *first = handler->stack.top().get();
	if (first->getType() == eOperandType::Int8)
		if (first->toString() == operand->toString())
			return;
	throw AssertNotEqual();
}

void Assert::Int16(std::vector<std::string> number, Handler *handler)
{
	OperandFactory factory;
	IOperand const *operand = factory.createOperand(eOperandType::Int16, number[0]);
  	//handler->stack.push(std::shared_ptr<const IOperand>(operand));
	IOperand const *first = handler->stack.top().get();
	if (first->getType() == eOperandType::Int16)
		if (first->toString() == operand->toString())
			return;
	throw AssertNotEqual();
}

void Assert::Int32(std::vector<std::string> number, Handler *handler)
{
	OperandFactory factory;
	IOperand const *operand = factory.createOperand(eOperandType::Int32, number[0]);
  	//handler->stack.push(std::shared_ptr<const IOperand>(operand));
	IOperand const *first = handler->stack.top().get();
	if (first->getType() == eOperandType::Int32)
		if (first->toString() == operand->toString())
			return;
	throw AssertNotEqual();
}

void Assert::Double(std::vector<std::string> number, Handler *handler)
{
	OperandFactory factory;
	IOperand const *operand = factory.createOperand(eOperandType::Double, number[0]);
  	//handler->stack.push(std::shared_ptr<const IOperand>(operand));
	IOperand const *first = handler->stack.top().get();
	if (first->getType() == eOperandType::Double)
		if (first->toString() == operand->toString())
			return;
	throw AssertNotEqual();
}

void Assert::Float(std::vector<std::string> number, Handler *handler)
{
	OperandFactory factory;
	IOperand const *operand = factory.createOperand(eOperandType::Float, number[0]);
  	//handler->stack.push(std::shared_ptr<const IOperand>(operand));
	IOperand const *first = handler->stack.top().get();
	if (first->getType() == eOperandType::Float)
		if (first->toString() == operand->toString())
			return;
	throw AssertNotEqual();
}

std::string Assert::clearNumber(std::string number)
{
	std::string value;

	for (int i = 0; i < number.length() && number[i] != END_NUMBER; i++)
		value += number[i];
	return value;
}

void Assert::Handle(std::vector<std::string> line, Handler *handler)
{
	if (handler->stack.size() < 1)
		throw AssertEmptyStack();

	std::vector<Action*>					actions;
	std::vector<std::string>				number;

	actions.push_back(new Action("int8", &Assert::Int8));
	actions.push_back(new Action("int16", &Assert::Int16));
	actions.push_back(new Action("int32", &Assert::Int32));
	actions.push_back(new Action("double", &Assert::Double));
	actions.push_back(new Action("float", &Assert::Float));
	if (line.size() == 2)
	{
		char *value = (char*)line[1].c_str();
		if (strchr(value, START_NUMBER) && strchr(value, END_NUMBER))
		{
			std::vector<std::string> split = Utils::split(line[1], START_NUMBER);
			if (split.size() == 2)
			{
				std::string type = split[0]; // var type
				number.push_back(Assert::clearNumber(split[1]));
				for (int i = 0; i < actions.size(); i++)
				{
					if (actions[i]->name == type)
						actions[i]->func(number, handler);
				}
			}
			else {
				// throw error
			}
		}
	}
	else
	{
		// throw error
	}
	for (int i = 0; i < actions.size(); i++)
		delete actions[i];
}
