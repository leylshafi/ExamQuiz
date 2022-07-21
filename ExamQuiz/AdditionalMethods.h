#pragma once
void StartMain::chooseQuizForPlayer(int& c, bool isPlayer)
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
				unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

				shuffle(quizes[i].getQuestions().begin(), quizes[i].getQuestions().end(), std::default_random_engine(seed));
				for (auto j = quizes[i].getQuestions().begin(); j!=quizes[i].getQuestions().end(); j++)
				{
					cout << *j << endl;
					cout << "Enter your answer: " << endl;
					cin >> ans;
					for (size_t k = 0; k < ( * j).getAnswers().size(); k++)
					{
						if (ans == (*j).getAnswers()[k].getText() && (*j).getAnswers()[k].GetIfIsCorrect() == true)
							corr += 1;
					}

				}
			}

		}
		if (corr > max)
			max = corr;
		string forLeaderBoard;
		if (corr > 0 && isPlayer == true) {
			cout << "How do you want to be added to the leaderboard: " << endl;
			cin >> forLeaderBoard;
			forLeaderBoard = forLeaderBoard + "   " + to_string(corr);
			leaderBoard.push_back(forLeaderBoard);
		}
		cout << "Your score" << corr << endl;

		Sleep(3000);

	}
}

void StartMain::chooseMenuForPlayer(int& c, bool isPlayer)

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
		if (c == 0) {
			readFile();
			chooseTheQuiz = true;
			while (chooseTheQuiz) {
				system("cls||clear");
				c == 0 ? cout << setw(10) << char(62) : cout << ' ';
				cout << setw(10) << "Go Back";
				cout << endl;
				for (size_t i = 0; i < vectorOfQuizNames.size(); i++)
				{
					c == i + 1 ? cout << setw(10) << char(62) : cout << ' ';
					cout << setw(10) << vectorOfQuizNames[i];
					cout << endl;

				}
				chooseQuizForPlayer(c, isPlayer);
			}
			Sleep(4000);


		}
		else if (c == 1) {
			cout << R"(
__________________________________________________________________________________________
    _                                                                                     
    /                         /                          /                               /
---/--------__-----__-----__-/-----__----)__------------/__-----__-----__----)__-----__-/-
  /       /___)  /   )  /   /    /___)  /   )          /   )  /   )  /   )  /   )  /   /  
_/____/__(___ __(___(__(___/____(___ __/______________(___/__(___/__(___(__/______(___/___
                                                                                          
                                                                                          
)" << endl;
			for (size_t i = 0; i < leaderBoard.size(); i++)
			{
				cout << i + 1 << ")" << leaderBoard[i] << endl;
			}

			Sleep(4000);
		}
		else if (c == 2) {
			cout << "Go back again" << endl;

			menuChoose = false;
			Sleep(1500);
			turnMain = true;
			startMain();
			menuChoose = true;


		}
	}

}
