#pragma once
#include<Windows.h>
void cursor_goto_0_0(void)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 0;
	pos.Y = 0;
	SetConsoleCursorPosition(handle, pos);
}
void cursor_hide(void)
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void set_color_and_background(const int& forg_color, const int& back_color) {
	WORD color = ((back_color & 0x0F) << 4) + (forg_color & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}