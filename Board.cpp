#include "Board.h"
#include <string>


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

// testing function, could be fixed up TODO
void Board::print_bitstring_pieces_board(std::bitset<64> &bitset) {

    int board_index = 0;

       for (int r = 7; r >= 0; r--) {
           for (int f = 0; f < 8; f++) {

               board_index = r*8 + f;

               if (bitset[board_index] == 0) {
                   std::cout << "- ";
               }
               else {
                   std::cout << "1 ";
               }
           }
           std::cout << "\n";
       }
        std::cout << "\n\n";
}
void  Board::print_game_board() {
    
    std::bitset<64> game_board;

    for (auto i : piece_boards) {

        game_board = game_board | i;
    }
    
    print_bitstring_pieces_board(game_board);
}