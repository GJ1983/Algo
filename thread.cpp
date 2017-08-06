#include<thread>
#include<iostream>
#include<fstream>
#include<mutex>

std::mutex mu;

void shared_print(std::string msg, int id)
{
	//mu.lock();  // May cause resource leak
	std::lock_guard<std::mutex> gu(mu);  // RAII
	std::cout<<msg<<id<<std::endl;
	//mu.unlock();
}

class LogFile
{
	std::mutex m_mutex;
	std::ofstream f;
public:
	LogFile()
	{
		f.open("log.txt");
	}
	void shared_print(std::string msg, int id)
	{
		std::lock_guard<std::mutex> gu(m_mutex);
		std::cout<<msg<<id<<std::endl;
	}
};

/********************* To Avoid deadlock **************************************************
******* 1. First ask Do you really need 2 mutex at a time *********************************
******* 2. Prefer single mutex at a time   ************************************************
******* 3. Avoid locking a mutex and then calling user provided function ******************
******* 4. Use std::lock to lock more than one mutex **************************************
******* 5. if usage of std::lock is not possible, then take mutex in the same order *******
* Locking granularity ======
* 1- Fine grained lock : protects small amount of data ************************************
* 2- Coarse grained lock : protects big amount of data ************************************
***
**** If you are taking two fine grained lock, than you are more exposed to deadlock ********
**** If you are taking two coarse grained lock, than you are loosing parellel computing ****
********************************************************************************************/



class Deadlock
{
	std::mutex m_mutex;
	std::mutex m_mutex2;
	std::ofstream f;
public:
	Deadlock()
	{
		f.open("log.txt");
	}
	void shared_print(std::string msg, int id)
	{
		std::lock(m_mutex,m_mutex2);  // To avoid deadlock
		//std::lock_guard<std::mutex> gu(m_mutex);
		//std::lock_guard<std::mutex> gu2(m_mutex2);
		std::lock_guard<std::mutex> gu(m_mutex, std::adopt_lock);  // adopt_lock is to notify lock has already taken, you just need to take ownership
		std::lock_guard<std::mutex> gu2(m_mutex2, std::adopt_lock);
		std::cout<<msg<<id<<std::endl;
	}
	void shared_print2(std::string msg, int id)
	{
		std::lock(m_mutex,m_mutex2);  // To avoid deadlock
		//std::lock_guard<std::mutex> gu2(m_mutex2);
		//std::lock_guard<std::mutex> gu(m_mutex);
		std::lock_guard<std::mutex> gu2(m_mutex2,std::adopt_lock);
		std::lock_guard<std::mutex> gu(m_mutex,std::adopt_lock);
		std::cout<<msg<<id<<std::endl;
	}
};

//void function_1(LogFile& log)
void function_1(Deadlock& dl)
{
	for(int i = 0 ; i>= -100; i--)
		//std::cout<<" from t1:  "<<i<<std::endl;
		//shared_print(std::string(" from t1:  "), i);
		//log.shared_print(std::string(" from t1:  "), i);
		dl.shared_print(std::string(" from t1:  "), i);
}

int main()
{

        std::cout<<std::thread::hardware_concurrency()<<std::endl;  // cpu core indication

        LogFile log;
        Deadlock dl;

        //std::thread t1(function_1,std::ref(log));
        std::thread t1(function_1,std::ref(dl));

	for(int i = 0; i<=100; i++)
	//	std::cout<<" from main: "<<i<<std::endl;
		//shared_print(std::string(" from main:  "), i);
		//log.shared_print(std::string(" from main:  "), i);
		dl.shared_print2(std::string(" from main:  "), i);

	t1.join();

	return 0;
}
