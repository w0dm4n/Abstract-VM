/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:57:42 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/15 12:00:18 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operand.hpp"

template <>
Operand<int8_t>::Operand (eOperandType type, std::string const& value) : type(type)
{
	double	val = stod(value);

	if (val < INT8_MIN || val > INT8_MAX)
		throw OperandOverflow();
	this->value = stoi(value);
}

template <>
Operand<int16_t>::Operand (eOperandType type, std::string const& value) : type(type)
{
	double	val = stod(value);
	if (val < INT16_MIN || val > INT16_MAX)
		throw OperandOverflow();
	this->value = stoi(value);
}

template <>
Operand<int32_t>::Operand (eOperandType type, std::string const& value) : type(type)
{
	double	val = stod(value);
	if (val < INT32_MIN || val > INT32_MAX)
		throw OperandOverflow();
	this->value = stoi(value);
}

template <>
Operand<float>::Operand (eOperandType type, std::string const& value) : type(type)
{
	double val = stod(value);
	if (val < FLT_MIN || val > FLT_MAX)
		throw OperandOverflow();
	this->value = stof(value);
}

template <>
Operand<double>::Operand (eOperandType type, std::string const& value) : type(type)
{
	double val = stold(value);
	if (val < DBL_MIN || val > DBL_MAX)
		throw OperandOverflow();
	this->value = stof(value);
}
