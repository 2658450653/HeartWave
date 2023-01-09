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
	// 随机粒子
	vector<myPoint> points;
	// 粒子个数
	int numsOfPoints;
	// 心形函数对象
	Heart *heart;
	// 构造函数
	HeartScatter(int numsOfPoints, Heart heart, double rate = 0.2);
	// 绘制散点
	void draw(double ox, double oy, COLORREF color = RGB(255, 0, 0));
};

