/*
 * Address.cpp
 *
 *  Created on: 17-Jan-2024
 *      Author: Dabbiru Sunil
 */

#include "Address.h"

Address::Address(std::string street, unsigned short postalCode,
		std::string cityName, std::string additionalInfo):street(street),
		postalCode(postalCode),cityName(cityName),additionalInfo(additionalInfo)
{

}

std::string Address::getStreet()
{
	return this->street;
}

unsigned short Address::getPostalCode()
{
	return this->postalCode;
}

std::string Address::getCityName()
{
	return this->cityName;
}

std::string Address::getAdditionalInfo()
{
	return this->additionalInfo;
}

Address::~Address()
{
	// TODO Auto-generated destructor stub
}
Address* Address::read(std::istream &in) {
	std::string street;
	unsigned short postalCode;
	std::string cityName;
	std::string additionalInfo;

	std::string data;

	getline(in, data, ';');
	street = data;

	getline(in, data, ';');
	postalCode = stol(data);

	getline(in, data, ';');
	cityName = data;

	getline(in, data);
	additionalInfo = data;

	Address *temp_address = new Address(street, postalCode, cityName,
			additionalInfo);
	return temp_address;
}

