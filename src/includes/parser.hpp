#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <vector>

#include "../../vm/includes/vm.hpp"

class Parser {
	public:
		void				buffer();
		void				setLine(lineInfos);
		bool				parseTokens();
	private:
		VM					vm;
		lineInfos			line;
		bool				shouldBuffer = false;
		bool				handleInstruction(std::string, std::string);
		IOperand const *	getOperand(std::string);
};

#endif
