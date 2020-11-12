#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <limits>
#include <stdexcept>

#include "exceptions.hpp"
#include "lineInfos.hpp"
#include "sign.hpp"
#include "IOperand.hpp"

template <class T>
class Operand : public IOperand {
	private:
		eOperandType	type;
		T	value;
	public:
		Operand(T value) {
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

			this->value = value;
		}

		int	getPrecision() const {
			return (int) sizeof(T);
		}

		eOperandType	getType() const {
			return this->type;
		}

		void	check(T v1, T v2, Sign sign) const {
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

		IOperand const	*operator+(IOperand const &rhs) const {
			if (this->getPrecision() < rhs.getPrecision()) {
				return rhs + (*this);
			}

			T v1 = this->value;
			T v2 = (T) rhs.getDoubleValue();

			this->check(v1, v2, Plus);

			return new Operand<T> (v1 + v2);
		}

		IOperand const	*operator-(IOperand const &rhs) const {
			if (this->getPrecision() < rhs.getPrecision()) {
				return rhs - (*this);
			}

			T v1 = this->value;
			T v2 = (T) rhs.getDoubleValue();

			this->check(v1, v2, Minus);

			return new Operand<T> (v1 - v2);
		}

		IOperand const	*operator*(IOperand const &rhs) const {
			if (this->getPrecision() < rhs.getPrecision()) {
				return rhs * (*this);
			}

			T v1 = this->value;
			T v2 = (T) rhs.getDoubleValue();

			this->check(v1, v2, Times);

			return new Operand<T> (v1 * v2);
		}

		IOperand const *operator/(IOperand const &rhs) const {
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

		IOperand const *operator%(IOperand const &rhs) const {
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

		double	getDoubleValue() const {
			return (double) this->value;
		}

		std::string	toString() const  {
			return std::to_string(this->value);
		}
};

#endif
