#include<iostream>
#include<mutex>


std::mutex mtx;

// Facade Pattern

class Headlight
{
public:
	void OnHeadLight()
	{
		std::cout<<" Headlight is switched on .. "<<std::endl;
	}
};

class Engine 
{
public:
	void TurnIgnitionOn()
	{
		std::cout<<" Ignition is  on .. "<<std::endl;
	}
};

class Facade
{
	Headlight hl;
	Engine ee;
public:
	void StartVechicle()
	{
		ee.TurnIgnitionOn();
		hl.OnHeadLight();
	}
};

// Singleton pattern
class Singleton
{
private:
	static Singleton *instance ;
	Singleton() {}
	Singleton(Singleton&);
	Singleton& operator=(Singleton&);
public:
	static Singleton* getInstance()
	{
		if(instance == NULL) 
		{
			std::lock_guard<std::mutex> lg(mtx);
			if(instance == NULL)
			{
				instance = new Singleton();
			}
		 }
                

		return instance;
	}
};

Singleton * Singleton::instance = NULL; 

int main()
{
	Singleton *single = Singleton::getInstance();
	Singleton *single1 = Singleton::getInstance();

//Facade

        Facade fe;
        fe.StartVechicle();
	return 0;
}
