#pragma once
#define _USE_MATH_DEFINES
#include <vector>
#include <cmath>

#include "CCS.h"

using namespace std;

const double pi = 3.14159265358979323846;


class Heart
{
private:
	vector<double> xp_list;
	vector<double> yp_list_s;
	vector<double> yp_list_h;
	void generat(int num_x, double sec_left, double sec_right);
	double ox, oy;
	double sec_left, sec_right;
	int num_x;

public:
	double unit_scale = 80;

	Heart(double ox, double oy, int num_x = 500, double unit_scale = 80, double sec_left= -pi, double sec_right= pi);
	double Heart_s(double x, double r = 1);
	double Heart_h(double x, double offset = 50, double r = 1);
	void draw(COLORREF color);
	void setSection(double sec_left, double sec_right);
	void setUnitScale(double unit_scale);
};

