/*
 * Student.cpp
 *
 *  Created on: 17-Jan-2024
 *      Author: Dabbiru Sunil
 */

#include "Student.h"
#include "Address.h"

unsigned int Student::nextMatrikelNumber=100000;

Student::Student(std::string firstName,std::string lastName,
		Poco::Data::Date dateOfBirth, std::string street,
		unsigned short postalCode, std::string cityName,
		std::string additionalInfo):firstName(firstName),
		lastName(lastName), dateOfBirth(dateOfBirth)

{
  Address temp_address(street,postalCode,cityName,additionalInfo);
  addressPointer= std::make_shared<Address>(temp_address);
  this->matrikelNumber=nextMatrikelNumber;
  nextMatrikelNumber++;

}

unsigned int Student::getMatrikelNumber()
{
	return this->matrikelNumber;
}

std::string Student::getFirstName() const
{
	return this->firstName;
}

std::string Student::getLastName() const
{
	return this->lastName;
}

Poco::Data::Date Student::getDateOfBirth() const
{
	return this->dateOfBirth;
}

std::shared_ptr<Address> Student::getAddressPointer() const
{
	return this->addressPointer;
}

void Student::setFirstName(std::string argfirstName)
{
	this->firstName=argfirstName;
}

void Student::setLastName(std::string arglastName)
{
	this->lastName=arglastName;
}

void Student::setDateOfBirth(Poco::Data::Date argdateOfBirth)
{
	this->dateOfBirth=argdateOfBirth;
}

void Student::setAddress(Address updateAddress)
{
	this->addressPointer=std::make_shared<Address>(updateAddress);
}

Student::~Student()
{
	// TODO Auto-generated destructor stub
}

std::vector<Enrollment>& Student::getEnrollments()
{
	return this->enrollments;
}

void Student::setEnrollment(Enrollment enrollment)
{
	this->enrollments.push_back(enrollment);

}

Student* Student::read(std::istream &in) {
	std::string firstName;
	std::string lastName;
	Poco::Data::Date dateofBirth;
	int day, month, year;

	std::string data;

	getline(in, data, ';');
	Student::nextMatrikelNumber = stol(data);

	getline(in, data, ';');
	firstName = data;

	getline(in, data, ';');
	lastName = data;

	getline(in, data, '.');
	day = stoi(data);

	getline(in, data, '.');
	month = stoi(data);

	getline(in, data, ';');
	year = stoi(data);

	dateofBirth.assign(year, month, day);

	Address *temp_address = Address::read(in);

	Student *temp_stud = new Student(firstName, lastName, dateofBirth,
			temp_address->getStreet(), temp_address->getPostalCode(),
			temp_address->getCityName(), temp_address->getAdditionalInfo());

	return temp_stud;
}

void Student::writeStudent(std::ostream &out)
{
	out<<this->matrikelNumber<<";"
	   <<this->firstName<<";"
	   <<this->lastName<<";"
	   <<this->dateOfBirth.day()<<"."<<this->dateOfBirth.month()<<"."<<this->dateOfBirth.year()<<";"
	   <<this->addressPointer.get()->getStreet()<<";"
	   <<this->addressPointer.get()->getPostalCode()<<";"
	   <<this->addressPointer.get()->getCityName()<<";"
	   <<this->addressPointer.get()->getAdditionalInfo()<<"\n";

}
