#define _USE_MATH_DEFINES
#include "Heart.h"


// x = acos(e)(1 + cos(e))
// y = asin(e)(1 + cos(e))
double Heart::Heart_s(double x, double r)
{
	return cos(x) * r * this->unit_scale * (1 - sin(x));
}

double Heart::Heart_h(double x, double offset, double r)
{
	return sin(x) * r * this->unit_scale * (1 - sin(x)) + offset;
}

void Heart::generat(int num_x, double sec_left, double sec_right)
{
	this->yp_list_s.clear();
	this->yp_list_h.clear();

	for (double x : this->xp_list) {
		this->yp_list_s.push_back(this->Heart_s(x));
		this->yp_list_h.push_back(this->Heart_h(x));
	}
	// 插值
	vector<double> tx(this->xp_list.begin(), this->xp_list.end());
	vector<double> tys(this->yp_list_s.begin(), this->yp_list_s.end());
	vector<double> tyh(this->yp_list_h.begin(), this->yp_list_h.end());
	// 第一步： 计算插值

	this->xp_list.clear();
	this->yp_list_s.clear();
	this->yp_list_h.clear();
	this->xp_list.push_back(tx[0]);
	this->yp_list_s.push_back(tys[0]);
	this->yp_list_h.push_back(tyh[0]);

	for (int i = 1; i < num_x; ++i) {

		this->xp_list.push_back((this->xp_list[this->xp_list.size() - 1] + tx[i]) / 2);
		this->yp_list_s.push_back(
			(this->yp_list_s[this->yp_list_s.size() - 1] + tys[i]) / 2
		);
		this->yp_list_h.push_back(
			(this->yp_list_h[this->yp_list_h.size() - 1] + tyh[i]) / 2);
		// 第二部： 保存值
		this->xp_list.push_back(tx[i]);
		this->yp_list_s.push_back(tys[i]);
		this->yp_list_h.push_back(tyh[i]);
	}
}

Heart::Heart(double ox, double oy, int num_x, double unit_scale, double sec_left, double sec_right) {
	this->sec_left = sec_left;
	this->sec_right = sec_right;
	this->num_x = num_x;
	this->unit_scale = unit_scale;
	// 设置原点
	this->ox = ox;
	this->oy = oy;
	// 生成散点
	double unit = (sec_right - sec_left) / (num_x - 1);
	double temp = sec_left;
	// 单位刻度
	for (int i = 0; i < num_x; ++i) {
		temp += unit;
		this->xp_list.push_back(temp);
	}
	
	this->yp_list_s.clear();
	this->yp_list_h.clear();

	for (double x : this->xp_list) {
		this->yp_list_s.push_back(this->Heart_s(x));
		this->yp_list_h.push_back(this->Heart_h(x));
	}
	// 插值
	vector<double> tx(this->xp_list.begin(), this->xp_list.end());
	vector<double> tys(this->yp_list_s.begin(), this->yp_list_s.end());
	vector<double> tyh(this->yp_list_h.begin(), this->yp_list_h.end());
	// 第一步： 计算插值

	this->xp_list.clear();
	this->yp_list_s.clear();
	this->yp_list_h.clear();
	this->xp_list.push_back(tx[0]);
	this->yp_list_s.push_back(tys[0]);
	this->yp_list_h.push_back(tyh[0]);

	for (int i = 1; i < num_x; ++i) {

		this->xp_list.push_back((this->xp_list[this->xp_list.size() - 1] + tx[i]) / 2);
		this->yp_list_s.push_back(
			(this->yp_list_s[this->yp_list_s.size() - 1] + tys[i]) / 2
		);
		this->yp_list_h.push_back(
			(this->yp_list_h[this->yp_list_h.size() - 1] + tyh[i]) / 2);
		// 第二部： 保存值
		this->xp_list.push_back(tx[i]);
		this->yp_list_s.push_back(tys[i]);
		this->yp_list_h.push_back(tyh[i]);
	}
}

void Heart::draw(COLORREF color)
{
	// 窗口的中心是绝对位置
	setorigin(this->ox, this->oy); // 设置中心位置
	
	for (int i = 0; i < this->xp_list.size(); ++i) {
		putpixel(this->yp_list_s[i], - this->yp_list_h[i], color);
	}
	setorigin(0, 0); // 设置中心位置
}

void Heart::setSection(double sec_left, double sec_right)
{
	this->sec_left = sec_left;
	this->sec_right = sec_right;
}

void Heart::setUnitScale(double unit_scale)
{
	this->unit_scale = unit_scale;
	generat(num_x, sec_left, sec_right);
}
