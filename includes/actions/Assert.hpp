/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Assert.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 08:22:31 by dmoureu-          #+#    #+#             */
/*   Updated: 2017/12/15 09:10:37 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSERT_HPP
# define ASSERT_HPP

#include "All.hpp"
#include "Action.hpp"
#include "Utils.hpp"

class Handler;
class Assert
{
	public:
		static void Handle(std::vector<std::string> line, Handler *handler);
		static void Int8(std::vector<std::string> line, Handler *handler);
		static void Int16(std::vector<std::string> line, Handler *handler);
		static void Int32(std::vector<std::string> line, Handler *handler);
		static void Double(std::vector<std::string> line, Handler *handler);
		static void Float(std::vector<std::string> line, Handler *handler);
		static std::string clearNumber(std::string number);

		struct AssertEmptyStack : public std::exception {
			virtual const char* what() const throw() {
				return "Trying to assert on empty stack";
			}
		};

		struct AssertNotEqual : public std::exception {
			virtual const char* what() const throw() {
				return "Assert not true";
			}
		};

};

#endif
