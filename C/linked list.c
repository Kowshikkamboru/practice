#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Display list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at beginning
struct Node* insertBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Insert at position
struct Node* insertPosition(struct Node* head, int value, int pos) {
    if (pos == 1)
        return insertBeginning(head, value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Delete from beginning
struct Node* deleteBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete from end
struct Node* deleteEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    return head;
}

// Delete at position
struct Node* deletePosition(struct Node* head, int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    if (pos == 1)
        return deleteBeginning(head);

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
    return head;
}

// Search value
void search(struct Node* head, int key) {
    int pos = 1;
    while (head != NULL) {
        if (head->data == key) {
            printf("Value %d found at position %d\n", key, pos);
            return;
        }
        head = head->next;
        pos++;
    }
    printf("Value not found\n");
}

// Main
int main() {
    struct Node* head = NULL;
    int choice, value, pos;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertBeginning(head, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                head = insertEnd(head, value);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                head = insertPosition(head, value, pos);
                break;

            case 4:
                head = deleteBeginning(head);
                break;

            case 5:
                head = deleteEnd(head);
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = deletePosition(head, pos);
                break;

            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(head, value);
                break;

            case 8:
                display(head);
                break;

            case 9:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}