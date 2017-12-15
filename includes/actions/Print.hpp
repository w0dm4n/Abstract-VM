/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:02:49 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/14 16:02:59 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_HPP
# define PRINT_HPP

#include "All.hpp"
#include "Handler.hpp"

class Handler;
class Print
{
	public:
	 static void Handle(std::vector<std::string> line, Handler *handler);

	 struct PrintEmptyStack : public std::exception {
		virtual const char* what() const throw() {
			return "Trying to print an empty stack";
		}
	};

	struct Not8BitInteger : public std::exception {
	 virtual const char* what() const throw() {
		 return "Trying to print an invalid type (not 8 bit integer)";
	 }
 };
};
#endif
