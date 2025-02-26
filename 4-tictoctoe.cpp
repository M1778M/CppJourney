#include <stdio.h>
#include <stdlib.h>
#include <ctime>

#define O_C 'O'
#define X_C 'X'
#define N_C '-'

unsigned short int *random_pc(const unsigned short int board[][3], unsigned short int *pgrn);
unsigned short int *random_pc(const unsigned short int board[][3]);
bool isEnd(const unsigned short int board[][3], const size_t size);
void move(unsigned short int board[][3], const unsigned short int *player_target, const bool plr_is_x);
void drawBoard(const unsigned short int board[][3], const unsigned short int size);
void fill_board(unsigned short int board[][3]);
void debug_board(const unsigned short int board[][3]);
unsigned short int *UserInput(unsigned short int board[][3]);
void move_a_round(unsigned short int board[][3], const unsigned short int size,const bool plr_is_x);
void gameloop(unsigned short int board[][3]);


int main(){
	srand(time(NULL));
	// unsigned short int testBoard[3][3];
	// unsigned short int *inp;
	// unsigned short int cp_choice[2];
	// unsigned short int testTarget[2] = {1,1};
	// fill_board(testBoard);
	// debug_board(testBoard);
	// drawBoard(testBoard,3);
	// for (int i = 0; i< 3; i++){
	// 	move_a_round(testBoard,3, true);
	// 	move(testBoard, random_pc(testBoard,cp_choice),false);
	// }
	unsigned short int Board[3][3];
	gameloop(Board);

	return 0;
}

void debug_board(const unsigned short int board[][3]){
	for (int i = 0; i < 3; i++)
		for (int j=0; j < 3; j++)
			printf("%d ",board[i][j]);
}

void gameloop(unsigned short int board[][3]){
	printf("\tWELCOME TO TICTOCTOE\n");
	fill_board(board);
	unsigned short int pc_choice[2];
	bool plr_is_x=false;
	bool is_plr_turn= false;
	if (rand() % 2)
	{
		plr_is_x = true;
		is_plr_turn = true;
		printf("You start the game, YOU ARE `%c`\n\n", X_C);
	}
	else
		printf("You are `%c`\n\n",O_C);
	if (is_plr_turn) drawBoard(board,3);
	do{
		if (is_plr_turn){
			drawBoard(board,3);
			unsigned short int *inp = UserInput(board);
			move(board, inp, plr_is_x);
			is_plr_turn = false;
		} else {
			move(board, random_pc(board,pc_choice), !plr_is_x);
			is_plr_turn = true;
			//drawBoard(board,3);
		}
		

	} while (!isEnd(board, 3));
	printf("\n\nGame ended. Good Game Gamer Girl. get it? 4 Gs in a row\n");
}

void move_a_round(unsigned short int board[][3], const unsigned short int size,const bool plr_is_x){
	drawBoard(board, size);
	unsigned short int *inp = UserInput(board);
	move(board,inp,plr_is_x);
	if (isEnd(board,(size_t)size))
		printf("END OF THE GAME");
}
bool valid_input(const unsigned short int x_, const unsigned short int y_){
	// printf("DEBUG(IS_VALID): x->%hu , y->%hu, cond->%b",x_,y_,x_ < 4 && x_ > 0 && y_ < 4 && y_ > 0);
	return x_ < 4 && x_ > 0 && y_ < 4 && y_ > 0 ? true : false;
}

bool illegal_move(const unsigned short int board[][3],const unsigned short int x_, const unsigned short int y_){
	// printf("\nDEBUG: x_->%hu, y_->%hu,, board[x][y]->%hu, cond->%b \n",x_,y_,board[x_][y_], board[x_][y_] < 2);
	return board[x_][y_] < 2 ? true : false;
}

unsigned short int *UserInput(unsigned short int board[][3]){
	unsigned short int x;
	unsigned short int y;
	char temp;
	do {
		printf("Your move (c, r): ");
		scanf("%hu %hu", &x, &y);
		scanf("%c",&temp);

	} while (!valid_input(x,y) || illegal_move(board,x-1,y-1));

	unsigned short int *r = (unsigned short int *)malloc(2);
	*(r+0) = x;
	*(r+1) = y;
	return r;
}

void drawBoard(const unsigned short int board[][3], const unsigned short int size){
	printf("C/R 1  2  3  \n");
	for (int i = 0; i < size; i++){
		printf("%d [", i+1);
		for (int j = 0; j < 3; j++)
			printf(" %c ", board[i][j]==0 ? O_C : board[i][j] == 1 ? X_C : N_C);
		printf("]\n");
	}
}
void fill_board(unsigned short int board[][3]){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++)
			board[i][j]=2;
	}
}

void move(unsigned short int board[][3], const unsigned short int *player_target, const bool plr_is_x){
	board[(*player_target)-1][(*(player_target+1))-1] = plr_is_x ? 1 : 0;
}

unsigned short int sum_arr(const unsigned short int arr[], const size_t size){
	unsigned short int sum = 0;
	for (int i = 0; i < size; i++)
		sum+=arr[i];
	return sum;	
}

bool isin_arr(const unsigned short int arr[], const size_t size, const unsigned short int element){
	for (int i = 0; i < size;i++)
		if (arr[i]==element)
			return true;
	return false;
}
bool check_sum(const unsigned short int arr[], const size_t size){
	return sum_arr(arr, size) == (arr[0]*size);
}

bool _x1_check(const unsigned short int arr[][3], const unsigned short int t){
	return arr[0][0] == t && arr[1][1]==t && arr[2][2]==t;
}
bool _x2_check(const unsigned short int arr[][3], const unsigned short int t){
	return arr[0][2] == t && arr[1][1]==t && arr[2][0]==t;
}

bool x_check(const unsigned short int arr[][3], const unsigned short int t){
	return _x1_check(arr, t) || _x2_check(arr, t);
}

bool isEnd(const unsigned short int board[][3], const size_t size){
	// Pattern matching
	// Rows
	for (int i = 0; i < size; i++)
		if (check_sum(board[i], size) && !isin_arr(board[i], size, 2))
			return true;
	// Columns
	unsigned short int rboard[3][3];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			rboard[j][i] = board[i][j];
	for (int i = 0; i < size; i++)
		if (check_sum(rboard[i], size) && !isin_arr(rboard[i], size, 2))
			return true;
	
	return x_check(board, 1) || x_check(board, 0);
}

unsigned short int *_dead_random_pc_(const unsigned short int board[][3], unsigned short int *pgrn){
	if (isin_arr(board[*pgrn], 3, 2)){
		*(pgrn+1) = *(pgrn+1) >= 0 && (*(pgrn+1)+1) <= 2 ? *(pgrn+1)+1 : *(pgrn+1)-1;
		return _dead_random_pc_(board, pgrn);
	} else {
		*pgrn = *pgrn >= 0 && (*pgrn+1) <= 2 ? *pgrn+1 : *pgrn-1;
		return _dead_random_pc_(board, pgrn);
	}
}

unsigned short int *random_pc(const unsigned short int board[][3],unsigned short int rn[2]){
	*rn = rand() % 3;
	*(rn+1) = rand() % 3;
	if (illegal_move(board,*rn,*(rn+1)))
		return random_pc(board,rn);
	else
		return rn;
}
