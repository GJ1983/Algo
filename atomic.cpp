#include<iostream>
#include<atomic>

class atom
{
private:
	std::atomic<int> count;
public:
	atom()
	{
		count = 0;
	}
	void increment()
	{
		count++;
	}
	void decrement()
	{
		count--;
	}
	int getValue()
	{
		return count.load();
	}
};

int main()
{
	atom a;
        a.increment();
	std::cout<<" atomic value is : "<< a.getValue() <<std::endl;
        a.decrement();
	std::cout<<" atomic value after decrement is : "<< a.getValue() <<std::endl;
	return 0;
}
