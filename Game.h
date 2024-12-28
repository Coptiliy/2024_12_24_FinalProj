#pragma once
#include<iostream>
#include<windows.h>
#include "Time.h"
#include "Key.h"
#include "Map.h"
#include "Cls_and_Print.h"

void print_game(const Map& map, const int& time_limit);

void print_game_with_fog(const Map& map, const int& time_limit, const int& length, const int& width);

void print_game_over(const int& over_id);

int play_game(const int& length, const int& width, const int& time_limit, const int& vision_length, const int& vision_width);

void print_menu(void);

void print_foreword(void);

void print_difficuty_option(void);

void print_difficuty_description(const int& difficulty);