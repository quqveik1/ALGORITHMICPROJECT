//\
#pragma love(PYTHON)
#pragma once
#include "TXLib.h"
#include <stdio.h>
#include "Lib\Q_Locale.h"
#include <conio.h>
//#include <assert.h>
//#include "Stuck.h"
#include "math.h"
#include "Q_CoordinatSystem.h"

const int MAXARRAYSIZE = 100;
int Comparision = 0;
int Exchange = 0;



//! @brief Ñòóêòóðà ñäåëàííàÿ äëÿ òîãî ÷òîáû äåòàëüíûå äàííûå ïðè âûçîâå dump() áûëî ïðîùå ñìîòðåòü


//! @brief Ïðîñòðàíñòâî èìåí, ÷òîáû áûëî ïðîùå ïåðåäàâàòü ìåòîä ðàñïå÷àòêè

enum PrintModes
{
	_VERCTICAL_  = 0b00,
	_HORIZONTAL_ = 0b01,
	_COLOR_      = 0b10
};





//! @brief Öâåòà äëÿ ðàñïå÷àòêè




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
void drawBubleEfficiency (int arr[], int len, coordinatSys sys);
void drawEfficiency (int arr[], int len, void (*sortFunc) (int arr[], int len), coordinatSys sys1, coordinatSys sys2, COLORREF color, double r = 1.5);
int findTheLess (int arr[], int len);
void exchange (int *n1, int *n2);
void selectionSort (int arr[], int len);
int lessThen (int arr[], int len, int num);
void swap (int &n1, int &n2);
void simpleInsertion (int arr[], int len);
void sortArr (void (*comparisionFunc1) (int arr[], int len), int arr[], int len, coordinatSys sys1, coordinatSys sys2, COLORREF color, double r = 1.5);
int isSorted (int arr[], int len);
int findTheBiggest (int arr[], int len);
int binarySearch (int arr[], int len, int num);
void binaryInsertion (int arr[], int len);
void divideArr (int arr[], int left, int right, int len);
void printSort (int arr[], int len, int middNum, int left, int currMiddNumIndex, int right, const char *cause = "");
void testDivide ();
void unittestDivided ();
void equal (int arr[], int arr2[], int len);
void unittestThreeFill ();
void sort3 (int arr[]);

void rotateArr (int arr[], int start, int finish);

void unittestSorted ();
void unittestSorted (void (*func) (int arr[], int len), const char *name);


//! @brief Ìàêðîñ äëÿ òîãî, ÷òîáû áûëî óäîáíî ïåðåäàâàòü äàííûå íà ñ÷åò ðàñïå÷àòêè
#define POSINFO {__FILE__, __LINE__, __FUNCSIG__}
#define NAMEINFO
//! @brief Ìàêðîñ äëÿ òîãî, ÷òîáû ðàñïå÷àòûâàòü íåêèå ïåðåìåííûå
#define printArr(name, length, ...) _printArr (name, length, POSINFO, ##__VA_ARGS__);
//#define printArr(arr,)
#define $(x, length) assert (0 <= (x) && (x) < length);
#define unit3(a, b, c) {int arr[3] = {a, b, c}; \
	sort3 (arr);								  \
	if (isSorted (arr, 3) != -1)				  \
	{											  \
		printf ("ERror");						  \
	}}											  \

