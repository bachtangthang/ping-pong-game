#include "cBall.h"
class cBar
{
private:
	int x;//toa do tren truc x
	int y1, y2;//toa do 2 bien tren truc y
public:
	int getx();
	int gety1();
	int gety2();
	void moveup();//bar di len
	void movedown();//bar di xuong
	cBar(int orginalx, int originaly1, int originaly2);//dua bar ve vi tri ban dau
	const cBar& operator=(const cBar& a);
	cBar();
};

