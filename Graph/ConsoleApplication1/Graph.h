#pragma once

#include <stdio.h> 
#include <stdlib.h> 
#include <fstream>

using namespace std;

struct Node
{
	int id;
	Node* next;
	int ves;
};
typedef Node *list;
/*
void printList(list p)
{
	while (p)
	{
		printf("%d ", p->key);
		p = p->next;
	}
	printf("\n");
}
*/
void insertLastNode(list p, int ves, int id)///complete
{
	list q = new Node;
	list x = p;
	q->id = id;
	q->ves = ves;
	while (x->next != NULL)
		x = x->next;
	/*ХЗ КАКОЙ ВАРИАНТ БУДЕТ РАБОТАТЬ*/
	//findItem(p, x->id)->next=q;
	//x->next = q;
}

void insertFirstNode(list p, int ves, int id)
{
	list q = new Node;
	q->id = id;
	q->ves = ves;
	q->next = p->next;
	p->next = q;
}


list findItem(list p, int id)
{
	bool f = false;
	list x = p;
	while (x && x->id != id)
	{
		x = x->next;
		if (!x) f = true;
	}
	if (!f) { return x; }
	else return 0;
}

void deletAfter(list p)
{
	if (p->next != NULL)
	{
		list q = p->next;
		p->next = q->next;
		delete q;
	}
}

void freeList(list p)
{
	list q;
	while (p)
	{
		q = p;
		p = p->next;
		delete q;
	}
}/*
list deletByKey(int k, list p)
{
	/*do
	{
	list temp = p;

	if (p&&p->key != k)
	{
	while (temp->next->key != k)
	{
	temp = temp->next;
	}

	deletAfter(temp);

	return p;
	}
	else if (p)
	{
	temp = p->next;
	delete p;
	p=temp;
	if (!findItem(p, k))return p;
	}

	} while (findItem(p, k));
	////////////////////////////////////////////////////////////////////////

	list temp = p;

	while (temp&&temp->next)
	{
		if (temp->next->key == k)
			deletAfter(temp);
		else temp = temp->next;
	}

	if (p->key == k)
	{
		temp = p->next;
		delete p;
	}

	return temp;
}*/
//////////////////////////////////////////////////////////////////////////

struct Graph
{
	list *list;
};
ifstream &operator >> (ifstream &stream, Graph &graph)
{
	int countNode = 0, id, nextNode, ves;
	static int i = 0;

	if (!graph.list[i])
	{
		stream >> countNode;
		//graph.list = new list[countNode];
		graph.list = (list*)realloc(graph.list, countNode * sizeof(list));
		for (int j = 0; j < countNode; j++)
			graph.list[j] = new Node;

		stream >> id;
		stream >> nextNode;
		stream >> ves;
		graph.list[i]->id = id;
		insertFirstNode(graph.list[i], ves, nextNode);
	}
	else
	{
		stream >> id;
		stream >> nextNode;
		stream >> ves;
		if (id == graph.list[i]->id)
		{
			insertFirstNode(graph.list[i], ves, nextNode);
		}
		else {
			i++;
			graph.list[i]->id = id;
			insertFirstNode(graph.list[i], ves, nextNode);
		}
	}
	return stream;
}