#include <catch2/catch.hpp>
#include "../../vm/includes/vm.hpp"

TEST_CASE( "Basic operations test", "[operations]" ) {
	const IOperand *top;
	OperandFactory factory;
	VM vm;

	vm.push(factory.createOperand(Int16, "12"));
	vm.push(factory.createOperand(Int16, "21"));

	vm.add();

	top = vm.top();

	REQUIRE( top->getType() == Int16 );
	REQUIRE( top->toString() == "33" );

	vm.push(factory.createOperand(Int32, "13"));

	vm.sub();

	top = vm.top();

	REQUIRE( top->getType() == Int32 );
	REQUIRE( top->toString() == "20" );
}
