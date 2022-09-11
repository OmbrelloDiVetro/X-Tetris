/**
* \file turn.c
* \author Lorenzo e Aresù
* \brief funzioni usate ogni turno delle partite
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataType.h"

/**
 * Funzione per riempire la tavola di 0
 *
 * \param a tavola 10*15 da riempire di 0
 */
void fill_table_with_0(int a[][col])
{
    int i, j;
    for(i = 0; i<col; i++)
    {
        for(j = 0; j<rig; j++)
        {
            a[j][i] = 0;
        }
    }
}

/**
 * Stampa a schermo la tavola
 *
 *\param matrix tavola da gioco
 */
void print_table(int matrix [15][10])
{
    int i, j;
    printf("-------------------");
    for(i=0; i<rig; i++){
        printf("\n");
        for(j=0; j<col; j++){
            printf("%d ", matrix[i][j]);
        }
    }
    printf("\n");
    printf("-------------------\n");
    printf("0 1 2 3 4 5 6 7 8 9\n");
}

/**
 * Funzione per controllare se i pezzi sono esauriti
 *
 * \param piece_count numero di pezzi rimanenti
 * \return ritorna int 1 se i pezzi sono esauriti e 0 altromenti
 */
int game_over( int piece_count[7]){
    int i, found, piece_over;
    found=0;
    piece_over=1;

    for(i = 0; i < 7; ++i){
        piece_over*=(piece_count[i]==0);
    }
    if(piece_over){
        printf("Pezzi esauriti");
        return 1;
    }

    return found;
}

/**
 * Stampa a schermo in una riga tutti i tipi di pezzi da gioco e quanti ne rimangono
 *
 * \param piece_count numero di pezzi rimanenti
 * \param pieces pointers ai pezzi selezionabili
 */
void print_all_pieces_row(int piece_count[7], Piece* pieces[7])
{/*to print the pieces in a line*/
    int i, j, k;
    printf("------------------------------------\n");
    for(i = 0; i < 4; i++)
    {
        printf("|");
        for(j = 0; j < 7; j++)
        {

            for(k = 0; k < 4; k++)
            {
                if(pieces[j]->matrix[i][k] != 0)
                    printf("@");
                else
                    printf(" ");
            }
            printf("|");
        }
        printf("\n");

    }
    printf("------------------------------------\n");

    printf(" I %d L %d J %d O %d S %d T %d Z %d\n", piece_count[0],piece_count[1],piece_count[2],piece_count[3],piece_count[4],piece_count[5],piece_count[6]);
}

/**
 * Funzione per copiare un pezzo
 *
 * \param chose pezzo da copiare
 * \param copy matrice dove viene copiato il pezzo
 */
void copy_piece(int chosen[4][4], int copy [4][4]){
    int i, j;
    for (i = 0; i < 4; ++i){
        for(j = 0; j < 4 ; j++){
            copy[i][j]=chosen[i][j];
        }
    }
}

/**
 * Stampa a schermo e permette di scegliere quale dei sette pezzi inserire e se la scelta è valida
 *
 * \param chosen scelta del giocatore
 * 
 */
void is_a_piece(char chosen [50])
{
    while(strlen(chosen)>1 || (*chosen!='I' && *chosen!='J' && *chosen!= 'L' && *chosen!='S' && *chosen!= 'O'  && *chosen!='T' && *chosen!= 'Z')){
        printf("Selezione non valida \n");
        printf("Scegli il tuo pezzo tra: I, L, J, O, S, T, Z \n");
        chosen[0] = 'A';
        scanf("%s", &chosen[0]);
    }
}

/**
 * Funzione per controllare un tipo di pezzo selezionato è esaurito
 *
 * \param chosen pezzo selezionato
 * \param pieces pointers ai pezzi selezionabili
 * \param piece_count numero di pezzi rimanenti
 * \return ritorna int 1 se il pezzo è stato esaurito e 0 altromenti
 */
int out_of_pieces(char* chosen, Piece* pieces [7], int* piece_count)
{
    int i;
    for(i = 0; i < 7; i++)
    {
        if(pieces[i]->name == chosen[0])
        {
            if(piece_count[i] <= 0)
            {
                printf("Hai esaurito i pezzi di quel tipo: \n ");
                chosen[0] = 'A';
                return 0;
            }
            else
                return 1;

        }
    }
    return 0;
}

/**
 * Stampa a schermo e permette di scegliere uno dei sette tipi di pezzi
 *
 * \param pieces pointers ai pezzi selezionabili
 * \param piece_count numero di pezzi rimanenti
 * \return ritorna il pezzo scelto
 */
