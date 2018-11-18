#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
    char *data;
    struct Node *next;
    struct Node *previous;
};

typedef struct Node node;
node *start = NULL, *last= NULL;

void insertAtbegining(char *x);//function to insert string at the beginning
void insertAtlast(char *x);//function insert string at last
void delstart();//to delete a node from begining
void dellast();//to delete a node from the end
void delmid(int position);//to delete a node from a particular position 
void delete();//the driver function to use all the delete functions
void display();//function to display the list of strings
int search(char *x);//function to check if a particular string exists in the list or not
node* insertAfter(char *x1,char *x2);//to insert a string after a particular string in the list
node* insertBefore(char *x1,char *x2);//to insert a string before a particular string in the list
int main()
{
    char ch='y';
    int a;
    do
    {
         printf("Enter-\n 1. To insert at begining\n 2. To insert at the end\n 3. To insert after a particular value\n 4. To insert before a particular value\n 5. To delete a node\n 6. To search\n 7. To display\n");
         scanf("%d",&a);
     switch(a)
     {
         case 1:
         printf("Enter the string\n");
         char *x;
         x=malloc(256);
         scanf("%s",x);
         insertAtbegining(x);
         break;
         case 2:
         printf("Enter the string\n");
         char *x1;
         x1=malloc(256);
         scanf("%s",x1);
         insertAtlast(x1);
         break;
         case 3:
         printf("Enter the string that you want to enter and the string after which you want to enter\n");
         char *x2,*y1;
         x2=malloc(256);
         y1=malloc(256);
         scanf("%s%s",x2,y1);
         insertAfter(x2,y1);
         break;
         case 4:
         printf("Enter the string that you want to enter and the string before which you want to enter\n");
         char *x3,*y2;
         x3=malloc(256);
         y2=malloc(256);
         scanf("%s%s",x3,y2);
         insertBefore(x3,y2);
         break; 
         case 5: 
         delete();
         break;
         case 6:
         printf("Enter the string you want to search\n");
         char *y;
         y=malloc(256);
         scanf("%s",y);
         search(y);
         break;
         case 7:
         display();
         break;
     }
     printf("\nDo you want to go again?(Y/N)");
     scanf(" %c",&ch);
     }while(ch=='Y' || ch=='y');
}


void insertAtbegining(char *x)
{
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data=malloc(256);

    newNode->data=x;
    newNode->next = newNode;
    newNode->previous = newNode;

    if(start==NULL)
    {
        start = newNode;
        last= newNode;
    }
    else
    {
        newNode->next = start;
        newNode->previous = last;
        start->previous = newNode;
        last->next = newNode;
        start = newNode;
    }

}

void insertAtlast(char *x)
{
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data=malloc(256);
    newNode->data = x;
    newNode->next = newNode;
    newNode->previous = newNode;

    if(start==NULL)
    {
        start = newNode;
        last= newNode;
    }
    else
    {
        last->next = newNode;
        newNode->next = start;
        newNode->previous = last;
        last= newNode;
        start->previous = last;
    }
}
node *insertAfter(char *k1,char *k2)
 {
     node *p=(node*)malloc(sizeof(node));
     p->data=malloc(256);
     p->data=k1;
     node *temp=start;
     while(strcmp(temp->data,k2)!=0)
     temp=temp->next;
     node *nextt=temp->next;
     p->next=nextt;
     p->previous=temp;
     temp->next=p;
     nextt->previous=p;
     return start;
 }

 node *insertBefore(char *x1,char *x2)
 {
     node *p=(node*)malloc(sizeof(node));
     p->data=malloc(256);
     p->data=x1;
     node *temp=start;
     while(strcmp(temp->data,x2)!=0)
     temp=temp->next;
     node *lastt=temp->previous;
     p->next=temp;
     p->previous=lastt;
     lastt->next=p;
     return start;
 }

int search(char *x)
{
    node *temp=start;
    int c=0,flag,val;
    if(temp==NULL)
    return -1;
    else
    {
        while(temp->next!=start)
        {
            c++;
            if(strcmp(temp->data,x)==0)
            {
                flag=1;
                c--;
                break;
            }
            temp=temp->next;
        }
        if(strcmp(temp->data,x)==0)
        {
            c++;
            flag=1;
        }
        if(flag==1)
        printf("Your string has been found!\n");
        else
        printf("String not found!\n");
    }
}

void delstart()
{
    if(start==NULL)  return;

    node *temp = start;

    last->next = start->next;
    start = start->next;
    start->previous = last;

    free(temp);
}

void dellast()
{
    if(start==NULL)  return;

    node *temp = start;
    node *current = start;

    while(current->next != start)
    {
        temp = current;
        current = current->next;
    }
    temp->next = start;     last= temp;
    start->previous = last;
    free(current);
}

//Delete a particular node in between
void delmid(int position)
{
    if(start==NULL)  return;

    if(position==1)
    {
        delstart();
        return;
    }

    node *current = start;
    node *temp;
    int count = 0;

    do
    {
        count++;
        temp = current;
        current = current->next;
    }   while(current->next != start && count<position-1);

    if(count==position-1)
    {
        if(current==last)
        {
            dellast();
            return;
        }

        temp->next = current->next;
        current->next->previous = temp;
        free(current);
        return;
    }

    printf("Position (%d) does not exist!\n", position);
}
//driver function to use all 3 delete functions
void delete()
{
    printf("1. To delete a node from the beginning\n 2. To delete a node at end\n 3. To delete a node from a particular position\n");
         int n;
         scanf("%d",&n);
         switch(n)
         {
             case 1: 
             delstart();
             break;
             case 2:
             dellast();
             break;
             case 3:
             printf("Enter the position from which you want to delete the node\n");
             int del;
             scanf("%d",&del);
             delmid(del);
             break;
         }
}
void display()
{
    if(start==NULL)  return;

    node *current = start;

    do
    {
        printf("%s->", current->data);
        current = current->next;
    }while(current != start);
}