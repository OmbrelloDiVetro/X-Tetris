/**
* \file mode.c
* \author Lorenzo e Aresù
* \brief funzioni per la gestione delle modalità e delle partite
*
*/
#include <stdio.h>
#include "strategy.h"
#include "turn.h"
#include "dataType.h"

/**
 * Funzione della partita multiplayer contro la CPU
 *
 * \param Player1 stato della tabella di gioco del primo gioctore
 * \param Player2 stato della tabella di gioco della CPU
 * \param piece_count numero di pezzi rimanenti
 * \param pieces pointers ai pezzi selezionabili
 */
void PvEGame(GameState Player1, GameState Player2, int piece_count[7], Piece* pieces [7]){
    int lines_cleared;
    int tops[10];
    fill_table_with_0(Player1.table);
    Player1.points=0;
    printf("  Campo del Player 1 \n");
    print_table(Player1.table);

    fill_table_with_0(Player2.table);
    Player2.points=0;
    printf("  Campo della CPU \n");
    print_table(Player2.table);

    while(!game_over(piece_count)){
        /*TURNO PLAYER 1*/

        printf("Player 1, il tuo punteggio è :%d \n", Player1.points);
        print_all_pieces_row(piece_count, pieces);

        copy_piece(chosen_piece(pieces, piece_count)->matrix, Player1.piece);
        Player1.rotation=chosen_rotation();
        rotate(Player1.piece, Player1.rotation);

        Player1.width=piece_width(Player1.piece);
        Player1.height=piece_height(Player1.piece);

        Player1.start_col=choose_position(Player1.piece);
        Player1.start_row=placement(Player1.piece, Player1.table, Player1.start_col);


        if(Player1.start_row < 0 || Player1.table[Player1.start_row][Player1.start_col] != 0 ){
            printf("Player 1, hai perso :( \n");
            printf("La CPU vince \n");
            break;
        }

        update_table(Player1.table, Player1.piece, Player1.height, Player1.width,Player1.start_row, Player1.start_col);
        lines_cleared = clear_line(Player1.table, &(Player1.points));
        if(lines_cleared > 2){
            revert_table(Player2.table, lines_cleared );
            print_table(Player2.table);
        }
        printf("Campo del Player 1 \n");
        print_table(Player1.table);
        printf("\n \n ");

        /*TURNO CPU*/

        printf("Il punteggio della CPU e' :%d \n", Player2.points);
        top_margin(Player2.table, tops);
    
        copy_piece(Check(piece_count, tops, Player2.table, &Player2.start_col)->matrix, Player2.piece);
        
        printf("CPU start col is %d \n", Player2.start_col);

        Player2.width=piece_width(Player2.piece);
        Player2.height=piece_height(Player2.piece);

        Player2.start_row=placement(Player2.piece, Player2.table, Player2.start_col);

        if(Player2.start_row<0 || Player2.table[Player2.start_row][Player2.start_col] != 0){
            printf("La CPU perde :( \n");
            printf("Player 1 vince\n");
            break;
        }

        update_table(Player2.table, Player2.piece, Player2.height, Player2.width,Player2.start_row, Player2.start_col);
        lines_cleared = clear_line(Player2.table, &(Player2.points));
        if(lines_cleared > 2){
            revert_table(Player1.table, lines_cleared );
            print_table(Player1.table);
        }
        printf("TAVOLA CPU \n");
        print_table(Player2.table);
        printf("\n \n ");

    }

    if(Player1.points!=Player2.points){
        printf("Il vincitore è: ");
        Player1.points > Player2.points? printf("Player 1"): printf("CPU");
    }
}

/**
 * Funzione della partita multiplayer contro un altra persona
 *
 * \param Player1 stato della tabella di gioco del primo gioctore
 * \param Player2 stato della tabella di gioco del secondo giocatore
 * \param piece_count numero di pezzi rimanenti
 * \param pieces pointers ai pezzi selezionabili
 */