int main (int argc, const char *argv[])
{
	
	setRussianLocale ();

	//VAR (Stack, s1);


	 //humanRound (3.14);
	 //humanRound (16.14);
	 //humanRound (0.14);
	 //humanRound (1);
	
	txCreateWindow (400, 800);
	unittestSorted (&simpleInsertion, "simpleInsertion");
	unittestSorted (&bubleSort, "bubleSort");
	unittestSorted (&selectionSort, "selectionSort");
	unittestSorted (&binaryInsertion, "binaryInsertion");
	
	
	coordinatSys sys1 {};
	sys1.startPosPix_ = {0, 0};
	sys1.finishPosPix_ = {400, 400};
	sys1.nullCoor_ = {10, 390};

	coordinatSys sys2 {};
	sys2.startPosPix_ = {0, 400};
	sys2.finishPosPix_ = {400, 800};
	sys2.nullCoor_ = {10, 790};

	

	coordinatSysConfig conf;
	sys1.config_ = conf;

	int arr[1000] = {};

	sys1.intepretK_.y = -0.1;
	sys1.intepretK_.x = 1;

	sys1.drawAxis ({10, 1});
	sys2.intepretK_.y = -0.1;
	sys2.intepretK_.x = 1;


	sys2.drawAxis ({10, 1});
	randomfill (arr, 1000);
	//drawPar (sys);
	//drawBubleEfficiency (arr, 1000, sys);
	drawEfficiency (arr, 1000, &bubleSort, sys1, sys2, TX_BLUE, 2);

	drawEfficiency (arr, 1000, &selectionSort, sys1, sys2, TX_RED, 1.5);

	drawEfficiency (arr, 1000, &simpleInsertion, sys1, sys2, TX_GREEN, 1.5);
	
	drawEfficiency (arr, 1000, &binaryInsertion, sys1, sys2, TX_ORANGE, 1.5);

	txSetFillColor (TX_LIGHTRED);
	txSetColor (TX_LIGHTRED);
	txTextOut (220, 340, "Ñîðòèðîâêà âûáîðîì");

	txSetFillColor (TX_LIGHTCYAN);
	txSetColor (TX_LIGHTCYAN);
	txTextOut (220, 355, "Ñîðòèðîâêà ïóçûðüêîì");

	txSetFillColor (TX_LIGHTGREEN);
	txSetColor (TX_LIGHTGREEN);
	txTextOut (180, 370, "Ñîðòèðîâêà ïðîñòûìè âñòàâêàìè");
	 

	
	//int arr [1] = {8}; 
	//_printArr (arr, 5);
	 //printf ("Bigger: %d", binarySearch (arr, 3, 41));
	//divideArr (arr, 1);
	//_printArr (arr, 5); 0:|021913|  1:|031876|  2:|022926|  3:|005946|  4:|016715|  5:|013711|  6:|000000|
	//unittestThreeFill ();
	/*
	int arr[7] = {21913, 31876, 22926, 5946, 16715, 13711, 0};
	divideArr (arr, 0, 6, 7);
	unittestDivided ();
	//printArr (arr, 7);
	*/
	
	//unittestDivided ();
	

	/*
	//int arr [1000];

	//drawEfficiency (arr, 1000, bubleSort, )
	//unittestSorted ();

	//txCreateWindow (800, 800);


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
	*/

	setConsoleColor (_GRAY_);

	return 0;

}

void unittestThreeFill ()
{
	int arr[3];
	for (int i = 0; i < 1000; i++)
	{
		randomfill (arr, 3);
		sort3 (arr);
		if (isSorted (arr, 3) != -1)
		{	
			printf ("ERror");
		}
	}
	arr[0] = 20;
	arr[1] = 0;
	arr[2] = 10;
	sort3 (arr);
	if (isSorted (arr, 3) != -1)
	{	
		printf ("ERror");
	}

	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 1;
	sort3 (arr);
	if (isSorted (arr, 3) != -1)
	{	
		printf ("ERror");
	}
	 

	unit3 (-1, 0, 1);
	unit3 (82, 2, 1);
	unit3 (82, -1, 22);
	unit3 (0, 100, 100);
	unit3 (0, 0, 0);
	unit3 (1, 2, 3);
}

void sort3 (int arr[])
{
	if (arr[0] > arr[2])
	{
		exchange (&arr[0], &arr[2]);
	}
	if (arr[0] > arr[1])   
	{
		exchange (&arr[0], &arr[1]);
	}
	else if (arr[1] > arr[2])
	{
		exchange (&arr[1], &arr[2]);
	}
}

void bitSort ()
{

}

