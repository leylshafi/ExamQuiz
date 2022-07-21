#pragma once
class Answer
{

	string text;
	bool isCorrect;
public:
	Answer() = default;
	Answer(string text, bool isCorrect)
		:text(text), isCorrect(isCorrect)
	{}
	string getText()const { return text; }
	bool GetIfIsCorrect()const { return isCorrect; }
	friend ostream& operator<<(ostream& out, const Answer& a);
};
ostream& operator<<(ostream& out, const Answer& a)
{
	cout << a.text << endl;
	return out;
}

