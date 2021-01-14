#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <limits>
#include <iomanip>
#include <stdexcept>
#include <sstream>

#include "exceptions.hpp"
#include "lineInfos.hpp"
#include "sign.hpp"
#include "IOperand.hpp"
#include "operandFactory.hpp"

template <class T>
class Operand : public IOperand {
	public:
		Operand(T);
		Operand(std::string const &);
		IOperand const *	operator+(IOperand const &rhs) const;
		IOperand const *	operator-(IOperand const &rhs) const;
		IOperand const *	operator*(IOperand const &rhs) const;
		IOperand const *	operator/(IOperand const &rhs) const;
		IOperand const *	operator%(IOperand const &rhs) const;
		eOperandType		getType() const;
		int					getPrecision() const;
		std::string const &	toString() const;
		double				getDoubleValue() const;
		T					getValue() const;

		void				fillType();
		void				fillStr();
	private:
		T				value;
		eOperandType	type;
		std::string		str;
		OperandFactory	factory;
};

#include "../sources/operand.cpp"

#endif
