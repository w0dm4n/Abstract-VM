/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handler.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:27:10 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/13 15:27:13 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_HPP
# define HANDLER_HPP

#include "All.hpp"
#include "actions/Action.hpp"

class Handler
{
	public:

		Handler();
		Handler( Handler const & src );
		virtual ~Handler();

		void initActions();
		void Process(std::vector<std::string> line);
		static void Salope(std::vector<std::string> line);
		Handler &							operator=( Handler const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, Handler const & i);
	private:
		std::vector<Action*>	actions;
};

#endif
