#include "parser.hpp"

void	Parser::buffer() {
	this->shouldBuffer = true;
}

void	Parser::setLine(lineInfos line) {
	this->line = line;
}

void	Parser::freeStack() {
	this->vm.freeStack();
}

void	Parser::parseTokens() {
	std::string operation;
	std::string type;

	operation = this->line.tokens.front();

	if (this->line.tokens.size() == 2)
		type = this->line.tokens.back();
	
	this->handleInstruction(operation, type);
}

IOperand const	*Parser::getOperand(std::string operand) {
	OperandFactory factory;

	std::string type;
	std::string value;

	int opening = operand.find('(');
	int closing = operand.find(')');

	if (opening + 1 >= closing)
		throw ParsingException();

	type = operand.substr(0, opening);
	value = operand.substr(opening + 1, (closing - opening) - 1);

	if (type == "int8")
		return factory.createOperand(Int8, value);
	else if (type == "int16")
		return factory.createOperand(Int16, value);
	else if (type == "int32")
		return factory.createOperand(Int32, value);
	else if (type == "float")
		return factory.createOperand(Float, value);
	else if (type == "double")
		return factory.createOperand(Double, value);
	else
		throw ParsingException("Error: Unknown type \"" + type + "\"");
}

void	Parser::handleInstruction(std::string operation, std::string type) {
	if (type.size() != 0) {	
		if (operation == "push")
			this->vm.push(this->getOperand(type));
		else if (operation == "assert")
			this->vm.assertEquals(this->getOperand(type));
		else
			throw ParsingException("Error: Unknown operation \"" + operation + "\"");
	} else {
		if (operation == "pop")
			this->vm.pop();
		else if (operation == "add")
			this->vm.add();
		else if (operation == "sub")
			this->vm.sub();
		else if (operation == "mul")
			this->vm.mul();
		else if (operation == "div")
			this->vm.div();
		else if (operation == "mod")
			this->vm.mod();
		else if (operation == "dump")
			this->vm.dump();
		else if (operation == "print")
			this->vm.print();
		else if (operation == "exit")
			this->vm.exit();
		else
			throw ParsingException("Error: Unknown operation \"" + operation + "\"");
	}
}
