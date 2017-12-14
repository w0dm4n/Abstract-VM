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
Operand<int32_t>::Operand (eOperandType type, std::string const& value) : type(type)
{
	this->value = stoi(value);
}

template <>
Operand<int8_t>::Operand (eOperandType type, std::string const& value) : type(type)
{
	this->value = stoi(value);
}

template <>
Operand<int16_t>::Operand (eOperandType type, std::string const& value) : type(type)
{
	this->value = stoi(value);
}

template <>
Operand<float>::Operand (eOperandType type, std::string const& value) : type(type)
{
	this->value = stof(value);
}

template <>
Operand<double>::Operand (eOperandType type, std::string const& value) : type(type)
{
	this->value = stod(value);
}
