#include <iostream>
#include "mylib.h"
#define MAX 100

using namespace std;

int toa_do_x[MAX] = { 0 };
int toa_do_y[MAX] = { 0 };
int sl = 6;
int xqua = -1;
int yqua = -1;

//------------------

void ve_tuong();
void khoi_tao_ran();
void play();
void ve_ran();
void di_chuyen_ran(int x, int y);
bool game_over();
void tao_qua();
void ve_qua();
//-------------
bool kt_ran_an_qua();
void xu_ly_ran_an_qua();
bool kt_ran_cham_than();
void printInfo();

//------------------------------------------

void main()
{
	//--- menu tinh ----
	//--- menu dong ----

	printInfo();
	system("cls");
	srand(time(NULL));
	play();
	system("cls");
	gotoXY(45, 12);
	cout << "GAME OVER";
;	_getch();
}

void ve_tuong()
{
	for (int x = 10; x <= 95; x++)
	{
		gotoXY(x, 1);
		cout << "=";
		gotoXY(x, 25);
		cout << "=";
	}
	for (int y = 1; y <= 25; y++)
	{
		gotoXY(10, y);
		cout << "+";
		gotoXY(95, y);
		cout << "+";
	}
}
void play()
{
	ShowCur(0);
	SetColor(11);
	//BUILD GAME
	//---- setting ----
	ve_tuong();
	khoi_tao_ran();
	tao_qua();
	ve_qua();
	int x = toa_do_x[0];
	int y = toa_do_y[0];
	int check = 2; //rắn đi qua phải 

	//------ play ----
	while (true)
	{
		//---- clear data cu ---
		gotoXY(toa_do_x[sl], toa_do_y[sl]);
		cout << " ";
		//------ in ra rắn ----
		ve_ran();
		//------ điều khiển ---
		if (_kbhit())
		{
			char c = _getch();
			if (c == -32)
			{
				c = _getch();
				if (c == 72 && check != 0)
				{
					check = 1;//trên
				}
				else if (c == 80 && check != 1)
				{
					check = 0;//dưới
				}
				else if (c == 75 && check != 2)
				{
					check = 3;//trái
				}
				else if (c == 77 && check != 3)
				{
					check = 2;//phải
				}
			}
		}
		//------ di chuyển ---
		if (check == 0)
		{
			y++;
		}
		else if (check == 1)
		{
			y--;
		}
		else if (check == 2)
		{
			x++;
		}
		else if (check == 3)
		{
			x--;
		}
		//------ biên ----
		if (game_over())
		{
			break;
		}
		xu_ly_ran_an_qua();
		//------- xử lý rắn --------
		di_chuyen_ran(x, y);
		//---- speed ---
		Sleep(100);
	}
}
void khoi_tao_ran()
{
	int x_khoi_tao = 50;
	int y_khoi_tao = 13;
	for (int i = 0; i < sl; i++)
	{
		toa_do_x[i] = x_khoi_tao--;
		toa_do_y[i] = y_khoi_tao;
	}
}
void ve_ran()
{
	for (int i = 0; i < sl; i++)
	{
		gotoXY(toa_do_x[i], toa_do_y[i]);
		if (i == 0)
		{
			cout << "Q";
		}
		else
		{
			cout << "0";
		}
	}
}
void di_chuyen_ran(int x, int y)
{
	//them x,y vao dau toadox,toadoy
	for (int i = sl; i > 0; i--)
	{
		toa_do_x[i] = toa_do_x[i - 1];
		toa_do_y[i] = toa_do_y[i - 1];
	}
	toa_do_x[0] = x;
	toa_do_y[0] = y;
}
bool kt_ran_cham_than()
{
	for (int i = 1; i <= sl; i++)
	{
		if (toa_do_x[0] == toa_do_x[i] && toa_do_y[0] == toa_do_y[i])
		{
			return true;
		}
	}
	return false;
}
bool game_over()
{
	if (toa_do_x[0] == 10 || toa_do_x[0] == 95 || toa_do_y[0] == 1 || toa_do_y[0] == 25)
	{
		return true;
	}
	return kt_ran_cham_than();
}
bool kt_ran_de_qua()
{
	for (int i = 0; i < sl; i++)
	{
		if (xqua == toa_do_x[i] && yqua == toa_do_y[i]) {
			return true;
		}
	}
	return false;
}
void tao_qua()
{
	do
	{
		xqua = rand() % (93 - 10 + 1) + 10;
		yqua = rand() % (24 - 0 + 1) + 0;
	}
	while (kt_ran_de_qua());
}
void ve_qua()
{
	gotoXY(xqua, yqua); 
	cout << "$";
}
bool kt_ran_an_qua()
{
	return (toa_do_x[0] == xqua && toa_do_y[0] == yqua);
}
void xu_ly_ran_an_qua()
{
	if (kt_ran_an_qua())
	{
		sl++;
		tao_qua();
		ve_qua();
		
	}
}
void printInfo()
{
	int x = 10, y = 22;
	int xcu = -1, ycu = -1;
	while (true)
	{
		// xoa cu
		gotoXY(xcu, ycu);
		cout << "                       ";
		xcu = x;
		ycu = y;
		gotoXY(x, y);
		cout << "Player: Luc Thi Hue";
		y--;
		if (y == 14)
			break;
		Sleep(150);
	}
	x = 10, y = 22;
	xcu = -1, ycu = -1;
	while (true)
	{
		// xoa cu
		gotoXY(xcu, ycu);
		cout << "                        ";
		xcu = x;
		ycu = y;
		gotoXY(x, y);
		cout << "19020307";
		y--;
		if (y == 15)
			break;
		Sleep(150);
	}
	x = 10, y = 22;
	xcu = -1, ycu = -1;
	while (true)
	{
		// xoa cu
		gotoXY(xcu, ycu);
		cout << "                        ";
		xcu = x;
		ycu = y;
		gotoXY(x, y);
		cout << "Game Snake";
		y--;
		if (y == 16)
			break;
		Sleep(150);
	}
}