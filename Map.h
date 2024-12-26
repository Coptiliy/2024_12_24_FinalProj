#pragma once
#include<iostream>
#include<cstdlib>
#include "Cls_and_Print.h"
const int randnum(const int& l, const int& r)
//生成一个介于l，r的随机数
{
	return l + rand() % (r - l + 1);
}
const int randnum(const int& l, const int& r, const int& odevity)
//生成一个介于l，r的随机数
//odevity=1，生成奇数；odevity=2，生成偶数
{
	if (odevity == 1)
		return l - l % 2 + 1 + rand() % (r - l + 1 + l % 2 + r % 2 - 2) / 2 * 2;//如果l或r是偶数，缩小范围
	if (odevity == 2)
		return l + l % 2 + rand() % (r - l + 1 - l % 2 - r % 2) / 2 * 2;//如果l或r是奇数，缩小范围
	/*
	if (odevity == 1)
		return l - l % 2 + 1 + rand() % (r - l + 1) / 2 * 2;//如果l或r是偶数，缩小范围
	if (odevity == 2)
		return l + l % 2 + rand() % (r - l + 1) / 2 * 2;//如果l或r是奇数，缩小范围
	*/
}
class Map
{
private:
	int row, col;//row是行，col=column是列
	int** map;
	int x, y;//x,y表示老鼠的坐标
public:

	void clear(void)
		//将迷宫初始化
	{
		for (int i = 1; i <= row; ++i)
			for (int j = 1; j <= col; ++j)
			{
				if (i == row - 1 and j == col - 1) map[i][j] = 5;//5是终点
				else if (i == 1 or j == 1 or i == row or j == col) map[i][j] = 2;//2是地图边界的墙壁
				else map[i][j] = 0;//0是空地
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
			map[cx][i] = 1;//设置这一行的左右方向的墙壁
		}
		for (int j = sx + 1; j <= ex - 1; ++j)
		{
			if (j == x and cy == y) continue;
			if (j >= row - 2 and cy >= col - 2) continue;
			map[j][cy] = 1;//设置这一列的竖直方向的墙壁
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

		create_maze(sx, sy, cx, cy);//左上
		create_maze(cx, sy, ex, cy);//右上
		create_maze(sx, cy, cx, ey);//左下
		create_maze(cx, cy, ex, ey);//右下 

		return;
	}

	bool reachable(const int& delta_x, const int& delta_y)
		//x方向移动delta_x格，y方向移动delta_y格是否是可行的
		//如果可行，返回true，否则返回false
	{
		return map[x + delta_x][y + delta_y] == 0;
	}

	const char& symbol(const int& _x, const int& _y) const
		//返回迷宫对应坐标的char符号
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
		//打印整个迷宫
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
		//x方向移动delta_x格，y方向移动delta_y格
	{
		x += delta_x;
		y += delta_y;
		return;
	}

	void print_with_fog(const int& length, const int& width) const
		//打印带迷雾的迷宫，也就是只打印以自身为中心的行方向上下延伸length格，列方向左右延伸width格的长度。
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