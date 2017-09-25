#include<iostream>
#include<cstdio>
#include<cstring>

class Base
{
public:
	virtual void fun()
	{
		std::cout<<" From Base .."<<std::endl;
	}
};

//class Derived : public Base
//{
//};
class Derived : public Base
{
public:
	virtual void fun()
	{
		std::cout<<" From Base .."<<std::endl;
	}
};


struct TestConst
{
	TestConst()
	{
		std::cout<<" Inside struct constructor "<<std::endl;
	}
	~TestConst()
	{
		std::cout<<" Inside destructor .. "<<std::endl;
	}

};




//Reference counting string

class String
{
private:
	struct StringValue
	{
		int refCount;
		char *data ;
		StringValue(const char * initValue);
		~StringValue();
	};
	StringValue *value;
public:
	String(const char *initValue);
	String(const String & rhs);
	~String();
};

String::StringValue::StringValue(const char *initValue):refCount(1)
{
	data = new char[strlen(initValue)+1];
	strcpy(data,initValue);
}

String::StringValue::~StringValue()
{
	delete [] data;
}

String::String(const char *initValue):value(new StringValue(initValue) )
{

}

String::String(const String & rhs):value(rhs.value)
{
	++value->refCount;
}

String::~String()
{
	if(--value->refCount == 0)
		delete value;
}

int main()
{
std::cout<<" Main started "<<std::endl;
//static int a = 5;
//printf("%d",a--);
//if(a)
//main();
int *tt;
Base *pp = new Derived();

std::cout<<" Size of Base .."<<sizeof(Base)<<std::endl;
std::cout<<" Size of Derived .."<<sizeof(Derived)<<std::endl;

TestConst *tc = new TestConst();

TestConst ttc;

//p = static_cast<Base *>(tt);
//p = reinterpret_cast<Base *>(tt);

String s1(" Reference Counting string.");
String s2 = s1;
delete tc;
return 0;
}
