#include<iostream>
#include<windows.h>
#include "Time.h"
#include "Press_Key.h"
#include "Map.h"
#include "Cls_and_Print.h"
void print(const Map& map)
{
	map.print();
	set_game_timer();
	std::cout << "游戏已经开始了" << get_timer() << "秒\n";
}
void print_with_fog(const Map& map, const size_t& length, const size_t& width)
{
	map.print_with_fog(length, width);
	set_game_timer();
	std::cout << "游戏已经开始了" << get_timer() << "秒\n";
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	srand(time(NULL));
	set_reference_timer();
	cursor_hide();

	Map map(95, 225);//迷宫的行数的列数应该都是奇数

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
				//set_CD_timer();
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
			//print(map);
			print_with_fog(map, 10, 30);
		}
	}
	return 0;
}