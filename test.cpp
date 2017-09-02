#include<iostream>
#include<cstdio>
#include<cstring>

class Base
{
public:
virtual ~Base() = 0;
};

//class Derived : public Base
//{
//};




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
Base *p;

//p = static_cast<Base *>(tt);
p = reinterpret_cast<Base *>(tt);

String s1(" Reference Counting string.");
String s2 = s1;
return 0;
}
