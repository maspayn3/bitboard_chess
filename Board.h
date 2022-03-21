#include <iostream>
#include <bitset>
    

#define STARTING_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"

// end of fen  "w KQkq - 0 1"

class Board {

public:
    Board ();
    void load_from_fen(std::string fen);
    void print_bitstring_pieces_board(std::bitset<64> bitset);
    void print_game_board();



private:
    std::bitset<64> wp_board;
    std::bitset<64> wr_board;
    std::bitset<64> wb_board;
    std::bitset<64> wn_board;
    std::bitset<64> wq_board;
    std::bitset<64> wk_board;

    std::bitset<64> bp_board;
    std::bitset<64> br_board;
    std::bitset<64> bb_board;
    std::bitset<64> bn_board;
    std::bitset<64> bq_board;
    std::bitset<64> bk_board;
};

