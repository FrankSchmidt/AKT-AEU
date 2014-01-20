
/******************************************************************************/
/* Title: Uebung 1 */
/* Description: Grundlagen */
/**/
/* Creator: */
/* Matr.No: */
/* Time of creation: */
/* Time of modification: */
/* Compile options: gcc -Wall ueb1.c -o ueb1 */ 
/******************************************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//#include
//#include <time.h>
//#include <locale.h>
//#include <sys/types.h>
//#include <sys/utsname.h>
//#include <sys/time.h>


#include "bruecker.h"


void pln(char string[]) { printf("%s\n",string); }
void p(char nString[]) { printf("%s",nString); }

struct sBrueckBer sBrueBer;
//{
/*	sBrueckBer sBrueBer.fBLength = 0;
	sBrueBer.fPGleit = 0;
	sBrueBer.fPFest = 0;
	sBrueBer.fDistFestGleit = 0;
	sBrueBer.fWinkelFest = 0;
	sBrueBer.fWinkelGleit = 0;
	sBrueBer.fDML = 0;
	sBrueBer.fDMR = 0;
*/
//};

void InputBruecke()
{
	int iInput;

	pln("Brueckenlaenge(m): ");
	scanf("%f", &sBrueBer.fBLength);
	getchar();

	pln("Pos. Gleitlader(m): ");
	scanf("%f", &sBrueBer.fPGleit);
	getchar();

	pln("Pos. Festlager(m): ");
	scanf("%f", &sBrueBer.fPFest);
	getchar();

	sBrueBer.fDistFestGleit = abs(sBrueBer.fPGleit - sBrueBer.fPFest);

	p("Ist ein Lager schraeg(j/n): ");
//	setvbuf(stdin,NULL,_IONBF,0); 
//	setvbuf(stdin,NULL,_IOFBF,BUFSIZ);
	iInput = getchar(); 

	if ( 'j'  == iInput )
	{
		getchar();
		p("Festlager(f) oder Gleitlager(g) ");
		iInput = getchar();
		if ( 'g' == iInput )
		{
			pln("Winkel Gleit(Grad): ");
			scanf("%f", &sBrueBer.fWinkelGleit);
			getchar();
		}
		else if ( 'f' == iInput )
		{
			pln("Winkel Fest(Grad): ");
			scanf("%f", &sBrueBer.fWinkelFest);
			getchar();
		}
		else
		{
			pln("Falsche Eingabe!!!");
		}
	}
}

void InputDrehmomente()
{
	int iInput;
	
	pln("Drehmoment links(Nm): ");
	scanf("%f", &sBrueBer.fDML);
	getchar();

	if( sBrueBer.fDML != 0 )
	{
		p("Drehrichtung mit(m) gegen(g) den Uhrzeigersinn: ");
		iInput = getchar();
//		pln("");
		if ( 'm' == iInput )
		{
			sBrueBer.fDML = -sBrueBer.fDML;
			printf("\(%f\)", sBrueBer.fDML);
		}
	}

 
	pln("");
	pln( "Drehmoment rechts(Nm): ");
	scanf("%f", &sBrueBer.fDMR);
	getchar();

	if( sBrueBer.fDMR != 0 )
	{                   
		p("Drehrichtung mit(m) oder gegen(g) den Uhrzeitgersinn: ");
		iInput = getchar();
//		pln("");

		if ( 'm' == iInput )
		{
			sBrueBer.fDMR = -sBrueBer.fDMR;
		}
		printf("\(%f\)", sBrueBer.fDMR);
	}
}


int main(void)
{
	pln("Lass uns dann mal loslegen\n");
	
	int iMenu = 0;
	
	pln("----------------AKT WS2013/14-----------------");
	pln("--Automatisierung Energie- und Umwelttechnik--");
	pln("------------Author: Frank Schmidt-------------");
	pln("----------------------------------------------");

	do 
	{

		pln("\n");
		pln("----------------Auswahl Menue-----------------");
		pln(" (1): Daten eingeben");
		pln(" (2): Anzeigen der berechneten Lagerkraefte  ");
		pln(" (0): Beenden");
		pln("----------------------------------------------");
		pln("Eingabe: ");
		scanf("%i", &iMenu);
		pln("");

		switch ( iMenu )
		{
		
		case 1: pln("Eingabe wird verarbeitet...");
			
		//	Clear();
				InputBruecke();
				InputDrehmomente();
			/*	objBerechnung.InputPunktlasten();
				objBerechnung.InputVierecklasten();
				objBerechnung.InputDreiecklasten();
				objBerechnung.InputTrapezlasten();
			*/	break;

		case 2: pln("Berechnung laeuft...");
			/*
			objBerechnung.OutputLastenInfo();
				objBerechnung.BerechneLasten();
			*/	break;

		case 3: pln("Lade Standard-Werte...");
			/*
			objBerechnung.LoadDefault();
				objBerechnung.OutputLastenInfo();
				objBerechnung.BerechneLasten();
			*/	break;

		default: pln("Unzulaessige Eingabe");
		
		}

	} while ( iMenu != 0 );

	return 0;
}
