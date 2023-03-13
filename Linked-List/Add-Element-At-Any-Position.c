#include<stdio.h>
#include<stdlib.h>

struct Node {

    int data;
    struct Node* next;

}Node;

void InsertElementAtAnyPos(int p,int v);
void Print();
struct Node* head;
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

    int pos,num,flag=1;
    
    while(flag != 0){

        printf("Kindly Enter whole number between 0 and %d",count);
        printf("Enter a position :: ");
        scanf("%d",&pos);
        printf("Enter a Number you want to add :: ");
        scanf("%d",&num);
        printf("\n");

        InsertElementAtAnyPos(pos,num);
        Print();
        printf("You want to exit? if yes enter 0 or else enter 1 :: ");
        scanf("%d",&flag);
    }


    return 0;
}