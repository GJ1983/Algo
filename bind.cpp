#include<iostream>
#include<functional>


int fun(int a, int b, int c)
{
	std::cout<<(a-b-c)<<std::endl;
}

int main()
{
	using namespace std::placeholders ;

	auto fn1 = std::bind(fun, _1, 2, 3);

	fn1(10);

	auto fn2 = std::bind(fun, 2, _1, 3);
	fn2(10);

	return 0;
}
