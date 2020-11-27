#include "vm.hpp"

IOperand const	*VM::process(IOperand const *v1, IOperand const *v2, Sign sign) {
	IOperand const *result;

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

void	VM::assertEquals(IOperand const *expected) {
	if (this->stack.empty())
		throw StackException();

	IOperand const *operand = this->stack.back();

	if (operand->toString() != expected->toString())
		throw AssertionException("Error: Could not assert that " + operand->toString() + " = " + expected->toString());
}

void	VM::print() {
	if (this->stack.empty())
		throw StackException();

	IOperand const *operand = this->stack.back();

	std::cout << operand->toString() << std::endl; 
}


void	VM::dump() {
	for (auto it = this->stack.rbegin(); it != this->stack.rend(); ++it) {
		std::cout << (*it)->toString() << std::endl; 
	}
}

void	VM::add() {
	IOperand const *v2 = this->pop();
	IOperand const *v1 = this->pop();

	this->push(this->process(v1, v2, Plus));
}

void	VM::sub() {
	IOperand const *v2 = this->pop();
	IOperand const *v1 = this->pop();

	this->push(this->process(v1, v2, Minus));
}

void	VM::mul() {
	IOperand const *v2 = this->pop();
	IOperand const *v1 = this->pop();

	this->push(this->process(v1, v2, Times));
}

void	VM::div() {
	IOperand const *v2 = this->pop();
	IOperand const *v1 = this->pop();

	this->push(this->process(v1, v2, Divide));
}

void	VM::mod() {
	IOperand const *v2 = this->pop();
	IOperand const *v1 = this->pop();

	this->push(this->process(v1, v2, Modulo));
}

void	VM::exit() {
	this->freeStack();
	std::exit(0);
}

void	VM::freeStack() {
	for (IOperand const *operand : this->stack) {
		delete operand;
	}
}
