/*
 * Student.h
 *
 *  Created on: 17-Jan-2024
 *      Author: Dabbiru Sunil
 */

#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
#include "Enrollment.h"
#include <vector>
#include "Poco/Data/Date.h"
#include "Address.h"
#include <memory>
#include <fstream>
class Student
{
private:
	static unsigned int nextMatrikelNumber;
	unsigned int matrikelNumber;
	std::string firstName;
	std::string lastName;
	Poco::Data::Date dateOfBirth;
	std::vector<Enrollment> enrollments;
	std::shared_ptr<Address> addressPointer ;
public:
	Student(std::string firstName,std::string lastName,
			Poco::Data::Date dateOfBirth, std::string street,
			unsigned short postalCode, std::string cityName,
			std::string additionalInfo);
	unsigned int getMatrikelNumber();
	std::string getFirstName() const;
	std::string getLastName() const;
	Poco::Data::Date getDateOfBirth() const;
	std::vector<Enrollment>& getEnrollments() ;
	std::shared_ptr<Address> getAddressPointer() const ;
	void setAddress(Address updateAddress);
	void setFirstName(std::string argfirstName);
	void setLastName(std::string arglastName);
	void setDateOfBirth(Poco::Data::Date argdateOfBirth);
	void setEnrollment(Enrollment enrollment) ;
	virtual ~Student();
	virtual void writeStudent(std::ostream& out);
	static Student* read(std::istream &in);
};

#endif /* STUDENT_H_ */
