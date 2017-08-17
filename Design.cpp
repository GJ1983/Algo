#include<iostream>
#include<mutex>


std::mutex mtx;

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
	return 0;
}
