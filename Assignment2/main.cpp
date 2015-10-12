/*********************************************************************************************
*Author:					Austin Koos
*Date Created:				10/10/2015
*Last Modification Date:	10/11/2015
*Lab Number:				CST 211 Assignment 2
*Filename:					main.cpp
*
*Overview:
*	Tests the functionality of the templated Array2D class.  Makes use of all the member functions
*	and constructors.
*
*Input:
*
*
*Output:
*	Contents of arrays, number of rows and columns, and exceptions displayed to console 
*
***********************************************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Array2D.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Default ctor
	Array2D<char> arrChar;
	//2 arg ctor
	Array2D<int> arrInt(5, 1);
	//Const object
	const Array2D<double> arrDoub(1, 1);

	try
	{
		cout << arrDoub[0][0] << endl;
	}
	catch (Exception &except)
	{
		cout << except;
	}

	//GetRow 
	cout << "Rows: " << arrChar.GetRow() << endl;
	//GetColumn
	cout << "Columns: " << arrChar.GetRow() << endl;

	//SetRow
	arrChar.SetRow(5);
	//SetColumn
	arrChar.SetColumn(10);

	for (int i = 0; i < arrChar.GetRow(); i++)
	{
		for (int j = 0; j < arrChar.GetColumn(); j++)
		{
			//Sets data to characters using ASCII values
 			arrChar.SetData(i, j, 97 + j);
		}
	}
	
	for (int i = 0; i < arrInt.GetRow(); i++)
	{
		for (int j = 0; j < arrInt.GetColumn(); j++)
		{
			//[] operator and exception handling
			try
			{
				arrInt[i][j] = i;
			}
			catch (Exception &except)
			{
				cout << except;
			}
		}
	}

	//Copy ctor and operator =
	Array2D<int> arrInt2(arrInt);

	for (int i = 0; i < arrChar.GetRow(); i++)
	{
		for (int j = 0; j < arrChar.GetColumn(); j++)
		{
			//[] operator and exception handling
			try
			{
				cout << arrChar[i][j] << " ";
			}
			catch (Exception &except)
			{
				cout << except;
			}
		}
		cout << endl;
	}

	for (int i = 0; i < arrInt.GetRow(); i++)
	{
		for (int j = 0; j < arrInt.GetColumn(); j++)
		{
			//[] operator and exception handling
			try
			{
				cout << arrInt[i][j] << " ";
				cout << arrInt2[i][j] << " ";
			}
			catch (Exception &except)
			{
				cout << except;
			}
		}
		cout << endl;
	}

	//[] operator and exception handling
	try
	{
		cout << arrChar[10000][0] << " ";
	}
	catch (Exception &except)
	{
		cout << except;
	}

	//[] operator and exception handling
	try
	{
		cout << arrInt[0][10000] << " ";
	}
	catch (Exception &except)
	{
		cout << except;
	}

	return 0;
}