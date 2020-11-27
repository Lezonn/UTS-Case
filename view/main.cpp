#include "../controllers/controller.h"

void input(int n) {
    while(n--) {
        Profile c;
        char name[255];
        int date;
        char month[20];
        int year;
        scanf("%d %s %d - %[^\n]", &c.date, c.month, &c.year, c.name);
        getchar();
        pushPQ(c);
    }
}

void cureAll(int cure) {
    Node *curr = head;
    while(curr && cure) {
        removePQ();
        cure--;
    }
}

void printAll() {
    Node *curr = head;
    while(curr) {
        printf("%d %s %d - %s\n", curr->c.date, curr->c.month, curr->c.year, curr->c.name);
        curr = curr->next;
    }
}

int main() {
    int patients, cure;
    scanf("%d %d", &patients, &cure);
    input(patients);
    if(cure - patients >= 0) {
        printf("All patients get the cure, %d cure left\n", cure - patients);
    } else {
        cureAll(cure);
        printf("Need %d more cure\n", patients - cure);
        printAll();
        while(head) {
            removePQ();
        }
    }

    return 0;
}
