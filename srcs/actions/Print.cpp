/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:02:35 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/14 16:02:43 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions/Print.hpp"
#include "Handler.hpp"

void Print::Handle(std::vector<std::string> line, Handler *handler)
{
  if (!handler->stack.empty())
  {
    const IOperand *top = handler->stack.top().get();
    if (top->getType() == eOperandType::Int8)
    {
      Operand<int8_t> const *operand = static_cast<const Operand<int8_t>*>(top);
      std::cout << operand->getValue() << std::endl;
    }
    else
      throw Not8BitInteger();
  }
  else
    throw PrintEmptyStack();
	(void)line;
}
