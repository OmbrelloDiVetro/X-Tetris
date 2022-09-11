/**
* \file dataType.h
* \author Lorenzo e Aresù
* \brief Costanti utilizzate nel progetto e strutture delle pedine e delle partite
*
*/
#ifndef MAIN_C_DATATYPE_H
#define MAIN_C_DATATYPE_H


#define col 10
#define rig 15

typedef struct Piece{
    int matrix[4][4];
    char name;
}Piece;

typedef struct GameState{
    int table[15][10];
    int piece[4][4];
    int points;
    int height,width;
    int start_col, start_row;
    int rotation;
} GameState;

static Piece I = {
        1, 0, 0, 0,
        1, 0, 0, 0,
        1, 0, 0, 0,
        1, 0, 0, 0,
        'I'};
static Piece L = {
        2, 2, 2, 0,
        2, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        'L'};
static Piece J = {
        3, 3, 3, 0,
        0, 0, 3, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        'J'};
static Piece O= {
        4, 4, 0, 0,
        4, 4, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        'O'};
static Piece S = {
        0, 5, 5, 0,
        5, 5, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        'S'};
static Piece T = {
        6, 6, 6, 0,
        0, 6, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        'T'};
static Piece Z = {
        7, 7, 0, 0,
        0, 7, 7, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        'Z'};

#endif 
