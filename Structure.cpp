#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Stuck.h"
#include "Lib\Q_Locale.h"


//------------------------------------

//#define SETINFO(name) {__FILE__, __LINE__, __FUNCSIG__, #name}

int main (int argc, const char *argv[])
{
	setRussianLocale ();

	//Stack s1 (POSINFO(s1));
	//VAR(Stack, s1);

	//const char *s = "abc";
	//printf ("%llx\n\n", hashCalc ("abc", 3));

	//s1.push (10);
	
	StackTest st1 {{}, {POSINFO, "testData.data"}, {}};


	st1.data.dump (st1.data.structPos, "FirstDump");
	st1.mLeft [6+3] = 1235;
	st1.data.dump (st1.data.structPos, "SecondDump");
	//s1.push (7);
	//s1.push (8);
	//s1.stack[3] = 9;

	//s1.unittestCanary (3);


	//s1.dump ();
	//s1.push (1);
	//s2.push (3); 

	//s1.change (0, 1);

	//printf ("%d\n", s1.stack[0]);
	//printf ("%d\n", s1.stack[1]);
	//s1.dump ();
	  /*
	char str[1000] = "";
	int stat[256] = {};
	
	scanf ("%s", str);


	statText (str, stat);

	for (int i = 0; i < 256; i++)
	{
		if (stat[i] != 0)
			printf ("%c - %d\n", i, stat[i]);
	}
	*/
	//tenTo2 (130);

	//char text[100] = "";
	//int stat[256] = {};
	//int n;

	//scanf ("%s", text);
	
	
	//charToAscii ('a');
	///charToAscii ('b');
	//charToAscii ('�');
	//charToAscii ('�');

	//statText (text, stat);
	

	//tenTo2 (6);

	





	return 0;
}