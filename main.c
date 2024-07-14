#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct node node;
struct node {
    int data;
    node* next;
};
typedef struct element element;
struct element {
    node* first;
};

element* initialisation() {
    element* tete = malloc(sizeof(*tete));
    node* init = malloc(sizeof(*init));

    if(tete == NULL || init == NULL) {
        exit(EXIT_FAILURE);
    }
    init->data = 0;
    init->next = NULL;
    tete->first = init;

    return tete;
}

void insertValue(element* head,const int data) {
    node* nouveau = malloc(sizeof(*nouveau));

    if(head == NULL || nouveau == NULL) {
        exit(EXIT_FAILURE);
    }

    nouveau->data = data;
    nouveau->next = head->first;
    head->first = nouveau;
}

void reverseList(element* head) {
    node* previous = NULL;
    node* current = head->first;

    while(current!=NULL) {
        node* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head->first = previous;
}

void printList(const element* head) {
    node* current = head->first;
    while(current != NULL) {
        printf("%d->",current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void deleteList(element* head) {
     node *current = head->first,*delete = current->next;
    while (current!=NULL) {
        delete = current->next;
        free(current);
        current = delete;
    }
    head->first = NULL;
}

void verification(const element* head) {
    if(head->first == NULL) {
        printf("\n la liste a ete supprimee avec succes et l'espace liberee\n");
    }
    else {
        printf("\n la suppression a echouee...\n");
    }
}


int main(void)
{
    element* liste = initialisation();
    printf("entrez le nombre d'element de la liste !\n");
    int nbr = 0;
    scanf("%d",&nbr);

    for(int i=0;i<nbr;i++) {
        int value = 0;
        printf("\n entrez la valeur numero %d  :  ",i+1);
        scanf("%d",&value);
        insertValue(liste,value);
    }

    printf("\n affichage de la liste avant le renversement des nodes...\n");
    printList(liste);

    printf("effectuons maintenant le renversemenet de chaque node...\n ");
    reverseList(liste);

    printf("affichage de la liste renversee \n ");
    printList(liste);

    printf("passons maintenant a la suppression de la liste...\n ");
    deleteList(liste);

    printf("verification si la liste a ete supprimee...\n");
    verification(liste);

    return 0;
}
