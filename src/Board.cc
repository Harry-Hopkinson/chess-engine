#include "Board.h"
#include <iostream>

void printBoard(Game & game) {
  cout << "   A     B     C     D     E     F     G     H\n\n";

  for (int iLine = 7; iLine >= 0; iLine--) {
    if (iLine % 2 == 0) {
      printLine(iLine, BLACK_SQUARE, WHITE_SQUARE, game);
    } else {
      printLine(iLine, WHITE_SQUARE, BLACK_SQUARE, game);
    }
  }
}

void printLine(int iLine, int iColour1, int iColour2, Game & game) {
  int CELL = 6;

  for (int subLine = 0; subLine < CELL / 2; subLine++) {
    for (int iPair = 0; iPair < 4; iPair++) {
      for (int subColumn = 0; subColumn < CELL; subColumn++) {
        if (subLine == 1 && subColumn == 3) {
          cout << char(game.getPieceAtPosition(iLine, iPair * 2) != 0x20 ?
            game.getPieceAtPosition(iLine, iPair * 2) : iColour1);
        } else {
          cout << char(iColour1);
        }
      }

      for (int subColumn = 0; subColumn < CELL; subColumn++) {
        if (subLine == 1 && subColumn == 3) {
          cout << char(game.getPieceAtPosition(iLine, iPair * 2 + 1) != 0x20 ?
            game.getPieceAtPosition(iLine, iPair * 2 + 1) : iColour2);
        } else {
          cout << char(iColour2);
        }
      }
    }
  }
}