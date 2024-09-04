#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Add new records 
//View list of records 
//Modify records 
//View payment 
//Search Records 
//Delete records


struct Consumer{
    char name[50]; 
    char phoneNumber[15]; 
    float usage; 
    float totalBill; 
};

struct Consumer consumers[100]; 


int consumerCount = 0;

void addConsumer(){
    if(consumerCount < 100){
    struct Consumer newConsumer; 

    printf("Ajoutez le nom du client : ");
    scanf(" %[^\n]", newConsumer.name);

    printf("Entrez le numéro de téléphone: ");
    scanf(" %s", newConsumer.phoneNumber);

    printf("Entrez l'utilisation de forfait (Go): ");
    scanf("%f", &newConsumer.usage);

    newConsumer.totalBill = newConsumer.usage * 0.15;

    consumers[consumerCount++] = newConsumer;
    }else{
        printf("capacité maximale atteinte !");
    }    
}

void viewConsumers(){
    for(int i=0;i<100;i++){
        printf("Consommateur %d:\n", i + 1);
        printf("Nom : %s\n", consumers[i].name);
        printf("Numéro de téléphone : %s\n", consumers[i].phoneNumber);
        printf("Utilisation d'énergie : %.2f kWh\n", consumers[i].usage);
        printf("Facture totale : %.2f €\n", consumers[i].totalBill);
        printf("----------------------------\n");
    }
}