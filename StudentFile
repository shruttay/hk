#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct Stud
{
	int roll;
	string name;
	string div;
	string address;
}student;

void create()
{
	ofstream fout;
	fout.open("data.txt", ios::trunc);
	int ans = 1;
	do
	{
		cout<<"\nEnter Roll No : ";
		cin>>student.roll;
		fout<<student.roll<<" ";
		cout<<"\nEnter Name : ";
		cin>>student.name;
		fout<<student.name<<" ";
		cout<<"\nEnter Division : ";
		cin>>student.div;
		fout<<student.div<<" ";
		cout<<"\nEnter Address : ";
		cin>>student.address;
		fout<<student.address<<endl;
		cout<<"\nEnter more(1/0) : ";
		cin>>ans;
	}while(ans == 1);
	fout.close();
}

void add()
{
	ofstream fout;
	fout.open("data.txt", ios::app);
	cout<<"\nEnter Roll No : ";
	cin>>student.roll;
	fout<<student.roll<<" ";
	cout<<"\nEnter Name : ";
	cin>>student.name;
	fout<<student.name<<" ";
	cout<<"\nEnter Division : ";
	cin>>student.div;
	fout<<student.div<<" ";
	cout<<"\nEnter Address : ";
	cin>>student.address;
	fout<<student.address<<endl;
	fout.close();
}

void display()
{
	ifstream fin;
	fin.open("data.txt");
	fin.seekg(0,ios::beg);
	cout<<"\n\tThe Content of File are:\n";
	cout<<"\n\tRoll\tName\tDiv\tAddress";
	while (fin >> student.roll >> student.name >> student.div >> student.address)
	{
		cout << "\n\t" << student.roll << "\t" << student.name << "\t" << student.div << "\t" << student.address;
	}
	fin.close();
}

void search()
{
	int rollno;
	bool found = false;
	cout<<"\nEnter Roll No to search : ";
	cin>>rollno;
	ifstream fin;
	fin.open("data.txt");
	while(fin>>student.roll>>student.name>>student.div>>student.address)
	{
		if(student.roll == rollno)
		{
			found = true;
			cout<<"\nRoll No : "<<student.roll;
			cout<<"\nName : "<<student.name;
			cout<<"\nDivision : "<<student.div;
			cout<<"\nAddress : "<<student.address;
			break;
		}
	}
	fin.close();
	if(!found)
		cout<<"\nData not present";
}

void del()
{
	ifstream fin;
	fin.open("data.txt");
	ofstream tempfile;
	tempfile.open("temp.txt", ios::trunc);
	int r;
	cout<<"\nEnter Roll No to delete : ";
	cin>>r;
	bool found = false;
	while(fin>>student.roll>>student.name>>student.div>>student.address)
	{
		if(student.roll != r)
			tempfile<<student.roll<<" "<<student.name<<" "<<student.div<<" "<<student.address<<endl;
		else
			found = true;
	}
	fin.close();
	tempfile.close();
	if(found)
	{
		remove("data.txt");
		rename("temp.txt", "data.txt");
	}
	else
	{
		remove("temp.txt");
	}
}

int main()
{
	int ch;
	do
	{
		cout<<"\n\n******MENU******";
		cout<<"\n1 : Create";
		cout<<"\n2 : Insert";
		cout<<"\n3 : Display";
		cout<<"\n4 : Search";
		cout<<"\n5 : Delete";
		cout<<"\n6 : Exit";
		cout<<"\nEnter your choice : ";
		cin>>ch;

		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				add();
				break;
			case 3:
				display();
				break;
			case 4:
				search();
				break;
			case 5:
				del();
				break;
			case 6:
				cout<<"\nEnd of Program";
				break;
		}
	}while(ch != 6);
	return 0;
}
