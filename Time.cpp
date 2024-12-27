#pragma once
#include "Time.h"

//#define CD_TIME 300
long long reference_timer, game_timer;

/*
long long CD_timer;

void set_CD_timer(void)//��reference_timer����Ϊ��ǰ������
{
	const std::chrono::system_clock::time_point current_time_points = std::chrono::system_clock::now();//��ȡ��ǰϵͳʱ��current_time_points
	const std::chrono::milliseconds current_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(current_time_points.time_since_epoch());//��current_time_points�ĵ�λת��Ϊ����
	CD_timer = current_time_ms.count();
	return;
}

bool CD(long long CD_limit_ms)//����Ƿ��Ѿ���ȴ��Ҳ����current_time_ms-CD_timer��ֵ�Ƿ����CD_limit_ms
{
	const std::chrono::system_clock::time_point current_time_points = std::chrono::system_clock::now();//��ȡ��ǰϵͳʱ��current_time_points
	const std::chrono::milliseconds current_time_ms = std::chrono::duration_cast<std::chrono::milliseconds>(current_time_points.time_since_epoch());//��current_time_points�ĵ�λת��Ϊ����
	return current_time_ms.count() - CD_timer > CD_limit_ms;
}
*/
void set_reference_timer(void)//��reference_timer����Ϊ��ǰ����
{
	const std::chrono::system_clock::time_point current_time_points = std::chrono::system_clock::now();//��ȡ��ǰϵͳʱ��current_time_points
	const std::chrono::seconds current_time_s = std::chrono::duration_cast<std::chrono::seconds>(current_time_points.time_since_epoch());//��current_time_points�ĵ�λת��Ϊ��
	reference_timer = current_time_s.count();
	return;
}

bool should_renew_game_timer(void)//����Ƿ�Ӧ�ø��¼�ʱ����Ҳ���ǵ�ǰʱ����game_timer�Ĳ�ֵ�Ƿ��Ѿ����ڵ���1
{
	const std::chrono::system_clock::time_point current_time_points = std::chrono::system_clock::now();//��ȡ��ǰϵͳʱ��current_time_points
	const std::chrono::seconds current_time_s = std::chrono::duration_cast<std::chrono::seconds>(current_time_points.time_since_epoch());//��current_time_points�ĵ�λת��Ϊ��
	return game_timer != current_time_s.count();
}

void set_game_timer(void)//��game_timer����Ϊ��ǰ����
{
	const std::chrono::system_clock::time_point current_time_points = std::chrono::system_clock::now();//��ȡ��ǰϵͳʱ��current_time_points
	const std::chrono::seconds current_time_s = std::chrono::duration_cast<std::chrono::seconds>(current_time_points.time_since_epoch());//��current_time_points�ĵ�λת��Ϊ��
	game_timer = current_time_s.count();
	return;
}

long long get_timer(void)//��ȡ��ʱ����¼��ʱ�䣬Ҳ����game_timer-reference_timer��ֵ
{
	return game_timer - reference_timer;
}

void print_timer(void)//��ӡ��ʱ����¼��ʱ�䣬Ҳ����game_timer-reference_timer��ֵ
{
	std::cout << game_timer - reference_timer;
	return;
}

/*
void mtime(std::chrono::system_clock::time_point& startTime, int count=0) {     //starttimeΪ��һ�β������temp�����ʱ��
	seconds starttime_seconds_since_epoch = duration_cast<seconds>(startTime.time_since_epoch()); //starttimeת����

	auto now = system_clock::now();                                                //���岢��ȡϵͳʱ��now
	seconds seconds_since_epoch = duration_cast<seconds>(now.time_since_epoch());  //nowת������

	if (starttime_seconds_since_epoch.count() != seconds_since_epoch.count()) {      //�ж��Ƿ���Ҫ��ӡʱ��
		count += seconds_since_epoch.count() - starttime_seconds_since_epoch.count();  //countʱ�����
		startTime = now;
		//system("cls"); //����
		cout << "��Ϸ�Ѿ���ʼ" << count << "��" << endl;//���´�ӡȫ��

	}
}
*/
