#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node* next;
} node;

int length(node* head)
{
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

char* toCString(node* head)
{
    int len = length(head);
    char* str = (char*)malloc((len + 1) * sizeof(char)); 
    if (str == NULL) {
        printf("Memory allocation has failed.");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (head != NULL) {
        str[i++] = head->letter;
        head = head->next;
    }
    str[len] = '\0'; 
    return str;
}

void insertChar(node** pHead, char c)
{
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation has failed.");
        exit(EXIT_FAILURE);
    }

    newNode->letter = c;
    newNode->next = NULL;

    if (*pHead == NULL) {
        *pHead = newNode;
        return;
    }

    node* temp = *pHead;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteList(node** pHead)
{
    while (*pHead != NULL) {
        node* temp = *pHead;
        *pHead = (*pHead)->next;
        free(temp);
    }
}

int main(void)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt", "r");
    fscanf(inFile, " %d\n", &numInputs);
    while (numInputs-- > 0)
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++)
        {
            fscanf(inFile, " %c", &c);
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