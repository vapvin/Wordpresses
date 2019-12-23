#include <stdio.h>
#define INF 10000

int arr[INF];

int count = 0;

void addBack(int data) {
    arr[count] = data;
    count++;
}

void addFirst(int data) {
    for(int i = count; i>=1; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = data;
    count++;
}

int show() {
    for(int i = 0; i < count; i++) {
        printf("%d", arr[i]);
    }
}

int main(void) {

    addBack(8);
    addBack(5);
    addBack(7);
    addBack(1);
    addFirst(2);
    addFirst(4);
    show();
    
    return 0;
}