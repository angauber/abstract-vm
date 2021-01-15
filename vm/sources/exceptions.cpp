#include "exceptions.hpp"

Exception::Exception(std::string const &msg) {
	this->msg = msg;
	this->format();
}

void	Exception::setLine(lineInfos const *line) {
	this->line = line;

	this->format();
}

void	Exception::format() {
	this->error = this->msg;

	if (this->line) {
		if (this->line->nb > 0)
			this->error += " on line " + std::to_string(this->line->nb);
	
		if (!this->line->content.empty())
			this->error += ": \"" + this->line->content + "\"";
	}
}

char const	*Exception::what() const noexcept {
	return this->error.c_str();
}

OverflowException::OverflowException(std::string const &msg) : Exception(msg) {}

UnderflowException::UnderflowException(std::string const &msg) : Exception(msg) {}

DivisionException::DivisionException(std::string const &msg) : Exception(msg) {}

ModuloException::ModuloException(std::string const &msg) : Exception(msg) {}

ParsingException::ParsingException(std::string const &msg) : Exception(msg) {}

StackException::StackException(std::string const &msg): Exception(msg) {}

AssertionException::AssertionException(std::string const &msg) : Exception(msg) {}

OperationException::OperationException(std::string const &msg) : Exception(msg) {}
