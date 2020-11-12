#include "operandFactory.hpp"

IOperand const		*OperandFactory::createInt8(std::string const &value) const {
	return new Operand<int8_t> ((int8_t) std::stoi(value));
}

IOperand const		*OperandFactory::createInt16(std::string const &value) const {
	return new Operand<int16_t> ((int16_t) std::stoi(value));
}

IOperand const		*OperandFactory::createInt32(std::string const &value) const {
	return new Operand<int32_t> ((int32_t) std::stoi(value));
}

IOperand const		*OperandFactory::createFloat(std::string const &value) const {
	return new Operand<float> ((float) std::stof(value));
}

IOperand const		*OperandFactory::createDouble(std::string const &value) const {
	return new Operand<double> ((double) std::stod(value));
}

IOperand const		*OperandFactory::createOperand(eOperandType type, std::string const &value) const {
	IOperand const *(OperandFactory::*function[5])(std::string const & value) const = {
		&OperandFactory::createInt8, 
		&OperandFactory::createInt16,
		&OperandFactory::createInt32,
		&OperandFactory::createFloat,
		&OperandFactory::createDouble
	};

	try {
		return (this->*function[type])(value);
	} catch (std::out_of_range) {
		if (value[0] == '-') {
			throw UnderflowException();
		} else {
			throw OverflowException();
		}
	}
}
