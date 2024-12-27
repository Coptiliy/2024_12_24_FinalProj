#include "Game.h"

void print_game(const Map& map, const int& time_limit)
{
	map.print();
	set_game_timer();
	if (time_limit == -1) std::cout << "��Ϸ�Ѿ���ʼ��" << get_timer() << "��\n";
	else
	{
		std::cout << "ʣ��ʱ��:";
		if (time_limit - get_timer() <= 15) set_color_and_background(4, 0);
		std::cout << time_limit - get_timer();
		set_color_and_background(15, 0);
		std::cout << "��\n";
	}
}
void print_game_with_fog(const Map& map, const int& time_limit, const int& length, const int& width)
{
	map.print_with_fog(length, width);
	set_game_timer();
	if (time_limit == -1) std::cout << "��Ϸ�Ѿ���ʼ��" << get_timer() << "��\n";
	else
	{
		std::cout << "ʣ��ʱ��:";
		if (time_limit - get_timer() <= 15) set_color_and_background(4, 0);
		std::cout << time_limit - get_timer();
		set_color_and_background(15, 0);
		std::cout << "��\n";
	}
}
void print_game_over(const int& over_id)
//id==1���򵽴��յ��������Ϸ������ʤ����
//id==2����ʱ��ľ���������Ϸ������ʧ�ܣ�
{
	if (over_id == 1)
	{
		std::cout << "�㵽�����յ㣡��";
		set_color_and_background(2, 0);
		std::cout << "ʤ��";
		set_color_and_background(15, 0);
		std::cout << "�ˣ�\n";
	}
	if (over_id == 2)
	{
		std::cout << "ʱ��ľ�����";
		set_color_and_background(4, 0);
		std::cout << "ʧ��";
		set_color_and_background(15, 0);
		std::cout << "�ˣ�\n";
	}
}
int play_game(const int& length, const int& width, const int& time_limit, const int& vision_length, const int& vision_width)
//���vision_length==0���ӡ�����Թ�
//����ֵΪ1���򵽴��յ��������Ϸ������ʤ����
//����ֵΪ2����ʱ��ľ���������Ϸ������ʧ�ܣ�
{
	system("cls");
	set_reference_timer();

	Map map(length, width);//�Թ�������������Ӧ�ö�������

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
		"                      ��Ϸ����                    \n"
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
		"���ԣ�\n"
		"\n";
	Sleep(2000);
	std::cout <<
		"��̤����;�ĵ�";
	set_color_and_background(3, 0);
	std::cout <<
		"��";
	set_color_and_background(15, 0);
	std::cout <<
		"����ͷ���㾭����һ���ǳء�\n"
		"\n";
	Sleep(3000);
	std::cout <<
		"��������ǣ�";
	Sleep(1000);
	set_color_and_background(6, 0);
	std::cout <<
		"����ľګ������żһ��";
	set_color_and_background(15, 0);
	std::cout <<
		"��\n"
		"\n";
	Sleep(3000);
	std::cout <<
		"���㣬";
	Sleep(1000);
	std::cout <<
		"��̽�ճ���֮ʱ��";
	Sleep(1000);
	std::cout <<
		"����������������ס�������";
	set_color_and_background(10, 0);
	std::cout <<
		"��ħ��ʦ";
	set_color_and_background(15, 0);
	std::cout <<
		"����������͵Ϯ��\n"
		"\n";
	Sleep(3000);
	std::cout <<
		"�㱻�����һֻ";
	set_color_and_background(4, 0);
	std::cout <<
		"����";
	set_color_and_background(15, 0);
	std::cout <<
		"��";
	Sleep(2000);
	std::cout <<
		"�ؽ��˳�������ĵ����\n"
		"\n";
	Sleep(3000);
	std::cout <<
		"���ڣ���ֻ��ʮ�����޵�ʱ�䣬�ҵ����ڣ�\n"
		"\n";
	Sleep(1000);
	std::cout <<
		"����.......\n"
		"\n";
	set_color_and_background(4, 0);
	Sleep(3000);
	std::cout <<
		"����.......\n"
		"\n";
	Sleep(3000);
	set_color_and_background(15, 0);
	std::cout <<
		"��ѡ���Ѷ�ϵ��(1~4):\n";
}
void print_difficuty(const int& difficulty)
{
	if (difficulty == 1)
	{
		set_color_and_background(15, 0);
		std::cout <<
			"�Ѷȣ�1\n"
			"���δ�С��25*115\n"
			"ʱ�����ƣ�300��\n"
			"��Ұ����������\n";
		set_color_and_background(3, 0);
		std::cout <<
			"�����ڵ��ε����½�\n";
		set_color_and_background(15, 0);
	}
	if (difficulty == 2)
	{
		set_color_and_background(15, 0);
		std::cout <<
			"�Ѷȣ�2\n"
			"���δ�С��45*135\n"
			"ʱ�����ƣ�300��\n"
			"��Ұ��17*65\n";
		set_color_and_background(3, 0);
		std::cout <<
			"�����ڵ��ε����½�\n";
		set_color_and_background(15, 0);
	}
	if (difficulty == 3)
	{
		set_color_and_background(15, 0);
		std::cout <<
			"�Ѷȣ�3\n"
			"���δ�С��75*255\n"
			"ʱ�����ƣ�300��\n"
			"��Ұ��17*65\n";
		set_color_and_background(3, 0);
		std::cout <<
			"�����ڵ��ε����½�\n";
		set_color_and_background(15, 0);
	}
	if (difficulty == 4)
	{
		set_color_and_background(15, 0);
		std::cout <<
			"�Ѷȣ�4\n"
			"���δ�С��165*325\n"
			"ʱ�����ƣ�300��\n"
			"��Ұ��17*49\n";
		set_color_and_background(3, 0);
		std::cout <<
			"�����ڵ��ε����½�\n";
		set_color_and_background(15, 0);
	}
}