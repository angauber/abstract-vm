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

	if (this->getType() == Float || this->getType() == Double)
		stream << std::setprecision(std::numeric_limits<T>::digits10);

	stream << this->value;
	
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
double	Operand<T>::getDoubleValue() const {
	return (double) this->value;
}

template <class T>
void	Operand<T>::check(T v1, T v2, Sign sign) const {
	switch(sign) {
		case Plus:
			if ((v1 + v2) > std::numeric_limits<T>::max())
				throw OverflowException();
			else if ((v1 + v2) < std::numeric_limits<T>::min()) 
				throw UnderflowException();
			break;
		case Minus:
			if ((v1 - v2) > std::numeric_limits<T>::max())
				throw OverflowException();
			else if ((v1 - v2) < std::numeric_limits<T>::min()) 
				throw UnderflowException();
			break;
		case Times:
			if ((v1 * v2) > std::numeric_limits<T>::max())
				throw OverflowException();
			else if ((v1 * v2) < std::numeric_limits<T>::min()) 
				throw UnderflowException();
			break;
		case Divide:
			if ((v1 / v2) > std::numeric_limits<T>::max())
				throw OverflowException();
			else if ((v1 / v2) < std::numeric_limits<T>::min()) 
				throw UnderflowException();
			break;
		case Modulo:
			if (((int32_t)v1 % (int32_t)v2) > std::numeric_limits<T>::max())
				throw OverflowException();
			else if (((int32_t)v1 % (int32_t)v2) < std::numeric_limits<T>::min()) 
				throw UnderflowException();
			break;
	}
}

template <class T>
IOperand const	*Operand<T>::operator+(IOperand const &rhs) const {
	if (this->getPrecision() < rhs.getPrecision()) {
		return rhs + (*this);
	}

	T v1 = this->value;
	T v2 = (T) rhs.getDoubleValue();

	this->check(v1, v2, Plus);

	return new Operand<T> (v1 + v2);
}

template <class T>
IOperand const	*Operand<T>::operator-(IOperand const &rhs) const {
	if (this->getPrecision() < rhs.getPrecision()) {
		return rhs - (*this);
	}

	T v1 = this->value;
	T v2 = (T) rhs.getDoubleValue();

	this->check(v1, v2, Minus);

	return new Operand<T> (v1 - v2);
}

template <class T>
IOperand const	*Operand<T>::operator*(IOperand const &rhs) const {
	if (this->getPrecision() < rhs.getPrecision()) {
		return rhs * (*this);
	}

	T v1 = this->value;
	T v2 = (T) rhs.getDoubleValue();

	this->check(v1, v2, Times);

	return new Operand<T> (v1 * v2);
}

template <class T>
IOperand const	*Operand<T>::operator/(IOperand const &rhs) const {
	if (this->getPrecision() < rhs.getPrecision()) {
		return rhs / (*this);
	}

	T v1 = this->value;
	T v2 = (T) rhs.getDoubleValue();

	if (v2 == 0)
		throw DivisionException();

	this->check(v1, v2, Divide);

	return new Operand<T> (v1 / v2);
}

template <class T>
IOperand const	*Operand<T>::operator%(IOperand const &rhs) const {
	if (this->getPrecision() < rhs.getPrecision()) {
		return rhs % (*this);
	}

	T v1 = this->value;
	T v2 = (T) rhs.getDoubleValue();

	if (this->getType() == Float || this->getType() == Double || rhs.getType() == Float || rhs.getType() == Double)
		throw ModuloException();

	if (v2 == 0)
		throw DivisionException();

	this->check(v1, v2, Modulo);

	return new Operand<T> ((int32_t)v1 % (int32_t)v2);
}

template <class T>
std::string const	&Operand<T>::toString() const {
	return this->str;
}
