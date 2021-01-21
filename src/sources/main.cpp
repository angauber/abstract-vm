#include "lexer.hpp"

#include <typeinfo>

int	main(int ac, char **av) {
	Lexer lexer;

	if (ac == 2) {
		return lexer.readFromFile(av[1]);
	} else {
		return lexer.readFromStdin();	
	}
}
