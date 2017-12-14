/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dump.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:33:46 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/14 16:34:05 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMP_HPP
# define DUMP_HPP

#include "All.hpp"

class Handler;
class Dump
{
	public:
	 static void Handle(std::vector<std::string> line, Handler *handler);
};
#endif
