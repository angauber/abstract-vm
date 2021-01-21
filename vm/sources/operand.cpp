#include "operand.hpp"

template <class T>
Operand<T>::Operand(T value) {
	this->fillType();

	this->value = value;
	this->fillStr();
}

template <class T>
Operand<T>::Operand(std::string const &value) {
	this->fillType();

	double v = std::stod(value);

	if (v > std::numeric_limits<T>::max())
		throw OverflowException();
	else if (v < std::numeric_limits<T>::min())
		throw UnderflowException();
	
	this->value = (T) v;
	this->fillStr();
}

template <class T>
void	Operand<T>::fillType() {
	if (std::is_same_v<T, int8_t>)
		this->type = Int8;
	else if (std::is_same_v<T, int16_t>)
		this->type = Int16;
	else if (std::is_same_v<T, int32_t>)
		this->type = Int32;
	else if (std::is_same_v<T, float>)
		this->type = Float;
	else if (std::is_same_v<T, double>)
		this->type = Double;
}

template <class T>
void	Operand<T>::fillStr() {
	std::ostringstream stream;

	/* Setting max precision */
	if (this->getType() == Float || this->getType() == Double)
		stream << std::setprecision(std::numeric_limits<T>::digits10);

	/* Avoiding int8_t ASCII conversion */
	if (this->getType() == Int8) {
		stream << (int) this->value;
	}
	else {
		stream << this->value;
	}
	
	this->str = stream.str();
}


template <class T>
int		Operand<T>::getPrecision() const {
	return this->type;
}

template <class T>
eOperandType	Operand<T>::getType() const {
	return this->type;
}

template <class T>
IOperand const	*Operand<T>::operator+(IOperand const &rhs) const {
	eOperandType type = this->getPrecision() > rhs.getPrecision() ? this->getType() : rhs.getType();

	double v1 = (double) this->value;
	double v2 = stod(rhs.toString());
	std::ostringstream stream;

	stream << v1 + v2;

	return this->factory.createOperand(type, stream.str());
}

template <class T>
IOperand const	*Operand<T>::operator-(IOperand const &rhs) const {
	eOperandType type = this->getPrecision() > rhs.getPrecision() ? this->getType() : rhs.getType();
	double v1 = (double) this->value;
	double v2 = stod(rhs.toString());
	std::ostringstream stream;

	stream << v1 - v2;

	return this->factory.createOperand(type, stream.str());
}

template <class T>
IOperand const	*Operand<T>::operator*(IOperand const &rhs) const {
	eOperandType type = this->getPrecision() > rhs.getPrecision() ? this->getType() : rhs.getType();
	double v1 = (double) this->value;
	double v2 = stod(rhs.toString());
	std::ostringstream stream;

	stream << v1 * v2;

	return this->factory.createOperand(type, stream.str());
}

template <class T>
IOperand const	*Operand<T>::operator/(IOperand const &rhs) const {
	eOperandType type = this->getPrecision() > rhs.getPrecision() ? this->getType() : rhs.getType();
	double v1 = (double) this->value;
	double v2 = stod(rhs.toString());
	std::ostringstream stream;

	if (v2 == 0)
		throw DivisionException();

	stream << v1 / v2;

	return this->factory.createOperand(type, stream.str());
}

template <class T>
IOperand const	*Operand<T>::operator%(IOperand const &rhs) const {
	eOperandType type = this->getPrecision() > rhs.getPrecision() ? this->getType() : rhs.getType();
	int32_t v1 = (int32_t) this->value;
	int32_t v2 = (int32_t) stoi(rhs.toString());
	std::ostringstream stream;

	if (type == Float || type == Double)
		throw ModuloException();

	if (v2 == 0)
		throw DivisionException();

	stream << v1 % v2;

	return this->factory.createOperand(type, stream.str());
}

template <class T>
std::string const	&Operand<T>::toString() const {
	return this->str;
}
