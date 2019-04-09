#include <engineering/electrical/ee.h>
int GetVoltage(int CountryCode)
{
	if(CountryCode==1)
		return 110;
	else
		return 220;
}
