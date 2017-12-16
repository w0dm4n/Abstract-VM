/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UserEntry.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmarinh <frmarinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:12:42 by frmarinh          #+#    #+#             */
/*   Updated: 2017/12/12 15:12:44 by frmarinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "UserEntry.hpp"
#include "Utils.hpp"

UserEntry::UserEntry ()
{
	this->eof = false;
	this->flagError = false;
	this->contentCall = false;
}

UserEntry::UserEntry ( UserEntry const & src )
{
	*this = src;
}

UserEntry &				UserEntry::operator=( UserEntry const & rhs )
{
	(void)rhs;
	return (*this);
}

UserEntry::~UserEntry ()
{
	return ;
}

std::ostream &				operator<<(std::ostream & o, UserEntry const & i)
{
	(void)i;
	return (o);
}

void UserEntry::checkEOF()
{
	for (size_t i = 0; i < this->lines.size(); i++)
	{
		if (this->lines[i] == EOF_AVM)
			this->eof = true;
	}
}

std::string	UserEntry::replaceNewline(char *buffer)
{
	int len = strlen(buffer);
	if (buffer[len - 1] == '\n')
		buffer[len - 1] = '\0';
	return (buffer);
}

std::vector<std::string> &UserEntry::getContent()
{
	if (this->getFlagError())
	{
		if (this->contentCall && this->lines.size() > 1)
			this->lines.erase(this->lines.begin());
		else
			this->contentCall = true;
	}
	return this->lines;
}

void UserEntry::readFile(std::string fileName)
{
	std::ifstream ifs(fileName);
	if (ifs)
	{
		std::string content((std::istreambuf_iterator<char>(ifs)),
			(std::istreambuf_iterator<char>()));
		if (content.length() > 0) {
			this->lines = Utils::split(content, '\n');
		} else {
			throw InvalidFileGivenAsArgument();
		}
	}
	else
		throw InvalidFileGivenAsArgument();
}

void UserEntry::readEntry()
{
	char	buffer[USER_READ];

	while (!this->eof)
	{
		memset((char*)&buffer, 0, (USER_READ - 1));
		if (read(STDOUT_FILENO, (char*)&buffer, (USER_READ - 1)) > 0)
			this->lines.push_back(this->replaceNewline((char*)&buffer));
		this->checkEOF();
	}
}

void UserEntry::checkErrorFlag(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], FLAG_ERROR))
			this->flagError = true;
	}
}

bool UserEntry::getFlagError()
{
	return this->flagError;
}
