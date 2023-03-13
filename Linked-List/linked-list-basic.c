#include<stdio.h>
#include<stdlib.h>

struct Node{
	
	int data;
	struct Node* next;
}Node;

void InsertElementAtBeginingOfList(int x);
void Print();

struct Node* head;


void InsertElementAtBeginingOfList(int x){
	
	struct Node* temp = malloc(sizeof(Node)); //created new node of type Node

	temp->data = x;
	temp->next = head;
	head = temp;
}

void Print(){

	struct Node* temp1 = head; //created a temporary pointer to traverse the list and assigned to head value so that head remain unchanged

	printf("List is :: ");
	while(temp1 != NULL){
		
		printf("%d ",temp1->data);
		temp1 = temp1->next;

	}
	printf("\n");
}
int main(){
	
	head = NULL;
	int i,n,num;
	printf("Enter the number of elements :: ");
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		
		printf("Enter a number :: ");
		scanf("%d",&num);
		
		InsertElementAtBeginingOfList(num);
		Print();
	}

	return 0;
}

