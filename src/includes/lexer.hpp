#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "parser.hpp"

class Lexer {
	public:
		int							readFromFile(char *);
		int							readFromStdin();
		lineInfos					line;
	private:
		Parser						parser;
		bool						shouldBuffer;
		int							read(std::istream &);
		void						readStream(std::istream &);
		std::vector<std::string>	getTokensFromLine(std::string);
};

#endif
