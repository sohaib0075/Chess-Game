#include <iostream>
#include <string>
#include <windows.h> //libary for clear screen function
using namespace std;
const int gridsize = 8;
void chessboard(char board[gridsize][gridsize]);
void chessgrid(char board[gridsize][gridsize]);
void entermove(char board[gridsize][gridsize], string& move);
bool makingmoves(char board[gridsize][gridsize], string move, char turn);
bool checkmate(char board[gridsize][gridsize], char turn);
int main()
{
 char board[gridsize][gridsize];
 string move;
 char turn = 'b';
 cout << "\n \t WHITE'S TURN " << endl << endl;
 chessboard(board);
 chessgrid(board);
 while (true)
 {
 entermove(board, move);
 if (makingmoves(board, move, turn))
 {
 // change of turns
 if (turn == 'w')
 {
 cout << "\n \t WHITE'S TURN" << endl;
 turn = 'b';
 }
 else
 {
 cout << "\n \tBLACK'S TURN" << endl;
 turn = 'w';
 }
 }
 if (checkmate(board, turn))
 {
 if (turn == 'w')
 {
 cout << "\n \t Shah Mat! White wins." << endl;
 }
 else
 {
 cout << "\n \t Shah Mat! black wins." << endl;
 }
 break;
 }
 }
 return 0;
}
// chess board
void chessgrid(char board[gridsize][gridsize])
{
 cout << " ";
 for (int i = 0; i < gridsize; i++)
 {
 cout << (char)('a' + i) << " ";
 }
 cout << endl;
 for (int i = 0; i < gridsize; i++)
 {
 cout << i + 1 << " ";
 for (int j = 0; j < gridsize; j++)
 {
 cout << board[i][j] << " ";
 }
 cout << i + 1 << endl;
 }
 cout << " ";
 for (int i = 0; i < gridsize; i++)
 {
 cout << (char)('a' + i) << " ";
 }
 cout << endl;
}
//initialize of the grid (chess board)
void chessboard(char board[gridsize][gridsize])
{
 //white
 board[0][0] = 'R';
 board[0][1] = 'N';
 board[0][2] = 'B';
 board[0][3] = 'Q';
 board[0][4] = 'K';
 board[0][5] = 'B';
 board[0][6] = 'N';
 board[0][7] = 'R';
 //black
 board[7][0] = 'r';
 board[7][1] = 'n';
 board[7][2] = 'b';
 board[7][3] = 'q';
 board[7][4] = 'k';
 board[7][5] = 'b';
 board[7][6] = 'n';
 board[7][7] = 'r';
 //empty squares
 for (int i = 1; i < 7; i++)
 {
 for (int j = 0; j < gridsize; j++)
 {
 board[i][j] = '.';
 }
 }
}
// enter moves
void entermove(char board[gridsize][gridsize], string& move)
{
 int Old_Row = move[1] - '1';
 int Old_Colm = move[0] - 'a';
 int New_Row = move[4] - '1';
 int New_Colm = move[3] - 'a';
 // board update
 board[New_Row][New_Colm] = board[Old_Row][Old_Colm];
 board[Old_Row][Old_Colm] = '.';
 chessgrid(board);

 cout << "\nenter your move " << endl;
 cout << "for Example ( a1 - a6 ) : ";
 cin >> move;
 system("CLS");//to clear screen after the move
}
bool makingmoves(char board[gridsize][gridsize], string move, char turn)
{
 int Old_Row = move[1] - '1';
 int Old_Colm = move[0] - 'a';
 int New_Row = move[4] - '1';
 int New_Colm = move[3] - 'a';
 // to check if the move is valid or not
 if (board[Old_Row][Old_Colm] == '.')
 {
 cout << "\n \t WRONG MOVE" << endl;
 cout << "Kindly select a piece first\n";
 chessboard(board);
 chessgrid(board);
 return false;
 }
 else if (turn == 'b' && islower(board[Old_Row][Old_Colm])) {
 cout << "Invalid move: It is not black's turn\n";

 return false;
 }
 else if (board[Old_Row][Old_Colm] == 'R' || board[Old_Row][Old_Colm] == 'r')
 {
 if (Old_Row != New_Row && Old_Colm != New_Colm)
 {
 cout << "\n \tWRONG MOVE! " << endl;
 cout << "\n Rock can only move in Horizontally or Vertically" << endl;
 board[New_Row][New_Colm] = board[Old_Row][Old_Colm];
 board[Old_Row][Old_Colm] = '.';
 chessboard(board);
 chessgrid(board);
 return false;
 }
 }
 else if (board[Old_Row][Old_Colm] == 'N' || board[Old_Row][Old_Colm] == 'n')
 {
 if (abs(New_Row - Old_Row) != 2 || abs(New_Colm - Old_Colm) != 1)
 {
 if (abs(New_Row - Old_Row) != 1 || abs(New_Colm - Old_Colm) != 2)
 {
 cout << "\n \t WRONG MOVE! " << endl;
 cout << "\n Knight can only move in L shape" << endl;


 return false;
 }

 }

 }
 else if (board[Old_Row][Old_Colm] == 'B' || board[Old_Row][Old_Colm] == 'b')
 {
 if (abs(New_Row - Old_Row) != abs(New_Colm - Old_Colm))
 {
 cout << "\n \t WRONG MOVE! " << endl;
 cout << "\n Bishop can only move in Diagonally not up and down or right and left\n";
 board[New_Row][New_Colm] = board[Old_Row][Old_Colm];
 board[Old_Row][Old_Colm] = '.';
 chessboard(board);
 chessgrid(board);
 return false;
 }
 }
 // board update
 board[New_Row][New_Colm] = board[Old_Row][Old_Colm];
 board[Old_Row][Old_Colm] = '.';
 chessgrid(board);
 return true;
}
// to check if the current player is in checkmate or not
bool checkmate(char board[gridsize][gridsize], char turn)
{
 //king's location
 // int king_row = -1, king_col = -1;
 int k = 0, K = 0;
 for (int i = 0; i < gridsize; i++)
 {
 for (int j = 0; j < gridsize; j++)
 {
 if (board[i][j] == 'k')
 {
 k = 1;
 break;
 }
 if (board[i][j] == 'K')
 {
 K = 1;
 break;
 }
 }
 }
 if (k == 0 || K == 0)
 return true;
 return false;
}