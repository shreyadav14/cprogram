#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node{
    int data;
    struct node* link;
}node;

void insert_at_front(node** head, int val){
    node* new = (node*)malloc(sizeof(node));
    new->data = val;
    new->link = *head;
    *head = new;
}

void insert_at_end(node** head, int val){
    node *temp = *head;
    node *new = (node*)malloc(sizeof(node));
    new->data = val;
    if(temp == NULL){
        *head = new;
    }
    else{
 while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new;              
    }
    new->link = NULL;
}

void insert_at_pos(node** head, int pos, int val) {
    node* new_node = malloc(sizeof(node));
    new_node->data = val;
    new_node->link = NULL;

    if (*head == NULL) {
        if (pos == 1) {
            *head = new_node;
        } else {
            printf("Invalid position\n");
            free(new_node); // don't leak memory
            return;
        }
    } else if (pos == 1) {
        new_node->link = *head;
        *head = new_node;
    } else {
        node* current = *head;
        int count = 1;
        while (current->link != NULL && count < pos - 1) {
            current = current->link;
            count++;
        }
        if (count == pos - 1) {
            new_node->link = current->link;
     current->link = new_node;
        } else {
            printf("Invalid position\n");
            free(new_node); // don't leak memory
        }
    }
}

int delete_from_front(node** head){
    if(*head == NULL){
        return INT_MIN;
    }
    else{
        int data = (*head)->data;
        node* temp = *head;
        *head = (*head)->link;
        free(temp);
        return data;
    }
}

int delete_from_end(node** head){
    if(*head == NULL){
        return INT_MIN;
    }
    else{
        node *temp = *head;
        node *prev = NULL;
        while(temp->link != NULL){
            prev = temp;
            temp = temp->link;
        }
        prev->link = NULL;
        int data = temp->data;
 free(temp);
        return data;
    }
}

int delete_by_pos(node** head, int pos){
    if(*head == NULL){
        return INT_MIN;
    }
    else if(pos == 1){
        int data = delete_from_front(head);
        return data;
    }
    else{
        node* current = *head;
        node* prev = NULL;
        int count = 0;
        while (current->link != NULL && count < pos - 1) {
            prev = current;
            current = current->link;
            count++;
        }
        if (count == pos - 1){
            prev->link = current->link;
            int data = current->data;
            free(current);
            return data;
        }
        else{
            return INT_MIN;
       }
    }
}

int delete_by_val(node** head, int val){
    if(*head == NULL){
        return INT_MIN;
    }
    else if(val == (*head)->data){
        int data = delete_from_front(head);
        return data;
    }
    else{
        node* current = *head;
        node* prev = NULL;
        while (current->link != NULL && current->data != val) {
            prev = current;
            current = current->link;
  }
        if (current->data == val){
            prev->link = current->link;
            int data = current->data;
            free(current);
            return data;
        }
        else{
            return INT_MIN;
        }
    }
}

void printll(node* head){
    while(head!=NULL){
        printf("%d->", head->data);
        head = head->link;
    }
    printf("NULL\n");
}

int main(){
    node* head = NULL;
    int pos,var,flag = 0;
    while(flag != 1){
        printf("[1] Insert at front\n[2] Insert at end\n[3] Insert at position\n[4] Delete from front\n[5] Delete from end\n[6] Delete by position\n[7] Delete by value\n[8] Print linked list\n[9] Exit\nEnter choice: ");
        int choice;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter number to insert at front: ");
            scanf("%d",&var);
  insert_at_front(&head,var);
            break;
        case 2:
            printf("Enter number to insert at end: ");
            scanf("%d",&var);
            insert_at_end(&head,var);
            break;
        case 3:
            printf("Enter position to insert: ");
            scanf("%d",&pos);
            printf("Enter number to insert: ");
            scanf("%d",&var);
            insert_at_pos(&head,pos,var);
            break;
        case 4:
            var = delete_from_front(&head);
            if(var != INT_MIN){
                printf("Deleted number: %d\n",var);
            }
            else{
                printf("List is empty\n");
            }
            break;
        case 5:
            var = delete_from_end(&head);
            if(var != INT_MIN){
                printf("Deleted number: %d\n",var);
            }
            else{
                printf("List is empty\n");
            }
            break;
        case 6:
            printf("Enter position to delete: ");
            scanf("%d",&pos);
  var = delete_by_pos(&head,pos);
            if(var != INT_MIN){
                printf("Deleted number: %d\n",var);
            }
            else{
                printf("Position out of range\n");
            }
            break;
        case 7:
            printf("Enter value to delete: ");
            scanf("%d",&pos);
            var = delete_by_val(&head,pos);
            if(var != INT_MIN){
                printf("Deleted number: %d\n",var);
            }
            else{
                printf("Value not found in list\n");
            }
            break;
        case 8:
            printll(head);
            break;
        case 9:
            flag = 1;
            break;
        default:
            printf("Invalid choise\n");
       }
}
}