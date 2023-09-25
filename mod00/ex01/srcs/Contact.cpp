#include "Contact.hpp"

Contact::Contact() {
	this->FirstName.clear();
	this->LastName.clear();
	this->Nickname.clear();
	this->PhoneNumber.clear();
	this->DarkestSecret.clear();
}

Contact::~Contact() {}

void	Contact::FillInfos () {
	this->FirstName = GetEntry("First name : ");
	this->LastName = GetEntry("Last name : ");
	this->Nickname = GetEntry("Nickname : ");
	this->PhoneNumber = GetEntry("Phone number : ");
	this->DarkestSecret = GetEntry("Darkest secret : ");
}

void	Contact::View() const {
	std::cout	<< "First name : " << this->FirstName << std::endl
				<< "Last name : " << this->LastName << std::endl
				<< "Nickname : " << this->Nickname << std::endl
				<< "Phone number : " << this->PhoneNumber << std::endl
				<< "Darkest secret : " << this->DarkestSecret << std::endl;
}

std::string Contact::GetFirstName() {
	return (this->FirstName);
}

std::string Contact::GetLastName() {
	return (this->LastName);
}

std::string Contact::GetNickname() {
	return (this->Nickname);
}