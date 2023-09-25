#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>

PhoneBook::PhoneBook() {
	this->NbOfContacts = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::Add() {
	static int Index = 0;
	this->ContactTab[Index].FillInfos();
	if (this->NbOfContacts < 8) {
		++this->NbOfContacts;
	}
	if (++Index == 8) {
		Index = 0;
	}
}

void PhoneBook::View() {
	std::cout	<< "|" << std::setw(10) << "Index"
				<< "|" << std::setw(10) << "First name"
				<< "|" << std::setw(10) << "Last name"
				<< "|" << std::setw(10) << "Nickname"
				<< "|" << std::endl;
	for (int i = 0; i < this->NbOfContacts; ++i) {
		std::cout	<< "|" << std::setw(10) << i + 1
					<< "|" << std::setw(10) << Trunc10(this->ContactTab[i].GetFirstName())
					<< "|" << std::setw(10) << Trunc10(this->ContactTab[i].GetLastName())
					<< "|" << std::setw(10) << Trunc10(this->ContactTab[i].GetNickname())
					<< "|" << std::endl;
	}
}

void PhoneBook::Search() {
	if (this->NbOfContacts == 0) {
		std::cout << "PhoneBook empty use ADD to add a contact" << std::endl;
		return;
	}
	View();
	int Index;
	bool ValidIndex;
	do {
		std::string Entry = GetEntry("Enter index : ");
		if (!IsOnlyNum(Entry)) {
			ValidIndex = false;
			std::cout << "Invalid format please try again" << std::endl;
		}
		else {
			ValidIndex = true;
		}
		if (ValidIndex) {
			Index = atoi(Entry.c_str());
			if (Index < 1 || Index > this->NbOfContacts) {
				ValidIndex = false;
				std::cout << "Invalid index please try again" << std::endl;
			}
		}
	} while (!ValidIndex);
	this->ContactTab[Index - 1].View();
}