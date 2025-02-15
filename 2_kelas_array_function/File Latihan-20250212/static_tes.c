#include <stdio.h>

void display();

int main()
{
	display();
	display();
}

void display()
{
	static int c = 0;
	// int c = 0; //jika ingin bandingkan tanpa static
	printf("print pertama = %d \n",c++);
	//c += 5;
	printf("print kedua = %d \n",c++);
}
