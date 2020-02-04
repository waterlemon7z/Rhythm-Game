#pragma
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define ALTALE 4
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
#define ENTER 13
#define BLUE 9
#define GREEN 10
#define OCK 11
#define RED 12
#define PINK 13
#define YELLOW 14
#define WHITE 15
#define COLOR(A) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),A);
#define SIZE 600
#ifndef __HEADER_RHYTHM_
#define __HEADER_RHYTHM_

/*Global Variable*/
int Altale[4][SIZE];

/*Core Functions*/
void GMBoardVOID(int iSel);//Rhythm game Board

int TitleINT();//Rhythm game Title

void InitVOID();//Rhythm game Title

void MusicSetVOID();

void cursor(int n);

void gotoxy(int x, int y);

void AltaleSheet();


#endif