#include "operandFactory.hpp"

IOperand const		*OperandFactory::createInt8(std::string const &value) const {
	int res = std::stoi(value);

	if (res > std::numeric_limits<int8_t>::max())
		throw OverflowException();
	else if (res < std::numeric_limits<int8_t>::min())
		throw UnderflowException();

	return new Operand<int8_t> ((int8_t) res);
}

IOperand const		*OperandFactory::createInt16(std::string const &value) const {
	int res = std::stoi(value);

	if (res > std::numeric_limits<int16_t>::max())
		throw OverflowException();
	else if (res < std::numeric_limits<int16_t>::min())
		throw UnderflowException();

	return new Operand<int16_t> ((int16_t) res);
}

IOperand const		*OperandFactory::createInt32(std::string const &value) const {
	int res = std::stoi(value);

	if (res > std::numeric_limits<int32_t>::max())
		throw OverflowException();
	else if (res < std::numeric_limits<int32_t>::min())
		throw UnderflowException();

	return new Operand<int32_t> ((int32_t) res);
}

IOperand const		*OperandFactory::createFloat(std::string const &value) const {
	float res = std::stof(value);

	if (res > std::numeric_limits<float>::max())
		throw OverflowException();
	else if (res < std::numeric_limits<float>::min())
		throw UnderflowException();

	return new Operand<float> (res);
}

IOperand const		*OperandFactory::createDouble(std::string const &value) const {
	int res = std::stod(value);

	if (res > std::numeric_limits<double>::max())
		throw OverflowException();
	else if (res < std::numeric_limits<double>::min())
		throw UnderflowException();

	return new Operand<double> (res);
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
	}
}
