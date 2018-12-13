#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

struct node* insert( struct node* root, int data ) {
        
    if(root == NULL) {
    
        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
      
    } else {
      
        struct node* cur;
        
        if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
        } else {
            cur = insert(root->right, data);
            root->right = cur;
        }
    
        return root;
    }
}

int l= 0,r = -1;
int arr[1005],hi[1005];
void f(struct node * root,int lev,int h){
    if(root == NULL)
        return ;
    if(lev > r ){
        arr[++r + 500] = root->data;
        hi[r + 500] = h;
        f(root->left,lev-1,h+1);
        f(root->right,lev+1,h+1);
    }
    else if(lev < l){
        arr[500 + (--l)] = root->data;
        hi[500 + l] = h;
        f(root->left,lev-1,h+1);
        f(root->right,lev+1,h+1);
    }
    else{
        if(hi[500+lev] > h){
            arr[500 + lev] = root->data;
            hi[500+ lev] = h;
        }
        f(root->left,lev-1,h+1);
        f(root->right,lev+1,h+1);
    }
}
void d(){
    int i;
    for(i=500+l; i<=500+r;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
void topView( struct node *root) {
    if(root != NULL){
        r++;
        arr[r + 500] = root->data;
        hi[r + 500] = 0;
        f(root->right,1,1);
        f(root->left,-1,1);
        d();
    }
}
int main() {
  
    struct node* root = NULL;
    
    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }
  
    topView(root);
    return 0;
}
