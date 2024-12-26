#pragma once
#include<iostream>
#include<chrono>

//#define CD_TIME 300

long long reference_timer, game_timer;

/*
long long CD_timer;

void set_CD_timer(void)//将reference_timer设置为当前毫秒数
{
	const std::chrono::system_clock::time_point current_time_points = std::chrono::system_clock::now();//获取当前系统时间current_time_points
	const std::chrono::milliseconds current_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(current_time_points.time_since_epoch());//将current_time_points的单位转换为毫秒
	CD_timer = current_time_ms.count();
	return;
}

bool CD(long long CD_limit_ms)//检查是否已经冷却，也就是current_time_ms-CD_timer的值是否大于CD_limit_ms
{
	const std::chrono::system_clock::time_point current_time_points = std::chrono::system_clock::now();//获取当前系统时间current_time_points
	const std::chrono::milliseconds current_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(current_time_points.time_since_epoch());//将current_time_points的单位转换为毫秒
	return current_time_ms.count() - CD_timer > CD_limit_ms;
}
*/
void set_reference_timer(void)//将reference_timer设置为当前秒数
{
	const std::chrono::system_clock::time_point current_time_points = std::chrono::system_clock::now();//获取当前系统时间current_time_points
	const std::chrono::seconds current_time_s = std::chrono::duration_cast<std::chrono::seconds>(current_time_points.time_since_epoch());//将current_time_points的单位转换为秒
	reference_timer = current_time_s.count();
	return;
}

bool should_renew_game_timer(void)//检查是否应该更新计时器，也就是当前时间与game_timer的差值是否已经大于等于1
{
	const std::chrono::system_clock::time_point current_time_points = std::chrono::system_clock::now();//获取当前系统时间current_time_points
	const std::chrono::seconds current_time_s = std::chrono::duration_cast<std::chrono::seconds>(current_time_points.time_since_epoch());//将current_time_points的单位转换为秒
	return game_timer != current_time_s.count();
}

void set_game_timer(void)//将game_timer设置为当前秒数
{
	const std::chrono::system_clock::time_point current_time_points = std::chrono::system_clock::now();//获取当前系统时间current_time_points
	const std::chrono::seconds current_time_s = std::chrono::duration_cast<std::chrono::seconds>(current_time_points.time_since_epoch());//将current_time_points的单位转换为秒
	game_timer = current_time_s.count();
	return;
}

long long get_timer(void)//获取计时器记录的时间，也就是game_timer-reference_timer的值
{
	return game_timer - reference_timer;
}

void print_timer(void)//打印计时器记录的时间，也就是game_timer-reference_timer的值
{
	std::cout << game_timer - reference_timer;
	return;
}

/*
void mtime(std::chrono::system_clock::time_point& startTime, int count=0) {     //starttime为上一次操作后的temp储存的时间
	seconds starttime_seconds_since_epoch = duration_cast<seconds>(startTime.time_since_epoch()); //starttime转成秒

	auto now = system_clock::now();                                                //定义并获取系统时间now
	seconds seconds_since_epoch = duration_cast<seconds>(now.time_since_epoch());  //now转化成秒

	if (starttime_seconds_since_epoch.count() != seconds_since_epoch.count()) {      //判断是否需要打印时间
		count += seconds_since_epoch.count() - starttime_seconds_since_epoch.count();  //count时间计算
		startTime = now;
		//system("cls"); //清屏
		cout << "游戏已经开始" << count << "秒" << endl;//重新打印全屏

	}
}
*/
