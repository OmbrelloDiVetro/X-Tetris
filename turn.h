/**
* \file turn.h
* \author Lorenzo e Aresù
* \brief libreria usate ogni turno delle partite
*
*/
#ifndef MAIN_C_TURN_H
#define MAIN_C_TURN_H
#include "dataType.h"

/**
 * Funzione per riempire la tavola di 0
 *
 * \param a la tavola
 */
void fill_table_with_0(int a[][col]);

/**
 * Stampa a schermo la tavola
 *
 * \param matrix tavola da gioco
 */
void print_table(int matrix [15][10]);

/**
 * Funzione per controllare  se i pezzi sono esauriti
 *
 * \param piece_count numero di pezzi rimanenti
 * \return ritorna int 1 se i pezzi sono esauriti e 0 altromenti
 */
int game_over( int piece_count[7]);

/**
 * Stampa a schermo in una riga tutti i tipi di pezzi da gioco e quanti ne rimangono
 *
 * \param piece_count numero di pezzi rimanenti
 * \param pieces pointers ai pezzi selezionabili
 */
void print_all_pieces_row(int piece_count[7], Piece* pieces[7]);

/**
 * Funzione per copiare un pezzo
 *
 * \param chose pezzo da copiare
 * \param copy matrice dove viene copiato il pezzo
 */
void copy_piece(int chosen[4][4], int copy [4][4]);

/**
 * Stampa a schermo e permette di scegliere quale dei sette pezzi inserire e se la scelta è valida
 *
 * \param chosen scelta del giocatore
 * 
 */
void is_a_piece(char chosen [50]);

/**
 * Funzione per controllare un tipo di pezzo selezionato è esaurito
 *
 * \param chosen pezzo selezionato
 * \param pieces pointers ai pezzi selezionabili
 * \param piece_count numero di pezzi rimanenti
 * \return ritorna int 1 se il pezzo è stato esaurito e 0 altromenti
 */
int out_of_pieces(char* chosen, Piece* pieces [7], int* piece_count);

/**
 * Stampa a schermo e permette di scegliere uno dei sette tipi di pezzi
 *
 * \param pieces pointers ai pezzi selezionabili
 * \param piece_count numero di pezzi rimanenti
 * \return ritorna il pezzo scelto
 */
Piece* chosen_piece(Piece* pieces [7], int* piece_count);

/**
 * Stampa a schermo e permette di scegliere di quanti gradi ruotare il pezzo
 *
 * \return ritorna la rotazione scelta
 * 
 */
int chosen_rotation();

/**
 * Funzione per ruotare il pezzo di 90°*rotation_count
 *
 * \param piece pezzo
 * \param rotation_counter numero di volte per cui ruotare il pezzo di 90°
 */
void rotate_alt(int piece [4][4], int rotation_counter);

/**
 * Funzione per spostare il pezzo nell'estremo alto a sinistra della matrice 4*4
 *
 * \param piece pezzo
 *
 */
void shift_piece(int piece [4][4]);

/**
 * Funzione per ruotare il pezzo
 *
 * \param piece pezzo
 * \param rotation_counter numero di volte per cui ruotare il pezzo di 90°
 */
void rotate (int piece [4][4], int rotation_counter);

/**
 * Funzione per calcolare la larghezza del pezzo
 *
 * \param tetramino pezzo
 * \return ritorna la larghezza del pezzo
 */
int piece_width(int (*tetramino) [4]);

/**
 * Funzione per calcolare l'altezza del pezzo
 *
 * \param tetramino pezzo
 * \return ritorna la l'altezza del pezzo
 */
int piece_height(int (*tetramino) [4]);

/**
 * Funzione controlla se una mossa spinge il pezzo fuori dalla tavola
 *
 * \param column colonna dove potrebbe essere inserito il pezzo
 * \param tetramino pezzo
 * \return ritorna 1 la selezione è valida e 0 altromenti
 */
int valid_selection(int column, int (*tetramino) [4] );

/**
 * Stampa a schermo e permette di scegliere in che colonna inserire un pezzo
 *
 * \param tetramino pezzo
 * \return ritorna la colonna scelta
 */
int choose_position(int (* tetramino) [4]);

/**
 * Funzione per trovare da quale riga bisogna iniziare a copiare il pezzo sulla tavola
 *
 * \param tetramino pezzo
 * \param matrix tavola da gioco
 * \param starting_col colonna scelta per inserire il pezzo
 * \return ritorna la riga della tavola da cui cominciare a copiare il pezzo
 */
int placement(int (* tetramino) [4], int matrix [15][10], int starting_col);

/**
 * Funzione per aggiornare la tavola da gioco
 *
 * \param matrix tavola da gioco
 * \param piece pezzo
 * \param height altezza del pezzo
 * \param width larghezza del pezzo 
 * \param starting_row riga della tavola da cui cominciare a copiare il pezzo
 * \param starting_col colonna scelta per inserire il pezzo
 */
void update_table(int matrix [15][10], int piece [4][4], int height, int width, int start_row, int start_col);

/**
 * Calcola il numero di righe eliminate e i punti ottenuti
 *
 * \param table tavola da gioco
 * \param points_counter punti ottenuti
 * \return ritorna il numero di righe eliminate
 */
int clear_line(int table[15][10],int* points_counter);

/**
 * Stampa il numero delle righe da invertire e partendo dal fondo della tavola, le invertisce
 *
 * \param table tavola da gioco
 * \param n righe da invertire
 */
void revert_table( int table[15][10], int n);

#endif 
