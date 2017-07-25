#include<iostream>
#include<boost/bimap.hpp>
#include<string>

//using namespace std;

int main()
{
	typedef boost::bimap<std::string, int> bimap;
	bimap animals;

	animals.insert({"cat",4});
	animals.insert({"shark",0});
	animals.insert({"spider",8});

	std::cout<<animals.left.count("cat") << std::endl;
	std::cout<<animals.right.count(8) << std::endl;

        //for(auto it = animals.begin(); it != animals.end(); ++it)
        for(boost::bimap<std::string,int>::iterator it = animals.begin(); it != animals.end(); ++it)
        std::cout<< it->left << " has "<< it->right << " legs "<<std::endl;
	return 0;
}
