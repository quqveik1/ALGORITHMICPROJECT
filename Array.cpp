
#pragma once
#include "Structure.cpp"
#include "TXLib.h"
#include <stdio.h>
#include "Lib\Q_Locale.h"
#include <conio.h>
#include "math.h"
#include "Q_CoordinatSystem.h"
#include "$a.cpp"


#define unittestSedgewick(parts, len) {int arr[] = parts; divideArr (arr, 0, len - 1);}


struct MYINT 
{
	int num = 0;
	static int Comparision;
	static int Exchange;

	MYINT& operator = (MYINT a2);
	MYINT& operator = (int a2);
};

MYINT& MYINT::operator = (int a2)
{
	num = a2;
	Exchange++;
	return *this;
}

MYINT& MYINT::operator = (MYINT a2)
{
	num = a2.num;
	Exchange++;
	return *this;
}

// a = b
// set (a, b);
// this 
// a.set(b)
// 
//


bool operator > (const MYINT &a1, const MYINT &a2);
bool operator >= (const MYINT &a1, const MYINT &a2);
bool operator < (const MYINT &a1, const MYINT &a2);
bool operator <= (const MYINT &a1, const MYINT &a2);
bool operator == (const MYINT &a1, const MYINT &a2);
bool operator != (const MYINT &a1, const MYINT &a2);

bool operator > (const MYINT &a1, const int &a2);
bool operator >= (const MYINT &a1, const int &a2);
bool operator < (const MYINT &a1, const int &a2);
bool operator <= (const MYINT &a1, const int &a2);
bool operator == (const MYINT &a1, const int &a2);
bool operator != (const MYINT &a1, const int &a2);

bool operator > (const int &a1, const MYINT &a2);
bool operator >= (const int &a1, const MYINT &a2);
bool operator < (const int &a1, const MYINT &a2);
bool operator <= (const int &a1, const MYINT &a2);
bool operator == (const int &a1, const MYINT &a2);
bool operator != (const int &a1, const MYINT &a2);

bool operator != (const MYINT &a1, const MYINT &a2)
{
	a1.Comparision++;
	if (a1.num != a2.num)
	{
		return true;
	}
	return false;
}

bool operator == (const MYINT &a1, const MYINT &a2)
{
	a1.Comparision++;
	if (a1.num == a2.num)
	{
		return true;
	}
	return false;
}

bool operator > (const int &a1, const MYINT &a2)
{
	a2.Comparision++;
	if (a1 > a2.num)
	{
		return true;
	}
	return false;
}

bool operator >= (const int &a1, const MYINT &a2)
{
	a2.Comparision++;
	if (a1 >= a2.num)
	{
		return true;
	}
	return false;
}

bool operator < (const int &a1, const MYINT &a2)
{
	a2.Comparision++;
	if (a1 < a2.num)
	{
		return true;
	}
	return false;
}

bool operator <= (const int &a1, const MYINT &a2)
{
	a2.Comparision++;
	if (a1 <= a2.num)
	{
		return true;
	}
	return false;
}

bool operator != (const int &a1, const MYINT &a2)
{
	a2.Comparision++;
	if (a1 != a2)
	{
		return true;
	}
	return false;
}

bool operator == (const int &a1, const MYINT &a2)
{
	a2.Comparision++;
	if (a1 == a2)
	{
		return true;
	}
	return false;
}

bool operator > (const MYINT &a1, const int &a2)
{
	a1.Comparision++;
	if (a1.num > a2)
	{
		return true;
	}
	return false;
}

bool operator >= (const MYINT &a1, const int &a2)
{
	a1.Comparision++;
	if (a1.num >= a2)
	{
		return true;
	}
	return false;
}

bool operator < (const MYINT &a1, const int &a2)
{
	a1.Comparision++;
	if (a1.num < a2)
	{
		return true;
	}
	return false;
}

bool operator <= (const MYINT &a1, const int &a2)
{
	a1.Comparision++;
	if (a1.num <= a2)
	{
		return true;
	}
	return false;
}


bool operator != (const MYINT &a1, const int &a2)
{
	a1.Comparision++;
	if (a1.num != a2)
	{
		return true;
	}
	return false;
}

bool operator == (const MYINT &a1, const int &a2)
{
	a1.Comparision++;
	if (a1.num == a2)
	{
		return true;
	}
	return false;
}

bool operator > (const MYINT &a1, const MYINT &a2)
{
	a1.Comparision++;
	if (a1.num > a2.num)
	{
		return true;
	}
	return false;
}

bool operator >= (const MYINT &a1, const MYINT &a2)
{
	a1.Comparision++;
	if (a1.num >= a2.num)
	{
		return true;
	}
	return false;
}

bool operator < (const MYINT &a1, const MYINT &a2)
{
	a1.Comparision++;
	if (a1.num < a2.num)
	{
		return true;
	}
	return false;
}

bool operator <= (const MYINT &a1, const MYINT &a2)
{
	a1.Comparision++;
	if (a1.num <= a2.num)
	{
		return true;
	}
	return false;
}



int MYINT::Comparision = 0;
int MYINT::Exchange = 0;







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
void _printArr (MYINT arr[], const int length);
void _printArr (MYINT arr[], const int length, PositionInfo info, const int mode);
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


