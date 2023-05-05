#include "Hotel.h"


string Person::getName() {
	return this->name;
}

void Person::showInfo() {
	cout << "[Person] name: " << this->name << endl;
}

float Employee::getSalary() {
	return this->salary;
}

void Employee::setSalary(float value) { 
	this->salary = value; 
}

string Manager::getDepartment() {
	return this->department; 
}

void Manager::setDepartment(string department) {
	this->department = department; 
};

void Manager::showInfo() {
	cout << "\033[36m[Manager] name: " << this->name << " \tsalary: " << this->salary << " \tdepartment: " << this->department << "\033[0m" << endl;
}

int Guest::instanceCount = 0;

void Guest::showInfo() {
	cout << "\033[35m" << "[Guest] name: " << this->name << " \tsaunaAcces: " << this->saunaAcces << "\033[0m" << endl;
}

int Guest::getCount() { 
	return this->instanceCount; 
}

