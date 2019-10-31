#ifndef __BUFFER_H__
#define __BUFFER_H__
#include "Ingame.h"
using namespace std;
struct onetile//tao ra kieu du lieu gom ki tu ch va ma mau 
{
	char ch;
	int color;
};
void drawgame();//tao mang buffer chua gia tri sau do ve mang ra console
void drawbuffer();//ve mang buffer
void drawonetile(int dong, int cot);//ve 1 o co mau
void setbuffer();//tao gia tri mang buffer
void printMenu();// in menu ban dau
#endif
