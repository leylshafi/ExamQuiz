#pragma once
class Admin:public User
{
	string username;
	string password;
public:
	Admin(string name, string surname, int age,string username, string password)
		:User(name,surname,age),username(username), password(password)
	{}
	string getUsername()const { return username; }
	string getPassword()const { return password; }
	friend ostream& operator<<(ostream& out, const Admin& a);
};
ostream& operator<<(ostream& out, const Admin& a)
{

	cout << "Name: " << a.getName() << endl
		<< "Surname: " << a.getSurname() << endl
		<< "Age: " << a.getAge() << endl;
	cout << "Username: " << a.username << endl;
	cout << "Password: " << a.password << endl;
	return out;
}

Admin createAdmin()
{
	string username, password,name,surname;
	int age;
	cout << "Enter name: " << endl;
	cin>>name;
	cout << "Enter surname: " << endl;
	cin>>surname;
	cout << "Enter age: " << endl;
	cin >> age;
	cout << "Enter username: " << endl;
	cin >> username;
	cout << "Enter password: " << endl;
	cin >> password;
	Admin a(name,surname,age,username, password);
	return a;
}

