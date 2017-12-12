/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:57:42 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/12 17:57:47 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operand.hpp"

template <>
Operand<int>::Operand (eOperandType type) : type(type)
{
	std::cout << "Bonjour" << std::endl;
	return ;
}
