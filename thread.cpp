#include<thread>
#include<iostream>

void thread_function()
{
	for(int i = 0; i< 100; i++)
	std::cout << " Thread is runing : " << std::endl;
}

int main()
{
	std::thread threadobj(thread_function) ;

	for(int i =0 ; i< 100 ;i++)
	std::cout << " Display from Main thread : " <<std::endl;
	threadobj.join();

	std::cout<< " Exit from the main thread : " << std:: endl;

	return 0;
}
