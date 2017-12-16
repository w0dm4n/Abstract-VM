/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:16:53 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/15 07:26:43 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserEntry.hpp"
#include "Parser.hpp"
#include "Operand.hpp"

void		TestError(UserEntry &entry)
{
	std::vector<std::string> content = entry.getContent();
	try
	{
		Parser::ParseEntry(content);
	}
	catch (std::logic_error &e)
	{
		std::cout << "Logic error occured: " << e.what() << std::endl;
		if (content.size() > 1)
			TestError(entry);
	}
	catch (std::exception &e)
	{
		std::cout << "An exception occured: " << e.what() << std::endl;
		if (content.size() > 1)
			TestError(entry);
	}
}

int		main(int argc, char **argv)
{
	UserEntry entry;

	try
	{
		entry.checkErrorFlag(argc, argv);
		if (argc == 1)
			entry.readEntry();
		else if (argc >= 2)
			entry.readFile(argv[1]);
		else {
			throw UserEntry::WrongArgumentNumber();
		}

		try
		{
			Parser::ParseEntry(entry.getContent());
		}
		catch (std::logic_error &e)
		{
			std::cout << "Logic error occured: " << e.what() << std::endl;
			if (entry.getFlagError() == true)
				TestError(entry);
		}
		catch (std::exception &e)
		{
			std::cout << "An exception occured: " << e.what() << std::endl;
			if (entry.getFlagError() == true)
				TestError(entry);
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Error on start: " << e.what() << std::endl;
	}
	return (0);
}
