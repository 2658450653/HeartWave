#pragma once
#include <graphics.h>
#include <iostream>
#include <cmath>

#include "mypoint.h"

class CCS
{
public:
	static double x, y;
	static void plot_ccs(double x, double y,
		double length_x = 400, double length_y = 400,
		double unit = 10);
};

