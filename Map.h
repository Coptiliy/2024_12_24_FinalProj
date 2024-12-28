#pragma once
#include<iostream>
#include<cstdlib>
#include "Cls_and_Print.h"
const int randnum(const int& l, const int& r);
const int randnum(const int& l, const int& r, const int& odevity);
class Map
{
private:
	int row, col;//row是行，col=column是列
	int** map;
	int x, y;//x,y表示老鼠的坐标
public:

	void clear(void);

	void create_maze(int sx, int sy, int ex, int ey);

	bool reachable(const int& delta_x, const int& delta_y);

	bool win(void) const;

	const char& symbol(const int& _x, const int& _y) const;

	void color(void) const;

	void color(const int& _x, const int& _y) const;

	void print(void) const;

	void move(const int& delta_x, const int& delta_y);

	void print_with_fog(const int& length, const int& width) const;

	Map(const int& _row, const int& _col);

	~Map(void);
};