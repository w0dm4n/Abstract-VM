/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Add.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 02:39:57 by dmoureu-          #+#    #+#             */
/*   Updated: 2017/12/15 07:46:54 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUB_HPP
# define SUB_HPP

#include "All.hpp"

class Handler;
class Sub
{
	public:
	 static void Handle(std::vector<std::string> line, Handler *handler);
	 struct SubStackTooSmall : public std::logic_error {
	   SubStackTooSmall(const std::string& str) : std::logic_error(str) {}
	};
};

#endif
