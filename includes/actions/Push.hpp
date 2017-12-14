/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:07:16 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/13 16:07:26 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_HPP
# define PUSH_HPP

#include "All.hpp"
#include "Action.hpp"
#include "Utils.hpp"

class Handler;
class Push
{
	public:
		static void Handle(std::vector<std::string> line, Handler *handler);
		static void Int8(std::vector<std::string> line, Handler *handler);
		static void Int16(std::vector<std::string> line, Handler *handler);
		static void Int32(std::vector<std::string> line, Handler *handler);
		static void Double(std::vector<std::string> line, Handler *handler);
		static void Float(std::vector<std::string> line, Handler *handler);
};

#endif
