#include "Game.h"

void print_game(const Map& map, const int& time_limit)
{
	map.print();
	set_game_timer();
	if (time_limit == -1) std::cout << "游戏已经开始了" << get_timer() << "秒\n";
	else
	{
		std::cout << "剩余时间:";
		if (time_limit - get_timer() <= 15) set_color_and_background(4, 0);
		std::cout << time_limit - get_timer();
		set_color_and_background(15, 0);
		std::cout << "秒\n";
	}
}
void print_game_with_fog(const Map& map, const int& time_limit, const int& length, const int& width)
{
	map.print_with_fog(length, width);
	set_game_timer();
	if (time_limit == -1) std::cout << "游戏已经开始了" << get_timer() << "秒\n";
	else
	{
		std::cout << "剩余时间:";
		if (time_limit - get_timer() <= 15) set_color_and_background(4, 0);
		std::cout << time_limit - get_timer();
		set_color_and_background(15, 0);
		std::cout << "秒\n";
	}
}
void print_game_over(const int& over_id)
//id==1，因到达终点而导致游戏结束（胜利）
//id==2，因时间耗尽而导致游戏结束（失败）
{
	if (over_id == 1)
	{
		std::cout << "你到达了终点！你";
		set_color_and_background(2, 0);
		std::cout << "胜利";
		set_color_and_background(15, 0);
		std::cout << "了！\n";
	}
	if (over_id == 2)
	{
		std::cout << "时间耗尽！你";
		set_color_and_background(4, 0);
		std::cout << "失败";
		set_color_and_background(15, 0);
		std::cout << "了！\n";
	}
}
int play_game(const int& length, const int& width, const int& time_limit, const int& vision_length, const int& vision_width)
//如果vision_length==0则打印整个迷宫
//返回值为1，因到达终点而导致游戏结束（胜利）
//返回值为2，因时间耗尽而导致游戏结束（失败）
{
	system("cls");
	set_reference_timer();

	Map map(length, width);//迷宫的行数的列数应该都是奇数

	bool final_flag = 0;

	while (true)
	{
		if (time_limit - get_timer() < 50 and final_flag == 0) {
			mciSendStringW(L"close bgm1", NULL, 0, NULL);
			mciSendStringW(L"open ./music/final.mp3 alias final", NULL, 0, NULL);
			mciSendStringW(L"play final", NULL, 0, NULL);
			final_flag = 1;
		}

		bool should_refresh = false;
		should_refresh = should_refresh or should_renew_game_timer();
		if (key_down(VK_LEFT))
		{
			if (map.reachable(0, -1))
			{
				should_refresh = true;
				map.move(0, -1);
			}

		}
		if (key_down(VK_RIGHT))
		{
			if (map.reachable(0, 1))
			{
				should_refresh = true;
				map.move(0, 1);
			}
		}
		if (key_down(VK_UP))
		{
			if (map.reachable(-1, 0))
			{
				should_refresh = true;
				map.move(-1, 0);
			}
		}
		if (key_down(VK_DOWN))
		{
			if (map.reachable(1, 0))
			{
				should_refresh = true;
				map.move(1, 0);
			}
		}
		if (should_refresh)
		{
			cursor_goto_0_0();

			if (vision_length == -1) print_game(map, time_limit);
			else print_game_with_fog(map, time_limit, vision_length, vision_width);

			if (map.win())
			{
				print_game_over(1);
				Sleep(3000);
				return 1;
			}

			set_game_timer();
			if (time_limit - get_timer() <= 0 and time_limit != -1)
			{
				print_game_over(2);
				Sleep(3000);
				return 2;
			}
		}
		Sleep(10);
	}
	return -655;
}
void print_menu(void)
{
	std::cout <<
		"**!**=()=**!**  Welcome Maze Game ~~~  my friend!   **!**=()=**!**\n"
		"           QWQ                         qwq        \n"
		"               The palace of our game            \n"
		"                      游戏大厅                    \n"
		"\n"
		"\n";
	set_color_and_background(3, 0);
	std::cout <<
		"1. Start your journey,my warrior !\n";
	set_color_and_background(4, 0);
	std::cout <<
		"2. hope to see you again\n";
	set_color_and_background(15, 0);
	std::cout <<
		"============================================\n";
}
void print_description(void)
{
	mciSendStringW(L"open ./music/2.mp3 alias bgm2", NULL, 0, NULL);
	mciSendStringW(L"play bgm2", NULL, 0, NULL);
	set_color_and_background(15, 0);
	std::cout <<
		"引言：\n"
		"\n";
	Sleep(2000);
	std::cout <<
		"在踏上征途的第";
	set_color_and_background(3, 0);
	std::cout <<
		"三";
	set_color_and_background(15, 0);
	std::cout <<
		"个年头，你经过了一座城池。\n"
		"\n";
	Sleep(3000);
	std::cout <<
		"城里的人们，";
	Sleep(1000);
	set_color_and_background(6, 0);
	std::cout <<
		"神情木讷，像玩偶一样";
	set_color_and_background(15, 0);
	std::cout <<
		"。\n"
		"\n";
	Sleep(3000);
	std::cout <<
		"而你，";
	Sleep(1000);
	std::cout <<
		"在探险城市之时，";
	Sleep(1000);
	std::cout <<
		"不幸遭遇了罪魁祸首————";
	set_color_and_background(10, 0);
	std::cout <<
		"黑魔法师";
	set_color_and_background(15, 0);
	std::cout <<
		"————的偷袭。\n"
		"\n";
	Sleep(3000);
	std::cout <<
		"你被变成了一只";
	set_color_and_background(4, 0);
	std::cout <<
		"老鼠";
	set_color_and_background(15, 0);
	std::cout <<
		"，";
	Sleep(2000);
	std::cout <<
		"关进了充满迷雾的地牢里。\n"
		"\n";
	Sleep(3000);
	std::cout <<
		"现在，你只有十分有限的时间，找到出口，\n"
		"\n";
	Sleep(1000);
	std::cout <<
		"逃离.......\n"
		"\n";
	set_color_and_background(4, 0);
	Sleep(3000);
	std::cout <<
		"逃离.......\n"
		"\n";
	Sleep(3000);
	set_color_and_background(15, 0);
	std::cout <<
		"请选择难度系数(1~4):\n";
}
void print_difficuty(const int& difficulty)
{
	if (difficulty == 1)
	{
		set_color_and_background(15, 0);
		std::cout <<
			"难度：1\n"
			"地牢大小：25*115\n"
			"时间限制：300秒\n"
			"视野：整个地牢\n";
		set_color_and_background(3, 0);
		std::cout <<
			"出口在地牢的右下角\n";
		set_color_and_background(15, 0);
	}
	if (difficulty == 2)
	{
		set_color_and_background(15, 0);
		std::cout <<
			"难度：2\n"
			"地牢大小：45*135\n"
			"时间限制：300秒\n"
			"视野：17*65\n";
		set_color_and_background(3, 0);
		std::cout <<
			"出口在地牢的右下角\n";
		set_color_and_background(15, 0);
	}
	if (difficulty == 3)
	{
		set_color_and_background(15, 0);
		std::cout <<
			"难度：3\n"
			"地牢大小：75*255\n"
			"时间限制：300秒\n"
			"视野：17*65\n";
		set_color_and_background(3, 0);
		std::cout <<
			"出口在地牢的右下角\n";
		set_color_and_background(15, 0);
	}
	if (difficulty == 4)
	{
		set_color_and_background(15, 0);
		std::cout <<
			"难度：4\n"
			"地牢大小：165*325\n"
			"时间限制：300秒\n"
			"视野：17*49\n";
		set_color_and_background(3, 0);
		std::cout <<
			"出口在地牢的右下角\n";
		set_color_and_background(15, 0);
	}
}