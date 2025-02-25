// Including required libraries
#include <iostream>
#include <stdio.h>
#include <ctime>
// Constants
#define ROCK 1
#define PAPER 2
#define SCISSORS 3
#define WIN_STATE 1
#define LOSE_STATE 2
#define DRAW_STATE 3
#define INVALID_STATE 5

// Choice message
#define DINPUT "Enter choice:\n\t1. Rock\n\t2. Paper\n\t3. Scissors\n\t:"

// Player class (GameEngine)
class Player{
	private:
		// Counter variables
		int WIN_COUNT=0;
		int LOSE_COUNT=0;
		int DRAW_COUNT=0;
		int ROUNDS=0;
	public:
		// get input from user
		int get_input(){
			unsigned int inp;
			printf(DINPUT);
			std::cin >> inp;
			std::cin.clear();
			fflush(stdin);
			return inp;
		}
		// Public Add to counter variables functions
		void win(){printf("You won this round.\n");WIN_COUNT+=1;}
		void lose(){printf("You lost this round.\n");LOSE_COUNT+=1;}
		void draw(){printf("You drawn this round.\n");DRAW_COUNT+=1;}
		void add_round(){ROUNDS+=1;}

		// Public get counter variables functions
		int get_win(){
			return WIN_COUNT;
		}
		int get_lose(){
			return LOSE_COUNT;
		}
		int get_draw(){
			return DRAW_COUNT;
		}
		
		int get_rounds(){
			return ROUNDS;
		}
		
};
// Functions declarations
unsigned int random_state();
unsigned int compare_states(int st_1, int st_2);
void gameloop(Player *plr);
// main function
int main(){
	printf("Welcome to the rock, paper, scissors game.\n");
	Player plr;
	gameloop(&plr);
	printf("END OF THE GAME, HOPE YOU ENJOYED. ROUNDS PLAYED: %d\n\n", plr.get_rounds());
	printf("STATS:\n\tWINS: %d\n\tLOSSES: %d\n\tDRAWS: %d\n\tTROUNDS: %d\n\n",plr.get_win(), plr.get_lose(), plr.get_draw(), plr.get_rounds());
	return 0;
}
// Functions definitions
void gameloop(Player *plr){ // Gets a pointer to the player class to submit changes and read from its variables
	// set random seed at the start of the game loop
	srand(time(NULL));
	char *temp; // temp variable supposed to clear the buffer and fill this with it but it looks like I'm just learning c++
	// Game loop
	do{
		// Get player state (from input)
		int P_STATE = plr->get_input();
		// Get Computer's random state (AI)
		int C_STATE = random_state();
		// Show what happened (It's a little bit messy but works
		printf("You chose %s and Computer chose %s\n", P_STATE==ROCK ? "Rock" : P_STATE==SCISSORS ? "Scissors" : P_STATE==PAPER ? "Paper" : "INVALID_PARAM" , C_STATE==ROCK ? "Rock" : C_STATE == SCISSORS? "Scissors" : C_STATE == PAPER ? "Paper" : "INVALID_PARAM");
		// Compare states and add to needed state
		switch (compare_states(P_STATE, C_STATE)){
			case WIN_STATE:
				plr->win();break;
			case LOSE_STATE:
				plr->lose();break;
			case DRAW_STATE:
				plr->draw();break;
			default:// Quit the program if input is invalid (Avoided bugs)
				printf("Invalid state. restart\n");std::cin.clear();fflush(stdin);exit(0);
		}
		// Add one to the round count
		plr->add_round();
		// printf("DEBUG: DRAWS->%d\tLOSES->%d\tWINS->%d\nDEBUG: CDRAW: %b\tCLOSE: %b\tCWIN: %b\n", plr.get_draw(), plr.get_lose(), plr.get_win(), plr.get_draw() <= 3, plr.get_lose() <= 3, plr.get_win() <= 3);
	} while (plr->get_win() < 3 && plr->get_lose() < 3 && plr->get_draw() < 3); // Condition for only 3 possibilities (3wins, 3loss, 3draws)
}
// returns a random state (ROCK, PAPER, SCISSORS) It's called state because It sounds cool
unsigned int random_state(){
	return (rand() % 3)+1;
}
// compares two states sees if st_1 wins or loses or draws with st_2
unsigned int compare_states(int st_1, int st_2){
	switch (st_1){
		case ROCK:
			switch (st_2){
				case ROCK: return DRAW_STATE;
				case PAPER: return LOSE_STATE;
				case SCISSORS: return WIN_STATE;
			}
		case PAPER:
			switch (st_2){
				case ROCK: return WIN_STATE;
				case PAPER: return DRAW_STATE;
				case SCISSORS: return LOSE_STATE;
			}
		case SCISSORS:
			switch (st_2){
				case ROCK: return LOSE_STATE;
				case PAPER: return WIN_STATE;
				case SCISSORS: return DRAW_STATE;
			}
		default:
			return INVALID_STATE;
	}
}
// 128 lines that is sexy
