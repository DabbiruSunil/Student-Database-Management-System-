/*
 * WeeklyCourse.h
 *
 *  Created on: 17-Jan-2024
 *      Author: Dabbiru Sunil
 */

#ifndef WEEKLYCOURSE_H_
#define WEEKLYCOURSE_H_
#include "Course.h"
#include "Poco/Data/Time.h"
#include "Poco/DateTime.h"
class WeeklyCourse:public Course
{
private:
	Poco::DateTime::DaysOfWeek dayOfWeek;
	Poco::Data::Time startTime;
	Poco::Data::Time endTime;

public:
	WeeklyCourse(std::string majorString,unsigned int courseKey, std::string title,
			unsigned char major,
			float credpoints,Poco::DateTime::DaysOfWeek dayOfWeek,
			Poco::Data::Time startTime,
			Poco::Data::Time endTime);
	Poco::DateTime::DaysOfWeek getDayOfWeek() const;
	Poco::Data::Time getStartTime() const;
	Poco::Data::Time getEndTime() const;
	virtual ~WeeklyCourse();
	virtual void writeWeelkyCourse(std::ostream& out);
	static WeeklyCourse* read(std::istream &in);
};

#endif /* WEEKLYCOURSE_H_ */
