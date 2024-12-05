#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold employee information
typedef struct Employee {
    int Emp_Id;
    char Name[50];
} Employee;

// Node structure for the linked list
typedef struct Node {
    Employee data;
    struct Node* next;
} Node;



Node* insert(Node* head, int Emp_Id, char* Name) {
    // Create a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data.Emp_Id = Emp_Id;
    strcpy(newNode->data.Name, Name);
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
        printf("Emp_Id: %d, Name: %s\n", temp->data.Emp_Id, temp->data.Name);
        temp = temp->next;
    }
}

int exists(Node* head, int Emp_Id) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data.Emp_Id == Emp_Id) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

Node* findUnion(Node* list1, Node* list2) {
    Node* unionList = NULL;
    Node* temp = list1;

    // Add all elements from list1
    while (temp != NULL) {
        if (!exists(unionList, temp->data.Emp_Id)) {
            unionList = insert(unionList, temp->data.Emp_Id, temp->data.Name);
        }
        temp = temp->next;
    }

    // Add elements from list2 that are not in list1
    temp = list2;
    while (temp != NULL) {
        if (!exists(unionList, temp->data.Emp_Id)) {
            unionList = insert(unionList, temp->data.Emp_Id, temp->data.Name);
        }
        temp = temp->next;
    }

    return unionList;
}


// Main function
int main() 
{
    Node* list1 = NULL;
    Node* list2 = NULL;
    Node* unionList = NULL;
    int choice;
    // Create first linked list
    do{
        printf("\nPress 1: For Insertion in list");
        printf("\nPress 2: For Display the list");
        printf("\nPress 3: For Getting Union of both list");
        printf("\nPress 99: for exit");
        printf("\n\t Choice:  ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                    int decision,id;
                    char name[30];
                    printf("\nEnter 1: for inserting Employee Data in List 1");
                    printf("\nEnter 2: for inserting Employee Data in List 2");
                    printf("\nEnter Decision : ");
                    scanf("%d",&decision);
                    if(decision == 1){
                        fflush(stdin);
                        printf("\t\tList 1");
                        printf("\nEnter Employee Name : ");
                        fgets(name, sizeof(name), stdin);
                        printf("\nEnter EMployee id :");
                        scanf("%d",&id);
                        list1 = insert(list1, id, name);
                    }else{
                        fflush(stdin);
                        printf("\t\tList 2");
                        printf("\nEnter Employee Name : ");
                        fgets(name, sizeof(name), stdin);
                        printf("\nEnter EMployee id :");
                        scanf("%d",&id);
                        list2 = insert(list2, id, name);
                    }              
                break;
            case 2:
                    int digit;
                    printf("There are three List which list you want to show \n1)List1\n2)List2\n3)unionList");
                    printf("\nEnter Choice : ");
                    scanf("%d",&digit);
                    switch(digit){
                        case 1: printf("\n Employee List 1\n");
                                displayList(list1);
                                break;
                        case 2: printf("\n Employee List 2\n");
                                displayList(list2);
                                break;
                        case 3: printf("\n Employee List union List\n");
                                displayList(unionList);
                                break;
                        default: printf("\nEnter Wrong Choice");
                                 break;
                      }                  
                    break;
            case 3:
                    unionList = findUnion(list1, list2);                  
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
