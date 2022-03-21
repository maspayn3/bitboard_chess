#include "Board.h"
#include <string>


Board::Board () {
    wr_board.reset();
    wb_board.reset();
    wn_board.reset();
    wp_board.reset();
    wq_board.reset();
    wk_board.reset();
    bp_board.reset();
    br_board.reset();
    bb_board.reset();
    bn_board.reset();
    bq_board.reset();
    bk_board.reset();
}


void Board::load_from_fen(std::string fen) {

    int rank = 0;
    int file = 0;
    int board_index = 0;

    for (auto i : fen) {

        if (i == '/') {
            rank += 1;
            file = 0;
            continue;
        }

        board_index = rank*8 + file;
        
        switch (i) {

        case 'p':
            bp_board[board_index] = 1;
            file++;
            break;
        
        case 'r':
            br_board[board_index] = 1;
            file++;
            break;

        case 'n':
            bn_board[board_index] = 1;
            file++;
            break;

        case 'b':
            bb_board[board_index] = 1;
            file++;
            break;

        case 'q':
            bq_board[board_index] = 1;
            file++;
            break;

        case 'k':
            bk_board[board_index] = 1;
            file++;
            break;

        case 'P':
            wp_board[board_index] = 1;
            file++;
            break;
        
        case 'R':
            wr_board[board_index] = 1;
            file++;
            break;

        case 'N':
            wn_board[board_index] = 1;
            file++;
            break;

        case 'B':
            wb_board[board_index] = 1;
            file++;
            break;

        case 'Q':
            wq_board[board_index] = 1;
            file++;
            break;

        case 'K':
            wk_board[board_index] = 1;
            file++;
            break;

        default:
            if (isdigit(i)) {
                file += (i - '0');
            }
            break;
        }
    }
    print_bitstring_pieces_board(wk_board);
}

void Board::print_bitstring_pieces_board(std::bitset<64> bitset) {

        for (int i = 0; i < 64; i++) {
            if (i != 0 && (i % 8) == 0) {
                std::cout << "\n";
            }

            if (bitset[i] == 0) {
                std::cout << "0 ";
            }
            else {
                std::cout << "1 ";
            }
        }
        std::cout << "\n\n";
}
void  Board::print_game_board() {
    
    std::bitset<64> game_board;

    // performs bit-wise logical OR operation to collect all positions from piece bitsets
    game_board = wp_board |
                 wr_board |
                 wb_board |
                 wn_board |
                 wq_board |
                 wk_board |
                 bp_board |
                 br_board |
                 bb_board |
                 bn_board |
                 bq_board |
                 bk_board;
    
    print_bitstring_pieces_board(game_board);
}