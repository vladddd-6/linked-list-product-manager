#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produs
{
    int id;
    char nume[50];
    float pret;
    struct Produs* next;
};

struct Produs* adauga_produs(struct Produs* head)
{
    struct Produs* nou=(struct Produs*)malloc(sizeof(struct Produs));
    printf("ID: ");
    scanf("%d", &nou->id);
    printf("Nume: ");
    scanf("%s", nou->nume);
    printf("Pret: ");
    scanf("%f", &nou->pret);
    nou->next=head;
    return nou;
}

void afiseaza_produs(struct Produs* head)
{
    struct Produs* temp=head;
    while(temp!=NULL)
    {
        printf("ID: %d\n", temp->id);
        printf("Nume: %s\n", temp->nume);
        printf("Pret: %f\n", temp->pret);
         printf("\n");
        temp=temp->next;
    }
}

void cauta_produs(struct Produs* head)
{
    int id;
    printf("Introdu ID produs: ");
    scanf("%d", &id);
    struct Produs* temp=head;
    while(temp!=NULL)
    {
        if(temp->id==id)
        {
             printf("Produs gasit!\n");
            printf("Nume: %s\n", temp->nume);
            printf("Pret: %.2f\n", temp->pret);
            return;
        }
         temp = temp->next;
    }
    printf("Produsul nu exista.\n");
}

struct Produs* sterge_produs(struct Produs* head)
{
    int id;
    printf("Introdu ID-ul produsului de sters: ");
    scanf("%d", &id);

    struct Produs* temp =head;
    struct Produs* prev =NULL;

    while(temp!=NULL)
    {
        if(temp->id==id)
        {
            if(prev==NULL)
            {
                head=temp->next;
            }
            else
            {
                prev->next=temp->next;
            }

            free(temp);
            printf("Produs sters.\n");
            return head;
        }

        prev=temp;
        temp=temp->next;
    }

    printf("Produsul nu a fost gasit.\n");
    return head;
}



int main()
{
    struct Produs* head=NULL;
    int optiune;
    do{
        printf("\n1 Adauga produs\n");
        printf("2 Afiseaza produs\n");
        printf("0 Iesire\n");

        printf("Alege: ");
        scanf("%d", &optiune);
        switch(optiune)
        {
            case 1:
                head=adauga_produs(head);
                break;
            case 2:
                afiseaza_produs(head);
                break;
            case 3:
                cauta_produs(head);
                break;
            case 4:
                head=sterge_produs(head);
                break;
        }
    }while(optiune!=0);

    return 0;
}