#include "vm.hpp"

IOperand const	*VM::process(Sign sign) {
	IOperand const *result;
	IOperand const *v2;
	IOperand const *v1;

	if (this->stack.size() < 2) {
		throw StackException();
	}

	v2 = this->pop();
	v1 = this->pop();

	try {
		switch (sign) {
			case Plus:
				result = *v1 + *v2;
				break;
			case Minus:
				result = *v1 - *v2;
				break;
			case Times:
				result = *v1 * *v2;
				break;
			case Divide:
				result = *v1 / *v2;
				break;
			case Modulo:
				result = *v1 % *v2;
				break;
			default:
				throw OperationException();
				break;
		}
	} catch (Exception const &) {
		delete v1;
		delete v2;

		throw;
	}

	delete v1;
	delete v2;

	return result;
}

void	VM::push(IOperand const *operand) {
	this->stack.push_back(operand);
}

IOperand const *VM::pop() {
	if (this->stack.empty())
		throw StackException();

	IOperand const *operand = this->stack.back();

	this->stack.pop_back();

	return operand;
}

IOperand const *VM::top() const {
	if (this->stack.empty())
		throw StackException();

	return this->stack.back();
}

void	VM::assertEquals(IOperand const *expected) const {
	if (this->stack.empty())
		throw StackException();

	IOperand const *operand = this->stack.back();

	if (operand->toString() != expected->toString()) {
		delete expected;
		throw AssertionException("Error: Could not assert that " + operand->toString() + " = " + expected->toString());
	}
	
	delete expected;
}

void	VM::render(IOperand const *operand) const {
	if (operand->getType() == Int8) {
		std::cout << (int8_t) stod(operand->toString()) << std::endl;
	} else {
		std::cout << operand->toString() << std::endl;
	}
}

void	VM::print() const {
	this->render(this->top());
}

void	VM::dump() const {
	for (auto operand = this->stack.rbegin(); operand != this->stack.rend(); ++operand) {
		this->render(*operand);
	}
}

void	VM::add() {
	this->push(this->process(Plus));
}

void	VM::sub() {
	this->push(this->process(Minus));
}

void	VM::mul() {
	this->push(this->process(Times));
}

void	VM::div() {
	this->push(this->process(Divide));
}

void	VM::mod() {
	this->push(this->process(Modulo));
}

void	VM::freeStack() {
	while (!this->stack.empty()) {
		delete this->pop();
	}
}
