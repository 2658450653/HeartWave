#pragma once
#include <graphics.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <time.h>

#include "mypoint.h"
#include "Heart.h"
#include "CCS.h"


using namespace std;

class HeartScatter
{
public:
	// �������
	vector<myPoint> points;
	// ���Ӹ���
	int numsOfPoints;
	// ���κ�������
	Heart *heart;
	// ���캯��
	HeartScatter(int numsOfPoints, Heart heart, double rate = 0.2);
	// ����ɢ��
	void draw(double ox, double oy, COLORREF color = RGB(255, 0, 0));
};

