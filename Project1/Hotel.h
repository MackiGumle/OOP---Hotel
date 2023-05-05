#pragma once
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Info {
public:
	virtual void showInfo() = 0;
};

class Person : public Info {
protected:
	string name;

public:
	Person(string name) : name(name) {}
	virtual ~Person() {}
	string getName();
	void showInfo() override;
};

class Employee {
protected:
	float salary;

public:
	Employee(float salary) : salary(salary) {}
	float getSalary();
	void setSalary(float value);
};

class Manager : public Person, Employee {
private:
	string department;

public:
	Manager(string name, float salary) : Person(name), Employee(salary), department("") {}
	Manager(string name, float salary, string department) : department(department), Person(name), Employee(salary) {}
	~Manager() { cout << "\033[36m[Manager] deleted\033[0m" << endl; }
	void showInfo() override;
	string getDepartment();
	void setDepartment(string department);
};

// Pretizeny konstruktor + static atribut
class Guest : public Person {
private:
	static int instanceCount;
	bool saunaAcces;

public:
	Guest(string name) : Person(name), saunaAcces(false) { instanceCount++; }
	Guest(string name, bool sauna) : Person(name), saunaAcces(sauna) { instanceCount++; }
	~Guest() { cout << "\033[35m[Guest] deleted, instance count: " << --instanceCount << "\033[0m" << endl; }
	void showInfo();
	int getCount();
};

// Dynamicke pole ukazatelu na objekty jine tridy + pridani, mazani a preskladani
// Pretizeny konstruktor
class Room : public Info {
private:
	int number;
	vector<Person*> guests;
	double price;

public:
	Room(int number, double price) : number(number), price(price) { }
	~Room();
	void addGuest(Person* guest);
	void remGuest(Person* guest);
	int getGuestsCount() { return (int) this->guests.size(); };
	Person* getGuest(string name);
	void showInfo() override;
	void printGuests();
};

class Hotel : public Info {
private:
	string name;
	vector<Room*> rooms;
	int rating;

public:
	Hotel(string name, vector<Room*> rooms, int rating) : name(name), rooms(rooms), rating(rating) {}
	~Hotel();
	void showInfo();
	void setRating(int rating);
	void addRoom(Room* room);
};
