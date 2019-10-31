#include "Buffer.h"
void main()
{
	int lenh;
	do
	{
		lenh = 0;
		system("cls");
		printMenu();
		cin >> lenh;
		system("cls");
		if (lenh == 1)
		{
			cIngame c(consolewidth, consoleheight);
			drawgame();
			c.playWithMan();
		}
		else if (lenh == 2)
		{
			cIngame d(consolewidth, consoleheight);
			drawgame();
			d.playWithCom();
		}
	} while (lenh != 3);
}