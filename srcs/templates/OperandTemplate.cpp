/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandTemplate.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:56:51 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/12 17:56:57 by frmarinh         ###   ########.fr       */
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
	return (*this);
}

template <class T>
std::ostream &				operator<<(std::ostream & o, Operand<T> const & i)
{

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
	std::string *lol = new std::string("aa");
	return *lol;
}

template <class T>
Operand<T>::~Operand ()
{
	return ;
}

template <class T>
Operand<T>::Operand (eOperandType type) : type(type)
{
	std::cout << "Default Type" << std::endl;
	return ;
}

template <class T>
IOperand const * Operand<T>::operator+( IOperand const & rhs ) const
{
	return (NULL);
}

template <class T>
IOperand const * Operand<T>::operator-( IOperand const & rhs ) const
{
	return (NULL);
}

template <class T>
IOperand const * Operand<T>::operator*( IOperand const & rhs ) const
{
	return (NULL);
}

template <class T>
IOperand const * Operand<T>::operator/( IOperand const & rhs ) const
{
	return (NULL);
}

template <class T>
IOperand const * Operand<T>::operator%( IOperand const & rhs ) const
{
	return (NULL);
}

#endif
