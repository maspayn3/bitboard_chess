// SDL Chess Main Program


#include "Board.h"


// With this setup we can check a pieces type and color with bit operations
enum Pieces {
    None = 0,
    Pawn = 1,
    Knight = 3,
    Bishop = 4,
    Queen = 5,
    King = 6,

    White = 8,
    Black = 16,
};


int main () {

    Board hello;

    hello.load_from_fen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");
    hello.print_game_board();
    return 0;
}