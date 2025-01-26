#include <stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	int column;
	int row;
	struct Node* next;
};
void GenerateMaxtrix(struct Node **Head, int data , int row , int column ) {

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->column = column;
	newNode->next = NULL;
	newNode->row = row;
	if (*Head == NULL) {
		*Head = newNode;
	}
	else {
		newNode->next = *Head;
		(*Head) = newNode;
	}
}

void  ConvertLinkedListToArray(int arr[10][10],struct Node* ptr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (ptr != NULL) {
				if (ptr->row == i && ptr->column == j) {
					arr[i][j] = ptr->data;
					ptr = ptr->next;
				}
				else {
					arr[i][j] = 0;
				}
			}
			
		}
		
	}
}

void sortList(struct Node** head) {
	if (*head == NULL || (*head)->next == NULL)
		return;

	struct Node* current;
	struct Node* index = head;
	int tempData, tempRow, tempColumn;



	for (current = *head; current != NULL; current = current->next) {
		for (index = current->next; index != NULL; index = index->next) {
			
			if (current->row > index->row ||
				(current->row == index->row && current->column > index->column)) {
				// Swap data
				tempData = current->data;
				tempRow = current->row;
				tempColumn = current->column;

				current->data = index->data;
				current->row = index->row;
				current->column = index->column;

				index->data = tempData;
				index->row = tempRow;
				index->column = tempColumn;
			}
		}
	}
}
int main() {
	struct Node* ptr = NULL;



	

	//Assume it it sorted in column and rows
	GenerateMaxtrix(&ptr, 15, 2, 5);
	GenerateMaxtrix(&ptr, 9, 8, 9);
	GenerateMaxtrix(&ptr, 10, 2, 6);
	GenerateMaxtrix(&ptr, 9, 9, 9);
	GenerateMaxtrix(&ptr, 5, 0, 0);

	sortList(&ptr);
	int array[10][10] = { {0} };
	ConvertLinkedListToArray(array, ptr, 10, 10);


	//Display
	for (int i = 0;i < 10;i++) {

		for (int x = 0;x < 10;x++) {
			printf("%d ", array[i][x]);
		}
		printf("\n");
	}




	return 0;
}