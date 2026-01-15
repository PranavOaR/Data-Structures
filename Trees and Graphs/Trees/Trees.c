#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} TreeNode;


TreeNode *insert(TreeNode *root, int data) {
    if (root == NULL) {
        TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}


TreeNode *search(TreeNode *root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void inorder(TreeNode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


void preorder(TreeNode *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(TreeNode *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}


TreeNode *minValueNode(TreeNode *node) {
    while(node->left!=NULL){
        node = node->left;
    }
    return node;

}


TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        TreeNode *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

/* Main function */
int main() {
    TreeNode *root = NULL;
    int choice, data, key;

    while (1) {
        printf("\n--- BINARY SEARCH TREE MENU ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Delete\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(root, key))
                    printf("Key found\n");
                else
                    printf("Key not found\n");
                break;

            case 3:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}

