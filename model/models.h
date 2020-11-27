struct Profile {
    int date;
    char month[20];
    int year;
    char name[255];
    int days;
};

struct Node {
    int value;
    Profile c;
    Node *next, *prev;
} *head, *tail;
