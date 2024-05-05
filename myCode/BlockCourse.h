/*
 * BlockCourse.h
 *
 *  Created on: 17-Jan-2024
 *      Author: Dabbiru Sunil
 */

#ifndef BLOCKCOURSE_H_
#define BLOCKCOURSE_H_
#include "Course.h"
#include "Poco/Data/Time.h"
#include "Poco/Data/Date.h"
class BlockCourse: public Course
{
private:
	Poco::Data::Date startDate;
	Poco::Data::Date endDate;
	Poco::Data::Time startTime;
	Poco::Data::Time endTime;

public:
	BlockCourse(std::string majorString,unsigned int courseKey, std::string title,
			unsigned char major,
			float credpoints,Poco::Data::Date startDate,
			Poco::Data::Date endDate,
			Poco::Data::Time startTime,
			Poco::Data::Time endTime);
	Poco::Data::Date getStartDate() const;
	Poco::Data::Date getEndDate() const;
	Poco::Data::Time getStartTime() const;
	Poco::Data::Time getEndTime() const;
	virtual void writeBlockCourse(std::ostream& out);
	static BlockCourse* read(std::istream &in);
	virtual ~BlockCourse();
};

#endif /* BLOCKCOURSE_H_ */
