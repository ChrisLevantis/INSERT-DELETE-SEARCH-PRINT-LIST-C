#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

void insertStart(struct node **head, int dataInserted) // edo ipotithete otui exis mesa idi stixia...
{
    if(*head == NULL)
    {
        printf("The List is NULL...");
        return;
    }

    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = dataInserted;

    new_node->next = *head;
    *head = new_node;
}

void insertAfter(struct node *prev_node, int dataInserted) // kai edo den mporis na exis null lista, diladi adia
{
    if (prev_node == NULL)
    {
        printf("Previus Node can not be NULLn\n");
        return;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->value = dataInserted;

    new_node->next = prev_node->next; // SOS --> ΜΗΝ ΤΑ ΒΑΛΕΙΣ ΑΝΑΠΟΔΑ...
    prev_node->next = new_node;
}

void insertAfter2(struct node **head, int key, int dataInserted) // kai edo den mporis na exis null lista, diladi adia
{
    if (*head == NULL)
    {
        printf("Empty list...\n");
        return;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->value = dataInserted;

    struct node *temp = *head;
    struct node *prev;

    while(temp != NULL && temp->value != key)
    {
        prev = temp;
        temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void append(struct node **head, int dataInserted) // εδω ή θα το βαλεις στο ΤΕΛΟΣ ή θα το βαλεις στην αρχη (με την προυπόθεση ότι η λίστα είναι άδεια) // ΠΡΟΣΕΧΕ ΚΑΙ ΒΑΛΕ ΔΥΟ **
{
        printf("\nTEST address of head append--> %p\n", &head);

    
    //1 dimiourgoume to node
    struct node *new_node = (struct node*)malloc(sizeof(struct node));

    /// tha to xrisimopoisoume an theloume na baloume sto telos
    struct node *last = *head;
    
    //2 dinoume timi sto new_node
    new_node->value = dataInserted;

    //3 dinoume sto next tou new_node tin timi NULL, giati i tha pai sto telos i tha pai stin arxi (an i lista einia adia)
    new_node->next = NULL;

    //4 tha tsekaroume an i lista einai adia
    if(*head == NULL)
    {
        *head = new_node;
        return;
    }
    
    //5 edo an theloume na baloume sto telos 
    while(last->next != NULL)
    {
        last = last->next; // se autin tin while kanis traverse mexri na ftasi sto telos
    }

    last->next = new_node;
    return;

}

void deleteAfter(struct node **head, int key) // edo diagrafis analoga me tin timi pou sou dinetai sto key..
{
    struct node *temp = *head; // apothikeuse to head stin metabliti temp
    struct node *prev;

    // an to head node apo mono tou exi tin timi pou prepi na diagrafi
    if(temp->value == key && temp != NULL)
    {  
        *head = temp->next;
        free(temp);
        return;
    }
    else
    {
        // kanis treversi oli tin lista mexri na bris to node p[ou exi to value pou thes, parallila kratas kai to prev, giati meta tha prepi na to alazis...
        while(temp != NULL && temp->value != key)
        {
            prev = temp;
            temp = temp->next;
        }
        // otam tha bgi apo tin while to temp tha dixni stin timi tou node pou exi tin timi pou theloume, kai to prev tha dixni sto proigoumeno node
        
        //an omos to temp exi gini NULL simaini oti den to brike
        if(temp == NULL)
        {
            printf("We could not find the key...");
            return;
        }
        
        prev->next = temp->next;
        free(temp);
    }
}

void deleteEnd(struct node **head)
{
    struct node *temp = *head; // last
    struct node *prev = *head;

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    // otan tha bgi apo edo to temp tha ne ston telaiutaio kombo kai to prev tha ne sto proteleutaio
    prev->next = NULL;
    free(temp);
}

void deleteStart(struct node **head)
{
    struct node *temp = *head;
    *head = temp->next;

    free(temp);
}

void searchKey(struct node* head, int key)
{
    printf("\nTEST address of head searchkey--> %p\n", &head);
    while(head != NULL && head->value != key)
    {
        head = head->next;
    }

    if(head == NULL)
    {
        printf("The key with value --> %d does not found...\n", head->value);
        return;
    }
    printf("The key with value --> %d found...\n", head->value);
}

void printList(struct node *n)
{
    if(n == NULL)
    {
        printf("Empty List...(in print)\n");
        return;
    }
    while (n != NULL)
    {
        printf("%d ", n->value);
        n = n->next;
    }
    printf("\n");
}

int main()
{
    // Dimiourgia 1ou Node pou tha ne adio stin arxi 
    struct node *head; // mallon to kathe node pou dimiourgis tha exi to diko toyu head poy mallon einai kai o diktis p...
    head = NULL;

    append(&head, 45);
    insertStart(&head, 12);
    searchKey(head, 12);
    insertAfter(head, 89);
    insertAfter2(&head, 12, 899);
    
    //insertStart(&head, 566);
    //append(&head, 789);
    //insertAfter(head, 159);
    //append(&head, 46);
    //insertAfter(head, 3);
    //deleteEnd(&head);
    //deleteStart(&head);

    //append(&head, 456);
    //insertStart(&head, 789);
    printList(head); 
    //insertAfter(head, 89);
    //insertStart(head, 89);

    /*
    // Dimiourgia 2ou Node
    struct node *head2;
    head2 = NULL;
    // Dimiourgia 3ou Node
    struct node *head3;
    head3 = NULL;

    head1 = (struct node *)malloc(sizeof(struct node));
    head2 = (struct node *)malloc(sizeof(struct node));
    head3 = (struct node *)malloc(sizeof(struct node));

    head1->value = 6; // bazis timi sto proto node
    head1->next = head2;

    head2->value = 34;
    head2->next = head3;

    head3->value = 56;
    head3->next = NULL;
   

    printf("--LIST BEFORE USE THE ADDAFTER FUNC--\n");
    printList(head1);

    printf("--LIST AFTER USE THE ADDAFTER FUNC--\n");
    insertAfter(head3, 898);
    printList(head3); 
    */
}
