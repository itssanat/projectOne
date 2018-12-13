#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct node
{
    int info;
    bool isRightThread;
    struct node * left,*right;
};
typedef struct node NODE;

NODE *createNode(int x){
    NODE * p = (NODE *)malloc(sizeof(NODE));
    p->info = x;
    p->left = NULL;
    return p;
}

NODE * insert(NODE * root,int x)
{
    if(root == NULL){
        NODE *p = createNode(x);
        p->isRightThread = false;
        p->right = NULL;
        return p;
    }
    if(root->left == NULL && root->info > x){
        NODE *p = createNode(x);
        p->right = root;
        p->isRightThread = true;
        root->left = p;
        return root;
    }
    if(root->right == NULL && root->info <= x){
        NODE *p = createNode(x);
        p->isRightThread = false;
        p->right = NULL;
        root->right = p;
        return root;
    }
    if(root->isRightThread && root->info < x){
        NODE *p = createNode(x);;
        p->isRightThread = true;
        root->isRightThread = false;
        p->right = root->right;
        root->right = p;
        return root;
    }
    if(root->info > x)
        root->left = insert(root->left,x);
    else
        root->right = insert(root->right,x);
        
    return root;
}

void inorder(NODE * root){
    if(root == NULL){
        return ;
    }
    printf("inorder: ");
    while(root->left !=NULL)
        root = root->left;
    
    while(root != NULL){
        printf("%d ",root->info);
        if(root->isRightThread == 1)
        {   
            root = root->right;
        }
        else{
            root = root->right;
            if(root != NULL){
                while(root->left !=NULL)
                root = root->left;
            }
        }        
    }
    printf("\n");
}

void preorder(NODE * root){
    if(root == NULL){
        return ;
    }
    else if(root->left==NULL&&root->right==NULL)
        printf("%d ",root->info);
    else if((root->left == NULL && root->isRightThread)){
        printf("%d ",root->info);
    }
    else if(root->isRightThread){
        printf("%d ",root->info);
        preorder(root->left);
    }
    else {
        printf("%d ",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NODE * root){
    if(root == NULL){
        return;
    }
    else if(root->left == NULL && root->right == NULL) 
        printf("%d ", root->info);
    /*else if((root->left == NULL && root->isRightThread)){
        printf("%d ",root->info);
    }*/
    else if(root->isRightThread){
        postorder(root->left);
        printf("%d ",root->info);
    }
    else {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->info);
    }
}
/*
int succeser(NODE *root){
    if(root->left == NULL) return root->info;
    return succeser(root->left);
}*/

NODE * delete (NODE * root,int x){
    NODE *par = NULL, *curr = root;
    int flag = 0;
    while(curr != NULL){
        if(curr->info == x){
            flag = 1;
            break;
        }
        par = curr;
        if(x<curr->info){
            if(curr->left != NULL)
                curr = curr->left;
            else
                break;
        }
        else{
            if(curr->isRightThread == false) 
                curr = curr->right;
            else
                break;
        }
    }
    if(flag == 0){
        printf("element not found\n");
        return root;
    }
    if(curr->left != NULL && curr->isRightThread==false){
        NODE * suc = root->right;
        while(suc->left != NULL)
            suc = suc->left;
        curr->info = suc->info;
        curr->right = delete(curr->right,suc->info);
    }
    else if(curr->left != NULL || curr->isRightThread == false){
        NODE * tmp;
        if(curr->left != NULL)
            tmp = curr->left;
        else
            tmp = curr->right;

        if(par == NULL)
            root = tmp;

        if(par->left == curr)
            par->left = tmp;
        else
            par->right  =tmp;
        if(curr->left != NULL)
            tmp->right = curr->right;
        else{
            
        }
        free(curr);
    }
    else{
        if(par == NULL)
            root = NULL;
        else if(curr == par->left){
            par->left = curr->left;
        }
        else{
            par->isRightThread = true;
            par->right = curr->right;
        }
        free(curr);
    }
    return root;
}

int main()
{
    int x;
    NODE * root = NULL;
    printf("1. Insert a node into the TBT\n");
    printf("2. Delete a node from the TBT.\n");
    printf("3. Display the preorder traversal of the TBT.\n");
    printf("4. Display the inorder traversal of the TBT. \n");
    printf("5. Display the postorder traversal of the TBT.\n");
    printf("6. to exit\n");
    
    
    while(1){
        scanf("%d",&x);
        switch(x){
            case 1:
                printf("enter your info");
                int i;
                scanf("%d",&i);
                root = insert(root,i);
                break;
            case 2:
                printf("enter info to delete");
                int x;
                scanf("%d",&x);
                root = delete(root,x);
                break;
            case 3:
                printf("preorder: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                printf("postorder: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("invalid input....\n");
        }
    }
}