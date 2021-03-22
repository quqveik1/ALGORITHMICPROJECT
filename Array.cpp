#pragma once
#include "TXLib.h"
#include <stdio.h>
#include "Lib\Q_Locale.h"
#include <conio.h>
#include <assert.h>
#include "Stuck.h"
#include "math.h"
#include "Q_CoordinatSystem.h"

const int MAXARRAYSIZE = 100;
int Comparision = 0;
int Exchange = 0;



//! @brief Стуктура сделанная для того чтобы детальные данные при вызове dump() было проще смотреть


//! @brief Пространство имен, чтобы было проще передавать метод распечатки

enum PrintModes
{
	_VERCTICAL_  = 0b00,
	_HORIZONTAL_ = 0b01,
	_COLOR_      = 0b10
};





//! @brief Цвета для распечатки




enum Colors
{
	_BLUE_ = 0x1,
	_RED_  = 0xc,
	     _CYAN_ = 0b00000011,
	_LIGHTCYAN_ = 0b00001011,
	_GRAY_ = 0b00001000
};

void _printArr (int arr[], const int length, const int mode = _VERCTICAL_);
void _printArr (int arr[], const int length, PositionInfo info, const int mode = _VERCTICAL_);
void fillArithmeticProg (int arr[], const int length, const int firstNum, const int delta);
void fillGeometricProg (int arr[], const int length, const int firstNum, const int delta);
//void setConsoleColor (unsigned int color);
void fill123var1 (int arr[], const int length);
void fill123var2 (int arr[], const int length);
void fill123var3 (int arr[], const int length);
void fill123var4 (int arr[], const int length);
void fill123var5 (int arr[], const int length);
void fill123var6 (int arr[], const int length);
void fill123var7 (int arr[], const int length);
void fill123321var1 (int arr[], const int length);
void fill123321var2 (int arr[], const int length);
void fill123321var3 (int arr[], const int length);
void fill123321var4 (int arr[], const int length);
void fill123321var5 (int arr[], const int length);

void fill135642var1 (int arr[], const int len);
void fill135642var2 (int arr[], const int len);

void fill123654var1 (int arr[], const double len);
void fill123654var2 (int arr[], const int len);
/// //////////////////////////////////////////////////////////


void bubleSort (int arr[], const int len);
void drawPar (coordinatSys sys);
void randomfill (int arr[], int len);
void drawBubleEfficiency (int arr[], int len, Rect sys);


//! @brief Макрос для того, чтобы было удобно передавать данные на счет распечатки
#define POSINFO {__FILE__, __LINE__, __FUNCSIG__}
#define NAMEINFO
//! @brief Макрос для того, чтобы распечатывать некие переменные
#define printArr(name, length, ...) _printArr (name, length, POSINFO(name), ##__VA_ARGS__);
#define $(x) assert (0 <= (x) && (x) < length);

int main (int argc, const char *argv[])
{
	txCreateWindow (800, 800);
	setRussianLocale ();

	//VAR (Stack, s1);


	 //humanRound (3.14);
	 //humanRound (16.14);
	 //humanRound (0.14);
	 //humanRound (1);
	coordinatSys sys;
	sys.startPosPix_ = {0, 0};
	sys.finishPosPix_ = {400, 400};

	sys.nullCoor_ = {200, 400};

	//int arr[1000] = {};
	//randomfill (arr, 1000);
	drawPar (sys);
	//drawBubleEfficiency (arr, 1000, sys);
	//bubleSort (arr, 1000);
	//s1.dump ();
	//_printArr (arr, 1000);

	//+1
	//1 2 3 1 2 3 1 2 3 1 2 3...
	//1 2 3 3 2 1 1 2 3 3 2 1..
	//1 2 3 2 1 2 3 2 1 2 3
	//1 3 5 7 9	.... 8 6 4 2
	//1 2 3 7 8 9 ..12 11 10 6 5 4
	//printArr(arr, 10);
	//printArr(arr, 10, _HORIZONTAL_);
	//rintArr(arr, 10, _HORIZONTAL_  | _COLOR_);
	//printArr(arr, 10, _HORIZONTAL_ | _COLOR_);

	setConsoleColor (_GRAY_);

	return 0;

}
/*
int main2 (int argc, const char *argv[])
{




	for (;;)
	{
		Sleep (100);

		if (GetAsyncKeyState (VK_F1))
		{
			break;
		}

		OpenClipboard (NULL);

		HGLOBAL memBlock = GetClipboardData (CF_TEXT);

        if (memBlock == NULL)
        {
			CloseClipboard ();
			continue;
		}


        const char* str = (const char*) GlobalLock (memBlock);

        if (str == NULL)
        {
			CloseClipboard ();
			continue;
		}

		printf ("%s", str);

		if (strstr (str, "OFF"))
		{
			if (ExitWindowsEx (EWX_POWEROFF, 1) == 0) printf ("\n\nLastError: %d\n", GetLastError ());
			printf ("\n\nshut down");
			GlobalUnlock (memBlock);
			CloseClipboard ();
			_getch ();
			break;
		}

		//SetClipboardData ()

		GlobalUnlock (memBlock);					 o
		CloseClipboard ();

	}
}
*/

