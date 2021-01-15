#include "operandFactory.hpp"
#include "operand.hpp"

IOperand const		*OperandFactory::createInt8(std::string const &value) const {
	return new Operand<int8_t> (value);
}

IOperand const		*OperandFactory::createInt16(std::string const &value) const {
	return new Operand<int16_t> (value);
}

IOperand const		*OperandFactory::createInt32(std::string const &value) const {
	return new Operand<int32_t> (value);
}

IOperand const		*OperandFactory::createFloat(std::string const &value) const {
	return new Operand<float> (value);
}

IOperand const		*OperandFactory::createDouble(std::string const &value) const {
	return new Operand<double> (value);
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
	} catch (const std::out_of_range &) {
		if (!value.empty() && value[0] == '-') {
			throw UnderflowException();
		} else {
			throw OverflowException();
		}
	} catch (const std::invalid_argument &) {
		throw ParsingException("Error: Unknown value");
	}
}
