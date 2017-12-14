/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pop.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:02:49 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/14 16:02:59 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POP_HPP
# define POP_HPP

#include "All.hpp"

class Handler;
class Pop
{
	public:
	 static void Handle(std::vector<std::string> line, Handler *handler);

	 struct PopOnEmptyStack : public std::exception {
		 virtual const char* what() const throw() {
			 return "Trying to pop an empty stack";
		 }
	 };
};

#endif
