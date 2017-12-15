/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Assert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:02:35 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/15 09:55:54 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions/Assert.hpp"
#include "Handler.hpp"

void Assert::Handle(std::vector<std::string> line, Handler *handler)
{
	if (!handler->stack.empty())
	{
		Handler *try_handler = new Handler();
		Push::Handle(line, try_handler);
		if (try_handler->stack.empty()){
			throw NotEqualsOnTheStackAssert();
		}
		IOperand const *top = handler->stack.top().get();
		IOperand const *top_new = try_handler->stack.top().get();
		if (top_new->getType() != top->getType()) {
			throw NotEqualsOnTheStackAssert();
		}
		switch (top_new->getType())
		{
			case eOperandType::Int8:
			{
				Operand<int8_t> const *operand = static_cast<const Operand<int8_t>*>(top);
				Operand<int8_t> const *operand_new = static_cast<const Operand<int8_t>*>(top_new);

				if (operand->getValue() != operand_new->getValue()) {
					throw NotEqualsOnTheStackAssert();
				}
				break;
			}

			case eOperandType::Int16:
			{
				Operand<int16_t> const *operand = static_cast<const Operand<int16_t>*>(top);
				Operand<int16_t> const *operand_new = static_cast<const Operand<int16_t>*>(top_new);

				if (operand->getValue() != operand_new->getValue()) {
					throw NotEqualsOnTheStackAssert();
				}
				break;
			}

			case eOperandType::Int32:
			{
				Operand<int32_t> const *operand = static_cast<const Operand<int32_t>*>(top);
				Operand<int32_t> const *operand_new = static_cast<const Operand<int32_t>*>(top_new);

				if (operand->getValue() != operand_new->getValue()) {
					throw NotEqualsOnTheStackAssert();
				}
				break;
			}

			case eOperandType::Float:
			{
				Operand<float> const *operand = static_cast<const Operand<float>*>(top);
				Operand<float> const *operand_new = static_cast<const Operand<float>*>(top_new);

				if (operand->getValue() != operand_new->getValue()) {
					throw NotEqualsOnTheStackAssert();
				}
				break;
			}

			case eOperandType::Double:
			{
				Operand<double> const *operand = static_cast<const Operand<double>*>(top);
				Operand<double> const *operand_new = static_cast<const Operand<double>*>(top_new);

				if (operand->getValue() != operand_new->getValue()) {
					throw NotEqualsOnTheStackAssert();
				}
				break;
			}
		}
		delete try_handler;
	} else {
		throw NotEqualsOnTheStackAssert();
	}
}
