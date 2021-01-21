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
	private:
		T					value;
		std::string			str;
		eOperandType		type;
		OperandFactory		factory;
		void				fillType();
		void				fillStr();
};

#include "../sources/operand.cpp"

#endif
