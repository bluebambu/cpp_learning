#include <iostream>
#include <ctime>
#include <vector>

class A {
public:
	int num = 0;
	A(){
		std::cout << "A ctor called!"<<std::endl;
	}
	A(A&& a){
		num = a.num;
		std::cout << "A move ctor called!"<<std::endl;
	}
	A(const A& a){
		num = a.num;
		std::cout << "A copy ctor called!"<<std::endl;
	}
};

A func() {
	return A();
}

void mv(A&& a) {
	A a2 = std::move(a); // will call move-ctor
}

void copy_move(A&& a) {
	A a2 = a; // will call copy-ctor
}

int main () {

	mv(A());
	std::cout << "\033[1;31m ---seperator--- \033[0m \n";
	copy_move(A());


	clock_t now = clock();
	// colorful output
	std::cout << "\033[1;31m assigning lvalue...\033[0m \n";
	std::cout << "\033[1;31m ended assigning lvalue...\033[0m \n";
	std::cout << "time lapsed: " << (clock() - now) << std::endl;
}
