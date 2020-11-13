#include "lexer.hpp"

#include <typeinfo>

int	main(int ac, char **av) {
	Lexer lexer;

	if (ac == 2) {
		lexer.readFromFile(av[1]);
	} else {
		lexer.readFromStdin();	
	}

	return 0;
}
