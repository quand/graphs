#include "stdafx.h"
#include "Graph.h"
#include <string>
#include <locale.h>
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Russian");

	char *filein = "graph.txt", *fifoOut = "FIFO.txt", *lifoOut = "LIFO.txt";
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
	/*
	dest.open(fifoOut, ios::trunc);
	if (dest)
	{
		dest << grah;
	}
	dest.close();
	*/
	dest.open(lifoOut, ios::trunc);
	if (dest)
	{
		dest << grah;
	}
	dest.close();
	freeGraph(grah);
	getchar();
	return 0;
}

