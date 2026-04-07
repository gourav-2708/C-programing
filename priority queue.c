#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    int priority;
    struct Node* next;
};
struct Node *front = NULL, *rear = NULL;
void enqueue(int data, int priority){
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  if(temp == NULL){
    printf("Queue Overflow !!!\n");
    return;
}
    else{
        temp->data = data;
        temp->priority = priority;
        temp->next = NULL;
        if(rear == NULL){
            rear = front = temp;
        }
        else{
            rear->next = temp;
            rear = temp;
        }
        printf("%d added into the queue !!!\n", data);
    }

}
struct Node* getHighestPriority(){
    struct Node* curr = front, *prev=NULL, *temp = NULL;
    int max = 0;
    while(curr != NULL){
        if(curr->priority > max){
            max = curr->priority;
            temp = prev;
        }
        prev = curr;
        curr = curr->next;
    }
    return temp;
}
int dequeue(){
  if(front == NULL && rear == NULL){
    printf("Queue underflow !!!\n");
    return -1;
    }
  else if(front == rear){
    int val = front->data;
    front = rear = NULL;
    return val;
  }
  else{
    struct Node* temp = getHighestPriority();
    int val;
    if(temp == NULL){
       val = front->data;
       front = front->next;
    }
        else{
            val = temp->next->data;
            temp->next = temp->next->next;
        }
        return val;
  }
}
int peek(){
   if(front == NULL && rear == NULL){
    printf("Queue underflow !!!\n");
    return -1;
    }
  else if(front == rear){
   return front->data;
  }
  else{
    struct Node* temp = getHighestPriority();
    int val;
    if(temp == NULL){
       val = front->data;
    }
        else{
            val = temp->next->data;
        }
        return val;
  }
}
void display(){
   if(front == NULL && rear == NULL)
    printf("Queue is empty !!!\n");
    else{
        struct Node* temp = front;
        while(temp != NULL)
        printf("Priority : -->Value : %d\n ", temp->priority, temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    int choice, value, res, priority;
    while(1){
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value to Enqueue: ");
                scanf("%d", &value);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(value, priority);
                break;
            case 2:
                value = dequeue();
                if(value != -1){
                    printf("Dequeued value: %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if(value != -1){
                    printf("Front value: %d\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
