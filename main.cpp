#include<iostream>
#include "Time.h"
#include "Cls_and_Print.h"
#include "Play_Game.h"
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	srand(time(NULL));

	cursor_hide();

	while (true)
	{
		system("cls");
		print_menu();
		int opt;
		std::cin >> opt;
		system("cls");
		if (opt == 1)
		{
			print_description();
			int difficuty;
			std::cin >> difficuty;
			print_difficuty(difficuty);
			Sleep(2000);
			if (difficuty == 1)
			{
				play_game(25, 115, 300, -1, -1);
			}
			if (difficuty == 2)
			{
				play_game(45, 135, 300, 8, 32);
			}
			if (difficuty == 3)
			{
				play_game(75, 255, 300, 8, 32);
			}
			if (difficuty == 4)
			{
				play_game(165, 325, 300, 8, 24);
			}
		}
		if (opt == 2) break;
	}

	return 0;
}