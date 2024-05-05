/*
 * SimpleUI.cpp
 *
 *  Created on: 17-Jan-2024
 *      Author: Dabbiru Sunil
 */

#include "SimpleUI.h"

using std::cout;
using std::cin;
using std::endl;

SimpleUI::SimpleUI(StudentDb &db) :
		studentDatabaseInUI(db)
{

}

void SimpleUI::run()
{
	int choice = 0;
	while (1)
	{
		cout << "1-->Add New Course" << endl << "2-->List Courses" << endl;
		cout << "3-->Add New Student" << endl << "4-->Add Enrollment" << endl;
		cout << "5-->Print Student" << endl << "6-->Search Student" << endl;
		cout << "7-->Update Student" << endl;
		cout << "8-->Read Database from a file" << endl;
		cout << "9-->Write Database from a file" << endl;
		cout << "Please select one of the above options :" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			addNewCourse();
			break;
		case 2:
			printAllCourses();
			break;
		case 3:
			addNewStudent();
			break;
		case 4:
			addEnrollment();
			break;
		case 5:
			printStudent();
			break;
		case 6:
			searchStudent();
			break;
		case 7:
			updateStudent();
			break;
		case 8:
			readfile();
			break;
		case 9:
			writeIntoFile();
			break;
		/*case 10: {
					int numofStudents;
					cout << "Enter how many new students : "
							<< endl;
					cin >> numofStudents;

					studentDatabaseInUI.PopulateThroughServer(numofStudents);
					cout << "Data is populated from a server..." << endl;
					break;
				}*/
		default:
			cout << "Please select the correct option." << endl;
			break;

		}
	}

}

void SimpleUI::addNewCourse()
{
	bool courseType;
	unsigned int newCourseKey;
	std::string newTitle;
	std::string newMajorString;
	float newCreditPoints;
	cout << "Enter New Course key :" << endl;
	cin >> newCourseKey;
	cout << "Enter New Course Title :" << endl;
	std::getline(std::cin >> std::ws, newTitle);
	cout << "Enter New Course Major :" << endl;
	std::getline(std::cin >> std::ws, newMajorString);
	cout << "Enter New Course CreditPoints :" << endl;
	cin >> newCreditPoints;
	cout << "Enter 0 for Block Course and enter 1 for Weekly Course:" << endl;
	cin >> courseType;

	if (courseType == 0)
	{
		Poco::Data::Date newStartDate;
		Poco::Data::Date newEndDate;
		int year, month, day;
		int hours, minutes, seconds;
		Poco::Data::Time newStartTime;
		Poco::Data::Time newEndTime;

		cout << "Enter New Course Start date (YYYY-MM-DD) :" << endl;
		cout << "Enter the Year (YYYY):" << endl;
		cin >> year;
		cout << "Enter the Month (MM):" << endl;
		cin >> month;
		cout << "Enter the Day (DD):" << endl;
		cin >> day;
		newStartDate.assign(year, month, day);

		cout << "Enter New Course End date (YYYY-MM-DD) :" << endl;
		cout << "Enter the Year (YYYY):" << endl;
		cin >> year;
		cout << "Enter the Month (MM):" << endl;
		cin >> month;
		cout << "Enter the Day (DD):" << endl;
		cin >> day;
		newEndDate.assign(year, month, day);

		cout << "Enter New Course Start time (HH:MM:SS) :" << endl;
		cout << "Enter the Hours (HH):" << endl;
		cin >> hours;
		cout << "Enter the Minutes (MM):" << endl;
		cin >> minutes;
		cout << "Enter the Seconds (SS):" << endl;
		cin >> seconds;
		newStartTime.assign(hours, minutes, seconds);
		cout << "Enter New Course End time (HH:MM:SS) :" << endl;
		cout << "Enter the Hours (HH):" << endl;
		cin >> hours;
		cout << "Enter the Minutes (MM):" << endl;
		cin >> minutes;
		cout << "Enter the Seconds (SS):" << endl;
		cin >> seconds;
		newEndTime.assign(hours, minutes, seconds);
		BlockCourse BlkCrseObjt(newMajorString, newCourseKey, newTitle,
				newMajorString[0], newCreditPoints, newStartDate, newEndDate,
				newStartTime, newEndTime);

		studentDatabaseInUI.setBlockCourse(&BlkCrseObjt);

	}
	else
	{
		Poco::DateTime::DaysOfWeek newDayOfWeek;
		Poco::Data::Time newStartTime;
		Poco::Data::Time newEndTime;
		int day;
		int hours, minutes, seconds;
		cout << "Enter New Course Day of Week (i.e 0 to 6 where SUNDAY=0,"
				"MONDAY=1,TUESDAY=2,WEDNESDAY=3,THURSDAY=4,FRIDAY=5,"
				"SATURDAY=6) :" << endl;
		cin >> day;
		newDayOfWeek = (Poco::DateTime::DaysOfWeek) day;

		cout << "Enter New Course Start time (HH:MM:SS) :" << endl;
		cout << "Enter the Hours (HH):" << endl;
		cin >> hours;
		cout << "Enter the Minutes (MM):" << endl;
		cin >> minutes;
		cout << "Enter the Seconds (SS):" << endl;
		cin >> seconds;
		newStartTime.assign(hours, minutes, seconds);
		cout << "Enter New Course End time (HH:MM:SS) :" << endl;
		cout << "Enter the Hours (HH):" << endl;
		cin >> hours;
		cout << "Enter the Minutes (MM):" << endl;
		cin >> minutes;
		cout << "Enter the Seconds (SS):" << endl;
		cin >> seconds;
		newEndTime.assign(hours, minutes, seconds);

		WeeklyCourse wklyCrseObjt(newMajorString, newCourseKey, newTitle,
				newMajorString[0], newCreditPoints, newDayOfWeek, newStartTime,
				newEndTime);

		studentDatabaseInUI.setWeeklyCourse(&wklyCrseObjt);
	}

}

