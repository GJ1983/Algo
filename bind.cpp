#include<iostream>
#include<functional>


int fun(int a, int b, int c)
{
	std::cout<<(a-b-c)<<std::endl;
}

class Test
{
private:
	int a, b;
        int *x;
public:
	Test(int a1, int b1)
	try: a(a1), b(b1),x(new int() )
	{
		std::cout<<" Inside Constructor...."<<std::endl;
	}
	catch(...)
	{
	}
};

class Test_static
{
public:
	void print()
	{
		std::cout<<" Hello from test_static class "<<std::endl;
	}
};

void fibonacci(int n)
{
	long a=0, b=1, sum;

	for(int i=0; i<=n; i++)
	{
		sum = a+b;
		a = b;
		b = sum;
		std::cout<<a<<std::endl;
	}
}

int main()
{
	using namespace std::placeholders ;

        static Test_static ts1;
        ts1.print();

	auto fn1 = std::bind(fun, _1, 2, 3);

	fn1(10);

	auto fn2 = std::bind(fun, 2, _1, 3);
	fn2(10);

        Test t1(10,50);

        fibonacci(50);

	return 0;
}
