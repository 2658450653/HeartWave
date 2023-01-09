#include "HeartScatter.h"

HeartScatter::HeartScatter(int numsOfPoints, Heart heart, double rate)
{
	this->heart = &heart;
	double left = -pi;
	double right = pi;
	double delta = 0.01;
	double rnum, num;
	double x, y;
	srand((unsigned)time(NULL));
	for (int i = 0; i < (int)2 / delta; ++i) {
		for (int j = 0; j < numsOfPoints; ++j) {
			rnum = (double)rand() / RAND_MAX;
			double current_angle = left + i * delta * pi + rnum * 1.2;
			num = rnum * rate;
			x = this->heart->Heart_s(current_angle, 1-num);
			y = this->heart->Heart_h(current_angle, 50, 1-num);
			this->points.push_back(myPoint(x, y));
		}
	}
}

void HeartScatter::draw(double ox, double oy, COLORREF color)
{
	setorigin(ox, oy);
	for (auto p : this->points) {
		putpixel(p.x, p.y, color);
	}
	setorigin(0, 0);
}
