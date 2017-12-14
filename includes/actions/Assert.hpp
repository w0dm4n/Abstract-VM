/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Assert.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:02:49 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/14 16:02:59 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSERT_HPP
# define ASSERT_HPP

#include "All.hpp"
#include "Push.hpp"

class Handler;
class Assert
{
	public:
	 static void Handle(std::vector<std::string> line, Handler *handler);
	 struct NotEqualsOnTheStackAssert : public std::exception {
		virtual const char* what() const throw() {
			return "The value from the assert was not equal to the top of the stack";
		}
	};
};
#endif
