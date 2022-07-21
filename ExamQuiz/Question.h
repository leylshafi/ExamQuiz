#pragma once
class Question
{

	int no;
	string text;
	vector<Answer>answers;
	Question() = default;
public:
	Question(int no, string text)
		:no(no), text(text)
	{}
	int getNo()const { return no; }
	string getText()const { return text; }
	vector<Answer>& getAnswers() { return answers; }
	int size()const { return answers.size(); }
	friend ostream& operator<<(ostream& out, const Question& q);
};
ostream& operator<<(ostream& out, const Question& q)
{
	cout << q.no + 1 << ") " << q.text << endl;
	for (size_t i = 0; i < q.answers.size(); i++)
	{
		cout << "     " << char(i + 97) << ") " << q.answers[i];
	}
	return out;
}

