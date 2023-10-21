// C code to implement Priority Queue
// using Linked List
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node
 struct node
{
    char data[100] ;
    int priority;
    int completed;
    struct node* next;
};

struct node* newNode(char d[], int p)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    strcpy(temp->data,d);
    temp->priority = p;
    temp->completed=0;
    temp->next = NULL;
    return temp;
}


char* peek(struct node** head)
{
    return (*head)->data;
}


void pop(struct node** head)
{
    struct node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

// Function to push according to priority
void push(struct node** head, char d[], int p)
{
    struct node* start = (*head);
    struct node* temp = newNode(d, p);


if ((*head)->priority > p) 
{
    // Insert New Node before head
    temp->next = *head;
    (*head) = temp;
}
else 
{
// Traverse the list and find a
// position to insert new node
    while (start->next != NULL && start->next->priority < p) 
    {
        start = start->next;
    }
 
    temp->next = start->next;
    start->next = temp;
}
}

int isEmpty(struct node** head)
{
    return (*head) == NULL;
}


int main()
{

    printf("Welcome to To Do List\n");
    int choice;
    int i=1;
    int numberOfTask=0;
    int numberOfCompletedTask=0;
    struct node* pq = NULL; 
    while(choice!=6)
    {
    
    
    
    printf("\n\n1. Add a Task\n");
    printf("2. Remove a Task\n");
    printf("3. Mark Task as Completed\n");
    printf("4. Display all the Task with Priority\n");
    printf("5. Give Highest Priority task to be done\n");
    printf("6. Display All Completed Task");
    printf("7. Exit\n");
    printf("Pick a choice\n");
    scanf("%d",&choice);



switch(choice)
{
    case 1:
    {
        char task[100];
        int prior;
        printf("Enter the Task\n");
        scanf("%s",task);
        printf("Enter the priority for %s \n",task);
        scanf("%d",&prior);
        
       
         if(pq==NULL)
         {
            pq=newNode(task,prior);
         }
         else
         {
            push(&pq,task,prior);
         }
    
        numberOfTask++;
        printf("%s with priorty %d is inserted, To watch all the task Press 4", task, prior);
        break;
       
       
    }
    case 2:
    {
        char remove[100];
        
        if(!isEmpty(&pq))
        {
            struct node* prev = NULL;
            struct node* curr = pq;

            printf("Enter the Task to be removed\n");
            scanf("%s",remove);
            while(curr!= NULL && strcmp(curr->data, remove) != 0)
            {
                prev=curr;
                curr=curr->next;
            }

            if(curr!=NULL)
            {
                if(prev!=NULL)
                {
                    prev->next=curr->next;
                }
                else
                {
                    pq=curr->next;
                }


                free(curr);
                numberOfTask--;
                printf("%s has been removed from the task\n\n",remove);
            }
            else
            {
                printf("Task not found\n\n");
            }
        }
        else
        {
             printf("\nNo Task Currently Added\n\n");
        }
        break;
    }
    
    case 3:
    {
        char completed[100];
        if(!isEmpty(&pq))
        {
            struct node* ptr = pq;

            printf("Enter the Task to be marked complete\n");
            scanf("%s",completed);

             while(ptr!= NULL && strcmp(ptr->data, remove) != 0)
            {
                ptr=ptr->next;
            }

            


        }
    }

    case 4:
    {
        if(!isEmpty(&pq))
        {
            struct node* ptr=pq;
            printf("Total Number of Tasks:  %d",numberOfTask);
            printf("\n\nPriority   Task\n");
            printf("--------   -----------------\n");
            while(ptr!=NULL)
            {
                
                printf("%-10d %s\n",ptr->priority, ptr->data);
                ptr=ptr->next;
            }

            printf("\n\n\n");
            
        }
        else
            {
                printf("\nNo Task Currently Added\n\n");
            }
        break;
    }
    case 5:
    {
        if(!isEmpty(&pq))
        {
            struct node* ptr=pq;
            int highestPriority=pq->priority;
            printf("Highest Priority Tasks\n");
            while(ptr != NULL && ptr->priority == highestPriority)
            {
                printf("%s \n",ptr->data);
                ptr=ptr->next;
            }
        }
        else
        {
            printf("\nNo Task Currently Added\n\n");
        }
        break;
    }
    case 6:
    {
        
    }
    case 7:
    {
        printf("I hope you complete all your Tasks,Have A Nice Day Goodbye\n");
        exit(0);
    }

    default:
    {
         printf("Invalid choice. Please select a valid option.\n");
    }
}



}

return 0;
}