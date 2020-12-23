#pragma once

#include <assert.h>
#include "Array.cpp"

#define _ASSERT_                          \
{										  \
	if (checkup () != _OK_)				  \
	{									  \
		dump ();						  \
		assert ("checkup failed:(" == 0); \
	}									  \
}										  \

void statText (const char *text, int stat[256]);
void tenTo2 (unsigned int n);
void charToAscii (char c);


//! @mainpage
//!			 ��� �������� ���������� Stack

struct Stack
{
	//! @brief �������� ���������
	const int firstCanary = 0x7EF79D07;

//!	@brief ������������ ���� ������
//!
//!
//! @note ���� � ��� ������� ������ ������� ���� � ������� ��� �� ����������
//! 
//! @usage @code dump (_OverFlow_);
//!
//!@endcode

	enum errors
	{
		_OK_ = 0,
		_OverFlow_ = 1111,
		_MinusArrElement_ = -1, 
		_CANARYERROR_ = 1001
	};

	//!	@brief ����������� ������ Stack
	//! @param _structPos ��� ����� ��� ����������� ����� �������� ��������� � ������ ����� � dump()

	Stack (PositionInfo _structPos);

	//! @brief ������������ ������ �����
	static const int MaxSize = 2;

	//! @brief ��� � ���� ������� ���� ����� ������, ��� ��� ��������
	int stack[MaxSize] = {};
	
	//! @brief ������� ���������� ��������
	int lastPos = -1;

	
	

	//! @brief ���������� � ������� � �������� ����� ��� ��������� ���������� ��������� dump ();
	PositionInfo structPos = {};

	void pop ();
	void push (int num);
	void print ();
	void change (int num1, int num2);
	void dump (/*const char *name*/);
	int checkup ();
	void dump (const int cause);

	void unittest (int kOfPush = 1);
	void unittest2 (int kOfPush);
	//! @brief ������ ���������
	const int lastCanary =  0x12345E84;


};
//!	@brief ��������� ��� ����� ��������
//!
//!
//! 
//! @usage @code StackTest st1 {{}, {POSINFO(st1)}, {}};
//!
//!@endcode

struct StackTest
{
	int m1[1] = {};	
	Stack s2;
	int m2[1] = {};

	//StackTest (PositionInfo _structPos);
};


void Stack::unittest2 (int kOfPush)
{
	StackTest st1 {{}, {POSINFO(st1)}, {}};
	st1.m1[0] = 2;
	st1.m1[1] = 3;

	st1.m2[-1] = 4;

	st1.s2.dump();

}
/*
StackTest::StackTest (PositionInfo _structPos) :
	s1 (_structPos)
{

}
	*/


//!	@brief ����������� ������
//!
//!	@param _structPos ��� ������ PositionInfo  
//!
//! @return ������ � �� ����:)
//! 
//! @usage @code 
//!             Stack s1 (__FILE__, __LINE__, __FUNCSIG__, #s1);
//!@endcode

Stack::Stack (PositionInfo _structPos) :
	 structPos (_structPos) 
{ 		
}


//!	@brief ��������� �� ��������� ������ � lastPos, �� ��������� ���������
//!
//! @return _OK_ ���� ��� ������, �������� ������ ���� ���-�� ���������:(
//! @warning ��� ������ �������� ������ �� ����� ��������� ������, ��������� �������� �� �� �� �����
//! 
//! @usage @code checkup()
//!
//!@endcode
 

int Stack::checkup ()
{
	if (lastPos > MaxSize -1)
	{
		dump (_OverFlow_);
		assert (0 == 1);
	}

	if (lastPos < -1)
	{
		dump (_MinusArrElement_);
		assert (0 == 1);
		
	}

	if (firstCanary != 0x7EF79D07)
	{
		dump (_CANARYERROR_);
		assert (0 == 1);	
	}
	if (lastCanary != 0x12345E84)
	{
		dump (_CANARYERROR_);
		assert (0 == 1);
	}

	return _OK_;

}

//!	@brief ������� ��������� ������� � �����
//!
//! @return ������
//! @warning ��� �������� ��������� �� ������� ������� ���������� assert
//! 
//! @usage @code s1.pop ();
//!
//!@endcode

void Stack::pop ()
{
	//assert (-1 < lastPos && lastPos < MaxSize);
	assert (stack);

	//assert (checkup () == _OK_);
	checkup ();

	stack[lastPos]  = NULL;
	lastPos--;

	checkup ();
}

//!	@brief ��������� ����� ������� � ����
//!
//!	@param num - ����� ������� ����� ���������
//!
//! @return ������
//! @warning ��� ���������� ��������� � ������ ������ ���������� assert
//! 
//! @usage @code s1.push (2);
//!
//!@endcode

