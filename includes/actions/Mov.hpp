/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mov.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:55:08 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/16 14:55:25 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOV_HPP
# define MOV_HPP

#include "All.hpp"

class Handler;
class Mov
{
	public:
	 static void Handle(std::vector<std::string> line, Handler *handler);
	 struct WrongValueOnMovInstruction : public std::exception {
		 virtual const char* what() const throw() {
			 return "Wrong value on mov instruction";
		 }
	 };
};

#endif