void unittestDivided ()
{
	int arr[1000] = {};
	for (int i = 0; i < 1000; i++)
	{
		randomfill (arr, i);
		printf ("--------------------------------------------------------------------------\n");
		divideArr (arr, 0, i, i + 1);
		
		isSorted (arr, i);
	}
		
}

int isDivided (int arr[], int len, int midNum, int mid)
{
	for (int i = 0; i < mid; i++)
	{
		if (arr[i] > midNum)
		{
			return i;
		}
	}
	for (int i = mid + 1; i < len; i++)
	{
		if (arr[i] < midNum)
		{
			return i;
		}
	} 
	return -1;
}

void testDivide ()
{
	int arr[1000] = {};
	for (int i = 0; i < 1000; i++)
	{
		randomfill (arr, i);
		divideArr (arr, 0, i, i+1);
		
		//_printArr (arr, i);
	}
}

void printSort (int arr[], int len, int middNum, int left, int currMiddNumIndex, int right, const char *cause)
{
	//return;
	for(int i = 0; i < len; i++)
	{
		txSetConsoleAttr (FOREGROUND_LIGHTGRAY);
		if (i == left) txSetConsoleAttr (FOREGROUND_LIGHTCYAN);
		if (i == right) txSetConsoleAttr (FOREGROUND_LIGHTRED);
		if (i == currMiddNumIndex) txSetConsoleAttr (FOREGROUND_LIGHTGREEN);
		

		printf ("%3d:", i);
		printf("|%6d|", arr[i]);
	}
	txSetConsoleAttr (FOREGROUND_LIGHTGRAY);
	printf ("\t left: %d \t middNum: %d \t right: %d \t cause: %s", left, middNum, right, cause);
	printf ("\n\n");
	_getch ();
}

void divideArr (int arr[], int left, int right, int len)
{


	if (right - left + 1 <= 1) return;

	if (right - left + 1 == 2)
	{
		if (arr[left] > arr[right])
		{
			exchange (&arr[left], &arr[right]);
		}
		return;
	}
	
	if (right - left + 1 == 3)
	{
		sort3 (&arr[left]);
		return;
	}
	int mid = (right - left + 1)/2;
	const int midd = arr[len/2];
	const int saveLeft = left;
	const int saveRight = right;
	bool findChange = false;
	int copyArr[1000] = {};
	equal (copyArr, arr, len);
	//printSort (arr, len, midd, left, mid, right, "Before sort");

	//int row[1000] = {};


	for (int  i = left; i <= mid; i ++)
	{
		//$ (i, 7);
		//printSort (arr, len, midd, left, mid, right);
		findChange = false;
		if (arr[i] > midd)
		{
			for (int j = right; j >= mid;j--)
			{
				//$ (j, 7);
				if (arr[j] <= midd)
				{
					exchange (&arr[i], &arr[j]);
					findChange = true;
					break;
				}
			}
			//printSort (arr, len, midd, left, mid, right, "Not Ended first");

			if (findChange == false)
			{

				while (!findChange)
				{
					//$ (mid, 7);
					mid--;	
					if (arr[mid] <= midd)
					{
						exchange (&arr[i], &arr[mid]);
						findChange = true;
						break;
					}
					
					
				}

				//printSort (arr, len, midd, left, mid, right, "after first mid");
			}
		}
	}

	//printSort (arr, len, midd, left, mid, right, "AfterFirst");

	//mid= len/2;
	//midd = arr[len/2];
	left = saveLeft; 
	right = saveRight;
	findChange = false;

	for (int  i = right; i >= mid; i--)
	{
		//$ (i, 7);
		findChange = false;
		if (arr[i] <= midd)
		{
			for (int j = left; j <= mid; j++)
			{
				//$ (j, 7);
				if (arr[j] >= midd)
				{
					//$ (j, len);
					//$ (i, len);
 					exchange (&arr[i], &arr[j]);
					findChange = true;
					break;
				}
			}
			//printSort (arr, len, midd, left, mid, right);

			if (findChange == false)
			{

				while (!findChange)
				{

					mid++;
					
					//$ (mid, 7);

 					if (arr[mid] >= midd)
					{
						//$ (mid, len);
						exchange (&arr[i], &arr[mid]);
						findChange = true;
						break;
					}
					
					
				}
				//printSort (arr, len, midd, left, mid, right, "after second mid");
			}
		}
	}

	if (mid > 1)
	{
		if (arr[mid] < midd && arr[mid - 1] > midd)
		{
			exchange (&arr[mid], &arr[mid - 1]);
		}
	}
	//printSort (arr, len, midd, left, mid, right, "Final");

	/*
	int sort = isDivided (arr, len, midd, mid);
	if (sort != -1)
		{
			//printf (name);
			printf ("\nError at: %d\n", sort);
			printf ("Mid = %d\n", mid);
			//printSort (copyArr, len, midd, left, mid, right, "Before");
			//printSort (arr, len, midd, left, mid, right, "Final");
			//rintArr (arr, i);
			_getch ();
		
	}
	*/

	left = saveLeft; 
	right = saveRight;

	

	if (arr[mid] <= midd)
	{
		//printSort (arr, 7, midd, saveLeft, mid, saveRight, "Before Recursion");
		divideArr (arr, saveLeft, mid, mid);
		divideArr (arr, mid+1, saveRight, len - (mid - 1));
	}
	if (arr[mid] > midd)
	{
		//printSort (arr, 7, midd, saveLeft, mid, saveRight, "Before Recursion");
		divideArr (arr, saveLeft, mid - 1, mid+  1);
		divideArr (arr, mid, saveRight, len - (mid - left));
	}
}


