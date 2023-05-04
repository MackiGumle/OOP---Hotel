#pragma once
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Info {
public:
	virtual void showInfo() = 0;
};

//1 4 5 6 9 10
class Person : public Info {
protected:
	string name;
	float salary;

public:
	Person(string name) : name(name), salary(0) {}
	Person(string name, float salary) : name(name), salary(salary) {}
	virtual ~Person() {}
	string getName() { return this->name; }
	float getSalary() { return this->salary; }
};

class Manager : public Person {
public:
	Manager(string name, float salary) : Person(name, salary) {}
	void showInfo() override { cout << "[Manager] name: " << this->name << endl; }
};

class Guest : public Person {
private:
	static int instanceCount;

public:
	Guest(string name) : Person(name) { instanceCount++; }
	Guest(string name, float salary) : Person(name, salary) { instanceCount++; }
	~Guest() { instanceCount--; }
	void showInfo() override { cout << "[Guest] name: " << this->name << endl; }
};

class Cook : public Person {
public:
	Cook(string name, float salary) : Person(name, salary) {}
	void showInfo() override { cout << "[Cook] name: " << this->name << "salary: " << this->salary << endl; }
};

class Room : public Info {
protected:
	int number;
	vector<Guest*> guests;
	double price;

public:
	Room(int number, double price) : number(number), price(price) { }
	Room(int number, vector<Guest*> guests, double price) : number(number), guests(guests), price(price) { }
	void showInfo() override { cout << "[Room] number: " << this->number << ", price: " << this->price << endl; }
	void addGuest(Guest* guest);
	void remGuest(Guest* guest);
	void printGuests();

};

class Hotel : public Info {
protected:
	string name;
	vector<Room*> rooms;
	int rating;

public:
	Hotel(string name, vector<Room*> rooms, int rating) : name(name), rooms(rooms), rating(rating) {}
	virtual ~Hotel() {}
	void showInfo() override { cout << "[Hotel] name: " << this->name << ", rating: " << this->rating << endl; }
};

class Reservation : public Info {
protected:
	int id;
	int duration;
	double totalPrice;
public:
	Reservation(int id, int duration, double totalPrice) : id(id), duration(duration), totalPrice(totalPrice) {}
	~Reservation() {}
	void calculateTotalPrice(double roomPrice);
	void showInfo() { cout << "[Reservation] id: " << this->id << " duration:" << this->duration << "price: " << this->totalPrice << endl; }
};
