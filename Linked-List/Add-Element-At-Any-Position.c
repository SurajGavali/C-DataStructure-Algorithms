#include<stdio.h>
#include<stdlib.h>

struct Node {

    int data;
    struct Node* next;

}Node;

void InsertElementAtAnyPos(int p,int v);
void Print();
void Delete();
struct Node* head;

void Delete(int n){

    struct Node* temp1 = head;
    int i;

    if(n==1){

        head = temp1->next;
        free(temp1);
    }
    else{

        for(i=0;i<n-2;i++){

            temp1 = temp1->next;
        }

        struct Node* temp2 = temp1->next;

        temp1->next = temp2->next;
        free(temp2);
    }

}
void Print(){

	struct Node* temp3 = head; //created a temporary pointer to traverse the list and assigned to head value so that head remain unchanged

	printf("List is :: ");
	while(temp3 != NULL){
		
		printf("%d ",temp3->data);
		temp3 = temp3->next;

	}
	printf("\n");
}

void InsertElementAtAnyPos(int p,int v){

    struct Node* temp1 = malloc(sizeof(Node));
    int i;
    temp1->data = v;
    temp1->next = NULL;

    if(p == 1){
        temp1->next = head;
        head = temp1;
        return;
    }

    struct Node* temp2 = head; 

    for(i=0;i<p-2;i++){

        temp2 = temp2 -> next;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}

int main(){

    head = NULL;
    int del;

    int pos,num,flag=1,count=1,delpos;
    
    while(flag != 0){

        printf("\nKindly Enter whole number between 0 and %d",count);
        printf("\nEnter a position to add number :: ");
        scanf("%d",&pos);
        printf("\nEnter a Number you want to add :: ");
        scanf("%d",&num);
        printf("\n");

        InsertElementAtAnyPos(pos,num);
	count++;
        Print();

        printf("Do you want to delete any number from list?(1/0) :: ");
	scanf("%d",&del);

	printf("\nvalue of del :: %d",del);
        if(del){
            printf("\nEnter Position to delete number :: ");
            scanf("%d",&delpos);

            if(delpos<count){
                Delete(delpos);
		        Print();
		        count--;
            }
            else{
                printf("\nPlease enter valid position!!!");
            }
            
	}
	printf("\nYou want to exit? if yes enter 0 or else enter 1 :: ");
        scanf("%d",&flag);
    }
    return 0;
}
