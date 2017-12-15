/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dump.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:32:42 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/15 08:44:34 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions/Dump.hpp"
#include "Handler.hpp"
#include "actions/Push.hpp"

std::ostream & operator<<(std::ostream & os, std::stack <std::shared_ptr<const IOperand>> stack)
{
    Handler handler_cpy;
    handler_cpy.stack.swap(stack);
    Push::reverse_stack(&handler_cpy);
    while (!handler_cpy.stack.empty())
    {
		IOperand const *top = handler_cpy.stack.top().get();

		switch (top->getType())
		{
			case eOperandType::Int8:
			{
				Operand<int8_t> const *operand = static_cast<const Operand<int8_t>*>(top);
				os << operand->getValue() << std::endl;
				break;
			}

			case eOperandType::Int16:
			{
				Operand<int16_t> const *operand = static_cast<const Operand<int16_t>*>(top);
				os << operand->getValue() << std::endl;
				break;
			}

			case eOperandType::Int32:
			{
				Operand<int32_t> const *operand = static_cast<const Operand<int32_t>*>(top);
				os << operand->getValue() << std::endl;
				break;
			}

			case eOperandType::Float:
			{
				Operand<float> const *operand = static_cast<const Operand<float>*>(top);
				os << operand->getValue() << std::endl;
				break;
			}

			case eOperandType::Double:
			{
				Operand<double> const *operand = static_cast<const Operand<double>*>(top);
				os << operand->getValue() << std::endl;
				break;
			}
		}
        handler_cpy.stack.pop();
    }
    return os;
}

void Dump::Handle(std::vector<std::string> line, Handler *handler)
{
	std::cout << handler->stack << std::endl;
}