void SimpleUI::printAllCourses()
{
	cout << "List of all Courses available in database: " << endl;
	for (auto &courseIterator : studentDatabaseInUI.getCourse())
	{
		cout << "Course key : " << courseIterator.first << endl;
		const Course *course = courseIterator.second.get();

		cout << "Course title : " << course->getTitle() << endl;
		cout << "Course major (char) : " << course->getMajorChar() << endl;
		cout << "Course creditPoints : " << course->getCreditPoints() << endl;
		cout << "Course major (string): " << course->getMajorString() << endl;

		if (course)
		{
			// Use dynamic_cast to check the actual type
			if (const BlockCourse *blockCourse =
					dynamic_cast<const BlockCourse*>(course))
			{
				// It's a BlockCourse
				cout << "Start Date of the block course is (YY-MM-DD): "
						<< blockCourse->getStartDate().year() << '-'
						<< blockCourse->getStartDate().month() << '-'
						<< blockCourse->getStartDate().day() << endl;
				cout << "End Date of the block course is (YY-MM-DD): "
						<< blockCourse->getEndDate().year() << '-'
						<< blockCourse->getEndDate().month() << '-'
						<< blockCourse->getEndDate().day() << endl;
				cout << "Start Time of the block course is (HH-MM-SS): "
						<< blockCourse->getStartTime().hour() << '-'
						<< blockCourse->getStartTime().minute() << '-'
						<< blockCourse->getStartTime().second() << endl;
				cout << "End Time of the block course is (HH-MM-SS): "
						<< blockCourse->getEndTime().hour() << '-'
						<< blockCourse->getEndTime().minute() << '-'
						<< blockCourse->getEndTime().second() << endl;
			}
			else if (const WeeklyCourse *weeklyCourse =
					dynamic_cast<const WeeklyCourse*>(course))
			{
				// It's a WeeklyCourse
				cout << "Day of Week of the weekly course: "
						<< weeklyCourse->getDayOfWeek();
				cout << "Start Time of the weekly course is (HH-MM-SS): "
						<< weeklyCourse->getStartTime().hour() << '-'
						<< weeklyCourse->getStartTime().minute() << '-'
						<< weeklyCourse->getStartTime().second() << endl;
				cout << "End Time of the weekly course is (HH-MM-SS): "
						<< weeklyCourse->getEndTime().hour() << '-'
						<< weeklyCourse->getEndTime().minute() << '-'
						<< weeklyCourse->getEndTime().second() << endl;
			}
		}

	}

}

