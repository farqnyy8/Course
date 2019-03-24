//Course cpp file

#include "Course.h"


//constructor
Course::Course(string& course_name, string& course_instructor, int capacity)
{
	number_of_students = 0;
	this->course_name = course_name;
	this->capacity = capacity;
	this->course_instructor = course_instructor;
 	students = new string[capacity];
}

Course::~Course()
{
	delete [] students;
	cout << "Dynamically created array (students) is  deleted" << endl;
}

//accessor
string Course::get_course_name() const
{
	return this->get_course_name();
}

string* Course::get_students() const
{
	return this->students;
}

int Course::get_number_of_students() const
{
	return this->number_of_students;
}

string Course::get_course_instructor_name() const
{
	return course_name + "'s instructor name is " + course_instructor + ".";
}

//behaviours
void Course::drop_student(string& student_name)
{
	int find = search(student_name);
		
	if (find == -1)
		cout << "Student is not taking this course." << endl;
	else
	{
		if (find == capacity - 1)
			students[find] = "";
		else
		{
			students[find] = "";
			
			for(int i = find; i < capacity - 1; i++)
			{
				students[i] = students[i+1];				
			}
		}
		
		number_of_students--;
		
		cout << endl << student_name << " has been deleted from this course." << endl << endl;		
	}
	
	system("pause");
}

//search function
int Course::search(const string student_name) {
	
	for(int i = 0; i < capacity; i++)
	{
		if(student_name == students[i])
			return i;
	}
	
	return -1;
}

void Course::add_student(string& student_name)
{
	if(number_of_students < capacity)
	{
		students[number_of_students] = student_name;
		cout << endl << student_name << " has been added to this course." << endl << endl;
		number_of_students++;
	}
	else
		cout << "\nError: can not add student. \nCourse Capacity is already maximized."
		<< "\nTry deleting an unserious student to add a serious one\n." << endl;
	
	system("pause");
}

//print course information
void Course::print()
{
	
	cout  <<  endl << "**************Course Information****************" << endl;
	
	cout << endl << "Course Name: " << course_name << endl << endl;
	cout << "Course Instructor: " << course_instructor << endl << endl;
	cout << "Course Capacity: " << capacity << endl << endl;
	
	if(number_of_students > 0)
	{
		cout << "Current Class Size: " << number_of_students << endl;
		cout << "Students: " << endl;
	
		for(int i = 0; i < number_of_students; i++)
			cout << "  Student " << i + 1 << ": " << students[i] << endl;
	}
	else if(number_of_students == 0)
		cout <<"There are no students taking this course yet. \nAdd student!" << endl;
	
	cout  <<  endl << "************************************************" << endl;
	system("pause");
}

//copy constructor
Course::Course(const Course& course)
{
	course_name = course.course_name;
	number_of_students = course.number_of_students;
	capacity = course.capacity;	
	students = new string[course.capacity];
	
	for(int i = 0; i < number_of_students; i++)
		students[i] = course.students[i];
}

//void clear
void Course::clear()
{
	int num = number_of_students;
	for(int i = 0; i < num; i++)
	{
		students[i] = "";
		number_of_students--;
	}
	
	cout << endl << "There are no more students in this Course." << endl;
	system("pause");
}
