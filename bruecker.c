
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
/*#include <unistd.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <sys/time.h>
*/

#include "bruecker.h"


void pln(char string[]){

	printf("%s\n",string);

}

void CBrueBer InputBruecke()
{
	char cInput;

	pln("Brueckenlaenge(m): ");
	scanf("%f", &BrueBer.fBLength);

	pln("Pos. Gleitlader(m): ");
	scanf("%f", &BrueBer.fPGleit);

	pln("Pos. Festlager(m): ");
	scanf("%f", &BrueBer.fPFest);

	BrueBer.fDistFestGleit = abs(BrueBer->fPGleit - BrueBer->fPFest);

	pln("Ist ein Lager schraeg(j/n)");
	scanf("%c", &cInput);

	if ( 'j'  == cInput )
	{
		pln("Festlager(f) oder Gleitlager(g)");
		scanf("%c", &cInput);
		if ( 'g' == cInput )
		{
			pln("Winkel Gleit(Grad): ");
			scanf("%f", &BrueBer.fWinkelGleit);
		}
		else if ( 'f' == cInput )
		{
			pln("Winkel Fest(Grad): ");
			scanf("%f", &BrueBer.fPFest);
		}
		else
		{
			pln("Falsche Eingabe!!!");
		}
	}
}


int main(void){

	pln("Lass uns dann mal loslegen\n");
	
	int iMenu = 0;
	
	CBrueckenBerech objBerechnung;
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
			
		//	objBerechnung.Clear();
				objBerechnung.InputBruecke();
		/*		objBerechnung.InputDrehmomente();
				objBerechnung.InputPunktlasten();
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
