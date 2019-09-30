#include "GlobalStuff.h"


namespace practicaprofesionaljulianbegapongsigil
{
int escKey = 0;
int aKey = 0;
int leftKey = 0;


namespace KeyManager
{

	void Update(int key, int state)
	{
		if (key == SL_KEY_ESCAPE)
		{
			escKey = state;

		}
		if (key == 'A')
		{
			aKey = state;

		}
		if (key == SL_KEY_LEFT)
		{
			leftKey = state;
		}
	}
	bool GetKeyUp(int key, int state)
	{
		if (key != 'A' || key != SL_KEY_LEFT || key || SL_KEY_ESCAPE)
		{
		
		if (key == 'A') {
			if (aKey == 1 && state == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if (key == SL_KEY_ESCAPE) {
			if (escKey == 1 && state == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		if (key == SL_KEY_LEFT) {
			if (leftKey == 1 && state == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		}

	}

}
}