#include<iostream>
#include<thread>
#include<future>

std::once_flag oflag;

class A
{
public:
	void f(int i, char c)
	{
	}
	long g(double x)
	{
		return 0;
	}

	int operator()(int N)
	{
		return 0;
	}
};

int foo(int x)
{
	return x*x;
}

int main()
{
	A a;
	std::thread th(a,6);   // copy of a in different thread
	std::thread th1(std::ref(a),6);  // a in different thread
	std::thread th2(A(),6);  // temporary A(), and then it is moved in different thread
	std::thread th3([](int x){ return x*x; },6);  // using lambda

	std::thread th4(&A::f,a,8,'a');   // copy of  in different thread , using member function
	std::thread th5(&A::f,&a,8,'a');   //original a  in different thread , using member function

	std::thread th6(foo,9);   // copy of a in different thread, using non member function


	std::async(std::launch::async,a,6);
	std::bind(a,6);
	std::call_once(oflag,a,6);
	return 0;
}
