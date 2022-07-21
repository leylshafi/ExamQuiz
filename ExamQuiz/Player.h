#pragma once
class Player:public User
{
	string username;

public:
	Player(string name, string surname,int age,string username)
		:User(name,surname,age), username(username)
	{}
	friend ostream& operator<<(ostream& out, const Player& p);
};
ostream& operator<<(ostream& out, const Player& p) {
	cout << "Name: " << p.getName() << endl
		<< "Surname: " << p.getSurname() << endl
		<< "Age: " << p.getAge() << endl;
	cout <<"Username: " << p.username << endl;
	return out;
}

Player createPlayer()
{
	string name, surname,username;
	int age;
	cout << "Enter your name: " << endl;
	cin >> name;
	cout << "Enter your surname: " << endl;
	cin >> surname;
	cout << "Enter your username: " << endl;
	cin >> username;
	cout << "Enter your age: " << endl;
	cin >> age;


	Player p(name, surname,age,username);
	return p;
}