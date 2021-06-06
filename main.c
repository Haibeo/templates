#include<stdio.h>
#include<string.h>
#include "bst.h"
#define  PATH1 "/home/haile/Desktop/ds-algo/inp.txt" 
#define  PATH2 "/home/haile/Desktop/ds-algo/oup.txt" 


//function prototype
bst load(bst);
void store(bst);
void store_node(node*);

bst load(bst BST){
    FILE* ptr = fopen(PATH1,"r");
    char name[20];
    char email[20];
    while(!feof(ptr)){
        fscanf(ptr,"%s%s",name,email);
        BST = insert_node(BST,strlen(name),name,email);
    }
    fclose(ptr);
    return BST;
}

FILE* ptr2;
void store(bst BST){
    ptr2 = fopen(PATH2,"w+");
    in_order_traverse(BST,store_node);
    fclose(ptr2);
}

void store_node(node *Node){
    fprintf(ptr2,"%s  %s\n",Node->name,Node->email);
}

void find(bst BST){
    char name[20];
    printf("\nEnter name :");
    scanf("%s",name);
    node* Node = search_node(BST,strlen(name));
    if(Node == NULL){
        printf("\nNot found");
    }else{
        printf("\nFound student :");
        printf("\nName : %s",name);
        printf("\nEmail : %s",Node->email);
    }
}

void insert(bst* BST){
    char name[20];
    char email[20];
    printf("\nEnter name :");
    scanf("%s",name);
    printf("\nEnter email :");
    scanf("%s",email);
    *BST = insert_node(*BST,strlen(name),name,email);
}

void Remove(bst* BST){
    char name[20];
    printf("\nEnter name :");
    scanf("%s",name);
    *BST = delete_node(*BST,strlen(name));
}


int main(){
    bst BST = init_bst();
    int choice = 0;
    while(choice != 6){
        printf("\n\t1.Load\n\t2.Find\n\t3.Insert\n\t4.Remove\n\t5.Store\n\t6.Quit");
        printf("\nChoice :");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            BST = load(BST);
            break;
            case 2:
            find(BST);
            break;
            case 3:
            insert(&BST);
            break;
            case 4:
            Remove(&BST);
            break;
            case 5:
            store(BST);
            break;
            case 6:
            free_bst(BST);
            break;
        }
    }
    return 0;
}