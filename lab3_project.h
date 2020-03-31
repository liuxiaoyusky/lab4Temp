#pragma once
#include "tic-tac-toe.h"

/* function declarations */
int usage(const char* filename);

/* enumerations */
enum input_indices { program_name = 0, input_game_name = 1, input_auto_player = 2};			

/* other global variables*/
#define NUM_ARGS 2							// number of arguments required for default game
#define AUTO_ARGS 3							// number of arguments required for auto player
int status;									//the return status of main function