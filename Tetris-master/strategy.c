/**
* \file strategy.c
* \author Lorenzo e Aresù
* \brief funzioni per la strategia di gioco della CPU
*
*/
#include "turn.h"
#include "dataType.h"

/**
 * Funzione per trovare le cime della tavola da gioco
 *
 * \param matrix tavola da gioco
 * \param tops cime della tavola da gioco
 */
void top_margin(int matrix[15][10], int* tops){
    int i, j;
    for(i = 0; i < 10 ; ++i){
        tops[i]=14;
    }

    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 15; j++)
        {
            if(matrix[j][i] != 0)
            {
                tops[i] = j;
                j=15;
            }
        }
    }
}

/**
 * Funzione per trovare una colonna adatta in cui mettere il pezzo I
 *
 * \param top cime della tavola da gioco
 * \param valid_columns colonne adatte per inserire il pezzo
 * \param height altezza del pezzo
 */
void I_check(int top[10], int* valid_columns, int height){
    int i;

    for(i = 0; i < 9; ++i){
        if(top[i] - height >= 0)
        {
            if(top[i+1]-top[i] < -2)
                valid_columns[i]=1;
            else if (top[i+1]-top[i] > 2)
                valid_columns[i+1]=1;
        }
    }
}

/**
 * Funzione per trovare una colonna adatta in cui mettere il pezzo L
 *
 * \param top cime della tavola da gioco
 * \param valid_columns colonne adatte per inserire il pezzo
 * \param height altezza del pezzo
 */
void L_check(int top[10], int* valid_columns, int height){
    int  i;
    for(i = 0; i < 8; ++i){
        if(top[i] - height >= 0)
            valid_columns[i]=(top[i] ==(top[i + 1] + 1) && top[i+2]==top[i+1]);
    }
}

/**
 * Funzione per trovare una colonna adatta in cui mettere il pezzo J
 *
 * \param top cime della tavola da gioco
 * \param valid_columns colonne adatte per inserire il pezzo
 * \param height altezza del pezzo
 */
void J_check(int top[10], int* valid_columns, int height){
    int i;
    for(i = 0; i < 8; ++i){
        if(top[i] - height >= 0)
            valid_columns[i]=(top[i]==top[i+1] && top[i+2]==top[i] + 1);
    }
}

/**
 * Funzione per trovare una colonna adatta in cui mettere il pezzo O
 *
 * \param top cime della tavola da gioco
 * \param valid_columns colonne adatte per inserire il pezzo
 * \param height altezza del pezzo
 */
void O_check(int top[10], int* valid_columns, int height){
    int i;
    for(i = 0; i < 9; ++i){
        if(top[i] - height >= 0){
            if(i!=8)
                valid_columns[i]=(top[i]==top[i+1] && top[i+2]-top[i] <= -1);
            else{
                valid_columns[i]=(top[i]==top[i+1] && top[i-1]-top[i] <= -1);
            }
        }
    }
}

/**
 * Funzione per trovare una colonna adatta in cui mettere il pezzo S
 *
 * \param top cime della tavola da gioco
 * \param valid_columns colonne adatte per inserire il pezzo
 * \param piece_height altezza del pezzo
 */
void S_check(int top[10], int valid_columns[10], int piece_height)
{
    int i;
    for(i = 0; i < 8; i++)
    {
        if(top[i] - piece_height >= 0)
        {
            if((top[i] == top[i + 1]) && (top[i + 2] == (top[i] - 1)))
            {
                valid_columns[i] = 1;
            }
        }
    }
}

/**
 * Funzione per trovare una colonna adatta in cui mettere il pezzo T
 *
 * \param top cime della tavola da gioco
 * \param valid_columns colonne adatte per inserire il pezzo
 * \param piece_height altezza del pezzo
 */
void T_check(int top[10], int valid_columns[10], int piece_height)
{
    int i;
    for(i = 0; i < 8; i++)
    {
        if(top[i] - piece_height >= 0)
        {
            if((top[i] == (top[i + 1] + 1)) && (top[i] == top[i + 2]))
            {
                valid_columns[i] = 1;
            }
        }
    }
}

/**
 * Funzione per trovare una colonna adatta in cui mettere il pezzo Z
 *
 * \param top cime della tavola da gioco
 * \param valid_columns colonne adatte per inserire il pezzo
 * \param piece_height altezza del pezzo
 */
void Z_check(int top[10], int valid_columns[10], int piece_height)
{
    int i;
    for(i = 0; i < 8; i++)
    {
        if(top[i] - piece_height >= 0)
        {
            if((top[i] == (top[i + 1] - 1)) && (top[i + 2] == top[i + 1]))
            {
                valid_columns[i] = 1;
            }
        }
    }
}

/**
 * Funzione per copiare la tavola da gioco
 *
 * \param copy matrice dove viene copiata la tavola da gioco
 * \param table tavola da gioco
 */
void copy_table(int copy[15][10], int table[15][10]){
    int i,j;
    for( i = 0; i < 15 ; ++i){
        for( j = 0; j< 10; j ++)
            copy[i][j]=table[i][j];
    }
}

