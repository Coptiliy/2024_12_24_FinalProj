#pragma once
#include<iostream>
#include<cstdlib>
#include "Cls_and_Print.h"
const int randnum(const int& l, const int& r)
//����һ������l��r�������
{
	return l + rand() % (r - l + 1);
}
const int randnum(const int& l, const int& r, const int& odevity)
//����һ������l��r�������
//odevity=1������������odevity=2������ż��
{
	if (odevity == 1)
		return l - l % 2 + 1 + rand() % (r - l + 1 + l % 2 + r % 2 - 2) / 2 * 2;//���l��r��ż������С��Χ
	if (odevity == 2)
		return l + l % 2 + rand() % (r - l + 1 - l % 2 - r % 2) / 2 * 2;//���l��r����������С��Χ
	/*
	if (odevity == 1)
		return l - l % 2 + 1 + rand() % (r - l + 1) / 2 * 2;//���l��r��ż������С��Χ
	if (odevity == 2)
		return l + l % 2 + rand() % (r - l + 1) / 2 * 2;//���l��r����������С��Χ
	*/
}
class Map
{
private:
	int row, col;//row���У�col=column����
	int** map;
	int x, y;//x,y��ʾ���������
public:

	void clear(void)
		//���Թ���ʼ��
	{
		for (int i = 1; i <= row; ++i)
			for (int j = 1; j <= col; ++j)
			{
				if (i == row - 1 and j == col - 1) map[i][j] = 5;//5���յ�
				else if (i == 1 or j == 1 or i == row or j == col) map[i][j] = 2;//2�ǵ�ͼ�߽��ǽ��
				else map[i][j] = 0;//0�ǿյ�
			}
	}

	void create_maze(int sx, int sy, int ex, int ey)
	{
		if (ex - sx <= 7 or ey - sy <= 7) return;
		const int cx = randnum(sx + 2, ex - 2, 2);
		const int cy = randnum(sy + 2, ey - 2, 2);
		for (int i = sy + 1; i <= ey - 1; ++i)
		{
			if (cx == x and i == y) continue;
			if (cx >= row - 2 and i >= col - 2) continue;
			map[cx][i] = 1;//������һ�е����ҷ����ǽ��
		}
		for (int j = sx + 1; j <= ex - 1; ++j)
		{
			if (j == x and cy == y) continue;
			if (j >= row - 2 and cy >= col - 2) continue;
			map[j][cy] = 1;//������һ�е���ֱ�����ǽ��
		}

		int plug_direction = randnum(1, 5);

		if (plug_direction != 1)
		{
			const int py = randnum(sy + 1, cy - 1, 1);
			map[cx][py - 1] = map[cx][py] = map[cx][py + 1] = 0;
		}
		if (plug_direction != 2)
		{
			const int py = randnum(cy + 1, ey - 1, 1);
			map[cx][py - 1] = map[cx][py] = map[cx][py + 1] = 0;
		}
		if (plug_direction != 3) map[randnum(sx + 1, cx - 1, 1)][cy] = 0;
		if (plug_direction != 4) map[randnum(cx + 1, ex - 1, 1)][cy] = 0;

		create_maze(sx, sy, cx, cy);//����
		create_maze(cx, sy, ex, cy);//����
		create_maze(sx, cy, cx, ey);//����
		create_maze(cx, cy, ex, ey);//���� 

		return;
	}

	bool reachable(const int& delta_x, const int& delta_y)
		//x�����ƶ�delta_x��y�����ƶ�delta_y���Ƿ��ǿ��е�
		//������У�����true�����򷵻�false
	{
		return map[x + delta_x][y + delta_y] == 0;
	}

	const char& symbol(const int& _x, const int& _y) const
		//�����Թ���Ӧ�����char����
	{
		if (_x <= 0 or _x >= row + 1 or _y <= 0 or _y >= col + 1)	return ' ';
		if (_x == x and _y == y)	return 'M';
		if (map[_x][_y] == 1 or map[_x][_y] == 2) return '#';
		if (map[_x][_y] == 5) return 'E';
		if (map[_x][_y] == 0) return ' ';
		return '!';
	}

	void color(void) const
	{
		set_color_and_background(15, 0);
		return;
	}

	void color(const int& _x, const int& _y) const
	{
		if (_x == x and _y == y) set_color_and_background(12, 0);
		else if (_x == row - 1 and _y == col - 1) set_color_and_background(3, 0);
		else set_color_and_background(15, 0);
		return;
	}

	void print(void) const
		//��ӡ�����Թ�
	{
		for (int i = 1; i <= row; ++i)
		{
			for (int j = 1; j <= col; ++j)
				std::cout << symbol(i, j);
			std::cout << '\n';
		}
		return;
	}

	void move(const int& delta_x, const int& delta_y)
		//x�����ƶ�delta_x��y�����ƶ�delta_y��
	{
		x += delta_x;
		y += delta_y;
		return;
	}

	void print_with_fog(const int& length, const int& width) const
		//��ӡ��������Թ���Ҳ����ֻ��ӡ������Ϊ���ĵ��з�����������length���з�����������width��ĳ��ȡ�
	{
		for (int i = x - length; i <= x + length; ++i)
		{
			for (int j = y - width; j <= y + width; ++j)
			{
				color(i, j);
				std::cout << symbol(i, j);
			}
			std::cout << '\n';
		}
		color();
	}

	Map(const int& _row, const int& _col)
	{
		row = _row;
		col = _col;
		x = row / 2 + 1;
		y = col / 2 + 1;
		map = new int* [row + 1];
		for (int i = 1; i <= row; ++i) map[i] = new int[col + 1];
		clear();
		create_maze(1, 1, row, col);
	}

};