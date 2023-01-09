#include <graphics.h>
#include <stdio.h>
#include <vector>
#include <cmath>

#include "mypoint.h"
#include "Heart.h"
#include "HeartScatter.h"
#include "CCS.h"



int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	double width, height, numsP;
	width = 600;
	height = 480;
	initgraph(width, height);
	numsP = 400;

	vector<HeartScatter> Scatters;

	double frq;

	for (int i = 0; i < numsP; i++) {
		frq = 0.2 * sin(i);
		Scatters.push_back(HeartScatter(numsP, Heart(width / 2, height / 2, 4000, 80 * (1 + frq)), 1));
	}

	BeginBatchDraw();
	while (1) {
		
		for (auto e : Scatters) {
			cleardevice();
			CCS::plot_ccs(width / 2, height / 2);
			e.draw(width / 2, height / 2, RGB(235, 60, 60));
			FlushBatchDraw();
			Sleep(5000 / numsP);
		}
		
	}
	EndBatchDraw();
	closegraph();
	return 0;
}