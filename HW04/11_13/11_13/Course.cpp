
#include <iostream>
#include "Course.h"
using namespace std;

Course::Course(const string& courseName, int capacity)
{
	numberOfStudents = 0;
	this->courseName = courseName;
	this->capacity = capacity;
	students = new string[capacity];
}

Course::Course(const Course& objCourse)
{
	courseName = objCourse.courseName;
	numberOfStudents = objCourse.numberOfStudents;
	capacity = objCourse.capacity;
	students = new string[capacity];
	for (int i = 0; i < numberOfStudents; i++)
	{
		students[i] = objCourse.students[i];
	}
}

Course::~Course()
{
	this->clear();
	this->courseName = "";
	delete[] students;
}

string Course::getCourseName() const
{
	return courseName;
}


void Course::addStudent(const string& name)
{
	if (numberOfStudents < capacity)
	{
		students[numberOfStudents] = name;
		numberOfStudents++;
	}
	else
	{
		//remember the old students memory pointer
		string* pStudent = students;

		//increase the size of the students
		students = new string[2 * capacity];

		//copy the original students info to the new students
		for (int i = 0; i < numberOfStudents; i++)
		{
			students[i] = pStudent[i];
		}

		//step 4: add new student
		students[numberOfStudents] = name;

		//step 5: increment the student number
		numberOfStudents++;

		//step 6: update the capacity
		capacity = 2 * capacity;

		//step 7: deallocate the memory for the old students so there is no memory leak 
		delete[] pStudent;
	}
}

void Course::dropStudent(const string& name)
{
	bool bIsNameInStudents = false;
	int i = 0;

	//step 1:  search to find the student name
	for (; i < numberOfStudents; i++)
	{
		if (students[i] == name)
		{
			bIsNameInStudents = true;
			break;
		}
	}

	// if found, then drop the student
	if (bIsNameInStudents)
	{
		for (; i < numberOfStudents - 1; i++)
		{
			students[i] = students[i + 1];
		}

		students[i] = "";

		numberOfStudents--;
	}
}

string* Course::getStudents() const
{
	return students;
}

int Course::getNumberOfStudent() const
{
	return numberOfStudents;
}

void Course::clear()
{
	for (int i = 0; i < numberOfStudents; i++)
	{
		students[i] = "";
	}
	numberOfStudents = 0;
}
