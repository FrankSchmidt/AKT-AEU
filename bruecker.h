//#include <vector>
#include <stdio.h>

//#define _USE_MATH_DEFINES
#include <math.h>
#include <string.h>

struct sLast
{
	char cArt;
	float fPosition;
	float fDistanz_G;
	float fDruck_G;
	char fDruckRi;
	float fDruckStrecke;
	float fDistanz_F;
	float dDruck_F;
} sLasten;

struct sBrueckBer
{
//public:
//	sBrueBer();

//	void InputBruecke();
/*	void InputDrehmomente;
	void InputPunktlasten;
	void InputVierecklasten;
	void InputDreiecklasten;
	void InputTrapezlasten;

	float InputPosition;
	float InputDruck;
	char InputLastArt;
	float InputLastBeginn;
	float InputLastEnde;
	float InputLastLinks;
	float InputLastRechts;

	void OutputLastenInfo;
	void BerechneLasten;
	void LoadDefault;
	void Clear;
*/
//private:
	float fBLength;
	float fPGleit;
	float fPFest;
	float fDistFestGleit;
	float fWinkelFest;
	float fWinkelGleit;

	float fDML;
	int fDML_DR;
	float fDMR;
	int fDMR_DR;

//	vector<sLasten> vecLasten;
};
