#include<iostream>
#include<cstring>
#include<cstdlib>



void reverse(char *str)
{
	std::cout<<str<<std::endl;

	int index = 0;
        int tindex = 0;

	int length = strlen(str);

	char *temp = (char *)malloc(length*sizeof(int));

	while(str[index] != '\0')
	{
		std::cout<<str[index];

		*(temp+tindex) = *(str+index);

		if(std::isspace(*(str+index)))
                {
			std::cout<<"======> "<<std::endl;
                        strcpy(temp, '\0');
			tindex = 0;
		}

                 
		index++;
		tindex++;
		std::cout<<" temp is "<<temp<<std::endl;
	}
}

void copy (char *str)
{
	int index = 0;

	int length = strlen(str);

	char *temp = (char *)malloc(length*sizeof(int));
         
        while(*(str+index))
        {
		*(temp+index) = *(str+index) ;
                index++; 
	}

	std::cout<<" temp is ====>"<<temp<<std::endl;
}

int main()
{

char *str = "my career stack";
reverse(str);
//copy(str);
return 0;
}