void PvpGame(GameState Player1, GameState Player2, int piece_count[7], Piece* pieces[7]){
    int lines_cleared;

    fill_table_with_0(Player1.table);
    Player1.points=0;
    printf("  Campo del Player 1 \n");
    print_table(Player1.table);

    fill_table_with_0(Player2.table);
    Player2.points=0;
    printf("  Campo del Player 2  \n");
    print_table(Player2.table);

    while(!game_over(piece_count)){
        /*TURNO PLAYER 1*/
        printf("Player 1, il tuo punteggio è :%d \n", Player1.points);
        print_all_pieces_row(piece_count, pieces);

        copy_piece(chosen_piece(pieces, piece_count)->matrix, Player1.piece);
        Player1.rotation=chosen_rotation();
        rotate(Player1.piece, Player1.rotation);

        Player1.width=piece_width(Player1.piece);
        Player1.height=piece_height(Player1.piece);

        Player1.start_col=choose_position(Player1.piece);
        Player1.start_row=placement(Player1.piece, Player1.table, Player1.start_col);

        if(Player1.start_row < 0 || Player1.table[Player1.start_row][Player1.start_col] != 0){
            printf("Player 1, hai perso :( \n");
            printf("Il vincitore è Player 2 \n");
            break;
        }

        update_table(Player1.table, Player1.piece, Player1.height, Player1.width,Player1.start_row, Player1.start_col);
        lines_cleared = clear_line(Player1.table, &(Player1.points));
        if(lines_cleared > 2){
            revert_table(Player2.table, lines_cleared );
        }

        print_table(Player1.table);

        /*TURNO PLAYER 2*/
        printf("Player 2, il tuo punteggio è :%d \n", Player2.points);
        print_all_pieces_row(piece_count, pieces);

        copy_piece(chosen_piece(pieces, piece_count)->matrix, Player2.piece);
        Player2.rotation=chosen_rotation();
        rotate(Player2.piece, Player2.rotation);

        Player2.width=piece_width(Player2.piece);
        Player2.height=piece_height(Player2.piece);

        Player2.start_col=choose_position(Player2.piece);
        Player2.start_row=placement(Player2.piece, Player2.table, Player2.start_col);

        if(Player2.start_row<0 || Player2.table[Player2.start_row][Player2.start_col] != 0){
            printf("Player 2, hai perso :( \n");
            printf("Il vincitore è Player 1");
            break;
        }

        update_table(Player2.table, Player2.piece, Player2.height, Player2.width,Player2.start_row, Player2.start_col);
        lines_cleared = clear_line(Player2.table, &(Player2.points));
        if(lines_cleared > 2){
            revert_table(Player1.table, lines_cleared );
        }

        print_table(Player2.table);

    }
    printf("Il vincitore è: ");
    Player1.points > Player2.points? printf("Player 1"): printf("Player 2");
}

/**
 * Funzione della partita single player
 *
 * \param Player stato della tabella di gioco del giocatore
 * \param piece_count numero di pezzi rimanenti
 * \param pieces pointers ai pezzi selezionabili
 */
void SinglePlayerGame(GameState Player, int piece_count[7], Piece* pieces[7]){
    fill_table_with_0(Player.table);
    print_table(Player.table);
    Player.points=0;

    while (!game_over( piece_count)){

        printf("Il tuo punteggio e' :%d \n", Player.points);
        print_all_pieces_row(piece_count, pieces);

        copy_piece(chosen_piece(pieces, piece_count)->matrix, Player.piece);

        Player.rotation=chosen_rotation();
        rotate(Player.piece, Player.rotation);

        Player.width=piece_width(Player.piece);
        Player.height=piece_height(Player.piece);

        Player.start_col=choose_position(Player.piece);
        Player.start_row=placement(Player.piece, Player.table, Player.start_col);

        if(Player.start_row<0 || Player.table[Player.start_row][Player.start_col] != 0){
            break;
        }

        update_table(Player.table, Player.piece, Player.height, Player.width,Player.start_row, Player.start_col);

        clear_line(Player.table, &Player.points);

        print_table(Player.table);

    }
    printf("GAME OVER \n");
}

/**
 * Funzione per il setup della partita multi player contro la CPU
 *
 *
 */
void modePvE()
{
    GameState Player1;
    GameState CPU;
    char delay[50];

    Piece* pieces[7]={&I, &L, &J, &O, &S, &T, &Z};
    int piece_count[7]={40, 40, 40 , 40, 40, 40, 40};

    PvEGame(Player1, CPU, piece_count, pieces);
    printf("inserisci qualsiasi carattere per chiudere la finestra\n");
    scanf("%s", delay);
}

/**
 * Funzione per il setup della partita multi player contro un altra persona
 *
 *
 */
void modePvP()
{
    GameState Player1;
    GameState Player2;
    char delay[50];

    Piece* pieces[7]={&I, &L, &J, &O, &S, &T, &Z};
    int piece_count[7]={40, 40, 40 , 40, 40, 40, 40};

    PvpGame(Player1, Player2, piece_count, pieces );
    printf("inserisci qualsiasi carattere per chiudere la finestra\n");
    scanf("%s", delay);
}

/**
 * Funzione per il setup della partita single player
 *
 *
 */
void modeSingle()
{
    Piece* pieces[7]={&I, &L, &J, &O, &S, &T, &Z};
    int piece_count[7]={20,20,20,20,20,20,20};

    GameState Player1;
    char delay[50];

    SinglePlayerGame(Player1, piece_count, pieces);
    printf("inserisci qualsiasi carattere per chiudere la finestra\n");
    scanf("%s", delay);
}
