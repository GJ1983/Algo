#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<string>
#include<list>
#include<algorithm>

//struct cmpbyStringLength
//{
//	bool operator() (const std::string &a, const std::string &b ) const
//	{
//		return a.length() < b.length();
//	}
//};

class cmpbyStringLength
{
public:
	bool operator() (const std::string &a, const std::string &b ) const
	{
		return a.length() < b.length();
	}
};


int main()
{
	std::string arr[]  = {"test","c","modern","network" };
	std::vector<std::string> vecofstrings(arr, arr+sizeof(arr)/sizeof(std::string)) ;

	std::map<std::string, int, cmpbyStringLength> mapofwords;
	//std::map<std::string, int> mapofwords;
	mapofwords.insert(std::make_pair("earth",1));
	mapofwords.insert(std::make_pair("sun",2));
	mapofwords.insert(std::make_pair("moon",3));
	mapofwords.insert(std::make_pair("mars",4));
	mapofwords.insert(std::make_pair("venus",5));
	mapofwords.insert(std::make_pair("mercury",6));
	mapofwords.insert(std::make_pair("saturn",7));
	mapofwords.insert(std::make_pair("jupiter",8));

	// add or update functionality, when an add is performed insert is more effieint than operator[]. This situation is reversed when we do an update

        mapofwords["test"] = 9;
        mapofwords["earth"] = 9;

	// check insertion status
	if(mapofwords.insert(std::make_pair("earth",1)).second == false)
	{
		std::cout<<" elemnent with key earth is not iserted as it already present "<< std::endl;
	} 

	// find

	if (mapofwords.find("mars") != mapofwords.end() )
	{
		std::cout<<" serached key is present in the map " <<std::endl;
	}

	std::map<std::string,int>::iterator mapitre = mapofwords.begin();
	while(mapitre != mapofwords.end() )
	{
		std::cout<< mapitre->first <<" :: " << mapitre-> second << std::endl;
		mapitre++;
	}

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
