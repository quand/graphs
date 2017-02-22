// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
//#include "Graph.h"
#include "Header.h"
#include <string>
#include <locale.h>
#include <iostream>


int main()
{
	setlocale(LC_ALL, "Russian");

	char *filein = "graph.txt", *fileout = "list.txt";
	Graph grah;
	grah.list = (list*)calloc(5, sizeof(list));

	ifstream source;
	ofstream dest;

	source.open(filein);
	if (source)
	{
		while (!source.eof())
		{
			source >> grah;
		}
	}
	else cout << "File doesn't exist";
	source.close();
	dest.open(fileout, ios::app);
	if (dest)
	{
		//dest << grah;
	}
	dest.close();

	getchar();
	return 0;
}

