#include "Rhythm.h"
#include "Music.h"

int frame[4][21];
int iPoint, iChoose, iMiss;
typedef struct _hit
{
	int D;
	int F;
	int J;
	int K;
}Hit;

Hit s_Hit;

/*
* name   : gotoXY
* date   : 2019.11.17
* author : DARK-SIRING
* arg    : int
* return      : void
* description : Return x and y.
*/

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

/*
* name   : cursor
* date   : 2019.11.17
* author : Lemon7z
* arg    : int
* return      : void
* description : Set cursor.
*/

void cursor(int n)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);

	system("mode con:cols=70 lines=40");
}

/*
* name   : GMBoardVOID
* date   : 2019.11.17
* author : DARK-SIRING
* arg    : int
* return      : void
* description : print game board.
*/

void GMBoardVOID(int iSel)
{
	
	cursor(0);
	int i, x, y, cur,cycle, iStartTick,  iKey, esc = 1;
	COLOR(YELLOW);
	printf("\t¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
	for (i = 0; i < 18; i++)
	{
		printf("\t¦¢         ¦¢         ¦¢         ¦¢         ¦¢ \n");
	}
	printf("\t¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
	printf("\t¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
	x = 11;
	y =1;
	cur = 1;
	cycle = 1; 
	iMiss = 0;
	if (iSel == ALTALE)
		PlaySound(TEXT("Altale.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	COLOR(GREEN);

	while (1)
	{
		iStartTick = (int)GetTickCount64();
		/*Reset Hit*/
		s_Hit.D = 0;
		s_Hit.F = 0;
		s_Hit.J = 0;
		s_Hit.K = 0;
		/*lane changer*/
		if (iSel == ALTALE)//For Altale
		{
			/*for (i = 20; i >= 0; i--)
			{

				frame[0][i] = Altale[0][cur + i];
				frame[1][i] = Altale[1][cur + i];
				frame[2][i] = Altale[2][cur + i];
				frame[3][i] = Altale[3][cur + i];
			}*/
			frame[0][20] = Altale[0][cur];
			frame[1][20] = Altale[1][cur];
			frame[2][20] = Altale[2][cur];
			frame[3][20] = Altale[3][cur];
			for (i = 1; i <= 19; i++)
			{

				frame[0][i] = frame[0][i+1];
				frame[1][i] = frame[1][i+1];
				frame[2][i] = frame[2][i+1];
				frame[3][i] = frame[3][i+1];
			}

		}
		/*print notes*/
			for (i = 20; i > 0; i--)
			{
				/* First Lane*/
				gotoxy(x, y);
				if (frame[0][i] == 1)
				{
					puts("¡á¡á¡á¡á");
				}
				else
					puts("        ");
				/* Second Lane*/
				gotoxy(x + 10, y);
				if (frame[1][i] == 1)
				{
					puts("¡á¡á¡á¡á");
				}
				else
					puts("        ");
				/* Third Lane*/
				gotoxy(x + 20, y);
				if (frame[2][i] == 1)
				{
					puts("¡á¡á¡á¡á");
				}
				else
					puts("        ");
				/* Last Lane*/
				gotoxy(x + 30, y);
				if (frame[3][i] == 1)
				{
					puts("¡á¡á¡á¡á");
				}
				else
					puts("        ");
				y++;
			}

		
		y = 2;

		cur++;
		/*key pressing*/
		while (GetTickCount64() - iStartTick < 100)
		{
			if (_kbhit())
			{
				iKey = _getch();
				switch (iKey)
				{
				case 'd':
					/*Pass*/
					if (frame[0][2] == 1|| frame[0][1] == 1)
					{
						iPoint++;
						frame[0][1] = 0;
						frame[0][2] = 0;
						gotoxy(x + 30, y+22);
						printf("COMBO : %d", iPoint);
						s_Hit.D = 1;
					}
					if (s_Hit.D == 1)
						break;
					/*Fast press to reset*/
					if (frame[0][4] == 1)
					{
						iPoint = 0;
						frame[0][4] = 0;
						gotoxy(x + 30, y + 22);
						printf("COMBO : %d   ", iPoint);
					}
					break;
				case 'f':
					if (frame[1][2] == 1 || frame[1][1] == 1)
					{
						iPoint++;
						frame[1][1] = 0;
						frame[1][2] = 0;
						gotoxy(x + 30, y + 22);
						printf("COMBO : %d", iPoint);
						s_Hit.F = 1;
					}
					if (s_Hit.F == 1)
						break;
					if (frame[1][4] == 1)
					{
						iPoint = 0;
						frame[1][4] = 0;
						gotoxy(x + 30, y + 22);
						printf("COMBO : %d   ", iPoint);
					}
					break;
				case 'j':
					if (frame[2][2] == 1 || frame[2][1] == 1)
					{
						iPoint++;
						frame[2][1] = 0;
						frame[2][2] = 0;
						gotoxy(x + 30, y + 22);
						printf("COMBO : %d", iPoint);
						s_Hit.J = 1;
					}
					if (s_Hit.J == 1)
						break;
					if (frame[2][4] == 1)
					{
						iPoint = 0;
						frame[2][4] = 0;
						gotoxy(x + 30, y + 22);
						printf("COMBO : %d   ", iPoint);
					}
					break;
				case 'k':
					if (frame[3][2] == 1 || frame[3][1] == 1)
					{
						iPoint++;
						frame[3][1] = 0;
						frame[3][2] = 0;
						gotoxy(x + 30, y + 22);
						printf("COMBO : %d", iPoint);
						s_Hit.K = 1;
					}
					if (s_Hit.K == 1)
						break;
					if (frame[3][4] == 1)
					{
						iPoint = 0;
						frame[3][4] = 0;
						gotoxy(x + 30, y + 22);
						printf("COMBO : %d   ", iPoint);
					}
					break;
				default:
					gotoxy(x + 40, y+ esc);
					printf("%d", cur);
					esc++;
					break;
				}
			}
		}

		if (frame[0][0] == 1 || frame[1][0] == 1 || frame[2][0] == 1 || frame[3][0] == 1 || frame[0][1] == 1 || frame[1][1] == 1 || frame[2][1] == 1 || frame[3][1] == 1)
		{
			gotoxy(x + 30, y + 22);
			iPoint = 0;
			printf("COMBO : %d  ", iPoint);
		}
		gotoxy(x + 40, y + esc);
 	}
}

/*
* name   : TitleINT
* date   : 2019.11.17
* author : DARK-SIRING
* arg    : int
* return      : Return value that chosen value by user.
* description : print game title.
*/

int TitleINT()
{
	int iChoose, h;
	h = 4;
	cursor(0);
	gotoxy(4, 2);
	puts("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªRhythm Game¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª");
	gotoxy(8, 4);
	puts("1. PLAY!!");
	gotoxy(8, 5);
	puts("0. Exit");
	gotoxy(20, h);
	puts("¢¸");

	while (1) {
		iChoose = _getch();
		if (iChoose == 224) {
			iChoose = _getch();
			if (iChoose == DOWN && h < 5) {
				gotoxy(20, h);
				puts("  ");
				h++;
				gotoxy(20, h);
				puts("¢¸");
			}
			else if (iChoose == UP && h > 4) {
				gotoxy(20, h);
				puts("  ");
				h--;
				gotoxy(20, h);
				puts("¢¸");
			}
		}
		if (iChoose == ENTER)
			break;
	}
	if (h == 4) //Select Music
	{
		system("cls");
		gotoxy(4, 2);
		puts("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ªSelect Music¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª");
		gotoxy(8, 4);
		COLOR(GREEN);
		puts("1. Altale");
		gotoxy(8, 5);
		COLOR(WHITE);
		puts("0. Exit");
		gotoxy(20, h);
		puts("¢¸");

		while (1) {
			iChoose = _getch();
			if (iChoose == 224) {
				iChoose = _getch();
				if (iChoose == DOWN && h < 5) {
					gotoxy(20, h);
					puts("  ");
					h++;
					gotoxy(20, h);
					puts("¢¸");
				}
				else if (iChoose == UP && h > 4) {
					gotoxy(20, h);
					puts("  ");
					h--;
					gotoxy(20, h);
					puts("¢¸");
				}
			}
			if (iChoose == ENTER)
				break;
		}
	}
	return h;
}

void InitVOID()
{
	int i, n;
	for (i = 0; i < 4; i++)
	{
		for (n = 0; n < SIZE; n++)
		{
			Altale[i][n] = 0;
		}
	}
	for (i = 0; i < 21; i++)
	{
		for (n = 0; n < 4; n++)
		{
			frame[n][i] = 0;
		}
	}
}

void MusicSetVOID()
{
	AltaleSheet();
}