void SimpleUI::addNewStudent()
{
	std::string newFirstName;
	std::string newLastName;
	Poco::Data::Date newDateOfBirth;
	int year, month, day;
	std::string newStreet;
	unsigned short newPostalCode;
	std::string newCityName;
	std::string newAdditionalInfo;
	cout << "Enter the First name of the student: " << endl;
	std::getline(std::cin >> std::ws, newFirstName);
	cout << "Enter the Last name of the student: " << endl;
	std::getline(std::cin >> std::ws, newLastName);
	cout << "Enter the Date of birth of the student (YY-MM-DD) : " << endl;
	cout << "Year of birth :" << endl;
	cin >> year;
	cout << "Month of birth :" << endl;
	cin >> month;
	cout << "Day of birth :" << endl;
	cin >> day;
	newDateOfBirth.assign(year, month, day);
	cout << "Enter the Student address's street information: " << endl;
	std::getline(std::cin >> std::ws, newStreet);
	cout << "Enter the Student address's Postal Code information: " << endl;
	cin >> newPostalCode;
	cout << "Enter the Student address's city name :" << endl;
	std::getline(std::cin >> std::ws, newCityName);
	cout << "Enter the Student's additional info:" << endl;
	std::getline(std::cin >> std::ws, newAdditionalInfo);
	Student studentobjt(newFirstName, newLastName, newDateOfBirth, newStreet,
			newPostalCode, newCityName, newAdditionalInfo);

	studentDatabaseInUI.setStudent(studentobjt);

}

void SimpleUI::addEnrollment()
{
	int newMatrikelNumber;
	unsigned int newCourseID;
	std::string newSemester;
	bool duplicateEnrollment = 0;
	cout << "Enter the matrikel number of the student: " << endl;
	cin >> newMatrikelNumber;
	cout << "Enter the course id for enrollment: " << endl;
	cin >> newCourseID;
	cout << "Enter the semester: " << endl;
	std::getline(std::cin >> std::ws, newSemester);
	for (auto& studentsIterator : studentDatabaseInUI.getStudent())
	{
		if (studentsIterator.first == newMatrikelNumber)
		{
			if (studentsIterator.second.getEnrollments().empty() != 0)
			{
				for (auto enrollmentsIterator : studentsIterator.second.getEnrollments())
				{
					if ((enrollmentsIterator.getSemester() == newSemester)
							&& (enrollmentsIterator.getcourse()->getCourseKey()
									== newCourseID))
					{
						duplicateEnrollment = 1;
					}

				}
			}

		}
	}
	if (duplicateEnrollment == 0)
	{
		for (auto& studentsIterator : studentDatabaseInUI.getStudent())
		{
			if (studentsIterator.first == newMatrikelNumber)
			{
				//auto coursesMap = studentDatabaseInUI.getCourse();
				for (auto& coursesMapIterator : studentDatabaseInUI.getCourse())
				{
					if (coursesMapIterator.first == (int)newCourseID)
					{
						Enrollment  newEnroomentObjkt(0, newSemester,(Course*)coursesMapIterator.second.get());

						studentsIterator.second.setEnrollment(
								newEnroomentObjkt);
						cout << "Enrollment for student with matrikel number :"
								<< newMatrikelNumber << " for course ID: "
								<< newEnroomentObjkt.getcourse()->getCourseKey() << " and semester :"
								<< newEnroomentObjkt.getSemester() << " successful " << endl;
						for (auto enrollmentIterator : studentsIterator.second.getEnrollments())
						{
							cout << "Grade :" << enrollmentIterator.getGrade()
									<< endl;
							cout << "Semester: "
									<< enrollmentIterator.getSemester() << endl;
						}
					}
				}
			}
		}

	}
	else
	{
		cout << "Enrollment for student with matrikel number :"
				<< newMatrikelNumber << " for course ID: " << newCourseID
				<< " and semester :" << newSemester << " already exists"
				<< endl;
	}

}

