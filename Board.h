#include <iostream>
#include <bitset>
    

#define STARTING_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"


// end of fen  "w KQkq - 0 1"

enum rankfile {
  a1, b1, c1, d1, e1, f1, g1, h1,
  a2, b2, c2, d2, e2, f2, g2, h2,
  a3, b3, c3, d3, e3, f3, g3, h3,
  a4, b4, c4, d4, e4, f4, g4, h4,
  a5, b5, c5, d5, e5, f5, g5, h5,
  a6, b6, c6, d6, e6, f6, g6, h6,
  a7, b7, c7, d7, e7, f7, g7, h7,
  a8, b8, c8, d8, e8, f8, g8, h8 
};

enum pieceIndex {
    pawn, rook, knight, bishop, queen, king
};
enum colorIndex {
    black = 0,
    white = 6
};

class Board {

public:
    Board ();
    void reset_boards();
    void load_from_fen(std::string fen);
    void print_bitstring_pieces_board(std::bitset<64> &bitset);
    void print_game_board();



private:

    // index [0-5]: black  [6-12]: white
    // order of pieces p, r, b, n, q, k
    std::bitset<64> piece_boards[12];


};

