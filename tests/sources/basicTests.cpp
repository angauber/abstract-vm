#include <stack>
#include <catch2/catch.hpp>
#include "../../vm/includes/vm.hpp"

TEST_CASE( "Basic tests", "[operations]" ) {
	std::stack<eOperandType> types;
	eOperandType type;
	OperandFactory factory;
	VM vm;

	types.push(Int8);
	types.push(Int16);
	types.push(Int32);
	types.push(Float);
	types.push(Double);

	while (!types.empty()) {
		type = types.top();
		types.pop();

		vm.push(factory.createOperand(type, "17"));
		vm.push(factory.createOperand(type, "36"));
		vm.push(factory.createOperand(type, "2"));
		vm.push(factory.createOperand(type, "22"));
		vm.push(factory.createOperand(type, "16"));
		vm.push(factory.createOperand(type, "3"));

		vm.add(); // 16 + 3

		REQUIRE( vm.top()->getType() == type );
		REQUIRE( vm.top()->toString() == "19" );

		vm.sub(); // 22 - 19

		REQUIRE( vm.top()->getType() == type );
		REQUIRE( vm.top()->toString() == "3" );

		vm.mul(); // 2 * 3

		REQUIRE( vm.top()->getType() == type );
		REQUIRE( vm.top()->toString() == "6" );

		vm.div(); // 36 / 6

		REQUIRE( vm.top()->getType() == type );
		REQUIRE( vm.top()->toString() == "6" );

		if (type != Float && type != Double) {
			vm.mod(); // 17 % 6

			REQUIRE( vm.top()->getType() == type );
			REQUIRE( vm.top()->toString() == "5" );
		}

		vm.freeStack();
	}
}
