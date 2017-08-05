#include<iostream>
#include<memory>
#include<vector>


std::weak_ptr<int> gw;

void fun()
{
	std::cout<<"Use count ==  "<<gw.use_count()<<":";
	//if(auto spt == gw.lock)
	//	std::cout<<*spt<<std::endl;
	//else
	//	std::cout<<"gw is expired \n";
}

int main()
{
//	{
//		auto sp = std::make_shared<int>(42);
//		gw = sp;
//		fun();
//	}

	//fun();

        union
	{
		int ii;
		float ff;
	};

	ii = 89;
	ff = 98.76;


        std::vector<std::unique_ptr<int> > vec;

        int x(1);
 
        std::unique_ptr<int> ptr (&x);

        //vec.push_back(std::move(ptr));


        std::vector<std::shared_ptr<int> > vec1;

        int x1(1);

        std::shared_ptr<int> ptr1 (&x1);

        vec1.push_back(ptr1);

	return 0;
}



