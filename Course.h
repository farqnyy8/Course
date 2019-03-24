//Course class header file

#ifndef COURSE_H_
#define COURSE_H_

#include <iostream>
#include <string>

using namespace std;

class Course{
	private:
		//data fields
		string course_name, course_instructor;
		string* students;
		int number_of_students;
		int capacity;
		
		//static function	
		int search(const string);	
		
	public:
		//constuctors
		Course(string&, string&, int);
		Course(const Course&);
		
		//destructor
		~Course();
		
		//accessors
		string get_course_name() const;
		string get_course_instructor_name() const;
		string* get_students() const;
		int get_number_of_students() const;
		
		//behaviours
		void add_student(string&);
		void drop_student(string&);
		void print();
		void clear();
};

#endif
