#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <string>
#include <exception>

#include "lineInfos.hpp"

class Exception : public std::exception {
	public:
								Exception(std::string const &);
		void					setLine(lineInfos const *line);
	    virtual char const *	what() const noexcept override;
		void					format();
	private:
		std::string			error;
		std::string			msg;
		lineInfos const	*	line = NULL;
};

class OverflowException : public Exception {
	public:
		OverflowException(std::string const & = "Error: Overflow");
};

class UnderflowException : public Exception {
	public:
		UnderflowException(std::string const & = "Error: Underflow");
};

class ModuloException : public Exception {
	public:
		ModuloException(std::string const & = "Error: Modulo on floating numbers is forbidden");
};

class DivisionException : public Exception {
	public:
		DivisionException(std::string const & = "Error: Division by zero is forbidden");
};

class ParsingException : public Exception {
	public:
		ParsingException(std::string const & = "Error: Unknown syntax");
};

class StackException : public Exception {
	public:
		StackException(std::string const & = "Error: Stack is empty");
};

class AssertionException : public Exception {
	public:
		AssertionException(std::string const & = "Error: Assert instruction is not correct");
};

class OperationException : public Exception {
	public:
		OperationException(std::string const & = "Error: Unknown operation");
};

#endif
