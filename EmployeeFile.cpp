#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

struct Employee
{
	int employeeID;
	char name[50];
	char designation[50];
	double salary;
};

void AddEmployee()
{
	ofstream file("Employee.dat",ios::binary|ios::app);
	
	Employee em;
	
	cout<<"\nenter the employee id :";
	cin>>em.employeeID;
	
	cout<<"\nenter name :";
	cin.ignore();
	cin.getline(em.name,50);
	
	cout<<"\nenter designattion :";
	cin.getline(em.designation,50);
	
	cout<<"\nenter salary :";
	cin>>em.salary;
	
	file.write(reinterpret_cast<char*>(&em),sizeof(Employee));
	
	file.close();
	
	cout<<"\ninformation added successfully";
}

void deleteEmployee(int employeeID)
{
	ifstream file("Employee.dat",ios::binary);
	ofstream temp("temp.dat",ios::binary);
	
	Employee em;
	bool found =false;

	
	while(file.read(reinterpret_cast<char*>(&em),sizeof(Employee)))
	{
		if(em.employeeID==employeeID)
		{
			found = true;
			continue;
		}
		temp.write(reinterpret_cast<char*>(&em),sizeof(Employee));
	}
	
	file.close();
	temp.close();
	if(found)
	{
		remove("Employee.dat");
		rename("temp.dat","Employee.dat");
		cout<<"\ninformation deleted successfully";
	}
	else
	{
		remove("temp.dat");
		cout<<"employee not found";
	}
}

void displayEmployee(int employeeID)
{
	ifstream file("Employee.dat",ios::binary);
	
	Employee em;
		
	bool found =false;

	
	while(file.read(reinterpret_cast<char*>(&em),sizeof(Employee)))
	{
		if(em.employeeID==employeeID)
		{
			found = true;
			break;
		}
	}
	file.close();
	if(found)
	{
		cout<<"\nemployee id:"<<em.employeeID;
		cout<<"\nname:"<<em.name;
		cout<<"\ndesignation:"<<em.designation;
		cout<<"\nsalary:"<<em.salary;
	}
	else
	{
		cout<<"employee not found";
	}
}	
int main()
{
	int employeeID;
	int ch;
	while(true)
	{
		cout<<"\n------------employee details--------------";
		cout<<"\n1.add employee";
		cout<<"\n2.delete employee";
		cout<<"\n3.display employee";
		cout<<"\n4.exit";
		cout<<"\nenter choice";
		cin>>ch;
		switch(ch)
		{
			case 1:
				AddEmployee();
				break;
			case 2:
				cout<<"\nenter employee id to delete";
				cin>>employeeID;
				deleteEmployee(employeeID);
				break;
			case 3:	
				cout<<"\nenter employee id to display";
				cin>>employeeID;
				displayEmployee(employeeID);
				break;
			case 4:	
				exit(0);
			default:
				cout<<"\nwrong choice";
		}
	}
	return 0;
}