void drawBubleEfficiency (int arr[], int len, Rect sys)
{
	//int halfx = (sys.x1 + sys.x2) / 2;
	//int halfy = (sys.y1 + sys.y2) / 2;
	//txLine (halfx,  sys.y2, halfx, sys.y1);
	//txLine (sys.x1, halfy, sys.x2, halfy);

	for (int l = 0; l < len; l++)
	{
		const char  *texty = "sd";
		const char  *textx = "sd";
		//sscanf (texty, "%d", (halfy + Comparision));
		//sscanf (textx, "%d", l);
		//txTextOut (halfx, (halfy + Comparision), texty);
		//txTextOut (l, halfy, texty);

		Comparision = 0;
		Exchange = 0;
		bubleSort (arr, l);
		//txSetPixel (halfx + l, sys.y2 - (halfy + Comparision), TX_WHITE);
		//txSetPixel (halfx + l, sys.y2 - (halfy + Exchange), TX_CYAN);
	}


}

void drawPar (coordinatSys sys)
{
	/*
	int halfx = (sys.x1 + sys.x2) / 2;
	int halfy = 25;
	txLine (halfx,  sys.y2, halfx, sys.y1);
	txLine (sys.x1, sys.y2 - halfy, sys.x2, sys.y2 - halfy);
	 */
	sys.drawAxis ({10, 10});

	for (double x = 0; x < sys.startPosPix_.x + sys.scalePix_.x; x += 0.1)
	{
		double f = x * x;
		sys.drawCircle ({x, f}, 1);
		sys.drawCircle ({-x, f}, 1);
	}


		/*
		txSetPixel (halfx + x, sys.y2 - (halfy  + f), TX_WHITE);
		txSetPixel (halfx - x, sys.y2 - (halfy + f), TX_WHITE);
		 */
}

void randomfill (int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		arr[i] = rand ();
	}
}


void bubleSort (int arr[], const int len)
{
	for (int n = 0; n < len; n ++)
	{
		for (int j = n; j < len - 1; j++)
		{
			Comparision++;
			if (arr[j] < arr[j + 1])
			{
				Exchange++;
				int copy = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = arr[j];
			}
		}
	}
}



void fill135642var1 (int arr[], const int len)
{
	int startn = 1;
	for (int i = 0; i < (len / 2) + 1; i++)
	{
		assert (0 <= i && i < len);
		assert (0 <= i && i < len);
		assert (0 <= len - (i + 1) && len - (i + 1) < len);
		arr[i] = startn;
		arr[len - (i + 1)] = startn + 1 ;
		startn += 2;
	}
}

void fill135642var2 (int arr[], const int len)
{
	for (int startn = 1; startn <= len; startn++)
	{
		int formula = abs ((len) * ((startn % 2 + 1) % 2) - startn/2);
		assert ( 0 <= formula && formula < len);
		arr[formula] = startn;
	}
}

void fill123654var1 (int arr[], const double len)
{
	int num = 1;
	for (int i = 0; i < round ((len / 2)); i++)
	{
		arr[i] = num;
		arr[int (len - i - 1)] = num + 3;
		num++;
		if ((i + 1) % 3 == 0) num += 3;

	}
}

void fill123654var2 (int arr[], const int len)
{
	int num = len;
	int delta = 1;
	for (int i = round (len/2); i < len; i++)
	{
		arr	[i] = num;
		arr[i - delta] = num-1;
		num--;
		if ((i + 1) % 3 == 0) num -= 3;
		delta+= 2;

	}
}


  /*
//!	@brief Устанавливает цвет, который вы пожелаете
//!
//!	@param color Цвет типа Word
//!
//! @return НИЧЕГО и не надо:)
//! @note Для него подходит пространство имен цветов Colors
//!
//! @usage @code setConsoleColor (_GRAY_);
//!
//!@endcode
void setConsoleColor (unsigned color)
{
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) color);
}
*/




