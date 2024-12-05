#include <stdio.h>
#include <stdlib.h>

// Define a structure for the tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to insert a node into the BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}


Node* findMin(Node* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}


Node* deleteNode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with one or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: Get the inorder successor
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int findHeight(Node* root) {
    if (root == NULL) return -1;
    int count=0;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    if (leftHeight > rightHeight) {
         count=leftHeight;
    }
    else{
        count=rightHeight;
    }
    count=count + 1;
    return count;
}

void display(Node* root) {
    if (root == NULL) {
        return;
    }
    // Recursively traverse the left subtree
    display(root->left);

    // Print the current node
    printf("%d ", root->data);

    // Recursively traverse the right subtree
    display(root->right);
}

// Function to count total nodes on the right-hand side of the root node
int countRightNodes(Node* root) {
    if (root == NULL)
     {
        return 0;
    }
    int count;
    count=countRightNodes(root->left) + countRightNodes(root->right) + 1;
    return count;
}

int main() {
    Node* root = NULL;
    int choice;
     do{
        printf("Press 1: Insertion in Binary Search Tree");
        printf("Press 2: Display the list");
        printf("Press 3: Delete a node in Binary Search Tree");
        printf("Press 4: smallest Node in Binary Search Tree");
        printf("Press 5: Total Children of  Binary Search Tree");
        printf("Press 6: Height of Binary Search Tree");
        printf("Press 7: Count Total Nodes in Binary Search Tree");
        printf("Press 99: for exit");
        printf("\n\t Choice:  ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                    int data;
                    printf("\nEnter Data in BST :");
                    scanf("%d",&data);
                    root= insert(root, data);                
                    break;
            case 2:
                    display(root);                  
                    break;
            case 3:
                     printf("Deleting node with value 30...\n");
                     root = deleteNode(root, 30);
                     break;
            case 4:
                    while (root != NULL && root->left != NULL) {
                         root = root->left;
                    }
                    printf("Smallest node in BST: %d\n", root->data);                
                    break;
            case 5:
                   int count;
                   if (root == NULL){ 
                        count =0;
                    }
                   if (root->left != NULL){ 
                        count++;
                    }
                   if (root->right != NULL) {
                        count++;
                   }
                   printf("Total children of root node: %d\n", count);                
                   break;
            case 6:
                    printf("Height of BST: %d\n", findHeight(root));                 
                    break;
            case 7:
                    printf("Total nodes on the right-hand side of root: %d\n", countRightNodes(root->right));                 
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



