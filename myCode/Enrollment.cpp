/*
 * Enrollment.cpp
 *
 *  Created on: 17-Jan-2024
 *      Author: Dabbiru Sunil
 */

#include "Enrollment.h"

Enrollment::Enrollment(float grade, std::string semester, Course *coursePtr) :
		grade(grade), semester(semester), course(coursePtr)
{
	// TODO Auto-generated constructor stub

}

std::string Enrollment::getSemester() const
{
	return this->semester;
}

Course* Enrollment::getcourse()
{
	return this->course;
}

void Enrollment::setSemester(std::string semesterArg)
{
	this->semester = semesterArg;
}

void Enrollment::setCourse(Course *coursePtr)
{
	this->course = coursePtr;
}

float Enrollment::getGrade() const
{
	return this->grade;
}

void Enrollment::setGrade(float gradeArg)
{
	this->grade = gradeArg;
}

Enrollment::~Enrollment()
{
	// TODO Auto-generated destructor stub
}

void Enrollment::writeEnrollment(std::ostream &out)
{
	out<<this->course->getCourseKey()<<";"
	    <<this->semester<<";"
		<<this->grade;

}

Enrollment* Enrollment::read(std::istream &in) {
	std::string data;

	float grade;
	std::string semester;


	getline(in, data, ';');
	semester = data;

	getline(in, data);
	grade = stof(data);

	Course* c = NULL; //Null pointer

	Enrollment* temp_enroll = new Enrollment(grade, semester, c);

	return temp_enroll;
}
