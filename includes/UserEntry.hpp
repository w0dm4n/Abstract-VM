#ifndef USERENTRY_HPP
# define USERENTRY_HPP

#include "All.hpp"

class UserEntry
{
	public:
		UserEntry();
		UserEntry( UserEntry const & src );
		virtual ~UserEntry();

		void						readEntry();
		void						readFile(std::string file);
		void						checkEOF();
		void						checkErrorFlag(int argc, char **argv);
		std::string 				replaceNewline(char*);
		std::vector<std::string>	&getContent();
		bool						getFlagError();

		UserEntry &							operator=( UserEntry const & rhs );
		friend std::ostream &				operator<<(std::ostream & o, UserEntry const & i);

		struct WrongArgumentNumber : public std::exception {
			virtual const char* what() const throw() {
				return "Wrong argument given to abstract VM";
			}
		};

		struct InvalidFileGivenAsArgument : public std::exception {
			virtual const char* what() const throw() {
				return "Invalid file given as argument";
			}
		};

	private:
	bool						flagError;
	bool						contentCall;
	bool 						eof;
	std::vector<std::string>	lines;
};

#endif
