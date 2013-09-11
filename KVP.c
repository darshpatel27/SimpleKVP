#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include "KVP.h"

struct map *createMap(){
	struct map *instance;
	instance = (struct map *)malloc(sizeof(struct map));
	instance->next = NULL;
	instance->key = NULL;
	instance->val = NULL;
	return instance;
}

void createKVP(struct map *m, char *key, char *val){
	if(m->key == NULL){
		m->key = (char *) malloc(sizeof(strlen(key)));
		m->val = (char *) malloc(sizeof(strlen(val)));
		strcpy(m->key,key);
		strcpy(m->val,val);
		m->next = NULL;
		return;
	}
	if(getValByKey(m,key) != NULL){
		modifyValByKey(m,key,val);
		return;
	}	
	struct map *temp,*curr;
	temp=m;
	while(temp->next != NULL){
		temp=temp->next;
	}
	curr = (struct map *)malloc(sizeof(struct map));
	curr->key = (char *) malloc(sizeof(strlen(key)));
	curr->val = (char *) malloc(sizeof(strlen(val)));
	strcpy(curr->key,key);
	strcpy(curr->val,val);
	curr->next=NULL;
	
	temp->next=curr;
}

bool modifyValByKey(struct map *m, char *key , char *val){
	if(m == NULL)
		return false;
	struct map *curr;	
	for(curr=m ;curr != NULL ;curr=curr->next){
		if(!strcmp(curr->key,key) && strcmp(curr->val,val)){
			free(curr->val);
			curr->val = (char *)malloc(sizeof(strlen(val)));
			strcpy(curr->val,val);
			return true;
		}
	}
	return false;
}

bool modifyKey(struct map *m, char *oldKey, char *newKey){
	if(m == NULL)
		return false;
	if(!strcmp(oldKey,newKey))
		return true;
	struct map *curr;	
	for(curr=m;curr != NULL;curr=curr->next){
		if(!strcmp(curr->key,oldKey)){
			free(curr->key);
			curr->key=(char *)malloc(sizeof(strlen(newKey)));
			strcpy(curr->key,newKey);
			return true;
		}
	}
	return false;
}

bool modifyKeysByVal(struct map *m, char *newKey, char *val){
	if(m == NULL)
		return false;
	struct map *curr;	
	for(curr=m;curr != NULL;curr=curr->next){
		if(!(strcmp(curr->val,val) && strcmp(curr->key,newKey))){
			free(curr->key);
			curr->key=(char *)malloc(sizeof(strlen(newKey)));
			strcpy(curr->key,newKey);
		}
	}	
	return true;
}

char *getValByKey(struct map *m, char *key){
	if(m == NULL)
		return NULL;
	struct map *curr;	
	for(curr=m;curr != NULL;curr=curr->next){
		if(!strcmp(curr->key,key)){
			return curr->val;
		}
	}
	return NULL;
}
void printArray(struct map *m){
	printf("\nPRINTING ARRAY\n\n");
	while(m != NULL){
		printf("KEY\t%s\t",m->key);
		printf("VALUE\t%s\n\n",m->val);
		m=m->next;
	}
}	
