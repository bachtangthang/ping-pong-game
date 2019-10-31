#include "cBar.h"

int cBar::getx()
{
	return x;
}

int cBar::gety1()
{
	return y1;
}

int cBar::gety2()
{
	return y2;
}

void cBar::moveup()
{
	y1--; // giam gia tri cua 2 bien de thanh di len
	y2--;
}

void cBar::movedown()
{
	y1++; //// tang gia tri cua 2 bien de thanh di xuong
	y2++;
}

cBar::cBar(int orginalx, int originaly1, int originaly2)
{
	x = orginalx;
	y1 = originaly1;
	y2 = originaly2;
}

const cBar& cBar::operator=(const cBar& a)
{
	x = a.x;
	y1 = a.y1;
	y2 = a.y2;
	return a;
}

cBar::cBar()
{
}
