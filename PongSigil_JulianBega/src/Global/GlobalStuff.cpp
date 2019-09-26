#include "GlobalStuff.h"

bool EscKeyWasPress = false;
bool AKeyWasPress = false;
bool LeftKeyWasPress = false;
bool EscKeyIsPress = false;
bool AKeyIsPress = false;
bool LeftKeyIsPress = false;


bool GetKeyUp(int Key) 
{

	if (Key == SL_KEY_ESCAPE)
	{
		EscKeyWasPress = EscKeyIsPress;
		EscKeyIsPress = slGetKey(SL_KEY_ESCAPE);
		if (EscKeyWasPress == true && EscKeyIsPress == false)
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}
	if (Key == 'A')
	{
		AKeyWasPress = AKeyIsPress;
		AKeyWasPress = slGetKey('A');
		if (AKeyWasPress == true && AKeyIsPress == false)
		{
			return true;
		}
		else
		{
			return false;
		}
		

	}
	if (Key == SL_KEY_LEFT)
	{
		LeftKeyWasPress = LeftKeyIsPress;
		LeftKeyIsPress = slGetKey(SL_KEY_LEFT);
		if (LeftKeyWasPress == true && LeftKeyIsPress == false)
		{
			return true;
		}
		else
		{
			return false;
		}
		
		
	}



	

}