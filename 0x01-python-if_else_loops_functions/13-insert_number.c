// Linked List in C Implementation code
#include<stdio.h>
#include<stdlib.h>
//stdlib is included because we will be using  ‘malloc’

// creating a node in linked list
struct Node {
    int data;
    struct Node* next;
    // Pointer pointing towards next node
};

//function to print the linked list
void display(struct Node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

struct Node* newNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insertion_sort(struct Node** head, struct Node* newNode)//function to insert data in sorted position
{
	//If linked list is empty
	if (*head == NULL || (*head)->data >= newNode->data)
	{
		newNode->next = *head;
		*head = newNode;
		return;
	}

	//Locate the node before insertion
	struct Node* current = *head;
	while (current->next != NULL && current->next->data < newNode->data)
		current = current->next;

	newNode->next = current->next;
	current->next = newNode;
}

// main function
int main()
{
    int k;
    //creating 4 pointers of type struct Node
    //So these can point to address of struct type variable
    struct Node* head = NULL;
    struct Node* node2 = NULL;
    struct Node* node3 = NULL;

    // allocate 3 nodes in the heap
    head =  (struct Node*)malloc(sizeof(struct Node));
    node2 = (struct Node*)malloc(sizeof(struct Node));
    node3 = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10; // data set for head node
    head->next = node2; // next pointer assigned to address of node2

    node2->data = 15;
    node2->next = node3;

    node3->data = 20;
    node3->next = NULL;

    printf("Linked list before insertion : ");
    display(head);

    printf("\nEnter data you want to insert: ");
    scanf("%d",&k);

    insertion_sort(&head, newNode(k));

    printf("Linked list after insertion : ");
    display(head);

    return 0;
