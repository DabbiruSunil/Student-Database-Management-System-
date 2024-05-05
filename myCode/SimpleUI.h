/*
 * SimpleUI.h
 *
 *  Created on: 17-Jan-2024
 *      Author: Dabbiru Sunil
 */

#ifndef SIMPLEUI_H_
#define SIMPLEUI_H_
#include "StudentDb.h"
#include<iostream>
#include "Poco/Data/Time.h"
#include "Poco/DateTime.h"
#include "StudentDb.h"
#include "Student.h"
#include "WeeklyCourse.h"
#include "BlockCourse.h"

class SimpleUI
{
private:
	StudentDb &studentDatabaseInUI;
public:
	SimpleUI(StudentDb& db);
	void addNewCourse();
	void printAllCourses();
	void addNewStudent();
	void addEnrollment();
	void printStudent();
	void updateStudent();
	void searchStudent();
	void run();
	void readfile();
	void writeIntoFile();
	virtual ~SimpleUI();
};

#endif /* SIMPLEUI_H_ */