void SimpleUI::printStudent()
{
	int newMatrikelNumber;
	cout << "Enter the matrikel number of the student: " << endl;
	cin >> newMatrikelNumber;
	for (auto studentsIterator : studentDatabaseInUI.getStudent())
	{
		if (studentsIterator.first == newMatrikelNumber)
		{
			cout << "First Name of the student is :"
					<< studentsIterator.second.getFirstName() << endl;
			cout << "Last Name of the student is :"
					<< studentsIterator.second.getLastName() << endl;
			cout << "Date of Birth of the student is (YY-MM-DD):"
					<< studentsIterator.second.getDateOfBirth().year() << "-"
					<< studentsIterator.second.getDateOfBirth().month() << "-"
					<< studentsIterator.second.getDateOfBirth().day() << endl;
			auto *addressPointer =
					studentsIterator.second.getAddressPointer().get();
			cout << "Address of the student is: " << endl;
			cout << "Street : " << addressPointer->getStreet() << endl;
			cout << "Postal Code : " << addressPointer->getPostalCode() << endl;
			cout << "City Name: " << addressPointer->getCityName() << endl;
			cout << "Additional Info: " << addressPointer->getAdditionalInfo()
					<< endl;

			//auto enrollments = studentsIterator.second.getEnrollments();

			            if (!(studentsIterator.second.getEnrollments().empty()))
			            {
			                cout << "Enrollments for this student:" << endl;

			                for (auto enrollment : studentsIterator.second.getEnrollments())
			                {
			                    cout << "Semester: " << enrollment.getSemester() << endl;
			                    cout << "Grade: " << enrollment.getGrade() << endl;
			                    cout << "Course Title: " << enrollment.getcourse()->getTitle() << endl;
			                    cout << "-------------------------" << endl;
			                }
			            }
			            else if((studentsIterator.second.getEnrollments().empty()))
			            {
			                cout << "No enrollments for this student." << endl;
			            }


		}
	}

}
void SimpleUI::searchStudent()
{
	cout
			<< "Enter the student's first name or last name you would like to search: "
			<< endl;
	std::string searchInput;
	bool studentFound = 0;
	std::getline(std::cin >> std::ws, searchInput);
	for (auto studentIterator : studentDatabaseInUI.getStudent())
	{
		std::size_t foundFirstName = searchInput.find(
				studentIterator.second.getFirstName());
		std::size_t foundLastName = searchInput.find(
				studentIterator.second.getLastName());
		if ((foundFirstName != std::string::npos)
				|| (foundLastName != std::string::npos))
		{
			studentFound = 1;
			cout << "Matrikel Number: "
					<< studentIterator.second.getMatrikelNumber() << endl;
			cout << "First name : " << studentIterator.second.getFirstName()
					<< endl;
			cout << "Last name : " << studentIterator.second.getLastName()
					<< endl;
		}
	}
	if (studentFound == 0)
	{
		cout << "No student with such name found in database" << endl;
	}

}

