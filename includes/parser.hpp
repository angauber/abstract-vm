#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <vector>

#include "vm.hpp"
#include "operandFactory.hpp"
#include "lineInfos.hpp"

class Parser {
	public:
		void				buffer();
		void				setLine(lineInfos);
		void				parseTokens();
		void				freeStack();
	private:
		VM					vm;
		lineInfos			line;
		bool				shouldBuffer = false;
		void				handleInstruction(std::string, std::string);
		IOperand const *	getOperand(std::string);
};

#endif
