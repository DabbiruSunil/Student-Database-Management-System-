/*
 * Course.h
 *
 *  Created on: 17-Jan-2024
 *      Author: Dabbiru Sunil
 */

#ifndef COURSE_H_
#define COURSE_H_
#include <string>
#include <map>
#include <fstream>
class Course
{
private:
	static std::map<unsigned char, std::string> majorById;
	unsigned int courseKey;
	std::string title;
	unsigned char major;
	float creditPoints;

public:
	Course(std::string majorString,unsigned int courseKey, std::string title,
	unsigned char major,
	float creditPoints);

	unsigned int getCourseKey()const;
	std::string getTitle() const;
	unsigned char getMajorChar() const;
	float getCreditPoints()const;
	std::string getMajorString()const;


	void setCourseKey(unsigned int courseKeyArg);
	void setTitle(std::string title);
	void setMajor(unsigned char major);
	void setCreditPoints(float creditPoints);
	virtual ~Course()=0;
	virtual void writeCourse(std::ostream& out);
};

#endif /* COURSE_H_ */
