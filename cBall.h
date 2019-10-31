#ifndef __CBALL_H__
#define __CBALL_H__
#include <iostream>
#include <cstdlib>
#include "console.h"
#include <cmath>
using namespace std;
class cBall
{
private:
	int x, y;//vi tri bong
	int xspeed, yspeed;//toc do bong tren truc Ox, Oy
	int sleep;// thoi gian delay giua 2 lan ve bong
public:
	int getX();
	int getY();
	int getXspeed();
	int getYspeed();
	int getSleep();
	cBall(int posx, int posy);//ham tao ball ban dau
	void setnewsleep();//ham set thoi gian delay moi
	void move();//ham di chuyen Ball
	const cBall& operator=(const cBall& a);
	cBall();
	void hitBar(); // ham phan xa khi bong dap vao thanh
	void hitWall(); // ham phan xa khi bong dap vao tuong
};
#endif