void bubleSort (MYINT arr[], const int len);
void drawPar (coordinatSys sys);
void randomfill (int arr[], int len);
void randomfill (MYINT arr[], int len);
void drawBubleEfficiency (int arr[], int len, coordinatSys sys);
void drawEfficiency (MYINT arr[], int len, void (*sortFunc) (MYINT arr[], int len), coordinatSys sys1, coordinatSys sys2, COLORREF color, double r);
int findTheLess (int arr[], int len);
void exchange (MYINT &n1, MYINT &n2);
void exchange (int *n1, int *n2);
void selectionSort (MYINT arr[], int len);
int lessThen (MYINT arr[], int len, int num);
void simpleInsertion (MYINT arr[], int len);

void sortArr (void (*comparisionFunc1) (MYINT arr[], int len), MYINT arr[], int len, coordinatSys sys1, coordinatSys sys2, COLORREF color, double r = 1.5);
int isSorted (int arr[], int len);
int isSorted (MYINT arr[], int len);
int findTheBiggest (MYINT arr[], int len);
int binarySearch (MYINT arr[], int len, int num);
void binaryInsertion (MYINT arr[], int len);

void sedgewickSort (MYINT arr[], int len);
//void divideArr (int arr[], int left, int right);
void divideArr (MYINT arr[], int left, int right);

void printSort (MYINT arr[], int len, int middNum, int left, int currMiddNumIndex, int right, const char *cause = "");
void printSort (int arr[], int len, int middNum, int left, int currMiddNumIndex, int right, const char *cause = "");
void testDivide ();
void unittestDivided ();
void equal (MYINT arr[], MYINT arr2[], int len);
void equal (int arr[], int arr2[], int len);
void unittestThreeFill ();
void sort3 (MYINT arr[]);
void sort3 (int arr[]);

void mergeSort (MYINT arr[], int left, int right, MYINT arrNew[]);
void mergeSort (MYINT arr[], int len);
void oldMergeSort (MYINT arr[], int len);

void mergeSortNew (MYINT arr[], int len);
void testMerge (MYINT arr[], int left, int right);
void testMerge ();

void merge2 (MYINT arr[], int left, const int SecondStart, int right, MYINT newArr[]);
void merge (MYINT arr[], int left, int right, MYINT newArr[]);
void merge (int arr[], int left, int right, int arrNew[]);
void unittestMergeSort ();

void quickSort (MYINT arr[], int len);
void quickSort (MYINT arr[], const int left, const int right);

void rotateArr (MYINT arr[], int start, int finish);

void unittestSorted ();
void unittestSorted (void (*func) (MYINT arr[], int len), const char *name);


