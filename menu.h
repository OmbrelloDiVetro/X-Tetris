/**
* \file menu.h
* \author Lorenzo e Aresù
* \brief libreria per il menu del gioco
*
*/
#ifndef MAIN_C_MENU_H
#define MAIN_C_MENU_H

/**
 * Stampa a schermo con padding e bordo
 *
 *@param txt stringa che viene stampato
 */
void easyPadding(char*);

/**
 * Stampa a schermo il titolo "Tetris" e il nome degli autori del programma
 *
 *
 */
void title();

/**
 * Stampa a schermo le regole del gioco "Tetris"
 *
 *
 */
void rules();

 /**
 * Stampa a schermo e permette di scegliere la modalità di gioco
 *
 * \return ritorna la scelata fatta dal giocatore
 */
int modeChoice();

/**
 * Funzione principale del menù
 *
 * \param status stato che  permette di scegliere se vedere le regole, scegliere modalità di gioco o uscire dal gioco
 */
void menu(int*);

/**
 * Chiama la funzione per iniziare a giocare da soli
 *
 *
 */
void singlePlayerMode();

/**
 * Stampa a schermo e permette di scegliere tra le due modalità multi player, contro la CPU o contro un giocatore umano
 *
 *
 */
void multiPlayerMode();

#endif 
