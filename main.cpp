#include "main.h"

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	srand((unsigned int)time(NULL));

	cursor_hide();

	bool should_show_foreword = true;

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
			if (should_show_foreword)
			{
				should_show_foreword = false;
				print_foreword();
			}
			print_difficuty_option();
			int difficuty;
			std::cin >> difficuty;
			//mciSendStringW(L"close bgm2", NULL, 0, NULL);
			print_difficuty_description(difficuty);
			mciSendStringW(L"open ./music/Kirov.mp3 alias Kirov", NULL, 0, NULL);
			mciSendStringW(L"play Kirov", NULL, 0, NULL);
			Sleep(2000);
			if (difficuty == 1)
			{
				play_game(25, 115, 90, -1, -1);
			}
			if (difficuty == 2)
			{
				play_game(45, 135, 180, 8, 32);
			}
			if (difficuty == 3)
			{
				play_game(75, 255, 240, 8, 32);
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