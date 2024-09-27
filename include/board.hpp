#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <bitset>



// end of fen  "w KQkq - 0 1"

/*
squareIndex {0..63} = 8*rankIndex + fileIndex;
rankIndex   {0..7}  = squareIndex div 8; // squareIndex >> 3;
fileIndex   {0..7}  = squareIndex mod 8; // squareIndex & 7;
*/


class Board {
public:
    enum square {
    a1, b1, c1, d1, e1, f1, g1, h1,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a8, b8, c8, d8, e8, f8, g8, h8 
    };

    enum piece_index {
        pawn, rook, knight, bishop, queen, king
    };

    enum color_index {
        black = 0,
        white = 6
    };

    static const int BITBOARD_COUNT = 12;
    static const int SQUARE_COUNT = 64;
    static const int FILE_COUNT = 8;
    static const int RANK_COUNT = 8;
    static constexpr char* STARTING_FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";

    Board ();
    void reset_boards();
    void load_from_fen(const std::string fen);
    void print_bitstring_pieces_board(const std::bitset<64> &board);
    std::bitset<64> get_occupied_board() const;
    void set_color_boards();
    void print_game_board() const;
    bool get_bit(const std::bitset<64> &board, int square) const;
private:
    // index [0-5]: black  [6-11]: white
    // order of pieces p, r, b, n, q, k
    std::bitset<64> piece_boards[12];
    std::bitset<64> black_pieces;
    std::bitset<64> white_pieces;
};

#endif