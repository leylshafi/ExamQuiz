#pragma once



void StartMain::chooseQuiz(int& c)
{
	int k;
	switch (k = _getch())
	{
	case KEY_UP:
		c--;
		if (c < 0)
			c = 0;
		break;
	case KEY_DOWN:
		c++;
		if (c > vectorOfQuizNames.size())
			c = vectorOfQuizNames.size();
		break;
	case'\r':
		int corr = 0;
		string ans;
		if (c == 0)
		{
			chooseTheQuiz = false;
			turnMain = true;
			startMain();
		}
		for (size_t i = 0; i < quizes.size(); i++)
		{
			if (i + 1 == c)
			{
				for (size_t j = 0; j < quizes[i].getQuestions().size(); j++)
				{
					cout << quizes[i].getQuestions()[j] << endl;
					cout << "Enter your answer: " << endl;
					cin >> ans;
					for (size_t k = 0; k < quizes[i].getQuestions()[j].getAnswers().size(); k++)
					{
						if (ans == quizes[i].getQuestions()[j].getAnswers()[k].getText() && quizes[i].getQuestions()[j].getAnswers()[k].GetIfIsCorrect() == true)
							corr += 1;
					}

				}
			}

		}
		if (corr > max)
			max = corr;
		cout << "Your score" << corr << endl;

		Sleep(3000);

	}
}

void StartMain::chooseMenu(int& c)
{

	int k;
	switch (k = _getch())
	{
	case KEY_UP:
		c--;
		if (c < 0)
			c = 0;
		break;
	case KEY_DOWN:
		c++;
		if (c > 3)
			c = 3;
		break;
	case '\r':

		
		system("cls||clear");
		if (c == 0)
		{
			ofstream ofs("quizNames.txt", ios::app);
			string whole;
			string quizname;
			cout << "Enter quiz name: " << endl;
			cin >> quizname;
			string FileName = quizname + to_string(quizCount + 1) + ".txt";
			ofs << FileName;
			ofs << ':';
			fstream file(FileName);
			quizCount++;
			file.open(FileName, ios::app);

			if (!file) {
				throw exception("File couldn't created");
			}

			Quiz q(quizname, __DATE__);
			if (!file.is_open()) {
				file.close();
				throw new exception("File can not opened");
			}
			file << endl << q.getName() << endl << q.getDateTime();
			file << ':';

			int numberOfQuestions;
			int numberOfAnswers;
			cout << "Enter the number of questions in quiz: " << endl;
			cin >> numberOfQuestions;
			string questionText;
			string answerText;
			bool isItTrue;
			int num = 97;
			for (size_t i = 0; i < numberOfQuestions; i++)
			{
				cout << "Enter question: " << endl;
				cin.ignore();
				getline(cin, questionText);
				Question question(i, questionText);
				file << endl << question.getNo() << endl << question.getText();
				file << ':';
				q.getQuestions().push_back(question);
				cout << "How many answer you will add?" << endl;
				cin >> numberOfAnswers;
				for (size_t j = 0; j < numberOfAnswers; j++)
				{
					cout << "Enter answer " << j + 1 << endl;
					cin.ignore();
					getline(cin, answerText);
					cout << "Is it true? " << endl;
					cin >> isItTrue;
					Answer a(answerText, isItTrue);
					file << endl << char(num++) << ")" << a.getText() << "-" << a.GetIfIsCorrect();
					file << ':';
					q.getQuestions()[i].getAnswers().push_back(a);

				}




			}
			quizes.push_back(q);
			ofs.close();

			
			Sleep(4000);
		}
		else if (c == 1) {
			readFile();
			
			while (chooseTheQuiz) {
				system("cls||clear");
				c == 0 ? cout <<setw(10)<< char(62) : cout << ' ';
				cout << setw(10) << "Go Back";
				cout << endl;
				for (size_t i = 0; i < vectorOfQuizNames.size(); i++)
				{
					c == i+1 ? cout << setw(10) << char(62) : cout << ' ';
					cout << setw(10) << vectorOfQuizNames[i];
					cout << endl;

				}
				chooseQuiz(c);
			}
			Sleep(4000);

		}
		else if (c == 2) {
			cout << "====== Leader Board ======" << endl;
			for (size_t i = 0; i < leaderBoard.size(); i++)
			{
				cout << i + 1 << ")" << leaderBoard[i] << endl;
			}

			Sleep(4000);
		}
		else if (c == 3) {
			cout << "Go back again" << endl;

			menuChoose = false;
			Sleep(1500);
			turnMain = true;
			startMain();
			menuChoose = true;


		}
	}

}