/**
 * Funzione per calcolare quanti punti darebbe una mossa
 *
 * \param piece pezzo 
 * \param tops cime della tavola da gioco
 * \param valid colonne adatte per inserire il pezzo con rispettivo punteggio
 * \param table tavola da gioco
 */
void points_check(Piece piece, int tops[10], int valid[10], int table [15][10]){
    int i;
    for( i = 0; i < 10; ++i){
        if(valid[i] != 0){
            int copied_table[15][10];
            int cleared;
            int dummy;
            copy_table(copied_table, table);
            update_table(copied_table, piece.matrix, piece_height(piece.matrix), piece_width(piece.matrix), placement(piece.matrix, copied_table, i), i);
            cleared = clear_line(copied_table, &dummy );

            switch(cleared)
            {
                case 0:
                    valid[i] = 1;
                    break;
                case 1:
                    valid[i] = 2;
                    break;
                case 2:
                    valid[i] = 7;
                    break;
                case 3:
                    valid[i] = 10;
                    break;
                case 4:
                    valid[i] = 12;
                    break;
            }
        }
    }
}


/**
 * Funzione per trovare la mossa migliore
 *
 * \param all_scores punti possibili
 * \param max punteggio migliore
 * \return ritorna la colonna della mossa che da il punteggio migliore
 */
int max_score(int *all_scores, int* max){
    int i;
    int temp_max=all_scores[0];
    int max_index=0;

    for( i = 1; i < 10; ++i){
        if(all_scores[i]>temp_max){
            temp_max=all_scores[i];
            max_index=i;
        }
    }
    *max=temp_max;
    return max_index;
}

/**
 * Funzione per la selezione delle mosse della CPU
 *
 * \param piece_count numero di pezzi rimanenti
 * \param tops cime della tavola da gioco
 * \param table tavola da gioco
 * \param start_col colonna scelta per inserire il pezzo
 * \return ritorna il pezzo migliore da usare
 */
Piece* Check(int piece_count[7], int tops[10], int table[15][10], int *start_col){
    int i,j, all_one=1;
    int best_move, best_piece, best_column;
    int I_valid[10]={0,0,0,0,0,0,0,0,0,0};
    int L_valid[10]={0,0,0,0,0,0,0,0,0,0};
    int J_valid[10]={0,0,0,0,0,0,0,0,0,0};
    int O_valid[10]={0,0,0,0,0,0,0,0,0,0};
    int S_valid[10]={0,0,0,0,0,0,0,0,0,0};
    int T_valid[10]={0,0,0,0,0,0,0,0,0,0};
    int Z_valid[10]={0,0,0,0,0,0,0,0,0,0};
    int moves[2][7];

    if(piece_count[0]>0){
        I_check(tops, I_valid, piece_height(I.matrix));
        points_check(I, tops, I_valid, table );
    }
    if(piece_count[1]>0){
        L_check(tops, L_valid, piece_height(L.matrix));
        points_check(L, tops, L_valid, table );
    }
    if(piece_count[2]>0){
        J_check(tops, J_valid, piece_height(J.matrix));
        points_check(J, tops, J_valid, table );
    }
    if(piece_count[3]>0){
        O_check(tops, O_valid, piece_height(O.matrix));
        points_check(O, tops, O_valid, table );
    }
    if(piece_count[4]>0){
        S_check(tops, S_valid, piece_height(S.matrix));
        points_check(S, tops, S_valid, table );
    }
    if(piece_count[5]>0){
        T_check(tops, T_valid, piece_height(T.matrix));
        points_check(T, tops, T_valid, table );
    }
    if(piece_count[6]>0){
        Z_check(tops, Z_valid, piece_height(Z.matrix));
        points_check(Z, tops, Z_valid, table );
    }

    moves[1][0]=max_score(I_valid, &(moves[0][0]));
    moves[1][1]=max_score(L_valid, &(moves[0][1]));
    moves[1][2]=max_score(J_valid, &(moves[0][2]));
    moves[1][3]=max_score(O_valid, &(moves[0][3]));
    moves[1][4]=max_score(S_valid, &(moves[0][4]));
    moves[1][5]=max_score(T_valid, &(moves[0][5]));
    moves[1][6]=max_score(Z_valid, &(moves[0][6]));

    for( i = 0; i < 7 ; ++i){
        all_one &= (moves[0][i]==0);
    }

    if(all_one){
        int min = tops[0];
        int min_index=0;
        for(i = 0; i < 10; ++i){
            if( tops[i]> min){
                min=tops[i];
                min_index=i;
            }
        }
        *start_col=min_index;
    }

    best_move=moves[0][0];
    best_piece=0;
    best_column=moves[1][0];

    for(i = 1; i < 7 ; ++i){
        if(moves[0][i] > best_move){
            best_move = moves[0][i];
            best_piece = i;
            best_column=moves[1][i];
        }
    }

    if(!all_one){
        *start_col=best_column;
    }

    switch(best_piece){
        case 0: return &I;
        case 1: return &L;
        case 2: return &J;
        case 3: return &O;
        case 4: return &S;
        case 5: return &T;
        case 6: return &Z;
    }
    /*return piece dummy*/
}