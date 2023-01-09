#include "CCS.h"

using namespace std;

double CCS::x = NULL;
double CCS::y = NULL;


/*
@x, y:					直角坐标系原点位置
@length_x, length_x:	横纵轴长度
@unit:					单位长度的像素值
*/
void CCS::plot_ccs(double x, double y, double length_x, double length_y, double unit)
{
	// 窗口的中心是绝对位置
	setorigin(x, y); // 设置中心位置
	CCS::x = x;
	CCS::y = y;

	//定义 轴的末端点
	myPoint xcor_left(-length_x / 2, 0);
	myPoint xcor_right(length_x / 2, 0);
	myPoint ycor_up(0, length_y / 2);
	myPoint ycor_down(0, -length_y / 2);

	// x轴
	line(xcor_left.x, 0, xcor_right.x, 0);
	// y轴
	line(0, ycor_up.y, 0, ycor_down.y);

	// 绘制箭头
	double arrowHead_scale = 10; // 箭头尺寸
	line(xcor_right.x, 0, length_x / 2 - arrowHead_scale / sqrt(2), arrowHead_scale / sqrt(2));
	line(xcor_right.x, 0, length_x / 2 - arrowHead_scale / sqrt(2), -arrowHead_scale / sqrt(2));
	line(0, ycor_up.y, arrowHead_scale / sqrt(2), -length_y / 2 + arrowHead_scale / sqrt(2));
	line(0, ycor_up.y, -arrowHead_scale / sqrt(2), -length_y / 2 + arrowHead_scale / sqrt(2));
	char c1 = 'x';
	outtextxy(xcor_right.x, xcor_right.y, c1);
	char c2 = 'y';
	outtextxy(ycor_up.x + 8, ycor_up.y, c2);

	// 绘制刻度
	double unit_scale = 5;
	double start = 0;
	double limit = max(xcor_right.x, ycor_up.y);
	while (start < limit) {
		// x轴
		if (start < length_x / 2) {
			line(start, 0, start, -unit_scale);
			line(-start, 0, -start, -unit_scale);
		}
		// y轴
		if (start < length_y / 2) {
			line(0, start, unit_scale, start);
			line(0, -start, unit_scale, -start);
		}
		start += unit;
	}

	setorigin(0, 0); // 还原中心位置
}