Piece* chosen_piece(Piece* pieces [7], int* piece_count)
{
    int i;
    char chosen[50];
    printf("Scegli il tuo pezzo tra: I, L, J, O, S, T, Z \n");
    /*printf("Write 50 character max \n");*/
    scanf("%s", chosen);

    do
    {
        is_a_piece(chosen);
    }while(!out_of_pieces(chosen, pieces, piece_count));

    for(i = 0; i < 7; ++i){
        if(chosen[0] == pieces[i]->name){
            piece_count[i]--;
            return pieces[i];
        }
    }
}

/**
 * Stampa a schermo e permette di scegliere di quanti gradi ruotare il pezzo
 *
 * \return ritorna la rotazione scelta
 * 
 */
int chosen_rotation(){
    int valid, degrees;
    char rotation [50];
    valid=0;
    printf("Seleziona di quanti gradi ruotarlo tra 0,90, 180 e 270 \n");
    scanf("%s", rotation);

    do{
        if(strcmp(rotation, "0") && strcmp(rotation, "90") && strcmp(rotation, "180") && strcmp(rotation, "270") ){
            printf("La rotazione selezionata non è valida, ripetere la selezione \n");
            scanf("%s", rotation);
        }
        else{
            valid=1;
        }
    } while(!valid);

    degrees= atoi(rotation);

    return degrees/90;

}

/**
 * Funzione per ruotare il pezzo di 90°*rotation_count
 *
 * \param piece pezzo
 * \param rotation_counter numero di volte per cui ruotare il pezzo di 90°
 */
void rotate_alt(int piece [4][4], int rotation_counter){
    int copy[4][4];

    while (rotation_counter > 0)
    {
        int i, j, k;
        copy_piece(piece, copy);

        for(i = 0; i < 4; ++i){
            k=3;
            for(j = 0; j < 4; ++j){
                piece[i][j]=copy[k--][i];
            }
        }
        rotation_counter--;
    }

}


/**
 * Funzione per spostare il pezzo nell'estremo alto a sinistra della matrice 4*4
 *
 * \param piece pezzo
 *
 */
void shift_piece(int piece [4][4]){
    int i, k, j;
    int start_col, start_row;

    int found;
    found=0;

    for(i=0; i<4 && !found; ++i){
        for(j=0; j<4 && !found; j++){
            if(piece[i][j] != 0){
                start_row=i;
                found=1;
            }
        }
    }
    
    found=0;
    for(i = 0; i < 4 && !found ; ++i){
        for(j = 0 ; j < 4 && !found ; ++j){
            if(piece[j][i] != 0){
                start_col=i;
                found=1;
            }
        }
    }
    


    for( i = 0 ; i < start_row ; ++i){
        for(k = 0 ; k < 3 ; k++){
            for (j = 0 ; j < 4 ; j++){
                piece[k][j]=piece[k+1][j];
            }
        }
        for(k = 0 ; k < 4 ; k++)
            piece[3][k]=0;
    }

    for( i = 0 ; i < start_col ; ++i){
        /*shifto tutto in alto*/
        for(k = 0 ; k < 3 ; k++){
            for (j = 0 ; j < 4 ; j++){
                piece[j][k]=piece[j][k+1];
            }
        }
        for( k = 0; k < 4 ; k++)
            piece[k][3]=0;
    }

}

/**
 * Funzione per ruotare il pezzo
 *
 * \param piece pezzo
 * \param rotation_counter numero di volte per cui ruotare il pezzo di 90°
 */
void rotate (int piece [4][4], int rotation_counter){
    int copy [4][4];
    int i, j, k, start_col, start_row, found;
    found=0;

    rotate_alt(piece, rotation_counter);

    if(rotation_counter!=0){
        shift_piece(piece);
    }
}

/**
 * Funzione per calcolare la larghezza del pezzo
 *
 * \param tetramino pezzo
 * \return ritorna la larghezza del pezzo
 */
int piece_width(int (*tetramino) [4]){
    int i, j, limit1 , limit2, found;
    found=0;

    for(i = 3; i >= 0 && !found; i--){

        for(j = 3; j >= 0 && !found; j--) {

            if(tetramino[j][i] != 0)
            {
                
                limit2 = i+1;
                found=1;
            }
        }
    }

    found=0;

    for(i=0; i<4 && !found; ++i){
        for(j=0; j<4 && !found; j++){
            if(tetramino[j][i] != 0){
                limit1=i;
                found=1;
            }
        }
    }
    
    return limit2-limit1;
}

/**
 * Funzione per calcolare l'altezza del pezzo
 *
 * \param tetramino pezzo
 * \return ritorna la l'altezza del pezzo
 */
