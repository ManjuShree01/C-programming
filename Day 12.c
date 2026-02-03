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
    else{
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
