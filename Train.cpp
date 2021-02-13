#include "Train.h"
#include <iostream>

bool isDigit(const size_t& SIZE_, const string& string_) {
	for (size_t i = 0; i < SIZE_; i++)
	{
		if (!isdigit(string_[i]))
		{
		}
		else {
			return true;
		}
	}
	return false;
}
void Train::setNumber(const int& number)
{
	this->number = number;
}

void Train::setName(const string& name)
{
	if (!name.empty())
	{
		if (isDigit(name.length(), name))
		{
			this->name = name;
		}

	}
	else {
		cout << "Enter Correct Name!" << endl;
	}
}

const int Train::getNumber() const
{
	return number;
}

const string Train::getName() const
{
	return name;
}

const int Train::getSize() const
{
	return size;
}

Car Train::getMaxPassengers(const int size) const
{
	Car max;
	max = *list.begin();
	for (auto& v : list)
	{
		if (max.getCountPassengers() < v.getCountPassengers())
		{
			max = v;
		}
	}
	return max;
}

Car Train::getMinPassengers(const int size) const
{
	Car min;
	min = *list.begin();
	for (auto& v : list) {
		if (min.getCountPassengers() > v.getCountPassengers())
		{
			min = v;
		}
	}
	return min;
}

const int Train::getAllPassengers() const
{
	int summ = 0;
	for (auto& v : list)
	{
		summ += v.getCountPassengers();
	}
	return summ;
}

Train::Train()
	:size(0)
{
	number = 0;
	name = "NoName";
}



Train::Train(const int& size_)
	:size(size_)
{
	number = 0;
	name = "NoName";
	for (size_t i = 0; i < size; i++)
	{
		Car car;
		list.push_back(car);
	}
}

Train::Train(const int& size_, const int& number, const string& name)
	:size(size_)
{
	this->number = number;
	this->name = name;
	for (size_t i = 0; i < size; i++)
	{
		Car car;
		list.push_back(car);
	}
}

Train::Train(const Train& other)
	:size(other.size)
{
	setName(other.name);
	copyCars(other);
	setNumber(other.number);
}

Train& Train::operator=(const Train& other)
{
	if (this != &other)
	{
		setName(other.name);
		copyCars(other);
		setNumber(other.number);
	}
	return *this;
}

Train::~Train()
{
	list.clear();
}

void Train::copyCars(const Train& other)
{
	for (auto& v : other.list)
	{
		list.push_back(v);
	}
}

void Train::print()const
{
	cout << "####################################" << endl;
	cout << "Name: " << name << endl;
	cout << "Number: " << number << endl;
	cout << "Size: " << size << endl;
	for (auto& v : list)
		cout << v << endl;
	cout << "####################################" << endl;
}

void Train::printAll() const
{
	print();
	cout << "Count of cars: " << size << endl;
	cout << "All Passegers: " << getAllPassengers() << endl;
	cout << "Number of car with Max passegers: " << getMaxPassengers(size).getTypeCar() << endl;
	cout << "Number of car with Min passegers: " << getMinPassengers(size).getTypeCar() << endl;
}