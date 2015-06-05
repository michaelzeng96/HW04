#include <iostream>
#include "Course.h"	
using namespace std;

int main()
{
	Course course1("DataStructures", 10);
	Course course2("Database Systems", 15);


	course1.addStudent("Peter Jones");
	course1.addStudent("Brian Smith");
	course1.addStudent("Anne Kennedy");

	Course course3(course1); //me testing out the copy constructor before i dropped a student from course 1

	course1.dropStudent("Brian Smith");

	cout << "Number of students in course1: " << course1.getNumberOfStudent() << "\n";
	string* students = course1.getStudents();
	for (int i = 0; i < course1.getNumberOfStudent(); i++)
	cout << students[i] << ", ";

	//The code under here was just from the original code in the book (i did not want to delete it), and
	//so i could make sure my copy constructor was funcitoning properly and was performing a deep copy
	//rather than a shallow one. I also checked this by debugging and looking at the memory address of 
	//the copied object's pointer and the original objects pointer, and making sure they were different 
	//address which meant that they would one alteration would not affect the other 

	course3.dropStudent("Peter Jones");

	course2.addStudent("Peter Jones");
	course2.addStudent("Steve Smith");

	cout << "\nNumber of students in course2: " << course2.getNumberOfStudent() << "\n";
	students = course2.getStudents();
	for (int i = 0; i < course2.getNumberOfStudent(); i++)
	cout << students[i] << ", ";

	cout << "\nNumber of students in course3: " << course3.getNumberOfStudent() << "\n";
	students = course3.getStudents();
	for (int i = 0; i < course3.getNumberOfStudent(); i++)
		cout << students[i] << ", ";
	
	return 0;
}