void Stack::push (int num)
{
	//assert (num != NULL);
	assert (stack);
	//assert (-2 < lastPos && lastPos < MaxSize - 1);

	checkup ();
	lastPos++;
	checkup ();
	stack[lastPos] = num;
	checkup ();

	//lastPos++;

}


//!	@brief �������� ��� ���� ��� ������������� �������������
//!
//! @return ������
//! @note ��� ������� ����� ������������ dump ();
//! 
//! @usage @code s1.print ();
//!
//!@endcode

void Stack::print ()
{
	//scheckup ();
	setConsoleColor (_CYAN_);	
	assert (stack);

	printf ("[ ");
	for (int i = 0; i <= lastPos; i++)
	{
		assert (0 <= i && i < MaxSize);
		setConsoleColor (_CYAN_);
		printf ("[%d] = ",  i);

		setConsoleColor (_LIGHTCYAN_);
		printf ("%d", stack[i]);

		setConsoleColor (_CYAN_);
		printf ("%s", (i != lastPos)? ", " : " ");
	}
	printf ("]\n");


	//lastPos++;

} 

//!	@brief ������ ��� �������� ������� ����� �����
//!
//!	@param num1 - ������� ������� �������� (������ �� 0)
//!	@param num2 - ������� ������� �������� (������ �� 0)
//!
//! @return ������
//! @warning ��� ������ �������������� ��������� ���������� assert
//! 
//! @usage @code s1.change (2, 3);
//!
//!@endcode

void Stack::change (int num1, int num2)
{
	checkup ();
	assert (stack);
	//assert (num1 != NULL);
	//assert (num2 != NULL);

	assert (0 <= num1 && num1 <= lastPos);
	assert (0 <= num2 && num2 <= lastPos);

	int copy = stack[num1];
	stack[num1] = stack[num2];
	stack[num2] = copy;
	checkup ();

}


void Stack::dump (/*const char *name*/)
{
	//printf ("%s = ", "sth:(");
	checkup ();
	print ();

	printf ("Adress: %p\n", this);
	structPos.printInfo ();
	checkup ();

	

}

//!	@brief ��������� ����� ���������� � ���������
//!
//!	@param cause �������������� ��������� ��������, ����� ��� ������ ������ � checkup()
//!
//! @return ������
//! @note �� ����� ��� ����� ��� ����������
//! 
//! @usage @code s1.dump ();
//!				 s1.dump (_OverFlow_);
//!
//!@endcode

void Stack::dump (const int cause)
{
	setConsoleColor (_RED_);
	printf ("ERROR:((((((((\n");
	printf ("Cause: %d\n", cause);
	//printf ("%s = ", "sth:(");
	print ();

	printf ("Adress: %p\n", this);
	printf ("Canary1: %x, Canary2: %x", firstCanary, lastCanary);
	structPos.printInfo ();


	

}

//!	@brief ������� ��������� ���� kOfPush ���-��� ����������
//!
//!	@param kOfPush ���-�� ���������, ������� ����� �������� � ���� 
//!
//! @return ������
//! @note �� ����� ��������� �� ������ ������ � �����
//! 
//! @usage @code s1.unittest
//!
//!@endcode

void Stack::unittest (int kOfPush)
{
	checkup ();
	pop ();
	/*
	for (int i = 0; i < kOfPush; i++)
	{
		push (1);
	}
	checkup ();

	for (int i = 0; i < kOfPush; i++)
	{
		//pop ();
	}

	checkup ();

	printf ("\nTest was succesfull\n");
	*/

	checkup ();

}



void statText (char *text, int stat[256])
{
	for (int i = 32; i < 256; i++)
	{
		//printf ("[%c] == %d\n", i, i);	
	}

	
	for (int i = 0; text[i] != 0; i++)
	{
		//printf ("[%c] == %d\n", text[i], (unsigned char) text[i]);
		assert (0 <= i && i <= 256);
		assert (-128 <= text[i] && text[i] < 128);
		stat[ (unsigned char) text[i] ]++;

	}

	for (int i = 0; i < 256; i++)
	{
		if (stat[i] != 0)
		{
			printf ("[%c] == %d\n", i, stat[i]);
		}

	}
	/*
	192	  96  48  24   12	6 3	1 0
	  0	   0   0   0	0	0 1	1
		   11000000
	
  */
}

void tenTo2 (unsigned int n)
{
	for (int i = 7; i >= 0; i--)
	{	
		//printf ("%d ", 1 << i);
				    
		printf ("%d", (n & (1 << i)) >> i);
		//printf ("\n");
	}
}

void charToAscii (char c)
{
	printf ("[%c] == (%+03d; ", c, c);
	tenTo2 (c);
	printf (")\n");

}


