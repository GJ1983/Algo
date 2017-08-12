#include<iostream>
#include<thread>
#include<deque>
#include<mutex>
#include<condition_variable> 


std::deque<int> deq;
std::mutex mu;
std::condition_variable cond;


///// Producer 
void function_1()
{
	int count = 10;

	while(count > 0)
	{
		std::unique_lock<std::mutex> locker(mu);
		deq.push_front(count);
		locker.unlock();

                cond.notify_one();    // Notify 

		std::this_thread::sleep_for(std::chrono::seconds(1));
		count--;
	}
}

//// consumer 
void function_2()
{
	int data = 0;
	while(data != 1)
	{
		std::unique_lock<std::mutex> locker(mu);
		//if(!deq.empty() )    //// busy waiting, to avoid this we need condition variable
		//{

                 cond.wait(locker);  // spurious wake, if thread wake by itself and if condition is not satisfied
                 cond.wait(locker, [](){ return !deq.empty() ;});  // by using this lambda expression we are preventing spurious wake

			data = deq.back();
			deq.pop_back();
			locker.unlock();
			std::cout<<"t2 got a value from t1: "<< data << std::endl;
		//}
		//else
		//{
			//locker.unlock();
		//}
	}
}

int main()
{
return 0;
}
