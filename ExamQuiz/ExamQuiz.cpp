#include <iostream>
#include<vector>
#include<conio.h>
#include<iomanip>
#include<Windows.h>
#include<string>
#include<vector>
#include<list>
#include<fstream>
#include<sstream>
#include<algorithm>
#include <random>      
#include <chrono>

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

#include"User.h"
#include"Admin.h"
#include"Guest.h"
#include"Player.h"

#include"Answer.h"
#include"Question.h"
#include"Quiz.h"
#include"Start.h"
#include"MethodsOfAdmin.h"
#include"AdditionalMethods.h"


int main()
{
	cout << R"(
 __          __         _                                         _                  ____            _       
 \ \        / /        | |                                       | |                / __ \          (_)      
  \ \  /\  / /    ___  | |   ___    ___    _ __ ___     ___      | |_    ___       | |  | |  _   _   _   ____
   \ \/  \/ /    / _ \ | |  / __|  / _ \  | '_ ` _ \   / _ \     | __|  / _ \      | |  | | | | | | | | |_  /
    \  /\  /    |  __/ | | | (__  | (_) | | | | | | | |  __/     | |_  | (_) |     | |__| | | |_| | | |  / / 
     \/  \/      \___| |_|  \___|  \___/  |_| |_| |_|  \___|      \__|  \___/       \___\_\  \__,_| |_| /___|
                                                                                                             
                                                                                                             
)" << endl;

    
	Sleep(4000);
	StartMain s;
	s.startMain();
}