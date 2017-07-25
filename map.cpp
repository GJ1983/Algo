#include<map>
#include<iostream>
#include<string>

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
	return 0;
}
