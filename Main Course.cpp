/*
Created by: Faruq E Hammed
Date: 
*/

//Main Course File

#include "Course.h"

//function declaration
void drop_student_from_course(Course&);
void add_student_to_course(Course&);
int display_menu();

int main()
{
	//local variables
	string name, teacher;
	int capacity;
	
	cout << "Enter Course Name: ";
	getline(cin, name);
	
	cout << "Enter Course Instructor Name: ";
	getline(cin, teacher);
	
	cout << "Enter Course Capacity: ";
	cin >> capacity;
	
	Course course(name, teacher, capacity);

	int choice;
	
	do
	{
		system("cls");
		
		choice = display_menu();
		
		switch(choice)
		{
			case 1: add_student_to_course(course); break;
			case 2: drop_student_from_course(course); break;
			case 3: cout << course.get_course_instructor_name() << endl; system("pause"); break; 
			case 4: course.print(); break;
			case 5: course.clear(); break;
			case 0: break; 
			default: cout <<"Invalid Input, choose another option." << endl;
		}
		
	}while(choice != 0);
	
	 
	
	return 0;
}

void add_student_to_course(Course& course)
{
	string name;
	
	cout << "Enter Name of student to be added: ";
	getline(cin, name);
	
	course.add_student(name);
}

void drop_student_from_course(Course& course)
{
	string name;
	
	cout << "Enter Name of student to be dropped: ";
	getline(cin, name);
	
	course.drop_student(name);
}

int display_menu()
{
	cout << "1. Add Student" << endl;
	cout << "2. Delete Student" << endl;
	cout << "3. Print Instuctor Name" << endl;
	cout << "4. Print Course Information" << endl;
	cout << "5. Remove all students from the Course" << endl;
	cout << "0. Stop Program" << endl;
	
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	cin.ignore();
	
	return choice;
}

	

