  /*
 * Course.cpp
 *
 *  Created on: 17-Jan-2024
 *      Author: Dabbiru Sunil
 */

#include "Course.h"
#include "cctype"
std::map<unsigned char, std::string> Course::majorById = { { 'E', "Embedded" }, {
		'A', "Automation" }, { 'C', "Communication" }, { 'P', "Power" } };
Course::Course(std::string majorString,unsigned int courseKey, std::string title,
		unsigned char major,
		float creditPoints):courseKey(courseKey),title(title),major(major),creditPoints(creditPoints)
{
 char tempCompChar;
 bool newMajorFlag=0;
 tempCompChar= std::toupper(majorString[0]);
  for(auto iteratorCourse:majorById)
  {
	  if(iteratorCourse.second[0]==tempCompChar)
	  {
		  this->major=iteratorCourse.first;
		  newMajorFlag=1;
	  }
  }
  if(newMajorFlag==0)
  {
	  majorById.insert({tempCompChar,majorString});
  }

}

std::string Course::getMajorString() const
{
  return this->majorById[major];
}

void Course::setCourseKey(unsigned int courseKeyArg)
{
	this->courseKey=courseKeyArg;
}

unsigned int Course::getCourseKey()const
{
	return this->courseKey;
}

std::string Course::getTitle() const
{
	return this->title;
}

unsigned char Course::getMajorChar() const
{
	return this->major;
}

float Course::getCreditPoints() const
{
	return this->creditPoints;
}

Course::~Course()
{
	// TODO Auto-generated destructor stub
}

void Course::setTitle(std::string title)
{
	this->title=title;
}

void Course::setMajor(unsigned char major)
{
	this->major=major;
}

void Course::setCreditPoints(float creditPoints)
{
	this->creditPoints=creditPoints;
}

void Course::writeCourse(std::ostream &out)
{
   out<<";"<<this->courseKey<<";"<<this->title<<";"<<this->majorById[major]<<";"<<this->creditPoints<<";";
}
