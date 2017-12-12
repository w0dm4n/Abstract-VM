/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:13:15 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/12 15:13:16 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
# define PARSER_HPP

#include "All.hpp"

class Parser
{
	public:

		Parser();
		Parser( Parser const & src );
		virtual ~Parser();
		static void ParseEntry(std::vector<std::string>);

		Parser &							operator=( Parser const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, Parser const & i);
};

#endif
