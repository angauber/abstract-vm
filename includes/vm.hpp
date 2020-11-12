#ifndef VM_HPP
#define VM_HPP

#include <vector>
#include <iostream>

#include "lineInfos.hpp"
#include "sign.hpp"
#include "operand.hpp"
#include "exceptions.hpp"

class VM {
	public:
		IOperand const *	process(IOperand const *, IOperand const *, Sign);
		IOperand const *	pop();

		void				push(IOperand const *);
		void				assert(IOperand const *);
		
		void				add();
		void				sub();
		void				mul();
		void				div();
		void				mod();

		void				dump();
		void				print();
		void				exit();	

		void				freeStack();
	private:
		std::vector<IOperand const *>	stack;
};

#endif