void SimpleUI::updateStudent()
{

	unsigned int searchMatrikelNumber;
	bool studentFound = 0, deleteUpdate = 0;
	std::string updateFirstName;
	std::string updateLastName;
	Poco::Data::Date updateDateOfBirth;
	std::string updateSemester;
	float updateGrade;
	std::vector<Enrollment> updateEnrollments;
	unsigned int updateCourseKey;
	int updateyear, updatemonth, updateday;
	std::string updateStreet;
	unsigned short updatePostalCode;
	std::string updateCityName;
	std::string updateAdditionalInfo;
	bool enrollmentUpdateChoice;
	bool selectedFirstName = 0, selectedLastName = 0, selectedDOB = 0,
			selectedEnrollment = 0, selectedAddress = 0;
	int choice;
	cout << "Enter the matrikel Number of the student: " << endl;
	cin >> searchMatrikelNumber;
	for (auto& studentIterator : studentDatabaseInUI.getStudent())
	{
		if (studentIterator.second.getMatrikelNumber() == searchMatrikelNumber)
		{
			studentFound = 1;
			do
			{
				cout << "0.To exit" << endl << "1.Update First Name "
						<< endl << "2.Update Last Name " << endl
						<< "3.Update Date of Birth " << endl
						<< "4.Update Address " << endl
						<< "5.Update Enrollments " << endl << "6.Delete Update"
						<< endl << "Enter your choice: " << endl;
				cin >> choice;
				switch (choice)
				{
				case 6:
					deleteUpdate = 1;
					cout << "Update Deleted" << endl;
					break;
				case 1:
					cout << "Enter the First name to be updated: " << endl;
					std::getline(std::cin >> std::ws, updateFirstName);
					selectedFirstName = 1;
					break;
				case 2:
					cout << "Enter the Last name to be updated: " << endl;
					std::getline(std::cin >> std::ws, updateLastName);
					selectedLastName = 1;
					break;
				case 3:
					cout
							<< "Enter the Date of Birth of the student to be updated: "
							<< endl;
					cout << "Enter the new year: " << endl;
					cin >> updateyear;
					cout << "Enter the new month: " << endl;
					cin >> updatemonth;
					cout << "Enter the new day: " << endl;
					cin >> updateday;
					updateDateOfBirth.assign(updateyear, updatemonth,
							updateday);
					selectedDOB = 1;
					break;
				case 4:
					cout
							<< "Enter 0 to delete an enrollment and 1 to update grade of the enrollment "
							<< endl;
					cin >> enrollmentUpdateChoice;
					if (enrollmentUpdateChoice)
					{
						cout
								<< "Enter the course key for which you want to update the grade: "
								<< endl;
						cin >> updateCourseKey;
						cout
								<< "Enter the semester for which you want to update the grade: "
								<< endl;
						std::getline(std::cin >> std::ws, updateSemester);
						for (auto enrollmentsIterator : studentIterator.second.getEnrollments())
						{
							if ((enrollmentsIterator.getSemester()
									== updateSemester)
									&& (enrollmentsIterator.getcourse()->getCourseKey()
											== updateCourseKey))
							{
								cout << "Enter the grade you want to update: "
										<< endl;
								cin >> updateGrade;
							}
						}
					}
					else
					{
						cout
								<< "Enter the course key for which you want to update the grade: "
								<< endl;
						cin >> updateCourseKey;
						cout
								<< "Enter the semester for which you want to update the grade: "
								<< endl;
						std::getline(std::cin >> std::ws, updateSemester);

					}
					selectedEnrollment = 1;
					break;

				case 5:
					cout << "Enter the Address of the student: " << endl;
					cout << "Enter the street: " << endl;
					std::getline(std::cin >> std::ws, updateStreet);
					cout << "Enter the postal code: " << endl;
					cin >> updatePostalCode;
					cout << "Enter the City name: " << endl;
					std::getline(std::cin >> std::ws, updateCityName);
					cout << "Enter the Additional info: " << endl;
					std::getline(std::cin >> std::ws, updateAdditionalInfo);
					studentIterator.second.getAddressPointer();
					selectedAddress = 1;

					break;

				}
			} while (choice != 0);

			if (deleteUpdate == 0)
			{
				if (selectedFirstName == 1)
				{
					studentIterator.second.setFirstName(updateFirstName);
				}
				if (selectedLastName == 1)
				{
					studentIterator.second.setLastName(updateLastName);
				}
				if (selectedDOB == 1)
				{
					studentIterator.second.setDateOfBirth(updateDateOfBirth);
				}
				if (selectedEnrollment == 1)
				{
					if (enrollmentUpdateChoice)
					{
						for (auto enrollmentsIterator : studentIterator.second.getEnrollments())
						{
							if ((enrollmentsIterator.getSemester()
									== updateSemester)
									&& (enrollmentsIterator.getcourse()->getCourseKey()
											== updateCourseKey))
							{
								enrollmentsIterator.setGrade(updateGrade);
							}
						}
					}
					else
					{
						for (auto enrollmentsIterator =
								studentIterator.second.getEnrollments().begin();
								enrollmentsIterator
										!= studentIterator.second.getEnrollments().end();
								++enrollmentsIterator)
						{
							if ((enrollmentsIterator->getSemester()
									== updateSemester)
									&& (enrollmentsIterator->getcourse()->getCourseKey()
											== updateCourseKey))
							{
								enrollmentsIterator =
										studentIterator.second.getEnrollments().erase(
												enrollmentsIterator);
								// After erase, the iterator is now pointing to the next element.
								--enrollmentsIterator; // Move it back to correctly process the next element.
								break; // No need to continue searching after deletion.
							}
						}

					}
				}
				if (selectedAddress == 1)
				{
					Address update_address(updateStreet, updatePostalCode,
							updateCityName, updateAdditionalInfo);
					studentIterator.second.setAddress(update_address);
				}

			}

		}

	}
	if (studentFound == 0)
	{
		cout << "Entered matrikel number " << searchMatrikelNumber
				<< " is not found in database. " << endl;
	}

}

void SimpleUI::readfile()
{
	std::string file_name;

	    cout << "Enter the file name that you want to read from: ";
	    cin >> file_name;

	    std::ifstream myFile(file_name);

	    if (myFile.is_open()) {
	        studentDatabaseInUI.read(myFile);
	        myFile.close();
	        cout << "All the data is read from the file." << endl;
	    } else {
	        cout << "File cannot be opened." << endl;
	    }
}

void SimpleUI::writeIntoFile()
{
	std::string file_name;

	cout << "Enter the file name that you want to read from: ";
		    cin >> file_name;
	std::fstream myFile;
	myFile.open(file_name,std::ios::out);
	if(myFile.is_open())
	{
		studentDatabaseInUI.write(myFile);
		myFile.close();
	}


}

SimpleUI::~SimpleUI()
{
	// TODO Auto-generated destructor stub
}

