/******************************/
/* names.c                    */
/* Linked list demonstration  */
/* (C) 2016 by A.A.Shtanyuk   */
/******************************/

#include "names.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

PITEM createList(PNAME_REC name_rec)
{
	PITEM item=(PITEM)malloc(sizeof(TITEM));
	item->name_rec=name_rec;
	item->prev=NULL;
	item->next=NULL;
	return item;
}
PNAME_REC createName(char *line)
{
	int i=0;
	PNAME_REC rec=(PNAME_REC)malloc(sizeof(TNAME_REC));
	while(*line && *line!=',')
		rec->name[i++]=*line++;
	rec->name[i]=0;
	line++;
	i=0;
	while(*line)
		rec->meaning[i++]=*line++;
	rec->meaning[i]=0;
	return rec;
}
PITEM addToTail(PITEM tail,
			   PNAME_REC name_rec)
{
	PITEM item=createList(name_rec);
	if(tail!=NULL)
	{
		tail->next=item;
		item->prev=tail;	
	}
	return item;
}
int countList(PITEM head)
{
	int count=0;
	while(head)
	{
		count++;
		head=head->next;
	}
	return count;
}
PITEM findByName(PITEM head,char *name)
{
	while(head)
	{
		if(strcmpi(head->name_rec->name,name)==0)
			return head;
		head=head->next;
	}
	return NULL;
}
void printName(PITEM item)
{
	if(item!=NULL)
	{
		puts(item->name_rec->name);
		puts(item->name_rec->meaning);
	}
}