void equal (int arr[], int arr2[], int len)
{
	for  (int i = 0; i < len; i++)
	{
		arr[i] = arr2[i];
	}
}

int ____TheVSTROeNNAYaFUnKZIjJaSKOKORAZRYADOVvV______	(double val)
{
	if (val == 0) return 0;
	return log10 (fabs (val));
}




void unittestSorted ()
{
	int arr[1000] = {};
	

	for (int i = 1; i <= 1000; i++)
	{	
		randomfill (arr, i);
		simpleInsertion (arr, i);
		int sort = isSorted (arr, i);
		if (sort != -1)
		{
			printf ("simpleInsertion\n");
			printf ("Error at: %d\n", sort);
			_printArr (arr, i);
			_getch ();
		}
	}

}

void unittestSorted (void (*func) (int arr[], int len), const char *name)
{
	int arr[1000] = {};
	

	for (int i = 1; i <= 1000; i++)
	{	
		randomfill (arr, i);
		func (arr, i);
		int sort = isSorted (arr, i);
		if (sort != -1)
		{
			printf (name);
			printf ("\nError at: %d\n", sort);
			printArr (arr, i);
			_getch ();
		}
	}
}


/*
2^0 = 1	 <==> log2 (1) = 0
2^1 = 2	 <==> log2 (2) = 1
2^2 = 4	 <==> log2 (4) = 2
2^3 = 8	 <==> log2 (8) = 3
2^4 = 16 <==> log2 (16) = 4
2^5 = 32 <==> log2 (32) = 5

10^0 = 1 <==> log10 (1) = 0
10^1 = 10 <==> log10 (10) = 1
10^2 = 100 <==> log10 (100) = 2
10^3 = 1000	<==> log10 (1000) = 3
10^4 = 10000 <==> log10 (10000) = 4
10^5 = 100000 <==> log10 (100000) = 5



 
*/


/*
* 
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
		!		  v	 *
1 10 13 37 86 97 425 23 321 213 41234 1233
*/



