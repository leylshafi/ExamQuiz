#pragma once
class Quiz
{

	string name="";
	string dateTime = "";
	vector<Question>questions;
public:

	Quiz() = default;
	Quiz(string name, string dateTime)
		:name(name), dateTime(dateTime), questions(questions)
	{}
	string getName()const{ return name; }
	string getDateTime() const { return dateTime; }
	vector<Question>& getQuestions() { return questions; }
	friend ostream& operator<<(ostream& out, const Quiz& q);
};


ostream& operator<<(ostream& out, const Quiz& q)
{
	cout << endl;
	cout << "Name: " << q.name << endl
		<< "Date Time: " << q.dateTime << endl;
	cout << endl;
	cout << "===== Questions =====" << endl;;
	for (size_t i = 0; i < q.questions.size(); i++)
	{
		cout << q.questions[i];
	}
	return out;
}

