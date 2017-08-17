#include<string>
#include "boost/lexical_cast.hpp"

using boost::lexical_cast ;
using boost::bad_lexical_cast;

int main()
{
int s = 23;
std::string ss = lexical_cast<std::string>(s);
//string s = lexical_cast<string>(s);
return 0;
}
