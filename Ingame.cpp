#include "Ingame.h"

cIngame::cIngame()
{
}

cIngame::cIngame(int w, int h)
{
	up1 = 'w';	down1 = 's';
	up2 = 'i'; down2 = 'k';
	score1 = 0; score2 = 0;
	width = w;
	height = h;
	cBall ballTemp(width / 2, (height +4)/ 2); // khoi tao bong o vi tri giua san choi
	ball = ballTemp;
	cBar p1Temp(1, (height - 2) / 2, (height + 10) / 2);  // khoi tao thanh p1
	p1 = p1Temp;
	cBar p2Temp(width - 2, (height - 2) / 2, (height + 10) / 2);//khoi toa thanh p2
	p2 = p2Temp;
	quit = 0;
}
bool cIngame::getQuit()
{
	return quit;
}
void cIngame::draw()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			if (ball.getX() == j && ball.getY() == i)//ve ball
			{
				gotoXY(j, i);
				cout << "o";  
			}
			else if (j == 1 && i >= p1.gety1() && i <= p1.gety2())//ve thanh p1
			{
				gotoXY(j, i);
				cout << "\xDB";
			}
			else if (j == width -2  && i >= p2.gety1() && i <= p2.gety2())// ve thanh p2
			{
				gotoXY(j, i);
				cout << "\xDB";
			}
		}
	gotoXY((consolewidth - 24)/2, 0);//den vi tri tren cung giua console
	cout << "score p1:" << score1 << " - " << "score p2:" << score2;
}
void cIngame::Input()
{
	Sleep(ball.getSleep());
	gotoXY(ball.getX(), ball.getY());//den vi tri de xoa ball cu
	cout << " ";//xoa ball
	ball.move();//ball chuyen toi vi tri moi
	//Sleep(257);

	if (_kbhit())//nhap input
	{
		char inputKey = _getch();
		if (inputKey == up1)
			if (p1.gety1() > 6)//bien tren
			{
				p1.moveup();//di len
				gotoXY(1, p1.gety2() + 1);//xoa vi tri cu
				cout << " ";
			}
		if (inputKey == up2)
			if (p2.gety1() > 6)//bien tren
			{
				p2.moveup();//di len
				gotoXY(width -2, p2.gety2() + 1);//xoa vi tri cu
				cout << " ";
			}
		if (inputKey == down1)
			if (p1.gety2() < height - 2)//bien duoi
			{
				p1.movedown();//di xuong
				gotoXY(1, p1.gety1() - 1);//xoa vi  tri cu
				cout << " ";
			}
		if (inputKey == down2)
			if (p2.gety2() < height - 2)//bien duoi
			{
				p2.movedown();//di xuong
				gotoXY(width-2, p2.gety1() - 1);//xoa vi tri cu
				cout << " ";
			}
	}
	//Sleep(ball.getSleep());
}
void cIngame::logic()
{
	if (p1.getx() == ball.getX() - 1 && p1.gety1() <= ball.getY() && p1.gety2() >= ball.getY())//dieu kien ball cham p1
	{
		ball.hitBar();//ham phan xa
		ball.setnewsleep();//tang toc 10%
	}
	if (p2.getx() == ball.getX() + 1 && p2.gety1() <= ball.getY() && p2.gety2() >= ball.getY())//dieu kien ball cham p2
	{
		ball.hitBar();//ham phan xa
		ball.setnewsleep();//tang toc 10%
	}
	if (ball.getY() == 6 || ball.getY() == height - 2)//dieu kien ball cham tuong
	{
		ball.hitWall();//ham phan xa tuong
	}
	if (ball.getX() <= 0)//p2 thang
	{
		score2++;// tang diem p2
		cBall ballTemp(width / 2, (height + 4) / 2);//dat lai ball
		ball = ballTemp;
	}
	if (ball.getX() >= width -2)//p1 thang
	{
		score1++;//tang diem p1
		cBall ballTemp(width / 2, (height + 4) / 2);//dat lai ball
		ball = ballTemp;
	}
	if (score1 == 3 || score2 == 3)//dieu kien ket thuc game
	{
		quit = 1;
	}
}
void cIngame::endGame()
{
	system("cls");
	if (score1 == 3)
	{
		cout << "player 1 win" << endl;
	}
	if (score2 == 3)
	{
		cout << "player 2 win" << endl;
	}
	Sleep(4000);
}

void cIngame::playWithMan()
{
	while (this->getQuit() == 0)
	{

		this->draw();
		this->Input();
		this->logic();
		if (this->getQuit() == 1)
		{
			this->endGame();
		}
	}
}

void cIngame::playWithCom()
{
	while (this->getQuit() == 0)
	{
		this->draw();
		this->Input();
		this->moveComBar();
		this->logic();
		if (this->getQuit() == 1)
		{
			this->endGame();
		}
	}
}

int cIngame::findBall()//ham tim toa do Y cua bong
{
	int ballx = ball.getX();
	int bally = ball.getY();
	int ballxspeed = ball.getXspeed();
	int ballyspeed = ball.getYspeed();
	while (ballx != width - 3)
	{
		if (bally == 6 || bally == height - 2)
		{
			ballyspeed = -ballyspeed;
		}
		ballx = ballx + ballxspeed;
		bally = bally + ballyspeed;
	}
	return bally;
}

void cIngame::moveComBar()//di chuyen thanh cua may la thanh p2
{
	if (ball.getXspeed() > 0 && ball.getX() == width / 2 + 1)
	{
		int k = findBall();
		if (k < p2.gety1())
		{
			while (p2.gety1() != k)
			{
				p2.moveup();//di len
				gotoXY(width - 2, p2.gety2() + 1);//xoa vi tri cu
				cout << " ";
			}
		}
		else
		{
			if (k > p2.gety2())
			{
				while (p2.gety2() != k)
				{
					p2.movedown();//di xuong
					gotoXY(width - 2, p2.gety1() - 1);//xoa vi tri cu
					cout << " ";
				}
			}
			else{}//truong hop da dung vi tri
		}
	}
}