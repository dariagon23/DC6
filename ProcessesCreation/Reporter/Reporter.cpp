#include<iostream>
#include<fstream>
using namespace std;
struct employee
{
int num; 
char name[10]; 
double hours; 
};
int mycmp(const void* a, const void* b)
{
	employee* a1 = (employee*)a;
	employee* b1 = (employee*)b;
	char* sa = (*a1).name;
	char* sb = (*b1).name;
	return strcmp(sa, sb);
}

int main(int argc, char *argv[])
{
	employee* emp;
	int count=3;
	int pay = atoi(argv[3]);

	fstream in(argv[1], ios::in);
	//file size
	in.seekg(0, ios::end);
	count=in.tellg();
	count= count / sizeof(employee);
	in.seekg(0, ios::beg);
	emp = new employee[count];
	//reading
	for (int i=0; i<count; i++)
	{		
		in.read((char*)&emp[i], sizeof(employee));
	}
	in.close();
	//sort by names
	qsort(emp, count, sizeof(employee), mycmp);
	//writing to txt
	ofstream out(argv[2]);
	out << "Report file \"" << argv[1] << "\"" << endl;
	out << "Employee's id num, employee's name, hours, salary" << endl;
	for (int i = 0; i < count; i++)
	{
		out << emp[i].num << " " << emp[i].name << " " << emp[i].hours << " " << emp[i].hours *pay  << endl;
	}
	out.close();
	delete[]emp;
	return 0;
}