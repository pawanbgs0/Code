#include "a.h"

int main()
{
    FILE *fptr;
    char temp[100];
    Node* tail = NULL;
    Node *head = NULL;

    fptr = fopen("data.txt", "r");

    do 
    {
        // fgets(temp.music, 100, fptr);
        // add_tail(&tail, temp);
        fgets(temp, 100, fptr);
        add_end(&tail, temp);

    }while (!feof(fptr));
    fclose(fptr);

    traverse_next(head);

    return 0;
}