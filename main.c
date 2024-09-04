#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Add new records
// View list of records
// Modify records
// View payment
// Search Records
// Delete records

void vider_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

struct Consumer
{
    char name[50];
    char phoneNumber[15];
    float usage;
    float totalBill;
};

struct Consumer consumers[100];

int consumerCount = 0;

void addConsumer()
{
    if (consumerCount < 100)
    {
        struct Consumer newConsumer;

        printf("Ajoutez le nom du client : ");
        scanf(" %[^\n]", newConsumer.name);

        printf("Entrez le numéro de téléphone: ");
        scanf(" %s", newConsumer.phoneNumber);

        printf("Entrez l'utilisation de forfait (Go): ");
        scanf("%f", &newConsumer.usage);

        newConsumer.totalBill = newConsumer.usage * 0.15;

        consumers[consumerCount++] = newConsumer;
    }
    else
    {
        printf("capacité maximale atteinte !");
    }
}

void viewConsumers()
{
    for (int i = 0; i < 100; i++)
    {
        printf("Consommateur %d:\n", i + 1);
        printf("Nom : %s\n", consumers[i].name);
        printf("Numéro de téléphone : %s\n", consumers[i].phoneNumber);
        printf("Utilisation d'énergie : %.2f kWh\n", consumers[i].usage);
        printf("Facture totale : %.2f €\n", consumers[i].totalBill);
        printf("----------------------------\n");
    }
}

void deleteConsumer(char phoneNumber[])
{
    int choix;
    char searchPhoneNumber[100];
    char searchName[100];
    int foundIndex = -1;

    printf("Entrez 1 pour rechercher par numéro de téléphone ou 2 pour le nom du consommateur : ");
    scanf("%d", &choix);
    vider_buffer();

    if (choix == 1)
    {
        printf("Entrez le numéro de téléphone : ");
        fgets(searchPhoneNumber, sizeof(searchPhoneNumber), stdin);
        searchPhoneNumber[strcspn(searchPhoneNumber, "\n")] = '\0';

        for (int i = 0; i < consumerCount; i++)
        {
            if (strcmp(consumers[i].phoneNumber, searchPhoneNumber) == 0)
            {
                foundIndex = i;
                break;
            }
        }
    }
    else if (choix == 2)
    {
        printf("Entrez le nom du consommateur : ");
        fgets(searchName, sizeof(searchName), stdin);
        searchName[strcspn(searchName, "\n")] = '\0'; // Supprimer le '\n'

        for (int i = 0; i < consumerCount; i++)
        {
            if (strcmp(consumers[i].name, searchName) == 0)
            {
                foundIndex = i;
                break;
            }
        }
    }
    else
    {
        printf("choix invalide");
    }
}

int main()
{
    printf("chose");
}