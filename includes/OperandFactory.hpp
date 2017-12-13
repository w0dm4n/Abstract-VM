/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:40:06 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/12 13:41:16 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_FACTORY
#define OPERAND_FACTORY

#include "All.hpp"
#include "Operand.hpp"

class OperandFactory
{
	public:
	IOperand const *createInt8( std::string const & value ) const;
	IOperand const *createInt16( std::string const & value ) const;
	IOperand const *createInt32( std::string const & value ) const;
	IOperand const *createFloat( std::string const & value ) const;
	IOperand const *createDouble( std::string const & value ) const;
	IOperand const * createOperand( eOperandType type, std::string const & value ) const;
};

#endif
