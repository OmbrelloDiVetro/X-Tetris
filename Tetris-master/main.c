/**
* \file main.c
* \author Lorenzo e Aresù
* \brief MAIN
* \section intro_sec Introduzione
*
* Abbiamo fatto una versione semplificata di Tetris in ASCII art,
* come specificato dalle indicazioni per il progetto.
*
*/
#include "menu.h"

/**
 * Funzione main del progetto Tetris
 *
 *
 */
int main()
{
    int status = 9;

    menu(&status);

    switch(status) {
        case 1:
            singlePlayerMode();
            break;
        case 2:
            multiPlayerMode();
            break;
        case 3:
            break;
        default:
            easyPadding("Errore");
    }
    return 0;
}
