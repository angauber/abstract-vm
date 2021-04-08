#include <stack>
#include <catch2/catch.hpp>
#include "../../vm/includes/vm.hpp"

TEST_CASE( "Negative test", "[operations]" ) {
	std::stack<eOperandType> types;
	OperandFactory factory;
	VM vm;

	vm.push(factory.createOperand(Int32, "32"));
	vm.push(factory.createOperand(Int32, "64"));

	vm.sub();

	REQUIRE( vm.top()->toString() == "-32" );
}

TEST_CASE( "Negative test on floating type", "[operations]" ) {
	std::stack<eOperandType> types;
	OperandFactory factory;
	VM vm;

	vm.push(factory.createOperand(Double, "32"));
	vm.push(factory.createOperand(Double, "64"));

	vm.sub();

	REQUIRE( vm.top()->toString() == "-32" );
}
