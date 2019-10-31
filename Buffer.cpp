#include "Buffer.h"
onetile buffer[consoleheight][consolewidth];

void setbuffer()
{
	for (int i = 0; i < consoleheight; i++)
		for (int j = 0; j < consolewidth; j++)//vong lap mang buffer[consoleheight][consolewidth]
		{
			if ((i == 5 || i == consoleheight - 1) && (j != 0 && j != consolewidth - 1))
			{
				buffer[i][j].ch = '\xCD';//bien ngang tren duoi
				buffer[i][j].color = 13;//green
			}
			else {
				if ((j == 0 || j == consolewidth - 1) && (i > 5 && i != consoleheight - 1))
				{
					buffer[i][j].ch = '\xBA';//bien doc trai, phai
					buffer[i][j].color = 10;//green
				}
				else {
					if (i == 5 && j == 0)
					{
						buffer[i][j].ch = '\xC9';//goctrai
						buffer[i][j].color = 13;//pink;
					}
					else {
						if (i == consoleheight - 1 && j == 0)
						{
							buffer[i][j].ch = '\xC8';//goc trai duoi
							buffer[i][j].color = 13;//pink
						}
						else {
							if (i == 5 && j == consolewidth - 1)
							{
								buffer[i][j].ch = '\xBB';//goc phai tren
								buffer[i][j].color = 13;//pink
							}
							else {
								if (i == consoleheight - 1 && j == consolewidth - 1)
								{
									buffer[i][j].ch = '\xBC';//goc phai duoi
									buffer[i][j].color = 13;//pink
								}
								else {
									buffer[i][j].ch = ' ';//ki tu trong
									buffer[i][j].color = 7;//default color
								}
							}
						}
					}
				}
			}

		}
}

void printMenu()
{
	TextColor(7);
	gotoXY((consolewidth - 24) / 2, (consoleheight - 16) / 2);
	cout << "Ping Pong Game";
	gotoXY((consolewidth - 24) / 2, (consoleheight - 14) / 2);
	cout << "1. 2 player mode";
	gotoXY((consolewidth - 24) / 2, (consoleheight - 12) / 2);
	cout << "2. player vs computer";
	gotoXY((consolewidth - 24) / 2, (consoleheight - 10) / 2);
	cout << "3. Quit game ";
	gotoXY((consolewidth - 28) / 2, (consoleheight - 6) / 2);
	cout << "****How to play****";
	gotoXY((consolewidth - 56) / 2, (consoleheight - 4) / 2);
	cout << "Player1 move up=w, move down=s. Player2 move up=i, move down=k";
	gotoXY((consolewidth - 24) / 2, (consoleheight + 6) / 2);
	cout << "Your choice: ";
}

void drawonetile(int dong, int cot)
{
	TextColor(buffer[dong][cot].color);
	cout << buffer[dong][cot].ch;
}

void drawbuffer()
{
	for (int i = 0; i < consoleheight; i++)
		for (int j = 0; j < consolewidth; j++)
		{
			drawonetile(i, j);
		}
}

void drawgame()
{
	setbuffer();
	drawbuffer();
}