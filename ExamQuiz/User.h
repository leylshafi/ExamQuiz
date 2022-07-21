#pragma once
class User
{
	string name;
	string surname;
	int age;

public:
	User(string name,string surname,int age)
	{
		this->name = name;
		this->surname = surname;
		this->age = age;
	}

	string getName()const { return name; }
	string getSurname()const { return surname; }
	int getAge()const { return age; }

};

