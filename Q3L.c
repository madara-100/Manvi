#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insert(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void split(Node* P, Node** Q, Node** R) {
    Node* temp = P;
    int position = 1;

    while (temp != NULL) {
        if (position % 2 != 0) {
            // Insert into list Q (odd position)
            *Q = insert(*Q, temp->data);
        } else {
            // Insert into list R (even position)
            *R = insert(*R, temp->data);
        }
        temp = temp->next;
        position++;
    }
}

int main() {
    Node* P = NULL; // Original list
    Node* Q = NULL; // List containing odd-positioned elements
    Node* R = NULL; // List containing even-positioned elements

    // Creating linked list P

    int choice;
    // Create first linked list
    do{
        printf("\nPress 1: For Insertion in list");
        printf("\nPress 2: For Display the list");
        printf("\nPress 3: For Split the list P in Q and R");
        printf("\nPress 99: for exit");
        printf("\n\t Choice:  ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                    int data;
                    printf("\nEnter Data in P :");
                    scanf("%d",&data);
                    P = insert(P, data);                
                    break;
            case 2:
                    char ch;
                    fflush(stdin);
                    printf("\nEnter the LIST Name : ");
                    scanf("%c",&ch);
                    if (ch == 'P') {
                         displayList(P);
                     //    break;
                    } else if (ch == 'Q') {
                         displayList(Q);
                    //     break;
                    } 
                    else if (ch == 'R') {
                         displayList(R);
                    //     break;
                    } 
                    else {
                        printf("\nInvalid list name.\n");
                    }               
                    break;
            case 3:
                    split(P, &Q, &R);                  
                    break;
            case 99:
                    printf("\n*******Thanks for your time***********\n");
                    break;
            default:
                    printf("\n This is not Right Choice");
     }
    }while(choice!=99);
    return 0;
}