bool StartMain::signIn(string username, string password)

{
	for (size_t i = 0; i < admins.size(); i++)
	{
		if (username == admins[i].getUsername() && password == admins[i].getPassword())
			return true;
	}
	return false;
}

void StartMain::chooseSign(int& c)

{
	int k;
	switch (k = _getch())
	{
	case KEY_UP:
		c--;
		if (c < 0)
			c = 0;
		break;
	case KEY_DOWN:
		c++;
		if (c > 1)
			c = 1;
		break;
	case '\r':
		system("cls||clear");
		if (c == 0)
		{
			admins.push_back(createAdmin());
			cout << "Succesfully Sign up" << endl;
			Sleep(1500);
			adminChoose = false;


		}
		else if (c == 1) {

			string username, password;
			cout << "Enter username and password: " << endl;
			cin >> username >> password;

			signIn(username, password) ? cout << "Welcome" : cout << "Username or password is incorrect";

			Sleep(1500);

			adminChoose = false;

		}
	}

}

void StartMain::mainSide(int& c)

{
	int k;
	switch (k = _getch())
	{
	case KEY_LEFT:
		c--;
		if (c < 0)
			c = 0;
		break;
	case KEY_RIGHT:
		c++;
		if (c > 2)
			c = 2;
		break;
	case '\r':

		system("cls||clear");
		if (c == 0)
		{
			turnMain = false;
			int c = 0;
			while (adminChoose)
			{
				system("cls");
				cout << setw(25) << "Sign up";
				c == 0 ? cout << char(60) : cout << ' ';
				cout << endl;
				cout << setw(25) << "Sign in";
				c == 1 ? cout << char(60) : cout << ' ';
				cout << endl;
				chooseSign(c);
			}

			while (menuChoose)
			{
				system("cls");
				cout << setw(25) << "Add quiz";
				c == 0 ? cout << char(60) : cout << ' ';
				cout << endl;
				cout << setw(25) << "Test quiz";
				c == 1 ? cout << char(60) : cout << ' ';
				cout << endl;
				cout << setw(25) << "See leader board";
				c == 2 ? cout << char(60) : cout << ' ';
				cout << endl;
				cout << setw(25) << "Exit";
				c == 3 ? cout << char(60) : cout << ' ';
				cout << endl;
				chooseMenu(c);
			}
		}
		else if (c == 1) {
			turnMain = false;
			cout << "Player" << endl;
			players.push_back(createPlayer());

			int c = 0;

			while (menuChooseUserr)
			{
				system("cls");
				cout << setw(25) << "Start quiz";
				c == 0 ? cout << char(60) : cout << ' ';
				cout << endl;
				cout << setw(25) << "See leader board";
				c == 1 ? cout << char(60) : cout << ' ';
				cout << endl;
				cout << setw(25) << "Go back to menu";
				c == 2 ? cout << char(60) : cout << ' ';
				cout << endl;
				chooseMenuForPlayer(c, 1);
			}
		}
		else if (c == 2) {
			turnMain = false;
			cout << "Guest" << endl;
			guests.push_back(createGuest());

			int c = 0;

			while (menuChooseUserr)
			{
				system("cls");
				cout << setw(25) << "Start quiz";
				c == 0 ? cout << char(60) : cout << ' ';
				cout << endl;
				cout << setw(25) << "See leader board";
				c == 1 ? cout << char(60) : cout << ' ';
				cout << endl;
				cout << setw(25) << "Go back to menu";
				c == 2 ? cout << char(60) : cout << ' ';
				cout << endl;
				chooseMenuForPlayer(c, 0);
			}
		}
		break;
	}
}