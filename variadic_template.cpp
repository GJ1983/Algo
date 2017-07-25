#include<iostream>

using namespace std;

void printstuff()
{
	cout<< endl ;
}

template <typename Tfirst, typename... Trest>
void printstuff (Tfirst first, Trest... rest)
{
	cout<< first << " ";
	printstuff(rest...);
}

void printMyThings()
{
	printstuff(3,3.3,"foo", 42);
}

int main()
{
	printMyThings();
	return 0;
}
