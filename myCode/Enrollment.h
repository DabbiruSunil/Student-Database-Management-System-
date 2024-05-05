/*
 * Enrollment.h
 *
 *  Created on: 17-Jan-2024
 *      Author: Dabbiru Sunil
 */

#ifndef ENROLLMENT_H_
#define ENROLLMENT_H_
#include "Course.h"
class Enrollment
{
private:
	float grade;
	std::string semester;
	Course* course ;
public:
	Enrollment(float grade,
	std::string semester, Course* coursePtr);
	std::string getSemester() const;
	Course* getcourse();
	void setSemester(std::string semesterArg);
	void setCourse(Course* coursePtr);
	void setGrade(float gradeArg);
	float getGrade() const;
	virtual ~Enrollment();
	void writeEnrollment(std::ostream& out);
	static Enrollment* read(std::istream &in);
};

#endif /* ENROLLMENT_H_ */
