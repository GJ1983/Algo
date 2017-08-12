#include<iostream>


class base
{
public:
	void PrintMsg(int a)
	{
		std::cout<<" Printing from PrintMsg of integer parameter. "<<std::endl;
	}
	virtual void PrintMsg(std::string msg = " Base version")
	{
		std::cout<<" Printing from "<<msg<<std::endl;
	}
protected:
	void forTesting()
	{
		std::cout<<" For testing overiding of protected from base: "<<std::endl;
	}
};

class Derived : public base
{
public:
	using base::PrintMsg;  // To make line 33 compile, we need to add this here
	virtual void PrintMsg(std::string msg = " Derived version")
	{
		std::cout<<" Printing from "<<msg<<std::endl;
	}
	void forTesting()
	{
		std::cout<<" For testing overiding of protected from Derived: "<<std::endl;
	}

};

namespace A
{
	struct x {} ;
	void function(x)
	{
		std::cout<<" Inside function with integer argument: "<<std::endl;
	} 	
	void function()
	{
		std::cout<<" Inside function with without argument: "<<std::endl;
	}
}

int global;

int Multiply(int &a)
{
	return a*10;
}

int& Global()
{
	return global;
}

int main()
{
        A::x x1;
	function(x1);
	//function();  This line will not compile, However above line will compile
	base *bptr = new Derived();
	bptr->PrintMsg();
	Derived *dptr = new Derived();
        dptr->PrintMsg(10);   // This line will not compile, to make it compile we need using::PrintMsg in public segment of Derived class

        int i = 80;

        //Multiply(10);
        Multiply(i);
        Global() = 89 ;
        std::cout<<" global is : "<<global<<std::endl;
        Derived d;
        d.forTesting();
	return 0;
}
