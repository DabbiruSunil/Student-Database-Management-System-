/*
 * WeeklyCourse.cpp
 *
 *  Created on: 17-Jan-2024
 *      Author: Dabbiru Sunil
 */

#include "WeeklyCourse.h"

WeeklyCourse::WeeklyCourse(std::string majorString,unsigned int courseKey, std::string title,
unsigned char major,
float credpoints,Poco::DateTime::DaysOfWeek dayOfWeek,
Poco::Data::Time startTime,
Poco::Data::Time endTime):Course(majorString,
		courseKey, title,major,credpoints),dayOfWeek(dayOfWeek),startTime(startTime),endTime(endTime)
{
	// TODO Auto-generated constructor stub

}

Poco::DateTime::DaysOfWeek WeeklyCourse::getDayOfWeek() const
{
	return this->dayOfWeek;
}

Poco::Data::Time WeeklyCourse::getStartTime() const
{
	return this->startTime;
}

Poco::Data::Time WeeklyCourse::getEndTime()const
{
	return this->endTime;
}

WeeklyCourse::~WeeklyCourse()
{
	// TODO Auto-generated destructor stub
}

void WeeklyCourse::writeWeelkyCourse(std::ostream &out)
{
	out<<"W";
	writeCourse(out);
	out<<dayOfWeek
	   <<";"<<this->startTime.hour()<<":"<<this->startTime.minute()<<":"<<this->startTime.second()
	   <<";"<<this->endTime.hour()<<":"<<this->endTime.minute()<<":"<<this->endTime.second();
}

WeeklyCourse* WeeklyCourse::read(std::istream &in) {
	Poco::DateTime::DaysOfWeek dayOfWeek; //0 to 6
	Poco::Data::Time startTime;
	Poco::Data::Time endTime;
	std::string title;
	float creditPoints;
	std::string major;
	std::string data;

	unsigned int courseKey;


	getline(in, data, ';');
	courseKey = stoi(data);

	getline(in, data, ';');
	title = data;

	getline(in, data, ';');
	major = data;

	getline(in, data, ';');
	creditPoints = stof(data);

	getline(in, data, ';');
	dayOfWeek = (Poco::DateTime::DaysOfWeek) stoi(data);

	getline(in, data, ':');
	int hours = stoi(data);

	getline(in,data,';');
	int mins = stoi(data);

	startTime.assign(hours,mins,0);

	getline(in, data, ':');
	hours = stoi(data);

	getline(in,data);
	mins = stoi(data);

	endTime.assign(hours,mins,0);

	WeeklyCourse *w= new WeeklyCourse(major,courseKey,title,major[0],creditPoints,
			dayOfWeek,startTime,endTime);
	return w;
}
