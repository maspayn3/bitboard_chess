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

    for (char c : fen) {

        // calculates index on chess board with [0] being the bottom left and [63] being the top right
        // walk on board starting w index 56 - 63
        board_index = rank * 8 - file;
        
        // decrement rank and reset file if so
        if (c == '/') {
            rank -= 1;
            file = 8;
            continue;
        }

        if (rank <= 0) break;

        else if (isdigit(c)) {
            file -= (c - '0');
        }
        else {
            int color = isupper(c) ? colorIndex::white : colorIndex::black;
            int piece;
                
            // based on FEN string conventions, will set bit in piece bitstrings to 1 based on pos in FEN
            // from Claude, concise switch statement
            switch (tolower(c)) {
                case 'p': piece = pieceIndex::pawn; break;
                case 'r': piece = pieceIndex::rook; break;
                case 'n': piece = pieceIndex::knight; break;
                case 'b': piece = pieceIndex::bishop; break;
                case 'q': piece = pieceIndex::queen; break;
                case 'k': piece = pieceIndex::king; break;
                default: continue;  // Invalid character, skip
            }
            piece_boards[color + piece][board_index] = 1;
            file--;
        }        
    }
    set_color_boards();
}

void Board::reset_boards() {
    // reset piece boards
    for (auto& board : piece_boards) {
        board.reset();
    }

    // reset color boards
    black_pieces.reset();
    white_pieces.reset();
}

bool Board::get_bit(std::bitset<64> &board, int square) {
    return board[square];
}

std::bitset<64> Board::get_occupied_board() {
    std::bitset<64> game_board;

    for (auto& i : piece_boards) {
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
               square = r * 8 + f;

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

void Board::print_game_board() {
    const char* piece_chars = "prnbqkPRNBQK";
    std::bitset<64> occupied = white_pieces | black_pieces;

    for (int rank = RANK_COUNT; rank > 0; rank--) {
        std::cout << rank << "    ";

        for (int file = 0; file < constants::FILE_COUNT; file++) {
            int square = (rank - 1) * 8 + file;

            if (occupied[square]) {
                for (int piece = 0; piece < 12; piece++) {
                    if (piece_boards[piece][square]) {
                        std::cout << piece_chars[piece] << ' ';
                        break;
                    }
                }
            }
            else {
                std::cout << "- ";
            }
        }
        std::cout << "\n";
    }
    std::cout << "\n     a b c d e f g h\n\n";
}