#ifndef __INGAME_H__
#define __INGAME_H__
#include "cBar.h"
#include "cBall.h"
#include <conio.h>
#define consolewidth 90
#define consoleheight  40
class cIngame
{
private:
	int width, height;//chieu dai va rong cua console
	int score1, score2;//diem p1,p2
	cBall ball;//ball
	cBar p1, p2;//2 thanh bar p1 va p2
	char up1, up2, down1, down2;//kis tu dieu kien p1,p2
	bool quit;//bien kiem tra thang thua
public:
	cIngame();
	cIngame(int w, int h);//tao man choi ban dau
	bool getQuit();
	void draw();//ve ball va thanh doc
	void Input();//nhap ki tu va dieu kien thanh
	void logic();//kiem tra va cham va tra ve phan xa 
	void endGame();//in ra ket qua, ket thuc game
	void playWithMan();//choi voi nguoi
	void playWithCom();//choi voi may
	int findBall();//tim toa do Y cua bong
	void moveComBar();//i chuyen thanh cua may'
};
#endif
