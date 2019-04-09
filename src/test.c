#include <stdio.h>
#include <engineering/electrical/ee.h> //to avoid writing #include "../include/engineering/electrical/ee.h" and #include "../include/engineering/electrical/me.h"
#include <engineering/mechanical/me.h> //define related folder to project-properties-c/c++ build-settings-includes
/*
gcc "-IC:\\Users\\user\\Desktop\\su\\eclipse-workspace\\libdepsam\\include" -O0 -g3 -Wall -c -fmessage-length=0 -o "src\\test.o" "..\\src\\test.c"
gcc "-IC:\\Users\\user\\Desktop\\su\\eclipse-workspace\\libdepsam\\include" -O0 -g3 -Wall -c -fmessage-length=0 -o "include\\engineering\\electrical\\ee.o" "..\\include\\engineering\\electrical\\ee.c"
gcc -o libdepsam.exe "include\\engineering\\electrical\\ee.o" "src\\test.o"
 *
 */
int main()
{
	printf("%lf\n", FRICTION_COEFFICIENT);
	printf("%d", GetVoltage(2));
	return 0;
}
