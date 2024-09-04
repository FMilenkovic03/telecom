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
    if(consumers < 100){
    struct Consumer newConsumer; 

    printf("Ajoutez le nom du client : ");
    anf(" %[^\n]", newConsumer.name);

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