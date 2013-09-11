#ifndef KVP
#define KVP
#define bool int
#define true 1
#define false 0

struct map{
	struct map *next;
	char *key;
	char *val;
};

struct map *createMap();
void createKVP(struct map *m,char *key,char *val);
bool modifyKey(struct map *m,char *oldKey,char *newKey);
bool modifyValByKey(struct map *m,char *key, char *newVal);
bool modifyKeysByVal(struct map *m, char *newKey, char *val);
char *getValByKey(struct map *m,char *key);
void printArray(struct map *m);

#endif
