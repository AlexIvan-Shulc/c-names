/******************************/
/* main.c                     */
/* Linked list demonstration  */
/* (C) 2016 by A.A.Shtanyuk   */
/******************************/

#include "names.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	int count=0;
	char buf[512];
	PITEM head,tail,item;
	fp=fopen("names.csv","rt");
	if(!fp) {
		perror("File names.csv:");
		exit(1);
	}
	fgets(buf,512,fp);
	while(fgets(buf,512,fp))
	{
		if(count==0)
		{
			head=createList(createName(buf));
			tail=head;
		}
		else
		{
			tail=addToTail(tail,createName(buf));
		}
		count++;
	}
	fclose(fp);
	printf("Total items: %d\n",countList(head));
	item=findByName(head,"olga");
	if(item==NULL)
		printf("Not found!\n");
	else
		printName(item);
	return 0;
}