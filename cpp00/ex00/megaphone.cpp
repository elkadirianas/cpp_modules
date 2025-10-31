#include <iostream>


void PrintUpper(std::string str){
	int len = str.length();
	for(int i = 0 ; i<len;i++)
		str[i]=std::toupper(str[i]);
	std::cout << str ;
}

int main(int argc , char **argv){
	int i =1 ;
	if(argc>1)
	{
		while(i<argc)
		{
			PrintUpper(argv[i]);
			i++;
		}
	}
	else 
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; 
	std::cout << std::endl ;
	return 0 ; 
}
