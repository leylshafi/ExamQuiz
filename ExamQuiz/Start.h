#pragma once
class StartMain
{
	vector<Admin>admins;
	vector<Guest>guests;
	vector<Player>players;
	vector<Quiz>quizes;

	vector<string>leaderBoard;

	vector<string>vectorOfQuizNames;
	int quizCount = 0;
	int max = 0;
	string FileName;

	bool turnMain = true;
	bool turnGuest = true;
	bool turnAdmin = true;
	bool chooseTheQuiz = true;
	bool menuChooseUserr = true;

	bool adminChoose = true;
	bool userChoose = true;
	bool menuChoose = true;

	string line;

public:
	
	void readFile()
	{
		string fileNameString;
		ifstream ifs("quizNames.txt", ios::in);

		if (!ifs)
			throw new exception("File can not find");

		if (!ifs.is_open()) {
			ifs.close();
			throw new exception("File can not opened");
		}

		while (!ifs.eof())
		{
			getline(ifs, fileNameString, ':');
			vectorOfQuizNames.push_back(fileNameString);
		}
		ifs.close();
	}

	void chooseQuiz(int& c);

	void chooseQuizForPlayer(int& c, bool isPlayer);

	void chooseMenu(int& c);
	
	void chooseMenuForPlayer(int& c, bool isPlayer);
	
	bool signIn(string username, string password);
	void chooseSign(int& c);
	
	void mainSide(int& c);
	
	void startMain() {
		int c = 0;
		while (turnMain) {
			system("cls");
			if (c == 0) {
				SetConsoleTextAttribute(h, 9);
				cout << setw(25) << "Admin";
				cout << endl;
				SetConsoleTextAttribute(h, 15);
			}
			else if (c == 1)
			{
				SetConsoleTextAttribute(h, 9);
				cout << setw(25) << "Player";
				cout << endl;
				SetConsoleTextAttribute(h, 15);
			}
			else if (c == 2)
			{
				SetConsoleTextAttribute(h, 9);
				cout << setw(25) << "Guest";
				cout << endl;
				SetConsoleTextAttribute(h, 15);
			}
			c == 0 ? cout << setw(40) << char(62) : cout << ' ';
			c == 1 ? cout << char(60) << setw(40) << char(62) : cout << ' ';
			c == 2 ? cout << char(60) : cout << ' ';

			mainSide(c);
		}
	}



};