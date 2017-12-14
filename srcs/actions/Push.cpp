#include "actions/Push.hpp"
#include "OperandFactory.hpp"
#include "Handler.hpp"

void Push::Int8(std::vector<std::string> number, Handler *handler)
{
	OperandFactory factory;
	IOperand const *operand = factory.createOperand(eOperandType::Int8, number[0]);
	Operand<int8_t> const *cast = static_cast<const Operand<int8_t>*>(operand);

	std::cout << "VALUE: " << cast->getValue() << std::endl;
  handler->stack.push(std::shared_ptr<const IOperand>(cast));

	IOperand const *top = handler->stack.top().get();
	Operand<int8_t> const *test = static_cast<const Operand<int8_t>*>(top);
	std::cout << "VALUE FROM THE STACK: " << test->getValue() << std::endl;
	//std::cout << As.top().get()->getType() << std::endl;

	//handler->stack.push(std::shared_ptr<Element>(cast));
	//std::cout << operand->getType() << std::endl;
}

void Push::Int16(std::vector<std::string> number, Handler *handler)
{
	std::cout << "Int16 with value: " << number[0] << std::endl;
}

void Push::Int32(std::vector<std::string> number, Handler *handler)
{
	std::cout << "Int32 with value: " << number[0] << std::endl;
}

void Push::Double(std::vector<std::string> number, Handler *handler)
{
	std::cout << "Double with value: " << number[0] << std::endl;
}

void Push::Float(std::vector<std::string> number, Handler *handler)
{
	std::cout << "Float with value: " << number[0] << std::endl;
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
				number.push_back(std::to_string(std::stoi(split[1])));
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
