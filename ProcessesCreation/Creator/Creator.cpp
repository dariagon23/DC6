#include <conio.h>
#include<iostream>
#include<fstream>
using namespace std;
struct employee
{
int num; 
char name[10]; 
double hours; 
};

int main(int argc, char *argv[])
{
	char binName[20];
	strcpy(binName, argv[1]);
	int count = atoi(argv[2]);
	employee emp;
	fstream fout(binName, ios::out);
	for(int i=0; i<count; i++)
	{
		std::cin >> emp.num >> emp.name >> emp.hours; 
		fout.write((char*)&emp, sizeof(employee));
	}
	fout.close();
	_getch();

 return 0;
} 