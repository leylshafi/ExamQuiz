#pragma once
class Guest:public User
{
	string dateOfLogin;
public:
	Guest(string name,string surname,int age,string dateOfLogin)
		:User(name,surname,age),dateOfLogin(dateOfLogin)
	{}

};

Guest createGuest()
{
	string  name, surname;
	int age;
	cout << "Enter name: " << endl;
	cin >> name;
	cout << "Enter surname: " << endl;
	cin >> surname;
	cout << "Enter age: " << endl;
	cin >> age;
	Guest g(name,surname,age,__DATE__);
	return g;
}

