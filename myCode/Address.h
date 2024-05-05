/*
 * Address.h
 *
 *  Created on: 17-Jan-2024
 *      Author: Dabbiru Sunil
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_
#include <string>
#include <fstream>
class Address
{
private:
	std::string street;
	unsigned short postalCode;
	std::string cityName;
	std::string additionalInfo;
public:
	Address(std::string street,unsigned short postalCode,std::string cityName,std::string additionalInfo);
	std::string getStreet();
	unsigned short getPostalCode();
	std::string getCityName();
	std::string getAdditionalInfo();
	virtual ~Address();
	static Address* read(std::istream &in);
};

#endif /* ADDRESS_H_ */
