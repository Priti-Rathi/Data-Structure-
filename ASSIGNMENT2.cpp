/*Knight's tour: The problem is to move the knight, beginning from any 
given square on the chessboard, in such a manner that it travels successively 
to all 64 squares, touching each square once and only once.
It is convenient to represent a solution by placing the numbers 1,2, ...,64 in 
the squares of the chessboard indicating the order in which the squares are 
reached. Note that it is not required that the knight be able to reach the 
initial position by one more move; if this is possible the knight's tour is 
called re-entrant. One of the more ingenious methods for solving the 
problem of the knight's tour is that given by J. C. Warnsdorff in 1823. His 
rule is that the knight must always be moved to one of the squares from 
which there are the fewest exits to squares not already traversed. Write a 
C++ program to implement Warnsdorff's rule and show it graphically.*/
#include <iostream>
using namespace std;
const int N = 8; 
const int M = 8; 
int board[N][M];
/*const int dx[] = {1,2,-2,-1,2,1,-1,-2};
 const int dy[] = {1,2,-2,-1,2,1,-1,-2};
 */
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
bool valid(int x, int y) 
{
 if(x >= 0 && y >= 0 && x < N && y < M) 
 {
 if(board[x][y] == -1) 
 {
 return true; 
 }
 }
 return false; // if not valid then return false
}
bool knightTour(int x, int y, int step) 
{
 if(step == N * M) 
 {
 return true; 
 }
 for(int i = 0; i < 8; i++) 
 {
 int nextX = x + dx[i];
 int nextY = y + dy[i];
 
 if(valid(nextX, nextY)) 
 {
 board[nextX][nextY] = step;
 if(knightTour(nextX, nextY, step + 1)) 
 {
 return true;
 }
 board[nextX][nextY] = -1;
 }
 }
 return false;
}
int main() 
{
 for(int i = 0; i < N; i++) {
 for(int j = 0; j < M; j++) {
 board[i][j] = -1;
 }
 }
 int startX = 0;
 int startY = 0;
 board[startX][startY] = 0;
 if (knightTour(startX, startY, 1)) 
 {
 for(int i = 0; i < N; i++) 
 {
 for(int j = 0; j < M; j++) 
 {
 cout << board[i][j] << "\t";
 }
 cout << endl;
 }
 } 
 else 
 {
 cout << "No solution exists." << endl;
 }
 return 0;
}
/*OUTPUT
0       59      38      33      30      17      8       63
37      34      31      60      9       62      29      16
58      1       36      39      32      27      18      7
35      48      41      26      61      10      15      28
42      57      2       49      40      23      6       19
47      50      45      54      25      20      11      14
56      43      52      3       22      13      24      5
51      46      55      44      53      4       21      12*/