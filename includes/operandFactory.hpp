#ifndef OPERANDFACTORY_HPP
#define OPERANDFACTORY_HPP

#include <vector>
#include <stdexcept>
#include <iostream>

#include "lineInfos.hpp"
#include "operand.hpp"
#include "exceptions.hpp"

class OperandFactory {
	private:
		IOperand const *	createInt8(std::string const &) const;
		IOperand const *	createInt16(std::string const &) const;
		IOperand const *	createInt32(std::string const &) const;
		IOperand const *	createFloat(std::string const &) const;
		IOperand const *	createDouble(std::string const &) const;
	public:
		IOperand const *	createOperand(eOperandType, std::string const &) const;
};

#endif
