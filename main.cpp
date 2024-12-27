#include "main.h"

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	srand((unsigned int)time(NULL));

	cursor_hide();

	while (true)
	{
		mciSendStringW(L"open ./music/1.mp3 alias bgm1", NULL, 0, NULL);
		mciSendStringW(L"play bgm1", NULL, 0, NULL);
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
			//mciSendStringW(L"close bgm2", NULL, 0, NULL);
			print_difficuty(difficuty);
			mciSendStringW(L"open ./music/Kirov.mp3 alias Kirov", NULL, 0, NULL);
			mciSendStringW(L"play Kirov", NULL, 0, NULL);
			Sleep(2000);
			if (difficuty == 1)
			{
				play_game(25, 115, 100, -1, -1);
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
	mciSendStringW(L"close bgm1", NULL, 0, NULL);
	return 0;
}