#include<string>
#include<vector>
#include<iostream>

int main()
{
std::string arr[]  = {"test","c","modern","network" };

std::vector<std::string> vecofstrings(arr, arr+sizeof(arr)/sizeof(std::string)) ;
return 0;
}