//! @brief Ìàêðîñ äëÿ òîãî, ÷òîáû áûëî óäîáíî ïåðåäàâàòü äàííûå íà ñ÷åò ðàñïå÷àòêè
#define POSINFO {__FILE__, __LINE__, __FUNCSIG__}
#define NAMEINFO
//! @brief Ìàêðîñ äëÿ òîãî, ÷òîáû ðàñïå÷àòûâàòü íåêèå ïåðåìåííûå
#define printArr(name, length, ...) _printArr (name, length, POSINFO, ##__VA_ARGS__);
#define unittestMerge(size, num1, num2, ...)			\
{												\
	MYINT arr[] = {num1, num2, ##__VA_ARGS__};	\
	mergeSortNew (arr, size);		\
	if (isSorted (arr, size) != -1)				\
	{											\
		printf ("Error\n");						\
		_printArr (arr, size);						\
	}											\
}
//#define printArr(arr,)

#define $(x, length) 								\
{													\
	if (! (0 <= (x) && (x) < length))				\
	{												\
		printf ("ASSERT CRASHED: %s: %d, len = %d",  #x, x, length);	\
	}												\
	assert (0 <= (x) && (x) < length);				\
}													

#define unit3(a, b, c) {int arr[3] = {a, b, c}; \
	sort3 (arr);								  \
	if (isSorted (arr, 3) != -1)				  \
	{											  \
		printf ("ERror");						  \
	}}											  \

int main (int argc, const char *argv[])
{
	
	setRussianLocale ();
	txCreateWindow (1000, 800);

	txSetTextAlign (TA_RIGHT);

<<<<<<< HEAD
=======

	 //humanRound (3.14);
	 //humanRound (16.14);
	 //humanRound (0.14);
	 //humanRound (1);
	
	txCreateWindow (400, 800);
	unittestSorted (&simpleInsertion, "simpleInsertion");
	unittestSorted (&bubleSort, "bubleSort");
	unittestSorted (&selectionSort, "selectionSort");
	unittestSorted (&binaryInsertion, "binaryInsertion");
	
	
>>>>>>> e44b73ce0f65be32a0dba8caedb1db33badf75f5
	coordinatSys sys1 {};
	sys1.startPosPix_ = {0, 0};
	sys1.finishPosPix_ = {1000, 400};
	sys1.nullCoor_ = {40, 380};

	coordinatSys sys2 {};
	sys2.startPosPix_ = {0, 400};
	sys2.finishPosPix_ = {1000, 800};
	sys2.nullCoor_ = {40, 780};

	

	coordinatSysConfig conf;
	sys1.config_ = conf;

	

	sys1.intepretK_.y = -0.1;
	sys1.intepretK_.x = 1;

	sys1.drawAxis ({10, 1});
	sys2.intepretK_.y = -0.1;
	sys2.intepretK_.x = 1;


	sys2.drawAxis ({10, 1});

	int textStartPosLeft = txGetExtentX () - 5;

	txSetFillColor (TX_BLACK);
	txSetColor (TX_BLACK);
	txTextOut (textStartPosLeft, 10, "���������");
	txTextOut (textStartPosLeft, 410, "������");

	txSetFillColor (TX_RED);
	txSetColor (TX_RED);
	txTextOut (textStartPosLeft, 270, "���������� �������");

	txSetFillColor (TX_BLUE);
	txSetColor (TX_BLUE);
	txTextOut (textStartPosLeft, 285, "���������� ���������");

	txSetFillColor (TX_GREEN);
	txSetColor (TX_GREEN);
	txTextOut (textStartPosLeft, 300, "���������� �������� ���������");

	txSetFillColor (TX_ORANGE);
	txSetColor (TX_ORANGE);
	txTextOut (textStartPosLeft, 315, "���������� ��������� ���������");

	txSetFillColor (TX_CYAN);
	txSetColor (TX_CYAN);
	txTextOut (textStartPosLeft, 330, "������� ����������");

	txSetFillColor (TX_PINK);
	txSetColor (TX_PINK);
	txTextOut (textStartPosLeft, 345, "���������� �������� �����������");

	txSetFillColor (TX_BLACK);
	txSetColor (TX_BLACK);
	txTextOut (textStartPosLeft, 360, "���������� �������� �����������");

	MYINT arr[1000] = {};

	

	
	randomfill (arr, 1000);
	drawEfficiency (arr, 1000, &bubleSort, sys1, sys2, TX_BLUE, 2);

	drawEfficiency (arr, 1000, &selectionSort, sys1, sys2, TX_RED, 1.5);

	drawEfficiency (arr, 1000, &simpleInsertion, sys1, sys2, TX_GREEN, 1.5);
	
	drawEfficiency (arr, 1000, &binaryInsertion, sys1, sys2, TX_ORANGE, 1.5);
<<<<<<< HEAD
	
	drawEfficiency (arr, 1000, &quickSort, sys1, sys2, TX_CYAN, 1.5); 
	drawEfficiency (arr, 1000, &oldMergeSort, sys1, sys2, TX_PINK, 1.5);
	drawEfficiency (arr, 1000, &mergeSortNew, sys1, sys2, TX_BLACK, 1.5);

=======

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
>>>>>>> e44b73ce0f65be32a0dba8caedb1db33badf75f5

	setConsoleColor (_GRAY_);

	return 0;

}

void oldMergeSort (MYINT arr[], int len)
{
	MYINT *arrn  = new MYINT [len];
	mergeSort (arr, 0 ,len - 1, arrn);
	delete[] arrn;
}

void merge2 (MYINT arr[], int left, const int SecondStart, int right, MYINT newArr[])
{
	int len = right - left + 1;
	int secondStart = SecondStart;
	int lastIndexArr = left;
	int lastI = 0;

	for (int i = left; i < SecondStart; i++)
	{
		if (secondStart >= len)
		{
			lastI = i;
			break;
		}
		if (arr[i] < arr[secondStart])
		{
			newArr[lastIndexArr] = arr[i];
			lastIndexArr++;
			continue;
		}
		else
		{
			newArr[lastIndexArr] = arr[secondStart];	
			lastIndexArr++;
			secondStart++;
			i--;
			continue;
		}
	}

	if (secondStart >= len)
	{
		for (int i = lastI; i < SecondStart; i++)
		{
			newArr[lastIndexArr] = arr[i];
			lastIndexArr;
		}
	}
	if (secondStart < len)
	{
		for (int i = secondStart; i <= right; i++)
		{
			newArr[lastIndexArr] = arr[i];
			lastIndexArr;
		}
	}

	for (int i = left; i <= right; i ++)
	{
		arr[i] = newArr[i];	
	}
}

/*
void mergeSort (MYINT arr[], int left, int right)
{
	MYINT na[1000] = {};
	int len = right - left + 1;
	int trueLen = len - (len % 3);


	if (1 >= len)
	{
		return;
	}

	if (len == 2)
	{
		//$ (left, Size);
		//$ (right, Size);
		if (arr[left] > arr[right])
		{
			exchange (arr[left], arr[right]);
		}
		return;
	}
	
	if (len == 3)
	{
		//$ (left, Size);
		//$ (right, Size);
		sort3 (&arr[left]);
		return;
	}
	int degree = log2 ((trueLen / 3));

	for (int i = 0; i <= degree; i++)
	{
		int delta = 3 * pow (2, i);
		if (delta == 3)
		{
			for (int j = left; j < trueLen; j+= 3)
			{
				sort3 (&arr[j]);
			}
			
			continue;
		}

		for (int j = left; j < trueLen; j += delta)
		{
			merge2 (arr, j, (delta + 1) / 2, j + delta, na);
		}


		
	}
	if (trueLen != 3 * pow (2, degree))
	{
		merge2 (arr, left, 3 * pow (2, degree), trueLen, na);	
	}
	if (len - trueLen == 2)
	{
		//$ (left, Size);
		//$ (right, Size);
		if (arr[left] > arr[right])
		{
			exchange (arr[left], arr[right]);
		}
		return;
	}
	
	if (len - trueLen == 3)
	{
		//$ (left, Size);
		//$ (right, Size);
		sort3 (&arr[left]);
		return;
	}


	if (trueLen != len)
	{
		merge2 (arr, left, trueLen, right, na);	
	}

}
*/

void quickSort (MYINT arr[], int len)
{
	//_printArr (arr, len);
	quickSort (arr, 0, len - 1);	
}

void quickSort (MYINT arr[], const int left, const int right)
{
	int len = (right - left) + 1;
	int currLeft = left;
	int currRight = right;
	int midIndex = (right + left) / 2; 
	int midNum = arr[midIndex].num;
	//printSort (arr, len, midNum, currLeft, midIndex, currRight, "Before");

	if (1 >= len)
	{
		return;
	}

	if (len == 2)
	{
		//$ (left, Size);
		//$ (right, Size);
		if (arr[left] > arr[right])
		{
			exchange (arr[left], arr[right]);
		}
		return;
	}
	
	if (len == 3)
	{
		//$ (left, Size);
		//$ (right, Size);
		sort3 (&arr[left]);
		return;
	}
	

	for (;;)
	{
		if (currRight  - currLeft <= 0) break;
		if (arr[currLeft] >= midNum)
		{
			while (midNum < arr[currRight])
			{
				if (currRight  - currLeft <= 0) break;
				currRight--;	
				
			}
			exchange (arr[currLeft], arr[currRight]);
			currLeft++;
			currRight--;
			continue;
		}
		currLeft++;
	}
	//printSort (arr, len, midNum, currLeft, midIndex, currRight, "After");
	if (arr[currRight] > midNum)
	{
		quickSort (arr, left, currRight - 1);
		quickSort (arr, currRight, right);
	}
	else
	{
		quickSort (arr, left, currRight);
		quickSort (arr, currRight + 1, right);
	}
	
}

void unittestMergeSort ()
{
	int arr[1000];
	for (int i = 1; i <= 1000; i++)
	{
		randomfill (arr, i);
		int *newArr = new int[i];
		//mergeSort (arr, 0, i - 1, newArr);
		if (isSorted (arr, i) != -1)
		{
			_printArr(arr, i);
			_getch ();
		}
		//printf ("%d", i);
	}
}

void mergeSort (MYINT arr[], int len)
{
	//mergeSort (arr, 0, len - 1);
}

void merge (MYINT arr[], int left, int SecondStart, int right, MYINT newArr[])
{
	int secondStart = SecondStart;
    const int len = right - left + 1;
	int lastI = 0;
	int lastIndexArr = left;
	if (len == 8)
	{
		;
		//DebugBreak ();
	}
	assert (left >= 0);
	//assert (lastIndexArr < len);

	for (int i = left; lastIndexArr <= right;)
	{
		if (i >= SecondStart)
		{
			newArr[lastIndexArr++] = arr[secondStart++];	
			continue;
		}
		if (secondStart > right)
		{
			newArr[lastIndexArr++] = arr[i++];
			continue;
		}
	
		if (arr[i] > arr[secondStart]) newArr[lastIndexArr++] = arr[secondStart++];
		else newArr[lastIndexArr++] = arr[i++];
	}
	/*
	for (int i = left; i < SecondStart; i++)
	{
		if (secondStart >= len)
		{
			lastI = i;
			break;
		}
		if (arr[i] < arr[secondStart])
		{
			newArr[$a (lastIndexArr, right + 1)] = arr[i];
			lastIndexArr++;
			continue;
		}
		else
		{
			newArr[$a (lastIndexArr, right + 1)] = arr[$a (secondStart, right + 1)];	
			lastIndexArr++;
			secondStart++;
			i--;
			continue;
		}
	}

	if (secondStart >= len)
	{
		for (int i = lastI; i < SecondStart; i++)
		{
			newArr[lastIndexArr] = arr[i];
			lastIndexArr;
		}
	}
	if (secondStart < len)
	{
		for (int i = secondStart; i <= right; i++)
		{
			newArr[lastIndexArr] = arr[i];
			lastIndexArr;
		}
	}
	*/
	//printf ("Newarr, right: %d\n", right);
	//_printArr (&newArr[left], len);

	/*
	for (int i = left; i <= right; i ++)
	{
		arr[i] = newArr[i];	
	}
	*/
}


void testMerge (MYINT arr[], int left, int right)
{
	if (isSorted (&arr[left], right - left  + 1) != -1)
	{
		printf ("Merge error\n");
		_printArr (arr, right - left + 1);
	}
}

void testMerge ()
{
	unittestMerge (3, 0, 0, 1);
	unittestMerge (4, 0, 0, 0, 0);
	unittestMerge (4, -1, -1, -1, -1);
	unittestMerge (4, -1, 0, -1, -1);
	unittestMerge (4, 999, 999, 999, 999);
	unittestSorted (mergeSortNew, "Merge");
}




void mergeSortNew (MYINT arr[], int len)
{
	MYINT *newArr = new MYINT [len];
	MYINT *sourceptr = {};
	MYINT *copyptr = {};
	/*
	for (int i = 0; i < len; i +=2)
	{
		//if (i >= len)
		if (arr[$a (i, len)] > arr[i + 1, len] && i + 1 < len)
		{								 
			newArr[$a (i, len)] = arr[$a (i + 1, len)];
			newArr[$a (i + 1, len)] = arr[$a (i, len)];
		}
		else
		{
			newArr[$a (i, len)] = arr[$a (i, len)];
			if (i + 1 < len)
			{
				newArr[$a (i + 1, len)] = arr[$a (i + 1, len)];
			}
		}
	}
	*/
	for (int i = 0; i < len; i +=2)
	{
		if (i+ 1 < len)
		{
			if (arr[i] > arr[i + 1])
			{
				exchange (arr[i], arr[i + 1]);
			}
		}
	}
	
	//printf ("\n\nNew m\n");
	//_printArr (arr, len);
	if (len == 3) sort3(arr);

	
	int lastI = 0;

	for (int size = 2; size <= len /2; size *= 2)
	{
		{
			$s
			txSetConsoleAttr (TX_RED);
		}

		//printf ("\nSize: %d\n", size);
		lastI = 0;
		bool finalMerge = false;
		for (int i = 0; i < len; i += 2 * size)
		{
			lastI = i;
			if (i % 2 == 0)
			{
				sourceptr = arr;
				copyptr = newArr;
			}
			else
			{
				sourceptr = newArr;
				copyptr = arr;
			}

			if (i + 2 * size > len)
			{	
				/*
				if (i + size >= len)
				{
					printf ("Final Merge||secondStart: %d\n", i);
					_printArr (arr, len);
					merge (arr, i, i + (size - size / 2) - 1, len - 1, newArr);
					printf ("Final Merge after||secondStart: %d\n", i);
					_printArr (arr, len);
					finalMerge = true;
					break;
				}
				printf ("Region Merge||secondStart: %d\n", i  + size);
				_printArr (arr, len);
				merge (arr, i, i + size, len - 1, newArr);	
				printf ("Region Merge after||secondStart: %d\n", i  + size);
				_printArr (arr, len);
				*/

				
				//printf ("Final Merge||i: %d\n", i);
				//_printArr (arr, len);
				merge (arr, i, i + size, len - 1, newArr);
				merge (arr, i - size * 2, i, len - 1, newArr);
				//printf ("Final Merge after||i: %d\n", i);
				//_printArr (arr, len);
				
			}
			else
			{
				merge (arr, i, i + size, i + 2 * size - 1, newArr);
				//testMerge (arr, i,  i + 2 * size - 1);
			}
			//merge (arr, i, i + size, i + 2 * size, newArr);	
		}

	}

	if (lastI % 2 == 0)
	{
		equal (newArr, arr, len);
	}

	//if (len = 200) _printArr (arr, len);
	//if (len == 999) _printArr (arr, len);

	
	//printf ("\n\nFinal m\n");
	//_printArr (arr, len);
	
	


}
 
void mergeSort (MYINT arr[], int left, int right,  MYINT arrNew[])
{
	
	if (left == right) return;
	if (left < right && right > 0);
	{
		//printf ("left: %d; right: %d, cause: %s\n", left, right, cause);
		//_getch ();
		//sprintf (newCause, "PreLeft: %d PreRight: %d", left, right);

		if (right - left > 1)
		{
			mergeSort (arr, left, (left + right) / 2, arrNew);
			mergeSort (arr, (left + right) / 2, right, arrNew);
		}
		merge (arr, left, right, arrNew);
	}
}

void mergeSort (int arr[], int left, int right, int arrNew[])
{
	
	if (left == right) return;
	if (left < right && right > 0);
	{
		//printf ("left: %d; right: %d, cause: %s\n", left, right, cause);
		//_getch ();
		//sprintf (newCause, "PreLeft: %d PreRight: %d", left, right);

		if (right - left > 1)
		{
			mergeSort (arr, left, (left + right) / 2, arrNew);
			mergeSort (arr, (left + right) / 2, right, arrNew);
		}
		merge (arr, left, right, arrNew);
	}
}

void merge (MYINT arr[], int left, int right, MYINT newArr[])
{
	/*
	if (left == right)
	{
		return;
	}
	if (right - left == 1)
	{
		if (arr[left] > arr[right])
		{
			exchange (&arr[left], &arr[right]);
			return;
		}
	}
	if (right - left == 2)
	{
		sort3 (&arr[left]);
		return;
	}


	int *newArr = new int [right - left + 1];
	int secondMStart = (right - left) / 2 + 1;
	int newArrLast = 0;
	int firstMStart = left;
	//printArr (arr, 6);

	for (int i = 0; i < right - left + 1; i++)
	{
		if (arr[firstMStart] > arr[secondMStart])
		{
			newArr[i] = arr[secondMStart];
			secondMStart++;

		}
		else
		{
			newArr[i] = arr[firstMStart];
			firstMStart++;
		}
		if (firstMStart >= (right - left) / 2 + 1)
		{
			for (int j = secondMStart; j <= right; j++)
			{
				newArr[i + j - secondMStart] = arr[j];
			}
			break;
		}
		if (secondMStart >= right)
		{
			for (int j = firstMStart; j <= (right - left) / 2 + 1; j++)
			{
				newArr[i + j - firstMStart] = arr[j];
			}
			break;
		}
	}
	printf ("newArr");
	printArr (newArr, right - left + 1);
	equal (&arr[left], newArr, right - left + 1);
	*/
	int middle = (left + right) / 2;  
	int start = left;                
	int secondStart = middle + 1;           
	for (int i = left; i <= right; i++) 
	{
		/*
		if ((secondStart > right) &&(start <= middle))
		{
			mas[j] = arr[start];
			start++;
			continue;
		}

		
		if (start >= middle)  
		{
			mas[j] = arr[secondStart];
			secondStart++;
			continue;
		}
		*/
		if (start > middle)
		{
			newArr[i] = arr[secondStart];
			secondStart++;
			continue;
		}
		if (secondStart > right)
		{
			newArr[i] = arr[start];
			start++;
			continue;
		}

		if ((arr[start] < arr[secondStart]))
		{
			newArr[i] = arr[start];
			start++;
		}
		else
		{
			newArr[i] = arr[secondStart];
			secondStart++;
		}

		
	}
	for (int i = left; i <= right; i++)  
	{

		arr[i] = newArr[i];
	}


	/*
	int *newM = new int [right - left + 1];
	int secondStart = (right + left)/2 + 1;
	for (int i = left; i <= (right + left)/2 + 1; i++)
	{ 
		if (secondStart >= right - left + 1) break;
		$ (i, 6);
		$ (secondStart, 6);
		$ (i, right - left + 1);
		$ (secondStart, right - left + 1);
		
		if (arr[i] < arr[secondStart])
		{
			newM[i] = arr[i];
		}
		else 
		{
			newM[i] = arr[secondStart];
			
			secondStart++;
		}
	}

	equal (&arr[left], newM, right - left + 1);

	delete[] (newM);
	*/


	
	//bubleSort (&arr[left], right - left + 1);
}

void merge (int arr[], int left, int right, int newArr[])
{
	/*
	if (left == right)
	{
		return;
	}
	if (right - left == 1)
	{
		if (arr[left] > arr[right])
		{
			exchange (&arr[left], &arr[right]);
			return;
		}
	}
	if (right - left == 2)
	{
		sort3 (&arr[left]);
		return;
	}


	int *newArr = new int [right - left + 1];
	int secondMStart = (right - left) / 2 + 1;
	int newArrLast = 0;
	int firstMStart = left;
	//printArr (arr, 6);

	for (int i = 0; i < right - left + 1; i++)
	{
		if (arr[firstMStart] > arr[secondMStart])
		{
			newArr[i] = arr[secondMStart];
			secondMStart++;

		}
		else
		{
			newArr[i] = arr[firstMStart];
			firstMStart++;
		}
		if (firstMStart >= (right - left) / 2 + 1)
		{
			for (int j = secondMStart; j <= right; j++)
			{
				newArr[i + j - secondMStart] = arr[j];
			}
			break;
		}
		if (secondMStart >= right)
		{
			for (int j = firstMStart; j <= (right - left) / 2 + 1; j++)
			{
				newArr[i + j - firstMStart] = arr[j];
			}
			break;
		}
	}
	printf ("newArr");
	printArr (newArr, right - left + 1);
	equal (&arr[left], newArr, right - left + 1);
	*/
	int middle = (left + right) / 2;  
	int start = left;                
	int secondStart = middle + 1;           
	for (int i = left; i <= right; i++) 
	{
		/*
		if ((secondStart > right) &&(start <= middle))
		{
			mas[j] = arr[start];
			start++;
			continue;
		}

		
		if (start >= middle)  
		{
			mas[j] = arr[secondStart];
			secondStart++;
			continue;
		}
		*/
		if (start > middle)
		{
			newArr[i] = arr[secondStart];
			secondStart++;
			continue;
		}
		if (secondStart > right)
		{
			newArr[i] = arr[start];
			start++;
			continue;
		}

		if ((arr[start] < arr[secondStart]))
		{
			newArr[i] = arr[start];
			start++;
		}
		else
		{
			newArr[i] = arr[secondStart];
			secondStart++;
		}

		
	}
	for (int i = left; i <= right; i++)  
	{
		arr[i] = newArr[i];
	}


	/*
	int *newM = new int [right - left + 1];
	int secondStart = (right + left)/2 + 1;
	for (int i = left; i <= (right + left)/2 + 1; i++)
	{ 
		if (secondStart >= right - left + 1) break;
		$ (i, 6);
		$ (secondStart, 6);
		$ (i, right - left + 1);
		$ (secondStart, right - left + 1);
		
		if (arr[i] < arr[secondStart])
		{
			newM[i] = arr[i];
		}
		else 
		{
			newM[i] = arr[secondStart];
			
			secondStart++;
		}
	}

	equal (&arr[left], newM, right - left + 1);

	delete[] (newM);
	*/


	
	//bubleSort (&arr[left], right - left + 1);
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

void sort3 (MYINT arr[])
{
	if (arr[0] > arr[2])
	{
		exchange (arr[0], arr[2]);
	}
	if (arr[0] > arr[1])   
	{
		exchange (arr[0], arr[1]);
	}
	else if (arr[1] > arr[2])
	{
		exchange (arr[1], arr[2]);
	}
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
	
	for (int i = 0; i < 1000; i++)
	{
		int arr[1000] = {};
		randomfill (arr, i + 1);
		//printf ("--------------------------------------------------------------------------\n");
		//Size = i + 1;
		//divideArr (arr, 0, i);
		//printArr (arr, i);
		
		isSorted (arr, i);
	}
	int arr[] = {1, 1, 1, 1, 1};
		
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
		//divideArr (arr, 0, i);
		
		//_printArr (arr, i);
	}
}

void printSort (MYINT arr[], int len, int middNum, int left, int currMiddNumIndex, int right, const char *cause)
{
	//return;
	for(int i = 0; i < len; i++)
	{
		txSetConsoleAttr (FOREGROUND_LIGHTGRAY);
		if (i == left) txSetConsoleAttr (FOREGROUND_LIGHTCYAN);
		if (i == right) txSetConsoleAttr (FOREGROUND_LIGHTRED);
		if (i == currMiddNumIndex) txSetConsoleAttr (FOREGROUND_LIGHTGREEN);
		

		printf ("%3d:", i);
		printf("|%6d|", arr[i].num);
	}
	txSetConsoleAttr (FOREGROUND_LIGHTGRAY);
	printf ("\t left: %d \t middNum: %d \t right: %d \t cause: %s", left, middNum, right, cause);
	printf ("\n\n");
	_getch ();
}

void printSort (int arr[], int len, int middNum, int left, int currMiddNumIndex, int right, const char *cause)
{
	//return;
	for(int i = left; i <= right; i++)
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

void sedgewickSort (MYINT arr[], int len)
{
	if (len > 1)
		divideArr (arr, 0, len - 1);
}

void divideArr (MYINT arr[], int left, int right)
{

	

	if (right - left + 1 <= 1) return;

	if (right - left + 1 == 2)
	{
		//$ (left, Size);
		//$ (right, Size);
		if (arr[left] > arr[right])
		{
			exchange (arr[left], arr[right]);
		}
		return;
	}
	
	if (right - left + 1 == 3)
	{
		//$ (left, Size);
		//$ (right, Size);
		sort3 (&arr[left]);
		return;
	}
 	int mid = (right + left)/2;
	const int midd = arr[(right + left)/2].num;
	const int saveLeft = left;
	const int saveRight = right;
	bool findChange = false;

	//printSort (arr, right - left + 1, midd, left, mid, right);
	//int copyArr[1000] = {};
	//equal (copyArr, arr, (right - left + 1));
	//printSort (arr, len, midd, left, mid, right, "Before sort");

	//int row[1000] = {};


	for (int  i = left; i < mid; i ++)
	{
		//$ (i, Size);
		//$ (i, 7);
		//printSort (arr, len, midd, left, mid, right);
		findChange = false;
		if (arr[i] > midd)
		{
			for (int j = right; j >= mid;j--)
			{
				//$ (j, Size);
				//$ (j, 7);
				if (arr[j] <= midd)
				{
					exchange (arr[i], arr[j]);
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
					//$ (mid, Size);
					if (arr[mid] <= midd)
					{
						exchange (arr[i], arr[mid]);
						findChange = true;
						//mid--;
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

	for (int  i = right; i > mid; i--)
	{
		//$ (i, Size);
		//$ (i, 7);
		findChange = false;
		if (arr[i] <= midd)
		{
			for (int j = left; j <= mid; j++)
			{
				//$ (j, Size);
				//$ (j, 7);
				if (arr[j] >= midd)
				{
					//$ (j, len);
					//$ (i, len);
 					exchange (arr[i], arr[j]);
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
					//$ (mid, Size);

 					if (arr[mid] >= midd)
					{
						//$ (mid, len);
						exchange (arr[i], arr[mid]);
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
			exchange (arr[mid], arr[mid - 1]);
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
		//$ (mid, Size);
		//printSort (arr, 7, midd, saveLeft, mid, saveRight, "Before Recursion");
		divideArr (arr, saveLeft, mid);
		divideArr (arr, mid+1, saveRight);
	}

	if (arr[mid] > midd)
	{
		//$ (mid, Size);
		//printSort (arr, 7, midd, saveLeft, mid, saveRight, "Before Recursion");
		divideArr (arr, saveLeft, mid - 1);
		divideArr (arr, mid, saveRight);
	}
}

void equal (MYINT arr[], MYINT arr2[], int len)
{
	for  (int i = 0; i < len; i++)
	{
		if (arr2[i] != 0xcdcdcdcd)
			arr[i] = arr2[i];
	}
}


void equal (int arr[], int arr2[], int len)
{
	for  (int i = 0; i < len; i++)
	{
		if (arr2[i] != 0xcdcdcdcd)
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
		//simpleInsertion (arr, i);
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

void unittestSorted (void (*func) (MYINT arr[], int len), const char *name)
{
	MYINT arr[1000] = {};
	

	for (int len = 1; len <= 1000; len++)
	{	
		randomfill (arr, len);
		func (arr, len);
		int sort = isSorted (arr, len);
		if (sort != -1)
		{
			printf (name);
			printf ("\nError at: %d\n", sort);
			//printArr (arr, i);
			_printArr (arr, len);
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



void simpleInsertion (MYINT arr[], int len)
{
	//int arr [5] = {61, 40, 55 ,41, 31};
	for (int i = 0; i < len - 1; i++)
	{
		int biggerNum = lessThen (arr, i + 1, arr[i + 1].num);

		rotateArr (arr, biggerNum, i + 1);
		
	}
	arr->Exchange /= 3;
	//_printArr (arr, len);

}

void binaryInsertion (MYINT arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		int biggerNum = binarySearch (arr, i + 1, arr[i + 1].num);

		rotateArr (arr, biggerNum, i + 1);
	}
}

int binarySearch (MYINT arr[], int len, int num)
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


void rotateArr (MYINT arr[], int start, int finish)
{
	if (start - finish == 1) return;
	int copy = arr[finish].num;
	for (int i = finish - 1; i >= start; i--)
	{
		arr[i + 1] = arr[i];
	}
	//Exchange /= 3;
	arr[start] = copy; 
	
}

int lessThen (MYINT arr[], int len, int num)
{
	for (int i = 0; i < len; i++)
	{
		if (num < arr[i])
		{
			//Exchange++;
			return i;
		}
	}
	return len +1;
}

void selectionSort (MYINT arr[], int len)	 
{
	for (int i = len; i > 0; i--)
	{
		//int minIndex = findTheLess (&arr[i], len - i) +  i;
		//exchange (&arr[i], &arr[minIndex]);
		int maxIndex = findTheBiggest (arr, i);
		exchange (arr[i - 1], arr[maxIndex]);
	}
}


int findTheBiggest (MYINT arr[], int len)
{
	int max = 0;
	for (int i = 0; i < len; i++)
	{
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
		//!!Comparision++;
		if (arr[i] < arr[min])
		{
			min = i;
		}
	}
	return min;
}




void drawEfficiency (MYINT arr[], int len, void (*sortFunc) (MYINT arr[], int len), coordinatSys sys1, coordinatSys sys2, COLORREF color, double r)
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
			//printf ("i: %d\n", isSorted (arr, i));
			for (int n = 0; n < i; n++)
			{
				//printf ("arr[%d]: %d\n", n, arr[n]);
			}
			//_getch ();
		}

		
	}
}

void bubleSort (MYINT arr[], const int len)
{
	for (int n = 0; n < len; n ++)
	{
		bool sorted = true;
		for (int j = 0; j < len - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				arr->Exchange++;
				int copy = arr[j].num;
				arr[j] =  arr[j + 1];
				arr[j + 1].num = copy;
				sorted = false;
			}
		}
		//if  (sorted == true) break;
	}
}

int isSorted (MYINT arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		arr[i].Comparision--;
		if (arr[i] > arr[i + 1]) return i;
	}
	return -1;
}

int isSorted (int arr[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		if (arr[i] > arr[i + 1]) return i;
	}
	return -1;
}


void sortArr (void (*comparisionFunc1) (MYINT arr[], int len), MYINT arr[], int len, coordinatSys sys1, coordinatSys sys2, COLORREF color, double r)
{
	randomfill (arr, len);
	arr->Comparision = 0;
	arr->Exchange = 0;

	comparisionFunc1 (arr, len);

	txSetFillColor (color);
	txSetColor (color); 
	sys1.drawCircle ({(double) len, (double) arr->Comparision}, r);
	txSetFillColor (color);
	txSetColor (color);
	sys2.drawCircle ({(double) len, (double) arr->Exchange}, r);
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
		//Comparision = 0;
		//Exchange = 0;
		//bubleSort (arr, l);
		txSetFillColor (TX_RED);
		txSetColor (TX_RED);
		//sys.drawCircle ({(double) l, (double) Comparision}, 1.5);
		txSetFillColor (TX_BLUE);
		txSetColor (TX_BLUE);
		//sys.drawCircle ({(double) l, (double) Exchange}, 1.5);

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

void randomfill (MYINT arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		arr[i].num = rand ();
	}
}







void exchange (int *n1, int *n2)
{
	//!!!Exchange++;
	int copy = *n1;
	*n1 = *n2;
	*n2 = copy;
}

void exchange (MYINT &n1, MYINT &n2)
{
	int copy = n1.num;
	n1 = n2;
	n2 = copy;
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
	//assert (0 < length && length < MAXARRAYSIZE);

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

void _printArr (MYINT arr[], const int length, PositionInfo info, const int mode)
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
			printf ("%d", arr[i].num);

			setConsoleColor (_CYAN_);
			printf ("%s", (i != length - 1)? ", " : " ");
		}
		//printf ("]\n");

	}
	else
	{
		for (int i = 0; i < length; i++)
		{
			printf ("%d: %d\n", i, arr[i].num);
		}
	}

	info.dump ();

}

void _printArr (MYINT arr[], const int length)
{
	
	{
		$sb
		printf ("Len: %d\n", length);
	}
	for (int i = 0; i < length; i++)
	{
		printf ("%d: %d\n", i, arr[i].num);
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
