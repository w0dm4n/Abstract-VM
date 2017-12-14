/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:50:14 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/12 16:50:56 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
# define OPERAND_HPP

#include "All.hpp"
#include "interfaces/IOperand.hpp"

template <class T>
class Operand : public IOperand
{
	public:
		Operand();
		Operand(eOperandType, std::string const&);
		Operand( Operand const & src );
		virtual ~Operand();

		eOperandType						getType( void ) const;
		int											getPrecision(void) const;
		T												getValue() const;
		IOperand const * operator+( IOperand const & rhs ) const;
		IOperand const * operator-( IOperand const & rhs ) const;
		IOperand const * operator*( IOperand const & rhs ) const;
		IOperand const * operator/( IOperand const & rhs ) const;
		IOperand const * operator%( IOperand const & rhs ) const;
		std::string const & toString( void ) const;

		Operand&								operator=( Operand const & rhs );
		friend std::ostream&		operator<<(std::ostream & o, Operand<T> const & i);
	private:
		eOperandType	type;
		T				value;
};

#include "../srcs/templates/OperandTemplate.cpp"

#endif
