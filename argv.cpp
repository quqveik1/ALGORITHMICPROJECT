#include <stdio.h>
#include "Lib\Q_Locale.h"
//#include "TXLib.h"

int main (int argc, const char *argv[])
{

	for (int i = 0; i < argc; i++)
	{
		printf ("[%d] стол = [%s]\n", i, argv[i]);
	}

}