#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "parser.hpp"

class Lexer {
	public:
		void						readFromFile(char *);
		void						readFromStdin();
		lineInfos					line;
	private:
		Parser						parser;
		bool						shouldBuffer;
		void						read(std::istream &);
		void						readStream(std::istream &);
		std::vector<std::string>	getTokensFromLine(std::string);
};

#endif
