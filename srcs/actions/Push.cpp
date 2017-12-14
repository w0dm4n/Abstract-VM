#include "actions/Push.hpp"
#include "OperandFactory.hpp"
#include "Handler.hpp"

void Push::Int8(std::vector<std::string> number, Handler *handler)
{
	OperandFactory factory;
	IOperand const *operand = factory.createOperand(eOperandType::Int8, number[0]);
  	handler->stack.push(std::shared_ptr<const IOperand>(operand));
}

void Push::Int16(std::vector<std::string> number, Handler *handler)
{
	OperandFactory factory;
	IOperand const *operand = factory.createOperand(eOperandType::Int16, number[0]);
  	handler->stack.push(std::shared_ptr<const IOperand>(operand));
}

void Push::Int32(std::vector<std::string> number, Handler *handler)
{
	OperandFactory factory;
	IOperand const *operand = factory.createOperand(eOperandType::Int32, number[0]);
  	handler->stack.push(std::shared_ptr<const IOperand>(operand));
}

void Push::Double(std::vector<std::string> number, Handler *handler)
{
	OperandFactory factory;
	IOperand const *operand = factory.createOperand(eOperandType::Double, number[0]);
  	handler->stack.push(std::shared_ptr<const IOperand>(operand));
}

void Push::Float(std::vector<std::string> number, Handler *handler)
{
	OperandFactory factory;
	IOperand const *operand = factory.createOperand(eOperandType::Float, number[0]);
  	handler->stack.push(std::shared_ptr<const IOperand>(operand));
}

std::string Push::clearNumber(std::string number)
{
	std::string value;

	for (int i = 0; i < number.length() && number[i] != END_NUMBER; i++)
		value += number[i];
	return value;
}

void Push::Handle(std::vector<std::string> line, Handler *handler)
{
	std::vector<Action*>					actions;
	std::vector<std::string>				number;

	actions.push_back(new Action("int8", &Push::Int8));
	actions.push_back(new Action("int16", &Push::Int16));
	actions.push_back(new Action("int32", &Push::Int32));
	actions.push_back(new Action("double", &Push::Double));
	actions.push_back(new Action("float", &Push::Float));
	if (line.size() == 2)
	{
		char *value = (char*)line[1].c_str();
		if (strchr(value, START_NUMBER) && strchr(value, END_NUMBER))
		{
			std::vector<std::string> split = Utils::split(line[1], START_NUMBER);
			if (split.size() == 2)
			{
				std::string type = split[0]; // var type
				number.push_back(Push::clearNumber(split[1]));
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
