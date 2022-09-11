/**
* \file mode.h
* \author Lorenzo e Aresù
* \brief libreria per la gestione delle modalità e delle partite
*
*/
#ifndef MAIN_C_MODE_H
#define MAIN_C_MODE_H
#include "dataType.h"

/**
 * Funzione della partita multiplayer contro la CPU
 *
 * \param Player1 stato della tabella di gioco del primo gioctore
 * \param Player2 stato della tabella di gioco della CPU
 * \param piece_count numero di pezzi rimanenti
 * \param pieces pointers ai pezzi selezionabili
 */
void PvEGame(GameState Player1, GameState Player2, int piece_count[7], Piece* pieces [7]);

/**
 * Funzione della partita multiplayer contro un altra persona
 *
 * \param Player1 stato della tabella di gioco del primo gioctore
 * \param Player2 stato della tabella di gioco del secondo giocatore
 * \param piece_count numero di pezzi rimanenti
 * \param pieces pointers ai pezzi selezionabili
 */
void PvpGame(GameState Player1, GameState Player2, int piece_count[7], Piece* pieces[7]);

/**
 * Funzione della partita single player
 *
 * \param Player stato della tabella di gioco del giocatore
 * \param piece_count numero di pezzi rimanenti
 * \param pieces pointers ai pezzi selezionabili
 */
void SinglePlayerGame(GameState Player, int piece_count[7], Piece* pieces[7]);

/**
 * Funzione per il setup della partita multi player contro la CPU
 *
 *
 */
void modePvE();

/**
 * Funzione per il setup della partita multi player contro un altra persona
 *
 *
 */
void modePvP();

/**
 * Funzione per il setup della partita single player
 *
 *
 */
void modeSingle();

#endif 
