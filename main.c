#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
        printf("Capacité maximale atteinte !\n");
    }
}

void viewConsumers()
{
    if (consumerCount == 0)
    {
        printf("Aucun consommateur à afficher.\n");
        return;
    }

    for (int i = 0; i < consumerCount; i++)
    {
        printf("Consommateur %d:\n", i + 1);
        printf("Nom : %s\n", consumers[i].name);
        printf("Numéro de téléphone : %s\n", consumers[i].phoneNumber);
        printf("Utilisation de forfait : %.2f Go\n", consumers[i].usage);
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
        searchName[strcspn(searchName, "\n")] = '\0';

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
        printf("Choix invalide !\n");
        return;
    }

    if (foundIndex != -1)
    {
        for (int i = foundIndex; i < consumerCount - 1; i++)
        {
            consumers[i] = consumers[i + 1];
        }
        consumerCount--;
        printf("Consommateur supprimé avec succès.\n");
    }
    else
    {
        printf("Consommateur non trouvé.\n");
    }
}

void modifyConsumer()
{
    int choix;
    char searchPhoneNumber[15];
    char searchName[50];
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
        searchName[strcspn(searchName, "\n")] = '\0';

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
        printf("Choix invalide !\n");
        return;
    }

    if (foundIndex != -1)
    {
        printf("Consommateur trouvé. Que voulez-vous modifier ?\n");
        printf("1. Nom\n");
        printf("2. Numéro de téléphone\n");
        printf("3. Utilisation (Go)\n");
        printf("4. Annuler\n");
        printf("Entrez votre choix : ");
        int modChoice;
        scanf("%d", &modChoice);
        vider_buffer();

        switch (modChoice)
        {
        case 1:
            printf("Entrez le nouveau nom : ");
            fgets(consumers[foundIndex].name, sizeof(consumers[foundIndex].name), stdin);
            consumers[foundIndex].name[strcspn(consumers[foundIndex].name, "\n")] = '\0';
            break;
        case 2:
            printf("Entrez le nouveau numéro de téléphone : ");
            fgets(consumers[foundIndex].phoneNumber, sizeof(consumers[foundIndex].phoneNumber), stdin);
            consumers[foundIndex].phoneNumber[strcspn(consumers[foundIndex].phoneNumber, "\n")] = '\0';
            break;
        case 3:
            printf("Entrez la nouvelle utilisation (Go) : ");
            scanf("%f", &consumers[foundIndex].usage);
            consumers[foundIndex].totalBill = consumers[foundIndex].usage * 0.15;
            break;
        case 4:
            printf("Modification annulée.\n");
            return;
        default:
            printf("Choix invalide !\n");
            return;
        }

        printf("Modification réussie.\n");
    }
    else
    {
        printf("Consommateur non trouvé.\n");
    }
}

void viewPayment()
{
    int choix;
    char searchPhoneNumber[15];
    char searchName[50];
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
        searchName[strcspn(searchName, "\n")] = '\0';

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
        printf("Choix invalide.\n");
        return;
    }

    if (foundIndex != -1)
    {
        printf("Facture totale pour %s : %.2f €\n", consumers[foundIndex].name, consumers[foundIndex].totalBill);
    }
    else
    {
        printf("Consommateur non trouvé.\n");
    }
}

void searchConsumer()
{
    int choix;
    char searchPhoneNumber[15];
    char searchName[50];
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
        searchName[strcspn(searchName, "\n")] = '\0';

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
        printf("Choix invalide.\n");
        return;
    }

    if (foundIndex != -1)
    {
        printf("Informations sur le consommateur %d:\n", foundIndex + 1);
        printf("Nom : %s\n", consumers[foundIndex].name);
        printf("Numéro de téléphone : %s\n", consumers[foundIndex].phoneNumber);
        printf("Utilisation : %.2f Go\n", consumers[foundIndex].usage);
        printf("Facture totale : %.2f €\n", consumers[foundIndex].totalBill);
    }
    else
    {
        printf("Consommateur non trouvé.\n");
    }
}

int main()
{
    int choix;

    while (1)
    {
        printf("\nMenu principal:\n");
        printf("1. Ajouter un consommateur\n");
        printf("2. Voir la liste des consommateurs\n");
        printf("3. Modifier un consommateur\n");
        printf("4. Supprimer un consommateur\n");
        printf("5. Voir le paiement d'un consommateur\n");
        printf("6. Rechercher un consommateur\n");
        printf("7. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        vider_buffer();

        switch (choix)
        {
        case 1:
            addConsumer();
            break;
        case 2:
            viewConsumers();
            break;
        case 3:
            modifyConsumer();
            break;
        case 4:
            {
                char phoneNumber[15];
                printf("Entrez le numéro de téléphone du consommateur à supprimer: ");
                fgets(phoneNumber, sizeof(phoneNumber), stdin);
                phoneNumber[strcspn(phoneNumber, "\n")] = '\0';
                deleteConsumer(phoneNumber);
            }
            break;
        case 5:
            viewPayment();
            break;
        case 6:
            searchConsumer();
            break;
        case 7:
            printf("Merci d'avoir utilisé notre système de gestion des consommateurs. Au revoir!\n");
            exit(0);
            break;
        default:
            printf("Choix invalide. Veuillez entrer un numéro entre 1 et 7.\n");
            break;
        }
    }

    return 0;
}
