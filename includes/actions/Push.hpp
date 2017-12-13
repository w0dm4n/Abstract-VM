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

class Push
{
	public:
		static void Handler(std::vector<std::string> line);
		static void Int8(std::vector<std::string> line);
		static void Int16(std::vector<std::string> line);
		static void Int32(std::vector<std::string> line);
		static void Double(std::vector<std::string> line);
		static void Float(std::vector<std::string> line);
};

#endif
