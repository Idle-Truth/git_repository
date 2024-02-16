#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
 node* pTemp = head;
int numCount = 0;

	if(head == NULL)
	{
		return NULL;
	}

	while(pTemp != NULL)
	{
		numCount++;
		
		pTemp = pTemp->next;

	}

	
	return numCount;
	

}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	 node* pTemp = head;
	char* newStr = (char*)malloc(sizeof(char)* (length(head)+1));

	if(head == NULL)
	{
		return NULL;
	}
int i = 0;
	while(pTemp != NULL)
	{
		newStr[i] = pTemp->letter;
		pTemp = pTemp->next;
		i++;

	}

	
    newStr[i] = '\0';
    return newStr;

}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* newNode = (node*)malloc(sizeof(node));
	 node* pTemp = *pHead;
	newNode->letter = c;
    newNode->next = NULL;
	if(*pHead == NULL)
	{
		*pHead = newNode;
		return;
	}


	while(pTemp->next != NULL)
	{
		pTemp = pTemp-> next;
	}
        
    
    pTemp->next = newNode;



}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	
	 node* current = *pHead;
	 node* next;

	 if(pHead == NULL)
	 {
		return;
	 }

	while(current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
		
	}
	
	*pHead = NULL;

}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}