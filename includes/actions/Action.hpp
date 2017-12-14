/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Action.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:17:39 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/13 15:17:42 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_HPP
# define ACTION_HPP

#include "All.hpp"

class Handler;
class Action
{
	public:

		Action();
		Action(std::string name, void(*foo)(std::vector<std::string>, Handler*));
		Action( Action const & src );
		virtual ~Action();

		Action &							operator=( Action const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, Action const & i);
		std::string name;
		void(*func)(std::vector<std::string>, Handler *handler);
};

#endif
