#include <catch2/catch.hpp>
#include "../../vm/includes/vm.hpp"

TEST_CASE( "Different types tests", "[operations]" ) {
	OperandFactory factory;
	VM vm;

	vm.push(factory.createOperand(Int16, "165"));
	vm.push(factory.createOperand(Int8, "15"));

	vm.sub();

	REQUIRE( vm.top()->getType() == Int16 );
	REQUIRE( vm.top()->toString() == "150" );

	vm.push(factory.createOperand(Float, "1.5"));

	vm.div();

	REQUIRE( vm.top()->getType() == Float );
	REQUIRE( vm.top()->toString() == "100" );

	vm.push(factory.createOperand(Double, "4.5"));
	
	vm.add();

	REQUIRE( vm.top()->getType() == Double );
	REQUIRE( vm.top()->toString() == "104.5" );

	vm.freeStack();
}
