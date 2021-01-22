#include <catch2/catch.hpp>
#include "../../vm/includes/vm.hpp"
#include <stack>

TEST_CASE( "Overflows on push", "[operations, overflow]" ) {
	OperandFactory factory;
	VM vm;

	try {
		vm.push(factory.createOperand(Int8, "128"));

		REQUIRE( false );
	} catch (OverflowException const &e) {
		REQUIRE( true );
	}

	try {
		vm.push(factory.createOperand(Int8, "-129"));

		REQUIRE( false );
	} catch (UnderflowException const &e) {
		REQUIRE( true );
	}
}

TEST_CASE( "Overflow on operation", "[operations, overflow]" ) {
	OperandFactory factory;
	VM vm;

	vm.push(factory.createOperand(Int8, "127"));
	vm.push(factory.createOperand(Int8, "1"));

	try {
		vm.add();

		REQUIRE( false );
	} catch (OverflowException const &e) {
		REQUIRE( true );
	}

	vm.push(factory.createOperand(Int8, "-128"));
	vm.push(factory.createOperand(Int8, "1"));

	try {
		vm.sub();

		REQUIRE( false );
	} catch (UnderflowException const &e) {
		REQUIRE( true );
	}
}
