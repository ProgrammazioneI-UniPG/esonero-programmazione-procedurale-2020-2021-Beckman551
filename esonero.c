//inclusione delle librerie
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>



int main () {

//dichiaro le variabili
time_t t;
srand((unsigned) time(&t));

char m[128];
char k[128];
char c[128];
int j;
int numero;

  //inserimento della stringa da cifrare
  printf ("Inserire una stringa M da cifrare di massimo 128 caratteri: ");
  fgets (m, 128, stdin);
  //pulisco il buffer con fflush
  fflush (stdin);
  printf ("Bene! Ora le verrà mostrato il menù nel quale potrà effettuare la sua scelta\n");

    printf ("\n*****MENU*****\n*Inserire il valore 1 per generare una chiave K in maniera manuale*\n*Inserire il valore 2 per generare una chiave K casuale*\n*Inserire il valore 3 per chiudere il programma*\n");
    do {
      printf ("\nInserisci un numero: ");
      scanf ("%d", &numero);
      //creazione del "menù" tramite lo switch e i case
      switch (numero) {
        case 1: printf ("Hai selezionato la prima voce!\n");
                  printf ("Ora digiti una stringa K che sarà la chiave di cifratura: ");
                  fgets (k, 128, stdin);
                  fflush (stdin);

                  //con il do while faccio reinserire la stringa K nel caso in cui sia minore della stringa M
                  do {
                    fgets(k, 128, stdin);
                    if(strlen(k) < strlen(m)) {
                    printf("ERRORE!Inserire nuovamente la chiave di cifratura K più grande della stringa M:");

                }
              } while (strlen(k) < strlen(m));

                          for(j = 0; j < strlen(k); j++) {

                          //xor utilizzato per cifrare
                          c[j] = m[j] ^ k[j];
                          m[j] = c[j] ^ k[j];
                          printf ("%d", c[j]);

                        }
                          printf ("\n|^| Ecco la stringa M cifrata e visualizzata come intero\n");
                          printf ("\nLa stringa M originaria è: %s\n", m);

        break;

        case 2: printf ("Hai selezionato la seconda voce\n");

                for(j = 0; j < strlen(m); j++) {

                //genero una k casuale
                k[j] = 32 + rand () % 96;
                printf ("%d", k[j]);
              }
                printf ("\n|^| Ecco la chiave K generata casualmente e visualizzata come intero\n");

                for (j = 0; j < strlen(m); j++) {

                  //xor utilizzato per cifrare
                  c[j] = k[j] ^ m[j];
                  m[j] = c[j] ^ k[j];
                  printf ("%d", c[j]);
                }
                  printf ("\n|^| Ecco la stringa M cifrata e visualizzata come intero\n");
                  printf ("\nLa stringa M originaria è: %s\n", m);
        break;

        case 3: printf ("Sei uscito ufficialmente dal programma\n");
        break;

        default:
        printf ("Il numero che hai selezionato non è presente nel menù. Riprova\n");
      }
    } while (numero != 1 && numero != 2 && numero != 3);
  }
