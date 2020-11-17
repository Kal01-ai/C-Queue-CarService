/*
   Program ID:      Car.c
   OS:              Windows 10
   Interpreter:     Code::Blocks 20.03
   Note:            Car Wash Service using queue to add car, remove car, display cars and total number of cars.
                    Due to the limitations of using Queue, To avoid errors,
                    Make sure the Queue is FULL before doing any other operations.
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 5

char carToWash[SIZE][10] = {0};
int FRONT = -1, REAR = -1;

void enQueue(char* value) {
    if(REAR == SIZE - 1) {
        printf("Queue is Full!\n\n"); }
    else {
        if(FRONT == -1) {
            FRONT = 0; }
        REAR++;
        strcpy(carToWash[REAR], value);
        printf("Car Number %s has been added to Queue.\n\n", value);
    }
}

void deQueue() {
    if(FRONT == -1) {
        printf("\nQueue is Empty!\n\n"); }
    else if(FRONT <= REAR) {
        printf("\nFinished washing Car Number %s\n\n", carToWash[FRONT]);
        FRONT++;
    } else if(FRONT > REAR) {
        printf("\nThe last car has been washed. The Queue is now reset\n\n");
        FRONT = -1;
        REAR = -1;
    }
}

void display() {
    if(REAR == -1) {
        printf("\nThere are no cars in the Queue!\n\n"); }
    else {
        printf("\nThe cars in Queue are: \n\n");
        for(int i = FRONT; i <= REAR; i++) {
            printf("%s\n\n", carToWash[i]);
        }
    }
}

void totalNumber() {
    if(REAR == -1) {
        printf("\nTotal Number of Cars = 0\n\n"); }
    else {
        printf("\nTotal Number of Cars = \n");
        int total = 0;
        for(int i = FRONT; i <= REAR; i++) {
            total = total + 1;
        }
        printf("%d\n\n", total);
    }
}

int main()
{
    bool isTrue = true;
    while(isTrue) {
    printf("\n*****************************\n");
    printf("WELCOME TO CAR WASH SERVICE");
    printf("\n*****************************\n");
    printf("\n1. Add Car\n2. Remove Car\n3. List Available Cars\n4. Total Number of Cars\n5. Quit\n");

    int num;
    printf("\nPick a Number: ");
    scanf("%d", &num);

    switch(num)
    {
        case 1:
            printf("\nEnter the Car's Number Plate to add to the Queue: ");
            char carPlate[10];
            scanf("%s", carPlate);
            enQueue(carPlate);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        case 4:
            totalNumber();
            break;
        case 5:
            isTrue = false;
            break;
        default:
            printf("The program failed. Please restart the program.\n");
            isTrue = false;
            break;
    }
  }
  return 0;
}
