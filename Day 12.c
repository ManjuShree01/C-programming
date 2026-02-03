//Browser history
#include <stdio.h>
int history[10];
int top  = -1;
void push(int pageid){
    top++;
    history[top] = pageid;
    printf("The value %d pushed to array \n", pageid);
}
void pop(){
    if(top == -1){
        printf("`No history to go back");
    }
    else{
        printf("Removed page is: %d \n", history[top]);
        top--;
    }
}
void peek(){
    if(top == -1){
        printf("On homepage");
    }
    else{
        printf("Current web page is: %d \n", history[top]);
    }
}
void isempty(){
    if(top == -1){
        printf("On home page.\n");
    }
    else
    {
        printf("Not empty.\n");
    }
}
void Size(){
    printf("History pages are %d \n", top +1);
}
int main() {
    push(10);
    isempty();
    Size();
    pop();
    Size();
    return 0;
}

//Undo operation
#include <stdio.h>
int undo[10], top = -1;
void push(int actionID) {
    undo[++top] = actionID;
    printf("Action %d saved.\n", actionID);
}
void pop() {
    if (top == -1) printf("Nothing to undo.\n");
    else printf("Undo performed. Removed action %d\n", undo[top--]);
}
void peek() {
    printf("Last action: %d\n", undo[top]);
}
int main() {
    push(1);
    push(2); 
    push(3); // Type A, B, C
    pop();                     // Undo C
    peek();                    // Shows B
    return 0;
}

//Plate in Cafe
#include <stdio.h>
#include <stdlib.h>
struct Plate {
    int id;
    struct Plate* next;
};
struct Plate* top = NULL;
void push(int id) {
    struct Plate* newPlate = malloc(sizeof(struct Plate));
    newPlate->id = id;
    newPlate->next = top;
    top = newPlate;
    printf("Plate P%d added.\n", id);
}
void pop() {
    if (top == NULL) return;
    struct Plate* temp = top;
    printf("Plate P%d removed.\n", top->id);
    top = top->next;
    free(temp);
}
int main() {
    push(1); push(2); push(3); // P1, P2, P3
    pop();                     // Removes P3
    printf("Top plate: P%d\n", top->id);
    return 0;
}

//Call Stack
#include <stdio.h>
#include <stdlib.h>
struct Function {
    char* name;
    struct Function* next;
};
struct Function* current = NULL;
void push(char* funcName) {
    struct Function* newCall = malloc(sizeof(struct Function));
    newCall->name = funcName;
    newCall->next = current;
    current = newCall;
    printf("Calling: %s\n", funcName);
}
void pop() {
    if (current == NULL) return;
    printf("Finished: %s\n", current->name);
    struct Function* temp = current;
    current = current->next;
    free(temp);
}
int main() {
    push("main"); push("func1"); push("func2");
    pop(); // func2 ends
    printf("Currently executing: %s\n", current->name);
    return 0;
}

//Ticket counter
#include <stdio.h>
int queue[10], front = 0, rear = -1, count = 0;
void enqueue(int id) {
    queue[++rear] = id;
    count++;
    printf("Customer %d joined the line.\n", id);
}
void dequeue() {
    if (count == 0) printf("Queue is empty.\n");
    else {
        printf("Customer %d served and left.\n", queue[front++]);
        count--;
    }
}
void showFront() {
    printf("Next customer to be served: %d\n", queue[front]);
}
void size() {
    printf("Total customers waiting: %d\n", count);
}
int main() {
    enqueue(101);
    enqueue(102);
    enqueue(103);
    dequeue();   // Removes 101
    showFront(); // Shows 102
    size();      // Shows 2
    return 0;
}

//Job management
#include <stdio.h>
int printerQueue[10], front = 0, rear = -1, count = 0;
void enqueue(int jobID) {
    printerQueue[++rear] = jobID;
    count++;
    printf("Job J%d added to printer.\n", jobID);
}
void dequeue() {
    if (count == 0) printf("No jobs to print.\n");
    else {
        printf("Printing... Job J%d finished.\n", printerQueue[front++]);
        count--;
    }
}
void showFront() {
    if (count > 0) printf("Next job in line: J%d\n", printerQueue[front]);
}
int main() {
    enqueue(1); // J1
    enqueue(2); // J2
    enqueue(3); // J3
    dequeue();   // Prints J1
    showFront(); // Shows J2
    return 0;
}

//Patient
#include <stdio.h>
#include <stdlib.h>
struct Patient {
    int id;
    struct Patient* next;
};
struct Patient *front = NULL, *rear = NULL;
int count = 0;
void enqueue(int patientID) {
    struct Patient* newPatient = malloc(sizeof(struct Patient));
    newPatient->id = patientID;
    newPatient->next = NULL;
    
    if (rear == NULL) front = rear = newPatient;
    else {
        rear->next = newPatient;
        rear = newPatient;
    }
    count++;
    printf("Patient P%d registered.\n", patientID);
}
void dequeue() {
    if (front == NULL) return;
    struct Patient* temp = front;
    printf("Patient P%d sent to doctor.\n", front->id);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    count--;
}
int main() {
    enqueue(1); enqueue(2); enqueue(3); // P1, P2, P3
    dequeue();                          // P1 leaves
    if (front) printf("Next patient: P%d\n", front->id);
    printf("Patients waiting: %d\n", count);
    return 0;
}

//Online shopping
#include <stdio.h>
#include <stdlib.h>
struct Order {
    int id;
    struct Order* next;
};
struct Order *front = NULL, *rear = NULL;
int count = 0;
void enqueue(int orderID) {
    struct Order* newOrder = malloc(sizeof(struct Order));
    newOrder->id = orderID;
    newOrder->next = NULL;

    if (rear == NULL) front = rear = newOrder;
    else {
        rear->next = newOrder;
        rear = newOrder;
    }
    count++;
    printf("Order O%d placed.\n", orderID);
}
void dequeue() {
    if (front == NULL) {
        printf("No orders to process.\n");
        return;
    }
    struct Order* temp = front;
    printf("Order O%d processed and dispatched.\n", front->id);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    count--;
}
int main() {
    enqueue(101); enqueue(102); enqueue(103);
    dequeue(); // Process O101
    if (front) printf("Next order to process: O%d\n", front->id);
    printf("Pending orders: %d\n", count);
    return 0;
}
