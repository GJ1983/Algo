#include<iostream>


class TClassA
{
public:
	void Display(const char *text)
	{
		std::cout<<text <<std::endl;
	}

	static void Wrapper_to_call_display(void *pt2Object, char * text);
};


void TClassA::Wrapper_to_call_display(void *pt2Object, char * text)
{
	TClassA *myself = (TClassA *)pt2Object;
	myself->Display(text);
}

void DoItA(void *p2tObject, void (*pt2Function)(void *pt2Object, char * text) )
{
	pt2Function(p2tObject, "Hi, This is just a Callback for testing.");
}

int main()
{
        TClassA obj;
   
        DoItA(&obj, TClassA::Wrapper_to_call_display);

	return 0;
}
