#include<stdlib.h>
#include<stdio.h>
#include "KVP.c"
int main(int argc,char **argv){
	struct map *head;
	head=createMap();
	createKVP(head,"first","1st");
	createKVP(head,"sec","2nd");
	printArray(head);
	createKVP(head,"first","3rd");
	printArray(head);
	modifyKey(head,"sec","second");
	printArray(head);
	modifyKeysByVal(head,"FIRST","3rd");
	printArray(head);
	
	char *val = getValByKey(head,"FIRST");
	printf("THE VALUE OF KEY FIRST IS %s\n\n",val);
	
	return 0;
}	
