//program to implement double hashing 
//if collision compute 
//index=(hash(key)+i*hash1(key))%size for i=0,1,2,...tablesize
//hash(key)=key%size;

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct element
{
	int key;
	char name[100];
	int mark;
};

void display(struct element *, int);
void insert_to_hash(struct element*, int,int, char*);
void delete_from_hash(struct element *,int ,int );
int hash1(int);
void search_in_hash(struct element *, int, int);
 
int main()
{
	struct element *hashtable;
	int i,n,ch,key,no_elements;
	char name[100];
	int tablesz;
  
	printf("Enter the table size..");
	scanf("%d",&tablesz);
  
	//create hash table
	hashtable=(struct element*)malloc(tablesz* sizeof(struct element));
	for(i=0;i<tablesz;i++)
		hashtable[i].mark=0;
	no_elements=0;
  
	while(1)
	{
		printf("\n1. Insert..");
		printf("\n2. Delete..");
		printf("\n3. Search..");
		printf("\n4. Display..");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: printf("Enter key..\n");
				scanf("%d",&key);
				printf("Enter name..\n");
				scanf("%s",name);
				insert_to_hash(hashtable,tablesz,key,name);
				break;
		case 2: printf("Enter the key for deletion..\n");
				scanf("%d",&key);
				delete_from_hash(hashtable,tablesz,key);
				break;
		case 3: printf("Enter the key to search..\n");
				scanf("%d",&key);
				search_in_hash(hashtable,tablesz,key);
				break;
		case 4:display(hashtable,tablesz);
		}
	}
}


void delete_from_hash(struct element *ht,int size,int key )
{
    int i,index,h;
    
    index=key %size;
    i=index;
    h=1;
     
    for(h=1;h<=size;h++)
    {
        if(ht[i].key==key)
        {
			printf("\nkey found..and deleted\n");
			ht[i].mark=0;
			return;
        }
		i=(index+h*hash1(key))%size;
    }
    printf("key not found\n");
}

int hash1(int key)
{
	return(key % 9);
} 
    

 
void display(struct element *ht, int size)
{
    int i;
    for(i=0;i<size;i++)
    {
		printf("%d :", i);
		if (ht[i].mark!=0)
			printf("Key = %d, name = %s",ht[i].key,ht[i].name);
		printf("\n");
    }
}  


void insert_to_hash(struct element*ht, int size,int key, char *name )
{
    int index,i,h;
    index=key %size;
    i=index;
    h=1;
	
	for(h=1;h<=size;h++)
    {
        if(ht[i].mark==0)
        {
			ht[i].key=key;
			strcpy(ht[i].name,name);
			ht[i].mark=1;
			return;
        }
		i=(index+h*hash1(key))%size;
		printf("\n%d + %d * %d \n",index, h,hash1(key));
    }
    printf("cannot insert..\n");
    return;
}

void search_in_hash(struct element *ht, int size, int key)
{
    int index, i, h, step;
    index = key % size;

    step = hash1(key);
    for (i = 0; i < size; i++) 
    {
        h = (index + i * step) % size;
        if (ht[h].mark == 0)
        {
            printf("Key %d not found (found empty slot).\n", key);
            return;
        }
        if (ht[h].mark == 1 && ht[h].key == key)
        {
            printf("\nKey %d found:\n", key);
            printf("   Name: %s\n", ht[h].name);
            printf("   Index in Hash Table: %d\n", h);
            return;
        }
    }
    printf("Key %d not found (exhausted probe sequence).\n", key);
}
