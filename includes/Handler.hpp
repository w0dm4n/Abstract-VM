/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handler.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:27:10 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/15 09:17:39 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLER_HPP
# define HANDLER_HPP

#include "All.hpp"
#include "Operand.hpp"
#include "actions/Action.hpp"
#include "actions/Push.hpp"
#include "actions/Pop.hpp"
#include "actions/Add.hpp"
#include "actions/Sub.hpp"
#include "actions/Mul.hpp"
#include "actions/Div.hpp"
#include "actions/Mod.hpp"
#include "actions/Assert.hpp"
#include "actions/Dump.hpp"
#include "actions/Assert.hpp"
#include "actions/Print.hpp"
#include "actions/Mov.hpp"
#include "actions/Swap.hpp"

class Handler
{
	public:

		Handler();
		Handler( Handler const & src );
		virtual ~Handler();

		void initActions();
		void Process(std::vector<std::string> line);
		Handler &							operator=( Handler const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, Handler const & i);
		std::stack <std::shared_ptr<const IOperand>> stack;

		struct UnknownInstructionGiven : public std::exception {
   		 virtual const char* what() const throw() {
   			 return "An unknown instruction has been given";
   		 }
   	 };

		 struct NoExitOnInstructions : public std::exception {
    		 virtual const char* what() const throw() {
    			 return "No exit instruction on the program";
    		 }
    	 };
	private:
		std::vector<Action*>	actions;
};

#endif
