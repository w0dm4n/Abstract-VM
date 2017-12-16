/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandTemplate.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:56:51 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/15 09:17:41 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operand.hpp"

#ifndef OPERAND_TEMPLATE
#define OPERAND_TEMPLATE

template <class T>
Operand<T>::Operand ( Operand const & src )
{
	*this = src;
}

template <class T>
Operand<T> &				Operand<T>::operator=( Operand const & rhs )
{
	(void)rhs;
	return (*this);
}

template <class T>
std::ostream &				operator<<(std::ostream & o, Operand<T> const & i)
{
	(void)i;
	return (o);
}

template <class T>
Operand<T>::Operand ()
{
	return ;
}

template <class T>
int Operand<T>::getPrecision() const
{
	return 0;
}

template <class T>
eOperandType Operand<T>::getType() const
{
	return (this->type);
}

template <class T>
std::string const & Operand<T>::toString( void ) const
{
	std::string const *line;

	line = new std::string(std::to_string(this->value));
	return (*line);
}

template <class T>
T Operand<T>::getValue() const
{
	return this->value;
}

template <class T>
Operand<T>::~Operand ()
{
	return ;
}

template <class T>
Operand<T>::Operand (eOperandType type, std::string const &value) : type(type)
{
	(void)value;
}

template <class T>
IOperand const * Operand<T>::operator+( IOperand const & rhs ) const
{
	double			value = (stod(this->toString()) + stod(rhs.toString()));
	eOperandType	bestType = this->getType();

	if (rhs.getType() > bestType)
		bestType = rhs.getType();

	Operand<T> *operand = new Operand(bestType, std::to_string(value));
	return (operand);
}

template <class T>
IOperand const * Operand<T>::operator-( IOperand const & rhs ) const
{
	double			value = (stod(this->toString()) - stod(rhs.toString()));
	eOperandType	bestType = this->getType();

	if (rhs.getType() > bestType)
		bestType = rhs.getType();

	Operand<T> *operand = new Operand(bestType, std::to_string(value));
	return (operand);
}

template <class T>
IOperand const * Operand<T>::operator*( IOperand const & rhs ) const
{
	double			value = (stod(this->toString()) * stod(rhs.toString()));
	eOperandType	bestType = this->getType();

	if (rhs.getType() > bestType)
		bestType = rhs.getType();

	Operand<T> *operand = new Operand(bestType, std::to_string(value));
	return (operand);
}

template <class T>
IOperand const * Operand<T>::operator/( IOperand const & rhs ) const
{
	double			value = (stod(this->toString()) / stod(rhs.toString()));
	eOperandType	bestType = this->getType();

	if (rhs.getType() > bestType)
		bestType = rhs.getType();

	Operand<T> *operand = new Operand(bestType, std::to_string(value));
	return (operand);
}

template <class T>
IOperand const * Operand<T>::operator%( IOperand const & rhs ) const
{
	double			value = fmod(stod(this->toString()),stod(rhs.toString()));
	eOperandType	bestType = this->getType();

	if (rhs.getType() > bestType)
		bestType = rhs.getType();

	Operand<T> *operand = new Operand(bestType, std::to_string(value));
	return (operand);
}

#endif
