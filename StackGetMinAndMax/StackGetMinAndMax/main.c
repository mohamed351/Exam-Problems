#include<stdio.h>
#include<stdlib.h>
struct Node {

	int data;
	struct Node* next;

};

void Push(struct Node** stackNode, int data) {

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode == NULL) {
		printf("Stackover flow \n");
		return;
	}
	newNode->data = data;
	newNode->next = NULL;
	if (*stackNode == NULL) {

		*stackNode = newNode;
	}
	else {
		newNode->next = *stackNode;
		*stackNode = newNode;
	}

}
int Pop(struct Node** stackNode) {
	int x = -1;
	if (*stackNode == NULL) {
		printf("stack is empty");
		return -1;
	}
	else {
		struct Node* temp = (*stackNode);
		*stackNode = (*stackNode)->next;
		x = temp->data;
	}
	return x;

}
int isEmpty(struct Node* stack) {

	return stack == NULL;
}
int peek(struct Node* stack, int index) {

	int x = -1;
	for (int i = 0;i < index && stack != NULL;i++) {
		stack = stack->next;
	}
	if (stack == NULL) {
		printf("Invalid Index \n");

	}
	else {
		x = stack->data;
	}
	return x;

}
int StackTop(struct Node* stack) {
	int x = -1;
	if (stack == NULL) {
		printf("Stack is Empty");
		return x;
	}
	else {
		x = stack->data;
	}
	return x;

}
void Display(struct Node* stack) {
	while (!isEmpty(stack))
	{
		int x = Pop(&stack);
		printf("%d \n", x);
	}
}
int GetMax(struct Node* stack) {

	int x = Pop(&stack);
	while (!isEmpty(stack))
	{
		int data = Pop(&stack);
		if (x < data) {
			x = data;
		}
	}
	return x;

}

int GetMin(struct Node* stack) {

	int x = Pop(&stack);
	while (!isEmpty(stack))
	{
		int data = Pop(&stack);
		if (x > data) {
			x = data;
		}
	}
	return x;

}
int main() {

	struct Node* node = NULL;
	Push(&node, 10);
	Push(&node, 20);
	Push(&node, 50);
	Push(&node, 30);
	Push(&node, 40);
	Display(node);
	printf("\n============Get Max================= \n");

	printf("Max :%d \n", GetMax(node));
	printf("Min :%d \n", GetMin(node));
	printf("Min :%d \n", GetMin(node));
	printf("Max :%d \n", GetMax(node));

	return 0;

}