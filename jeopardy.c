/*
 * Tutorial 3 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);


int main()
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Display the game introduction and initialize the questions
    initialize_game();
	// display_categories();
    // Prompt for players names
	printf("This is jeopardy \n");
    
    // initialize each of the players in the array
	for(int i = 0; i < 4; i++){
		players[i].score = 0;
		printf("Enter player name: ");
		scanf("%s", (char *) &players[i].name);
	}

    // Perform an infinite loop getting command input from users until game ends
	while(true)
    {
		if (boardComplete()==true){
			break;
		}
		char selected_player[MAX_LEN] = "";
		char selected_category[MAX_LEN] = "";
		int selected_val = 0;
		display_categories();
		do {
			if(strcmp(selected_player, "")!=0){
				printf("player %s was not found \n", selected_player);
			}
			printf("Enter first player's name: ");
            scanf("%s", (char *) &selected_player);
		}while(player_exists(players,4,selected_player) == false);

		printf("Player %s Turn \n", selected_player);
	

		do
		{
			printf("Enter a Category and Value that has not been selected\n");
			printf("Enter Category: ");
			scanf("%s", (char *) &selected_category);

			printf("Enter Amount: ");
			scanf("%d", (int *) &selected_val);
		}while(already_answered(selected_category, selected_val));
		
		display_question(selected_category, selected_val);
		char answer[MAX_LEN] = "";
		scanf(" %[^\n]s", (char *) &answer);
		if (valid_answer(selected_category, selected_val, answer)){
			printf("Correct answer \n");
			printf("%s gains %d points \n", selected_player, selected_val);
			update_score(players, 4, selected_player, selected_val);
		}else{
			printf("Your answer %s is incorrect \n", answer);
			int num = ques_num(selected_category, selected_val);
			printf("Correct answer was: %s \n", questions[num].answer);
		}
        // Call functions from the questions and players source files

        // Execute the game until all questions are answered

        
    }
	// Display the final results and exit
	show_results(players, 4);
	getchar();
    return EXIT_SUCCESS;
}

void show_results(player *players, int num_players) {
    int name = 0;
    int score = 0;
    int winner = 0;

    for(int i = 0; i < num_players; i++) 
	{
        if((int) strlen(players[i].name) > name)
		{
			name = strlen(players[i].name);
		}

        if(players[i].score > score) 
		{
            score = players[i].score;
            winner = i;
        }
    }

    printf("Scores: \n");
    for(int i = 0; i < num_players; i++)
	{
		printf("%*s: %d\n", name + 1, players[i].name, players[i].score);
	}
	
    printf("Winner: %s\n", players[winner].name);
}
