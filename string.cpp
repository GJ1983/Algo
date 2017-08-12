#include<iostream>
#include<vector>
#include<list>
#include<algorithm>


int main()
{

	std::list<int> ll = {4,8,2,4,4,4,6,5,8,4,2,6,9,10};

	std::remove(ll.begin(),ll.end(), 4);   // std::remove 
        //ll.remove(4);

        //ll.erase(itr, ll.end());

	std::list<int>::iterator liter = ll.begin();

	while(liter != ll.end() )
	{
		std::cout<<*liter<<std::endl;
		liter++;
	}

        std::cout<<" Vector functions starts ...... "<<std::endl;
        std::cout<<" ============================== "<<std::endl;
        std::cout<<" ============================== "<<std::endl;
        std::cout<<" ============================== "<<std::endl;
        std::cout<<" ============================== "<<std::endl;

	std::vector<int> vv = {3,8,2,3,3,3,6,5,8,3,2,6,9,10};
	auto itr = std::remove(vv.begin(),vv.end(), 3);  
        vv.erase(itr, vv.end());
 
        std::cout<<"capacity is : "<<vv.capacity()<<std::endl;

        vv.shrink_to_fit();

        std::cout<<"capacity after shrinking is : "<<vv.capacity()<<std::endl;

	std::vector<int>::iterator viter = vv.begin();

	while(viter != vv.end() )
	{
		std::cout<<*viter<<std::endl;
		viter++;
	}

	std::string s1("Hello");
	std::cout<<" s1 is : "<< s1<<std::endl;
	std::string s2("Hello",3);
	std::cout<<" s2 is : "<< s2<<std::endl;
	std::string s3(s1,3);
	std::cout<<" s3 is : "<< s3<<std::endl;
	std::string s4(s1,3,2);
	std::cout<<" s4 is : "<< s4<<std::endl;
	std::string s5({'a','b','c'});
	std::cout<<" s5 is : "<< s5 <<std::endl;
	std::string s6(5,'a');
	std::cout<<" s6 is : "<< s6<<std::endl;

	return 0;
}
