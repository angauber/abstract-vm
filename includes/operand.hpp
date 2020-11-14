#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <limits>
#include <iomanip>
#include <stdexcept>

#include "exceptions.hpp"
#include "lineInfos.hpp"
#include "sign.hpp"
#include "IOperand.hpp"

template <class T>
class Operand : public IOperand {
	private:
		T				value;
		eOperandType	type;
		std::string		str;
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
		void				check(T, T, Sign) const;

		void				fillType();
		void				fillStr();
};

#include "../sources/operand.cpp"

#endif
