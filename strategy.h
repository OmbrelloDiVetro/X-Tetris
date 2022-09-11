/**
* \file strategy.h
* \author Lorenzo e Aresù
* \brief library per la strategia di gioco della CPU
*
*/
#ifndef MAIN_C_STRATEGY_H
#define MAIN_C_STRATEGY_H
#include "dataType.h"

/**
 * Funzione per trovare le cime della tavola da gioco
 *
 * \param matrix tavola da gioco
 * \param tops cime della tavola da gioco
 */
void top_margin(int matrix[15][10], int* tops);

/**
 * Funzione per trovare una colonna adatta in cui mettere il pezzo I
 *
 * \param top cime della tavola da gioco
 * \param valid_columns colonne adatte per inserire il pezzo
 * \param height altezza del pezzo
 */
void I_check(int top[10], int* valid_columns, int height);

/**
 * Funzione per trovare una colonna adatta in cui mettere il pezzo L
 *
 * \param top cime della tavola da gioco
 * \param valid_columns colonne adatte per inserire il pezzo
 * \param height altezza del pezzo
 */
void L_check(int top[10], int* valid_columns, int height);

/**
 * Funzione per trovare una colonna adatta in cui mettere il pezzo J
 *
 * \param top cime della tavola da gioco
 * \param valid_columns colonne adatte per inserire il pezzo
 * \param height altezza del pezzo
 */
void J_check(int top[10], int* valid_columns, int height);

/**
 * Funzione per trovare una colonna adatta in cui mettere il pezzo O
 *
 * \param top cime della tavola da gioco
 * \param valid_columns colonne adatte per inserire il pezzo
 * \param height altezza del pezzo
 */
void O_check(int top[10], int* valid_columns, int height);

/**
 * Funzione per trovare una colonna adatta in cui mettere il pezzo S
 *
 * \param top cime della tavola da gioco
 * \param valid_columns colonne adatte per inserire il pezzo
 * \param piece_height altezza del pezzo
 */
void S_check(int top[10], int valid_columns[10], int piece_height);

/**
 * Funzione per trovare una colonna adatta in cui mettere il pezzo T
 *
 * \param top cime della tavola da gioco
 * \param valid_columns colonne adatte per inserire il pezzo
 * \param piece_height altezza del pezzo
 */
void T_check(int top[10], int valid_columns[10], int piece_height);

/**
 * Funzione per trovare una colonna adatta in cui mettere il pezzo Z
 *
 * \param top cime della tavola da gioco
 * \param valid_columns colonne adatte per inserire il pezzo
 * \param piece_height altezza del pezzo
 */
void Z_check(int top[10], int valid_columns[10], int piece_height);

/**
 * Funzione per copiare la tavola da gioco
 *
 * \param copy matrice dove viene copiata la tavola da gioco
 * \param table tavola da gioco
 */
void copy_table(int copy[15][10], int table[15][10]);

/**
 * Funzione per calcolare quanti punti darebbe una mossa
 *
 * \param piece pezzo 
 * \param tops cime della tavola da gioco
 * \param valid colonne adatte per inserire il pezzo
 * \param table tavola da gioco
 */
void points_check(Piece piece, int tops[10], int valid[10], int table [15][10]);

/**
 * Funzione per trovare la mossa migliore
 *
 * \param all_scores punti possibili
 * \param max punteggio migliore
 * \return ritorna la mossa che da il punteggio migliore
 */
int max_score(int *all_scores, int* max);

/**
 * Funzione per la selezione delle mosse della CPU
 *
 * \param piece_count numero di pezzi rimanenti
 * \param tops cime della tavola da gioco
 * \param table tavola da gioco
 * \param start_col colonna scelta per inserire il pezzo
 * \return ritorna il pezzo migliore da usare
 */
Piece* Check(int piece_count[7], int tops[10], int table[15][10], int *start_col);

#endif 
