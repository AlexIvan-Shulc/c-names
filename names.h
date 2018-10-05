/******************************/
/* names.h                    */
/* Linked list demonstration  */
/* (C) 2016 by A.A.Shtanyuk   */
/******************************/

struct NAME_REC
{
	char name[20];
	char meaning[256];
};

typedef struct NAME_REC TNAME_REC;
typedef TNAME_REC * PNAME_REC;

struct ITEM
{ 
	PNAME_REC name_rec;
	struct ITEM *next;
	struct ITEM *prev;
};

typedef struct ITEM TITEM;
typedef TITEM * PITEM;

PITEM createList(PNAME_REC name_rec);
PNAME_REC createName(char *line);
PITEM addToTail(PITEM tail,
			   PNAME_REC name_rec);
int countList(PITEM head);
PITEM findByName(PITEM head,char *name);
void printName(PITEM item);