void fill123var1 (int arr[], const int length)
{
	for (int i = 0; i < length; i++)
	{
		arr[i] = ((i + 1) % 3 == 0)? 3 : (i + 1) % 3;
	}
}

void fill123var2 (int arr[], const int length)
{
	for (int i = 0; i < length; i +=3)
	{
		arr[i] = 1;

	}
	for (int i = 1; i < length; i +=3)
	{
		arr[i] = 2;
	}
	for (int i = 2; i < length; i +=3)
	{
		arr[i] = 3;
	}
}

void fill123var3 (int arr[], const int length)
{
	arr[0] = 1;
	for (int i = 0; i < length; i++)
	{
		arr[i] = (i - 3 * ((int)i/3)) + 1;
		arr[i] = (i - 3 * ((int)i/3)) + 1;
	}
}


void fill123var4 (int arr[], const int length)
{
	for (int i = 0; i < length; i +=3)
	{
		arr[i] = 1;
		if (i + 1 < length) arr[i + 1] = 2;
		if (i + 2 < length) arr[i + 2] = 3;
	}
}

void fill123var5 (int arr[], const int length)
{
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;

	for (int i = 3; i < length; i += 3)
	{
		arr[i] = arr[i - 3];
		if (i + 1 < length) arr[i + 1] = arr[i - 2];
		if (i + 2 < length) arr[i + 2] = arr[i - 1];
	}
}

void fill123var6 (int arr[], const int length)
{
	for (int i = 0; i < length; i++)
	{
		arr[i] = 1 + i % 3;
	}
}

void fill123var7 (int arr[], const int length)
{

	/*1
	for (int i = 0; i < length; i++)
	{
		arr[i] = ((i + 1) % 3 == 0)? 3 : (i + 1) % 3;
	}
	*/

	/*2
	for (int i = 0; i < length; i +=3)
	{
		arr[i] = 1;

	}
	for (int i = 1; i < length; i +=3)
	{
		arr[i] = 2;
	}
	for (int i = 2; i < length; i +=3)
	{
		arr[i] = 3;
	}
	  */

	/*3
	arr[0] = 1;
	for (int i = 0; i < length; i++)
	{
		arr[i] = (i - 3 * ((int)i/3)) + 1;
	}
	*/

	/*4
	for (int i = 0; i < length; i +=3)
	{
		arr[i] = 1;
		if (i + 1 < length) arr[i + 1] = 2;
		if (i + 2 < length) arr[i + 2] = 3;
	}
	*/

	/*5
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;

	for (int i = 3; i < length; i += 3)
	{
		arr[i] = arr[i - 3];
		if (i + 1 < length) arr[i + 1] = arr[i - 2];
		if (i + 2 < length) arr[i + 2] = arr[i - 1];
	}
	*/



	assert (arr);
	assert (0 < length && length < MAXARRAYSIZE);

	int copy = 0;

	for (int i = 0; i < length; i ++)
	{
$(i)
		arr[i] = 3 - i % 3;
	}

	for (int i = 0; i < length; i += 3)
	{
		copy = arr[i];

		if (i + 2 < length)
		{
$(i)
$(i + 2)
			arr[i] = arr[i + 2];
			arr[i + 2] = copy;
		}
		else arr[i] = 1;
	}




}

void fill123321var1 (int arr[], const int length)
{
	for (int i = 0; i < length; i++)
	{
		arr[i] = ((i + 1) % 3 == 0)? 3 : (i + 1) % 3;
		if (((i + 1) % 3) == 0) i += 3;
	}
	for (int i = 3; i < length; i++)
	{
		arr[i] = ((i + 1) % 3 == 0)? 1 : 4 - (i + 1) % 3;
		if (((i + 1) % 3) == 0) i += 3;
	}
}

void fill123321var2 (int arr[], const int length)
{
	for (int i = 0; i < length; i += 6)
	{
		if (i     < length) arr[i    ] = 1;
		if (i + 1 < length) arr[i + 1] = 2;
		if (i + 2 < length) arr[i + 2] = 3;
		if (i + 3 < length) arr[i + 3] = 3;
		if (i + 4 < length) arr[i + 4] = 2;
		if (i + 5 < length) arr[i + 5] = 1;
	}
}

void fill123321var3 (int arr[], const int length)
{
	for (int i = 0; i < length; i += 3)
	{
		if (i     < length) arr[i    ] = 1;
		if (i + 1 < length) arr[i + 1] = 2;
		if (i + 2 < length) arr[i + 2] = 3;
	}

	int copy = 0;

	for (int i = 3; i < length; i += 6)
	{
		if (i < length)
		{

			copy = arr[i];

			if (i + 2 < length)
			{
				arr[i] = arr[i + 2];
				arr[i + 2] = copy;
			}
			else arr[i] = 3;
		}
	}

}

