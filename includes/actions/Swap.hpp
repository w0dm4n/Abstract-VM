/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:10:54 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/16 15:11:16 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_HPP
# define SWAP_HPP

#include "All.hpp"

class Handler;
class Swap
{
	public:
	 static void Handle(std::vector<std::string> line, Handler *handler);
};
#endif