void simpleInsertion (int arr[], int len)
{
	//int arr [5] = {61, 40, 55 ,41, 31};
	for (int i = 0; i < len - 1; i++)
	{
		//int biggerNum = lessThen (arr, i)
		int biggerNum = lessThen (arr, i + 1, arr[i + 1]);

		rotateArr (arr, biggerNum, i + 1);
		/*
		Exchange++;
		int copyCurrNum = arr[i + 1];

		for (int j = i; j >= biggerNum; j--)
		{
			Exchange++;
			arr[j + 1] = arr[j];	
		}

		Exchange++;
		if (i + 1 < len)
			arr[i + 1] = copyCurrNum;
			*/
		
	}
	Exchange /= 3;
	//_printArr (arr, len);

}

void binaryInsertion (int arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int biggerNum = binarySearch (arr, i + 1, arr[i + 1]);

		rotateArr (arr, biggerNum, i + 1);
	}
	Exchange /= 3;
}

int binarySearch (int arr[], int len, int num)
{
	/*
	assert (0 <= len / (2 * 1) && len / (2 * 1) <= len);
	Comparision++;
	if (num < arr[len / (2)])
	{
		return binarySearch (arr, len / (2), num);	
	}
	Comparision++;
	if (num > arr[len / (2)])
	{
		return binarySearch (&arr[len / (2)], len / (2), num);
	}
	return 	len / (2);
	*/
	int left = 0; int right = len;	
	for (int i = 0; ; i ++)
	{
		Comparision++;
		if (abs (right - left) == 0 || right < left)
		{
			/*
			if (arr[left] < num)
			{
				return left;
			}
			*/
			return left;
		}
		int mid = (right + left) / (2);
		
		Comparision++;
		if (num <= arr[mid])
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return len;
}


void rotateArr (int arr[], int start, int finish)
{
	if (start - finish == 1) return;
	int copy = arr[finish];
	for (int i = finish - 1; i >= start; i--)
	{
		Exchange++;
		arr[i + 1] = arr[i];
	}
	//Exchange /= 3;
	Exchange++;
	arr[start] = copy; 
	
}

int lessThen (int arr[], int len, int num)
{
	for (int i = 0; i < len; i++)
	{
		Comparision++;
		if (num < arr[i])
		{
			//Exchange++;
			return i;
		}
	}
	return len +1;
}

void selectionSort (int arr[], int len)	 
{
	for (int i = len; i > 0; i--)
	{
		//int minIndex = findTheLess (&arr[i], len - i) +  i;
		//exchange (&arr[i], &arr[minIndex]);
		int maxIndex = findTheBiggest (arr, i);
		exchange (&arr[i - 1], &arr[maxIndex]);
	}
}


int findTheBiggest (int arr[], int len)
{
	int max = 0;
	for (int i = 0; i < len; i++)
	{
		Comparision++;
		if (arr[i] > arr[max])
		{
			max = i;
		}
	}

	return max;
}

int findTheLess (int arr[], int len)
{
	int min = 0;
	for (int i = 0; i < len; i++)
	{
		Comparision++;
		if (arr[i] < arr[min])
		{
			min = i;
		}
	}
	return min;
}




void drawEfficiency (int arr[], int len, void (*sortFunc) (int arr[], int len), coordinatSys sys1, coordinatSys sys2, COLORREF color, double r)
{
	

	assert (sortFunc);

	for (int i = 0; i < len; i++)
	{
		//const char  *texty = "sd";
		//const char  *textx = "sd";
		//sscanf (texty, "%d", (halfy + Comparision));
		//sscanf (textx, "%d", l);
		//txTextOut (halfx, (halfy + Comparision), texty);
		//txTextOut (l, halfy, texty);

		sortArr (sortFunc, arr, i, sys1, sys2, color, r);
		if (isSorted (arr, i) != -1)
		{
			printf ("i: %d\n", isSorted (arr, i));
			for (int n = 0; n < i; n++)
			{
				printf ("arr[%d]: %d\n", n, arr[n]);
			}
			_getch ();
		}

		
	}
}

void bubleSort (int arr[], const int len)
{
	for (int n = 0; n < len; n ++)
	{
		bool sorted = true;
		for (int j = 0; j < len - 1; j++)
		{
			Comparision++;
			if (arr[j] > arr[j + 1])
			{
				Exchange++;
				int copy = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = copy;
				sorted = false;
			}
		}
		//if  (sorted == true) break;
	}
}

int isSorted (int arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		if (arr[i] > arr[i + 1]) return i;
	}
	return -1;
}


