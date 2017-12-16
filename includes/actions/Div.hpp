/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Add.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 02:39:57 by dmoureu-          #+#    #+#             */
/*   Updated: 2017/12/15 07:51:16 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIV_HPP
# define DIV_HPP

#include "All.hpp"

class Handler;
class Div
{
	public:
	 static void Handle(std::vector<std::string> line, Handler *handler);

	 struct DivStackTooSmall : public std::logic_error {
	   DivStackTooSmall(const std::string& str) : std::logic_error(str) {}
	};

	 struct DivByZero : public std::logic_error {
		DivByZero(const std::string& str) : std::logic_error(str) {}
	 };
};

#endif
