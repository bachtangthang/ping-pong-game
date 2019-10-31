#include "cBall.h"

int cBall::getX()
{
	return x;
}

int cBall::getY()
{
	return y;
}

int cBall::getXspeed()
{
	return xspeed;
}

int cBall::getYspeed()
{
	return yspeed;
}

int cBall::getSleep()
{
	return sleep;
}

cBall::cBall(int posx, int posy)
{
	x = posx;
	y = posy;
	//this->setspeed();
	do {
		xspeed = rand() % 3 + (-1); //random tu -1 -> 1
		yspeed = rand() % 3 + (-1);  //random tu -1 -> 1
	} while (xspeed == 0 || yspeed == 0); // tranh viec bong chay thang theo 1 truc
	sleep = 200;
}

void cBall::setnewsleep()
{
	sleep = sleep * 100 / 110; // tang 10% toc do bong
}

void cBall::move()
{
	x = x + xspeed; // di chuyen bong den toa do x moi
	y = y + yspeed; // di chuyen bong den toa do y moi
}

const cBall& cBall::operator=(const cBall& a)
{
	x = a.x;
	y = a.y;
	xspeed = a.xspeed;
	yspeed = a.yspeed;
	sleep = a.sleep;
	return a;

}

cBall::cBall()
{
}

void cBall::hitBar()
{
	int temp = -xspeed; // doi chieu cua van toc x cua bong de tao phan xa
	xspeed = temp;
}

void cBall::hitWall()
{
	int temp = -yspeed; // doi chieu cua van toc y cua bong de tao phan xa
	yspeed = temp;
}

