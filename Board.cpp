#include "Board.h"
#include <string>

using namespace constants;

Board::Board () {

    // possible unnecessary step TODO 
}


void Board::load_from_fen(std::string fen) {

    // reset all bitboards
    reset_boards();

    int rank = 8;
    int file = 8;
    int board_index = 0;

    for (auto i : fen) {

        // calculates index on chess board with [0] being the bottom left and [63] being the top right
        board_index = rank*8 - file;
        
        // based on FEN string conventions, will set bit in piece bitstrings to 1 based on pos in FEN
        switch (i) {
        case 'p':
            piece_boards[colorIndex::black + pieceIndex::pawn][board_index] = 1;
            file--;
            break;
        
        case 'r':
            piece_boards[colorIndex::black + pieceIndex::rook][board_index] = 1;
            file--;
            break;

        case 'n':
            piece_boards[colorIndex::black + pieceIndex::knight][board_index] = 1;
            file--;
            break;

        case 'b':
            piece_boards[colorIndex::black + pieceIndex::bishop][board_index] = 1;
            file--;
            break;

        case 'q':
            piece_boards[colorIndex::black + pieceIndex::queen][board_index] = 1;
            file--;
            break;

        case 'k':
            piece_boards[colorIndex::black + pieceIndex::king][board_index] = 1;
            file--;
            break;

        case 'P':
            piece_boards[colorIndex::white + pieceIndex::pawn][board_index] = 1;
            file--;
            break;
        
        case 'R':
            piece_boards[colorIndex::white + pieceIndex::rook][board_index] = 1;
            file--;
            break;

        case 'N':
            piece_boards[colorIndex::white + pieceIndex::knight][board_index] = 1;
            file--;
            break;

        case 'B':
            piece_boards[colorIndex::white + pieceIndex::bishop][board_index] = 1;
            file--;
            break;

        case 'Q':
            piece_boards[colorIndex::white + pieceIndex::queen][board_index] = 1;
            file--;
            break;

        case 'K':
            piece_boards[colorIndex::white + pieceIndex::king][board_index] = 1;
            file--;
            break;

        case '/': 
            rank -= 1;
            file = 8;
            break;

        default:
            // if the FEN char is a digit, must displace file (column) by this by "i" amount
            if (isdigit(i)) {
                file += (i - '0');
            }
            break;
        }
    }
    print_bitstring_pieces_board(piece_boards[11]);
}

void Board::reset_boards() {

}

bool Board::get_bit(std::bitset<64> &board, int square) {
    return board[square];
}

std::bitset<64> Board::occupied_board() {
    std::bitset<64> game_board;

    for (auto i : piece_boards) {
        game_board = game_board | i;
    } // for

    return game_board;
}

// testing function, could be fixed up TODO
void Board::print_bitstring_pieces_board(std::bitset<64> &board) {

    int square = 0;

       for (int r = 7; r >= 0; r--) {

           std:: cout << r + 1 << "    ";

           for (int f = 0; f < 8; f++) {

               square = r*8 + f;

               if (get_bit(board, square)) {
                   std::cout << "1 ";
               }
               else {
                   std::cout << "- ";
               }
           } // for
           std::cout << "\n";
       } // for
    std::cout << "\n     a b c d e f g h";
    std::cout << "\n\n";
}

void Board::set_color_boards() {

    for (size_t i = 0; i < 6; i++) {
        black_pieces = black_pieces | piece_boards[i];
    }

    for (size_t j = 6; j < 12; j++) {
        white_pieces = white_pieces | piece_boards[j];
    }
}

// prints game board with associated chars p, r, n, b, q, k
void  Board::print_game_board() {
    
    int square = 0;
    bool empty = false;

    for (int rank = RANK_COUNT; rank > 0; rank--) {
        std:: cout << rank << "    ";

        for (int file = FILE_COUNT; file > 0; file--) {
            empty = true;

            //prints starting with square 56
            square = rank*8 - file;

            for (int bb_piece = 0; bb_piece < PIECE_COUNT; bb_piece++) {

                if (get_bit(piece_boards[bb_piece], square)) {
                    empty = false;
                    
                    switch (bb_piece) {
                        case 0:
                            std::cout << "p ";
                            break;

                        case 1:
                            std::cout << "r ";
                            break;

                        case 2:
                            std::cout << "n ";
                            break;

                        case 3:
                            std::cout << "b ";
                            break;

                        case 4:
                            std::cout << "q ";
                            break;                  
                        
                        case 5:
                            std::cout << "k ";
                            break;

                        case 6:
                            std::cout << "P ";
                            break;

                        case 7:
                            std::cout << "R ";
                            break;

                        case 8:
                            std::cout << "N ";
                            break;

                        case 9:
                            std::cout << "B ";
                            break;

                        case 10:
                            std::cout << "Q ";
                            break;

                        case 11:
                            std::cout << "K ";
                            break;                  

                        default:
                            break;
                    }
                    break;
                }
            }
            if (empty) {
                std::cout << "- ";
            }
        }
        std::cout << "\n";
    // print board files
    } 
    std::cout << "\n     a b c d e f g h\n\n";
} // print_game_board()