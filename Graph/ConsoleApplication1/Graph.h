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

struct Graph
{
	list *list;
};

//insert new node in the end of list
void insertLastNode(list p, int ves, int id)
{
	list q = new Node;
	list x = p;
	q->id = id;
	q->ves = ves;
	q->next = NULL;
	while (x->next != NULL)
		x = x->next;
	x->next = q;
}
/*completly works*/
//insert new node in the top of list
void insertFirstNode(list p, int ves, int id)
{
	list q = new Node;
	q->id = id;
	q->ves = ves;
	q->next = p->next;
	p->next = q;
}

int top(list stack)
{
	int id;
	list x=stack;
	while (x&&x->next!=NULL) 
	{
		x=x->next;
	}
	return x->id;
}

int down(list stack)
{
	if (stack&&stack->next != NULL)
		return stack->next->id;
	else
		return stack->id;
}

int next(list stack)
{

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

void deleteLast(list p)
{
	list q,x = p;
	while (x->next->next != NULL && x->next != NULL)
		x = x->next;
	q = x->next;
	x->next = NULL;
	delete q;
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
}
void freeGraph(Graph graph) 
{
	int i=0;
	while (graph.list[i]) 
	{
		freeList(graph.list[i]);
		i++;
	}
}

list depthFirstSearch(Graph graph,int id) 
{
	int i=0,t,P;
	bool* now;
	list stack = new Node,x;
	stack->id=id;
	stack->next = NULL;
	while (graph.list[i])
	{
		i++;
	}
	now = (bool*)calloc(i + 1, sizeof(bool));
	now[id] = false;
	while (stack)
	{
		t = top(stack);
		P = top(graph.list[t]);
		while (P != down(graph.list[t]) && !now[P])
		{
			P = (graph.list[t]);
		}
	}
	

	return stack;
}


//////////////////////////////////////////////////////////////////////////
ifstream &operator >> (ifstream &stream, Graph &graph)
{
	int countNode = 0, id, nextNode, ves;
	static int i = 0;

	if (!graph.list[i])
	{
		stream >> countNode;
		graph.list = (list*)realloc(graph.list, countNode * sizeof(list));
		for (int j = 0; j < countNode; j++)
			graph.list[j] = new Node;
		graph.list[countNode] = NULL;
		stream >> id;
		stream >> nextNode;
		stream >> ves;
		graph.list[i]->id = id;
		graph.list[i]->next = NULL;
		//insertFirstNode(graph.list[i], ves, nextNode);
		insertLastNode(graph.list[i], ves, nextNode);
	}
	else
	{
		stream >> id;
		stream >> nextNode;
		stream >> ves;
		if (id == graph.list[i]->id)
		{
			//insertFirstNode(graph.list[i], ves, nextNode);
			insertLastNode(graph.list[i], ves, nextNode);
		}
		else {
			i++;
			graph.list[i]->id = id;
			graph.list[i]->next = NULL;
			//insertFirstNode(graph.list[i], ves, nextNode);
			insertLastNode(graph.list[i], ves, nextNode);
		}
	}
	return stream;
}
ofstream &operator <<(ofstream &stream, Graph graph)
{	
	int i=0;
	while (graph.list[i])
	{
		stream << "[" << graph.list[i]->id << "]->";
		while (graph.list[i]->next!=NULL) 
		{
			graph.list[i] = graph.list[i]->next;
			stream << "[" << graph.list[i]->id << "/" << graph.list[i]->ves << "]" << "->";
		}
		stream << endl;
		i++;
	}
	return stream;
}