/*Rhythm Game v1*/
/*DARK-Lemon7z*/
#include "Rhythm.h"
#include "Music.h"

int main()
{
	int iSel;
	InitVOID();//initial settings
	MusicSetVOID();//Set music notes
	iSel = TitleINT();
	if (iSel == 5)
		return 0;
	GMBoardVOID(iSel);
	return 0;
}    