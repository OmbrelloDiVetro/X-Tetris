/**
* \file menu.c
* \author Lorenzo e Aresù
* \brief funzioni per il menu del gioco
*
*/
#include <stdio.h>
#include <string.h>
#include "mode.h"

/**
 * Stampa a schermo con padding e bordo
 *
 *@param txt stringa che viene stampato
 */
void easyPadding(char* txt )
{/*for making the text look nice */
    unsigned int i;
    unsigned int margin = 4;
    unsigned int len = 70;

    printf("|");

    for(i = 0; i < margin; i++)
        printf(" ");

    printf("%s", txt);

    for(i = strlen(txt); i < len; i++)
        printf(" ");

    printf("|\n");
}

/**
 * Stampa a schermo il titolo "Tetris" e il nome degli autori del programma
 *
 *
 */
void title()
{
    printf("\n\n\n");
    easyPadding("Tetris!");
    easyPadding("by Lorenzo Senarigo, Aresu Sadeghi Gol");
    printf("\n\n\n");
}

/**
 * Stampa a schermo le regole del gioco "Tetris"
 *
 *
 */
void rules()
{
    char go_back;
    do
    {
        easyPadding("Tetris");
        easyPadding("Rules:");
        printf("\n");
        easyPadding("Single Player");
        easyPadding("Si hanno inizialmente a disposizione 20 pezzi per ciascun tipo, e 1");
        easyPadding("mossa consiste nello scegliere quale pezzo giocare, dovi farlo cadere");
        easyPadding("e con quale rotazione(4 rotazioni per pezzo disponibili).");
        easyPadding("Una volta posizionato un pezzo, se una o piu righe orizzontali");
        easyPadding("vengono riempite per intero, queste righe vengono cancellate come nel");
        easyPadding("tetris originale.");
        easyPadding(" ");
        easyPadding("La rimozione di 1 riga vale 1 punto, la rimozione di 2 righe con 1");
        easyPadding("solo pezzo vale 3 punti, 3 righe 6 punti, 4 righe 12 punti.");
        easyPadding("Il gioco termina quando finiscono i pezzi o il giocatore non riesce a");
        easyPadding("posizionare un tetramino nel campo di gioco rispettando il limite di");
        easyPadding("altezza.");
        easyPadding(" ");
        easyPadding(" ");
        easyPadding("Multi Player");
        easyPadding("Due giocatori giocano a turni alterni, ciascuno nel proprio campo di");
        easyPadding("gioco ma pescando dallo stesso insieme di tetramini.");
        easyPadding("In questa modalita si avranno 40 pezzi a disposizione.");
        easyPadding("Nel caso in cui un giocatore cancelli una o due linee simultaneamente");
        easyPadding(", il gioco procede come per il caso single player.");
        easyPadding("Nel caso il giocatore cancelli 3 o piu linee con una singola mossa,");
        easyPadding("il campo avversario viene modificato invertendo il");
        easyPadding("corrispondente numero di linee nella parte piu bassa della tavola:");
        easyPadding("una posizione vuota diventa piena e viceversa.");
        easyPadding("Un giocatore perde la partita se non posiziona correttamente un pezzo");
        easyPadding("nel proprio campo di gioco.");
        easyPadding("Se i pezzi finiscono vince il giocatore con il punteggio piu alto.");
        printf("\n");
        easyPadding("Premi invio per tornare al menu' principale");
        scanf("%c", &go_back);
    }while(!getchar());
}

/**
 * Chiama la funzione per iniziare a giocare da soli
 *
 *
 */
void singlePlayerMode()
{
    modeSingle();
}

/**
 * Stampa a schermo e permette di scegliere tra le due modalità multi player, contro la CPU o contro un giocatore umano
 *
 *
 */
void multiPlayerMode()
{
    char yesNo[250] = "a";
    do
    {
        easyPadding("Vuoi giocare contro un amico?");
        easyPadding("Inserisci y se si e n altrimenti");
        
        scanf("%s", yesNo);
        if(strlen(yesNo) == 1)
        {
            switch(yesNo[0])
            {
                case 'y':
                    modePvP();
                    break;
                case 'n':
                    modePvE();
                    break;
                default:
                    easyPadding("Input non valido!");
            }
        }
        else
            easyPadding("Non hai inserito un'opzione corretta, ripeti l'inserimento");

    } while((yesNo[0] != 'y' && yesNo[0] != 'n') || strlen(yesNo) > 1 );
}

/**
 * Stampa a schermo e permette di scegliere la modalità di gioco
 *
 * \return ritorna la scelata fatta dal giocatore
 */
int modeChoice()
{
    int choice = 9;

    do
    {
        easyPadding("Scegli la modalita' di gioco:");
        easyPadding("1. Single Player");
        easyPadding("2. Multi Player");
        easyPadding("3. Torna al menu' principale");
        scanf("%d", &choice);
        if(choice < 1 || choice > 3)
            easyPadding("Ripeti la scelta.");
    }
    while(choice < 1 || choice > 3);

    return choice;
}

/**
 * Funzione principale del menù
 *
 * \param status stato che  permette di scegliere se vedere le regole, scegliere modalità di gioco o uscire dal gioco
 */
void menu(int* status)
{
    int choice = 9;
    int gameMode;
    title();
    do
    {
        do
        {
            easyPadding("1. Regole");
            easyPadding("2. Modalita' di gioco");
            easyPadding("3. Esci dal gioco");
            scanf("%d",&choice);
            switch (choice)
            {
                case 1:/*shows the rules*/
                    rules();
                    break;
                case 2:/*chose if to play alone or with a friend*/
                    gameMode = modeChoice();
                    if(gameMode != 3)/*enters the mode you chose*/
                        *status = gameMode;
                    else
                        choice = 9;
                    break;
                case 3:
                    easyPadding("A presto!");
                    *status = choice;
                    break;
                default:
                    easyPadding("Ripeti la scelta.");
                    break;
            }
        }
        while (choice != 3 && choice !=2);
    }
    while(*status != 3 && *status != 1 && *status != 2);
}