int piece_height(int (*tetramino) [4]){
    int i, j, limit1 , limit2, found;
    found=0;

    for(i = 3; i >= 0 && !found; i--){

        for(j = 3; j >= 0 && !found; j--) {

            if(tetramino[i][j] != 0)
            {
                
                limit2 = i+1;
                found=1;
            }
        }
    }

    found=0;

    for(i=0; i<4 && !found; ++i){
        for(j=0; j<4 && !found; j++){
            if(tetramino[i][j] != 0){
                limit1=i;
                found=1;
            }
        }
    }
    /* printf("limite destro %d        limite sinistro %d \n", limit2, limit1);*/
    return limit2-limit1;
}

/**
 * Funzione controlla se una mossa spinge il pezzo fuori dalla tavola
 *
 * \param column colonna dove potrebbe essere inserito il pezzo
 * \param tetramino pezzo
 * \return ritorna 1 la selezione è valida e 0 altromenti
 */
int valid_selection(int column, int (*tetramino) [4] ){
    if (piece_width(tetramino)+column-1>=col || column<0 || column>= 10){
        return 0;
    }
    return 1;
}

/**
 * Stampa a schermo e permette di scegliere in che colonna inserire un pezzo
 *
 * \param tetramino pezzo
 * \return ritorna la colonna scelta
 */
int choose_position(int (* tetramino) [4]){
    int starting_column;

    printf("Dove vuoi inserire il pezzo? \n");

    printf("(Il pezzo verra' inserito alla destra della colonna scelta) \n");

    scanf("%d", &starting_column);

    while(!valid_selection(starting_column, tetramino)){
        printf("La posizione selezionata non è valida, ripetere la selezione: \n");

        scanf("%d", &starting_column);
    }
    return starting_column;
}

/**
 * Funzione per trovare da quale riga bisogna iniziare a copiare il pezzo sulla tavola
 *
 * \param tetramino pezzo
 * \param matrix tavola da gioco
 * \param starting_col colonna scelta per inserire il pezzo
 * \return ritorna la riga della tavola da cui cominciare a copiare il pezzo
 */
int placement(int (* tetramino) [4], int matrix [15][10], int starting_col){ /*mi dice in che riga posso mettere il pezzo*/

    int moves, valid, i, j;
    int width, height;

    width=piece_width(tetramino);
    height=piece_height(tetramino);

    moves=0;/*parto dalla prima riga (riga zero della tavola da gioco)*/
    valid=1; /*assumo posizione valida*/

    while(valid){
        if(moves + height - 1 < rig){

            for(i = 0; i < height; ++i){

                for(j = 0; j < width ; j++){
                    
                    if(tetramino[i][j] != 0   &&   matrix[moves+i][starting_col+j] != 0){
                        
                        valid = 0;
                    }
                }
            }
            valid? moves++: moves--;

        }
        else{
            
            valid = 0;
            moves--;
        }
    }
    return moves;
}

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
void update_table(int matrix [15][10], int piece [4][4], int height, int width, int start_row, int start_col){

    int i, j;

    for(i = 0; i < height; ++i){

        for(j = 0; j < width; j++){

            if(piece[i][j] != 0)
                matrix[start_row+i][start_col+j] = piece[i][j];
            
        }
    }
}

/**
 * Calcola il numero di righe eliminate e i punti ottenuti
 *
 * \param table tavola da gioco
 * \param points_counter punti ottenuti
 * \return ritorna il numero di righe eliminate
 */
int clear_line(int table[15][10],int* points_counter){
    int i, j, k, t;
    int cleared=0;
    int line_full;

    for(i = 0 ; i < 15; ++ i){
        line_full=1;
        for(j = 0; j < 10 ; j++){
            line_full*=(table[i][j]!=0); /*capisce se una linea è piena*/
        }
        if(line_full) {
            cleared++;
            for(k = i ; k > 0 ; k--){
                for(t = 0; t < 10 ; t++){
                    table[k][t]=table[k-1][t];
                }
            }
            for(t = 0 ; t < 10 ; t++)
                table[0][t]=0;
        }

    }
    if(cleared == 1)
        (*points_counter)++;
    else{
        *(points_counter) += 3 * cleared;
    }

    return cleared;
}

/**
 * Stampa il numero delle righe da invertire e partendo dal fondo della tavola, le invertisce
 *
 * \param table tavola da gioco
 * \param n righe da invertire
 */
void revert_table( int table[15][10], int n){

    int i, j;
    printf("Le tue ultime %d righe sono state invertite \n",n );
    for( i = rig-n; i < rig ; ++i){
        for( j = 0; j < col ; j++){
            if(table[i][j]==0) {
                table[i][j]=1;
            }
            else{
                table[i][j]=0;
            }
        }
    }
}