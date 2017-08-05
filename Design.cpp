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
			mtx.lock();
			if(instance == NULL)
			{
				instance = new Singleton();
				mtx.unlock();
			}
		 }
                

		return instance;
	}
};

Singleton * Singleton::instance = NULL; 

int main()
{
	Singleton *single = Singleton::getInstance();
	return 0;
}
