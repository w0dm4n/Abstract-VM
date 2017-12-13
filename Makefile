# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/20 17:57:50 by frmarinh          #+#    #+#              #
#    Updated: 2017/12/12 13:13:50 by frmarinh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_ABSTRACT_VM	=	avm

NAME		=   "Abstract VM"
NAMEBASE    =   $(shell basename $(NAME))
LENGTHNAME	=	`printf "%s" $(NAMEBASE) | wc -c`
MAX_COLS	=	$$(echo "$$(tput cols)-24-$(LENGTHNAME)"|bc)

CC			=	g++ -std=c++11
#FLAGS		=	-Wall -Wextra -Werror
FLAGS_O		=

SRCDIR_ABSTRACT_VM		=	srcs/
OBJDIR_ABSTRACT_VM		=	objs/

INCDIR				=	includes/

SRCBASE_ABSTRACT_VM	=	\
					main.cpp								\
					OperandFactory.cpp						\
					UserEntry.cpp							\
					Parser.cpp								\
					Utils.cpp								\
					Operand.cpp								\
					templates/OperandTemplate.cpp			\
					Handler.cpp 							\
					actions/Action.cpp	 					\
					actions/Push.cpp	 					\

INCS			=	$(addprefix $(INCDIR), $(INCBASE))

SRCS_ABSTRACT_VM			=	$(addprefix $(SRCDIR_ABSTRACT_VM), $(SRCBASE_ABSTRACT_VM))
OBJS_ABSTRACT_VM			=	$(addprefix $(OBJDIR_ABSTRACT_VM), $(SRCBASE_ABSTRACT_VM:.cpp=.o))

.SILENT:

all:		ACTIONS

ACTIONS:
	if test -f $(NAME_ABSTRACT_VM) ; then											\
		echo "make: Nothing to be done for \`all\`.";				        		\
	else																			\
		make BUILD 			&& 														\
		echo "\r\033[38;5;184m👥  AUTHOR(s): \033[0m\033[K" && 						\
		echo "\r\033[38;5;15m`cat auteur | sed s/^/\ \ \ \ -/g`\033[0m\033[K" &&    \
		echo "\033[38;5;44m☑️  ALL    $(NAMEBASE) is done\033[0m\033[K";			\
	fi

$(OBJDIR_ABSTRACT_VM):
	mkdir -p $(OBJDIR_ABSTRACT_VM)
	mkdir -p $(dir $(OBJS_ABSTRACT_VM))

$(OBJDIR_ABSTRACT_VM)%.o : $(SRCDIR_ABSTRACT_VM)%.cpp | $(OBJDIR_ABSTRACT_VM)
	$(CC) $(FLAGS) -MMD -c $< -o $@											\
		-I $(INCDIR)														\
		-I $(INCDIR)

fcleanlib:	fclean

re:			fclean all

relib:		fclean fcleanlib all

.PHONY:		fclean fcleanlib clean re relib

BUILD: $(OBJDIR_ABSTRACT_VM) $(OBJS_ABSTRACT_VM)
	$(CC) $(FLAGS) $(FLAGS_O) -o $(NAME_ABSTRACT_VM) $(OBJS_ABSTRACT_VM)
	echo "\r\033[38;5;22m📗  MAKE $(NAME_ABSTRACT_VM)"

clean:
	@rm -rf $(OBJDIR_ABSTRACT_VM)
	echo "\r\033[38;5;124m📕  CLEAN $(OBJDIR_ABSTRACT_VM)\033[0m\033[K";

fclean:		clean
	@rm -rf $(NAME_ABSTRACT_VM)
	echo "\r\033[38;5;124m📕  FCLEAN $(NAME_ABSTRACT_VM)\033[0m\033[K";

-include $(OBJS:.o=.d)
