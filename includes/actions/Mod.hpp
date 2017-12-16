/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Add.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 02:39:57 by dmoureu-          #+#    #+#             */
/*   Updated: 2017/12/15 08:30:35 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOD_HPP
# define MOD_HPP

#include "All.hpp"

class Handler;
class Mod
{
	public:
	 static void Handle(std::vector<std::string> line, Handler *handler);
	 struct ModStackTooSmall : public std::logic_error {
	   ModStackTooSmall(const std::string& str) : std::logic_error(str) {}
	};
};

#endif
