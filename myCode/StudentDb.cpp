/*
 * StudentDb.cpp
 *
 *  Created on: 17-Jan-2024
 *      Author: Dabbiru Sunil
 */

#include "StudentDb.h"
#include <boost/tokenizer.hpp>
#include <boost/json/src.hpp>

StudentDb::StudentDb()
{
	// TODO Auto-generated constructor stub

}

StudentDb::~StudentDb()
{
	// TODO Auto-generated destructor stub
}

void StudentDb::setWeeklyCourse(WeeklyCourse *course)
{
	this->courses.insert(
	{ course->getCourseKey(), std::make_unique<WeeklyCourse>(*course) });
}

void StudentDb::setStudent(Student student)
{
	this->students.insert(
	{ student.getMatrikelNumber(), student });

}

std::map<int, Student>& StudentDb::getStudent()
{
	return this->students;
}

std::map<int, std::unique_ptr<const Course>>& StudentDb::getCourse()
{
	return this->courses;
}

void StudentDb::setBlockCourse(BlockCourse *course)
{
	this->courses.insert(
	{ course->getCourseKey(), std::make_unique<BlockCourse>(*course) });
}

void StudentDb::read(std::istream &in)
{
	students.clear();
	courses.clear();

	std::cout << "Inside stude db" << std::endl;

	std::string data;
	int courses_num;
	int students_num;
	int enrollments_num;

	getline(in, data);
	courses_num = stoi(data);

	for (int i = 0; i < courses_num; i++)
	{
		getline(in, data, ';');
		std::string course_type = data;

		if (course_type == "W")
		{
			WeeklyCourse *temp_WeeklyCourse = WeeklyCourse::read(in);
			courses.insert(
					{ temp_WeeklyCourse->getCourseKey(), std::make_unique<
							WeeklyCourse>(*temp_WeeklyCourse) });

		}
		else if (course_type == "B")
		{

			BlockCourse *temp_BlockedCourse = BlockCourse::read(in);
			courses.insert(
					{ temp_BlockedCourse->getCourseKey(), std::make_unique<
							BlockCourse>(*temp_BlockedCourse) });

		}
	}

	getline(in, data);
	students_num = stoi(data);

	for (int i = 0; i < students_num; i++)
	{
		Student *student = (Student::read(in));
		students.insert(std::make_pair(student->getMatrikelNumber(), *student));
	}

	getline(in, data);
	enrollments_num = stoi(data);

	for (int i = 0; i < enrollments_num; i++)
	{
		unsigned int matrNum;
		Course *course;
		int coursekey;

		getline(in, data, ';');
		matrNum = stol(data);

		std::map<int, Student>::iterator itr_map;

		if (students.count(matrNum) != 0)
			itr_map = students.find(matrNum);

		getline(in, data, ';');
		coursekey = stoi(data);

		auto itr_course = courses.find(coursekey);
		course = (Course*) (itr_course->second.get());

		Enrollment *temp_enrollment = Enrollment::read(in);

		temp_enrollment->setCourse(course);

		itr_map->second.setEnrollment(*temp_enrollment);

	}

}

void StudentDb::write(std::ostream &out)
{
	int itemsToWriteCourse = 0, itemsToWriteStudent = 0;
	for ([[maybe_unused]] auto &courseIterator : courses)
	{
		itemsToWriteCourse++;
	}
	out << itemsToWriteCourse << "\n";
	for (auto &courseIterator : courses)
	{
		Course *course = (Course*) courseIterator.second.get();
		if (course)
		{
			// Use dynamic_cast to check the actual type
			if (BlockCourse *blockCourse = dynamic_cast<BlockCourse*>(course))
			{
				blockCourse->writeBlockCourse(out);
				out << "\n";
			}
			else if (WeeklyCourse *weeklyCourse =
					dynamic_cast<WeeklyCourse*>(course))
			{
				weeklyCourse->writeWeelkyCourse(out);
				out << "\n";
			}
		}

	}
	for ([[maybe_unused]] auto &studentIterator : students)
	{
		itemsToWriteStudent++;
	}
	out << itemsToWriteStudent << "\n";
	for (auto &studentsIterator : students)
	{
		studentsIterator.second.writeStudent(out);
	}
	int itemsToWriteEnrollment = 0;
	for (auto student : students)
	{
		itemsToWriteEnrollment += student.second.getEnrollments().size();
	}
	/*int itemsToWriteEnrollment=0;
	 for([[maybe_unused]]auto& enrollmentIterator:enrollments)
	 {
	 itemsToWriteEnrollment++;
	 }*/
	out << itemsToWriteEnrollment << "\n";
	for (auto itr_student : getStudent())
	{
		for (auto itr_enrollment : itr_student.second.getEnrollments())
		{
			out << itr_student.second.getMatrikelNumber() << ";";
			itr_enrollment.writeEnrollment(out);
		}
	}

}

/*void StudentDb::PopulateThroughServer(int numOfStudents)
{
	for (int i = 0; i < numOfStudents; i++)
	{
		boost::asio::ip::tcp::iostream socket("www.hhs.users.h-da.cloud",
				"4242");
		socket << "generate" << std::endl;

		std::string answer;
		getline(socket, answer);

		std::string jsonResponse;
		getline(socket, jsonResponse);

		boost::json::value jv = boost::json::parse(jsonResponse);

			boost::json::object obj = jv.as_object();

			boost::json::object name = obj["name"].as_object();
			boost::json::object dateOfBirth = obj["dateOfBirth"].as_object();
			boost::json::object address = obj["location"].as_object();

			unsigned int year = (unsigned int) (dateOfBirth["year"].as_int64()
					+ 1900);

			unsigned int month = (unsigned int) (dateOfBirth["month"].as_int64()
					+ 1);

			unsigned int day = (unsigned int) (dateOfBirth["date"].as_int64());

			Poco::Data::Date dob(year, month, day);

			std::string postalCodeStr = address["postCode"].as_string().c_str();
			unsigned short postalCode;

			try
			{
				if (stoi(postalCodeStr))
				{
					postalCode = (unsigned short) (stoi(postalCodeStr));
				}
			} catch (...)
			{
				i = i - 1;
				socket << "quit" << std::endl;
				continue;
			}

		this->setStudent(
					Student(name["firstName"].as_string().c_str(),
							name["lastName"].as_string().c_str(), dob,
							address["street"].as_string().c_str(), postalCode,
							address["city"].as_string().c_str(),
							address["state"].as_string().c_str()));


		socket << "quit" << std::endl;
		getline(socket, answer);

	}
}*/