void fill123321var4 (int arr[], const int length)
{
	for (int i = 0; i < length; i++)
	{
		if (i - 6 * ((int)(i/6)) < 3)
		{
			arr[i] = 1 + i % 3;
		}
		else
		{
			arr[i] = 3 - i % 3;
		}

	}
}


void fill123321var5 (int arr[], const int length)
{
	/*1
	for (int i = 0; i < length; i++)
	{
		arr[i] = ((i + 1) % 3 == 0)? 3 : (i + 1) % 3;
		if (((i + 1) % 3) == 0) i += 3;
	}
	for (int i = 3; i < length; i++)
	{
		arr[i] = ((i + 1) % 3 == 0)? 1 : 4 - (i + 1) % 3;
		if (((i + 1) % 3) == 0) i += 3;
	}
	*/

	/*2
	for (int i = 0; i < length; i += 6)
	{
		if (i     < length) arr[i    ] = 1;
		if (i + 1 < length) arr[i + 1] = 2;
		if (i + 2 < length) arr[i + 2] = 3;
		if (i + 3 < length) arr[i + 3] = 3;
		if (i + 4 < length) arr[i + 4] = 2;
		if (i + 5 < length) arr[i + 5] = 1;
	}
	*/
	/*3
	for (int i = 0; i < length; i += 3)
	{
		if (i     < length) arr[i    ] = 1;
		if (i + 1 < length) arr[i + 1] = 2;
		if (i + 2 < length) arr[i + 2] = 3;
	}

	int copy = 0;

	for (int i = 3; i < length; i += 6)
	{
		if (i < length)
		{

			copy = arr[i];

			if (i + 2 < length)
			{
				arr[i] = arr[i + 2];
				arr[i + 2] = copy;
			}
			else arr[i] = 3;
		}
	}
	*/

	/*4
	for (int i = 0; i < length; i++)
	{
		if (i - 6 * ((int)(i/6)) < 3)
		{
			arr[i] = 1 + i % 3;
		}
		else
		{
			arr[i] = 3 - i % 3;
		}

	}
	*/


	for (int i = 0; i < length; i += 6)
	{
		arr[i] = 1;
		if (i + 5 < length) arr[i + 5] = arr[i];
		if (i + 1 < length) arr[i + 1] = 2;
		if (i + 4 < length) arr[i + 4] = arr[i + 1];
		if (i + 2 < length)	arr[i + 2] = 3;
		if (i + 3 < length) arr[i + 3] = arr[i + 2];

	}




}

void _printArr (int arr[], const int length, const int mode)
{
	if (mode & _COLOR_)	// BBBBFFFF
	{					// irgbirgb
		setConsoleColor (0b10110101);
		//setConsoleColor (_BLUE_);
	}


    if (mode & _HORIZONTAL_)
	{
		for (int i = 0; i < length; i++)
		{
			//printf ("")
		}


	}
	for (int i = 0; i < length; i++)
	{
		printf ("%d: %d\n", i, arr[i]);
	}

}
 /*
void _printArr (int arr[], const int length, PositionInfo info, const int mode)
{
	if (mode & _COLOR_)	// BBBBFFFF
	{					// irgbirgb
		//setConsoleColor (0b10110101);

		setConsoleColor (_CYAN_);
	}

	if (mode & _HORIZONTAL_)
	{
		printf ("%s = [ ", info.name);
		for (int i = 0; i < length; i++)
		{
			setConsoleColor (_CYAN_);
			printf ("[%d] = ",  i);

			setConsoleColor (_LIGHTCYAN_);
			printf ("%d", arr[i]);

			setConsoleColor (_CYAN_);
			printf ("%s", (i != length - 1)? ", " : " ");
		}
		printf ("]\n");

	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			printf ("%d: %d\n", i, arr[i]);
		}
	}

	info.printInfo ();

}
 */


void fillArithmeticProg (int arr[], const int length, const int firstNum, const int delta)
{
	arr[0] = firstNum;
	for (int i = 1; i < length; i++)
	{
		arr[i] = arr[i-1] + delta;
	}

}

void fillGeometricProg (int arr[], const int length, const int firstNum, const int delta)
{
	arr[0] = firstNum;
	for (int i = 1; i < length; i++)
	{
		arr[i] = arr[i-1] * delta;
	}

}
