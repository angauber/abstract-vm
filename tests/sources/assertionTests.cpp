#include <catch2/catch.hpp>
#include "../../vm/includes/vm.hpp"
#include <stack>

TEST_CASE( "Assertions exceptions", "[operations, overflow]" ) {
	OperandFactory factory;
	VM vm;

	vm.push(factory.createOperand(Int16, "1856"));

	vm.assertEquals(factory.createOperand(Int16, "1856"));

	try {
		vm.assertEquals(factory.createOperand(Int16, "1855"));

		REQUIRE( false );
	} catch (AssertionException const &e) {
		REQUIRE( true );
	}
}
