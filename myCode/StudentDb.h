/*
 * StudentDb.h
 *
 *  Created on: 17-Jan-2024
 *      Author: Dabbiru Sunil
 */

#ifndef STUDENTDB_H_
#define STUDENTDB_H_
#include "Student.h"
#include <memory>
#include <iostream>
#include <map>
#include "WeeklyCourse.h"
#include "BlockCourse.h"
#include <boost/asio.hpp>
#include <boost/json.hpp>
#include<cctype>
#include<algorithm>
#include<stdlib.h>

class StudentDb
{
private:
	std::map <int, Student> students;
	std::map <int, std::unique_ptr<const Course>>courses;
public:
	StudentDb();
	void setWeeklyCourse(WeeklyCourse* course);
	void setBlockCourse(BlockCourse* course);
	void setStudent(Student student);
	std::map <int, Student>& getStudent();
	std::map <int, std::unique_ptr<const Course>> &getCourse() ;
	virtual ~StudentDb();
	void write (std::ostream& out);
	void read(std::istream &in);
	void PopulateThroughServer(int numOfStudents);
};

#endif /* STUDENTDB_H_ */
