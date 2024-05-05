/*
 * BlockCourse.cpp
 *
 *  Created on: 17-Jan-2024
 *      Author: Dabbiru Sunil
 */

#include "BlockCourse.h"

BlockCourse::BlockCourse(std::string majorString,unsigned int courseKey, std::string title,
		unsigned char major,
		float credpoints,Poco::Data::Date startDate,
		Poco::Data::Date endDate,
		Poco::Data::Time startTime,
		Poco::Data::Time endTime):Course(majorString,courseKey, title, major,
				credpoints),startDate(startDate),endDate(endDate),startTime(startTime),endTime(endTime)

{
	// TODO Auto-generated constructor stub

}

Poco::Data::Date BlockCourse::getStartDate() const
{
	return this->startDate;
}

Poco::Data::Date BlockCourse::getEndDate() const
{
	return this->endDate;
}

Poco::Data::Time BlockCourse::getStartTime() const
{
	return this->startTime;
}

Poco::Data::Time BlockCourse::getEndTime() const
{
	return this->endTime;
}

void BlockCourse::writeBlockCourse(std::ostream &out)
{
	out<<"B";
	writeCourse(out);
	out<<this->startDate.day()<<":"<<this->startDate.month()<<":"<<this->startDate.year()
			<<";"<<this->endDate.day()<<":"<<this->endDate.month()<<":"<<this->endDate.year()
			<<";"<<this->startTime.hour()<<":"<<this->startTime.minute()<<":"<<this->startTime.second()
			<<";"<<this->endTime.hour()<<":"<<this->endTime.minute()<<":"<<this->endTime.second();

}

BlockCourse::~BlockCourse()
{
	// TODO Auto-generated destructor stub
}

BlockCourse* BlockCourse::read(std::istream &in) {
	int year;
	int month;
	int day;
	std::string data;
	Poco::Data::Date startDate;
	Poco::Data::Date endDate;
	Poco::Data::Time startTime;
	Poco::Data::Time endTime;
	std::string title;
	float creditPoints;
	std::string major;
	unsigned int courseKey;

	getline(in, data, ';');
	courseKey = stoi(data);

	getline(in, data, ';');
	title = data;

	getline(in, data, ';');
	major = data;

	getline(in, data, ';');
	creditPoints = stof(data);

	getline(in, data, '.');
	day = stoi(data);

	getline(in, data, '.');
	month = stoi(data);

	getline(in, data, ';');
	year = stoi(data);

	startDate.assign(year, month, day);

	getline(in, data, '.');
	day = stoi(data);

	getline(in, data, '.');
	month = stoi(data);

	getline(in, data, ';');
	year = stoi(data);

	endDate.assign(year, month, day);

	getline(in, data, ':');
	int hours = stoi(data);

	getline(in, data, ';');
	int mins = stoi(data);

	startTime.assign(hours, mins, 0);

	getline(in, data, ':');
	hours = stoi(data);

	getline(in, data);
	mins = stoi(data);

	endTime.assign(hours, mins, 0);

	BlockCourse *temp_block = new BlockCourse(major,courseKey, title,major[0],
			creditPoints, startDate, endDate, startTime, endTime);

	return temp_block;
}

