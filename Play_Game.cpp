#include<iostream>
#include<windows.h>
#include "Time.h"
#include "Press_Key.h"
#include "Map.h"
#include "Cls_and_Print.h"
#include "Play_Game.h"
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
int play_game(const int& length, const int& width, const int& time_limit, const int& vision_length , const int& vision_width )
//如果vision_length==0则打印整个迷宫
//返回值为1，因到达终点而导致游戏结束（胜利）
//返回值为2，因时间耗尽而导致游戏结束（失败）
{
	Map map(length, width);//迷宫的行数的列数应该都是奇数

	while (true)
	{
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
			if (time_limit - get_timer() <= 0)
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