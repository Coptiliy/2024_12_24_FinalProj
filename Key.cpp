#pragma once
#include "Key.h"

bool key_down(const unsigned char& key_value)
{
	return (GetAsyncKeyState(key_value) & 0x8000);
}
bool key_short_press(const unsigned char& key_value)//�Ƿ�̰��˰���
{
	static bool key_state[256];
	if (key_down(key_value) and !key_state[key_value])//��һ��û�а��£�����ΰ�����
	{
		key_state[key_value] = true;
		return true;
	}
	if (!key_down(key_value)) key_state[key_value] = false;
	//if (key_state[key_value] >= 2000 or !key_down(key_value)) key_state[key_value] = 0;
	return false;
}