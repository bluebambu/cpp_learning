#include <iostream>
#include <ctime>
#include <vector>

class A {
public:
	int num = 0;
	A(){
		std::cout << "A ctor called!"<<std::endl;
	}
	A(A& a){
		num = a.num;
		std::cout << "A move ctor called!"<<std::endl;
	}
	A(const A& a){
		num = a.num;
		std::cout << "A copy ctor called!"<<std::endl;
	}
};

const A& func() {
	return A();
}

void mv(A&& a) {
	a.num = 2;
	A a2 = std::move(a); // will call move-ctor
	std::cout<<a2.num<<std::endl;
}

void copy_move(A&& a) {
	A a2 = a; // will call copy-ctor
}

int main () {

	mv(A()); // 想节约资源，就要用 move；想用 move并且想接受 temp var，就要用 rvalue。
	std::cout << "\033[1;31m ---seperator--- \033[0m \n";
	copy_move(A());
	std::cout << "\033[1;31m ---seperator--- \033[0m \n";
	func();

	clock_t now = clock();
	// colorful output
	std::cout << "\033[1;31m assigning lvalue...\033[0m \n";
	std::cout << "\033[1;31m ended assigning lvalue...\033[0m \n";
	std::cout << "time lapsed: " << (clock() - now) << std::endl;
}
