/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:43:16 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/12 15:43:18 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include "All.hpp"
#include <sstream>

class Utils
{
	public:

		Utils();
		Utils( Utils const & src );
		virtual ~Utils();

		Utils &							operator=( Utils const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, Utils const & i);
		static std::vector<std::string> split(const std::string &s, char delim);

		template<typename Out>
		static void split(const std::string &s, char delim, Out result);
};

#endif