void sortArr (void (*comparisionFunc1) (int arr[], int len), int arr[], int len, coordinatSys sys1, coordinatSys sys2, COLORREF color, double r)
{
	randomfill (arr, len);

	Comparision = 0;
	Exchange = 0;
	comparisionFunc1 (arr, len);

	txSetFillColor (color);
	txSetColor (color); 
	sys1.drawCircle ({(double) len, (double) Comparision}, r);
	txSetFillColor (color);
	txSetColor (color);
	sys2.drawCircle ({(double) len, (double) Exchange}, r);
}


void drawBubleEfficiency (int arr[], int len, coordinatSys sys)
{
	//int halfx = (sys.x1 + sys.x2) / 2;
	//int halfy = (sys.y1 + sys.y2) / 2;
	//txLine (halfx,  sys.y2, halfx, sys.y1);
	//txLine (sys.x1, halfy, sys.x2, halfy);
	sys.intepretK_.y = -0.1;

	sys.drawAxis ({10, 1});

	for (int l = 0; l < len; l++)
	{
		//const char  *texty = "sd";
		//const char  *textx = "sd";
		//sscanf (texty, "%d", (halfy + Comparision));
		//sscanf (textx, "%d", l);
		//txTextOut (halfx, (halfy + Comparision), texty);
		//txTextOut (l, halfy, texty);

		randomfill (arr, l);
		Comparision = 0;
		Exchange = 0;
		bubleSort (arr, l);
		txSetFillColor (TX_RED);
		txSetColor (TX_RED);
		sys.drawCircle ({(double) l, (double) Comparision}, 1.5);
		txSetFillColor (TX_BLUE);
		txSetColor (TX_BLUE);
		sys.drawCircle ({(double) l, (double) Exchange}, 1.5);

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
		txSetFillColor (TX_RED);
		txSetColor (TX_RED);
		sys.drawCircle ({x, f}, 1.4);
		sys.drawCircle ({-x, f}, 1.4);
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







void exchange (int *n1, int *n2)
{
	Exchange++;
	int copy = *n1;
	*n1 = *n2;
	*n2 = copy;
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
//!	@brief Óñòàíàâëèâàåò öâåò, êîòîðûé âû ïîæåëàåòå
//!
//!	@param color Öâåò òèïà Word
//!
//! @return ÍÈ×ÅÃÎ è íå íàäî:)
//! @note Äëÿ íåãî ïîäõîäèò ïðîñòðàíñòâî èìåí öâåòîâ Colors
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
//$(i)
		arr[i] = 3 - i % 3;
	}

	for (int i = 0; i < length; i += 3)
	{
		copy = arr[i];

		if (i + 2 < length)
		{
//$(i)
//$(i + 2)
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
	printf ("START\n");

	for (int i = 0; i < length; i++)
	{
		printf ("%d: %d\n", i, arr[i]);
	}

	printf ("FINISH\n");

}

void _printArr (int arr[], const int length, PositionInfo info, const int mode)
{
	if (mode & _COLOR_)	// BBBBFFFF
	{					// irgbirgb
		//setConsoleColor (0b10110101);

		setConsoleColor (_CYAN_);
	}

	if (mode & _HORIZONTAL_)
	{
		//printf ("%s = [ ", in);
		for (int i = 0; i < length; i++)
		{
			setConsoleColor (_CYAN_);
			printf ("[%d] = ",  i);

			setConsoleColor (_LIGHTCYAN_);
			printf ("%d", arr[i]);

			setConsoleColor (_CYAN_);
			printf ("%s", (i != length - 1)? ", " : " ");
		}
		//printf ("]\n");

	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			printf ("%d: %d\n", i, arr[i]);
		}
	}

	info.dump ();

}
 


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
