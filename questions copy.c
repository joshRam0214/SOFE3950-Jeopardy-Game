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
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    
    for (int a = 0; a < 12; a++) {
        questions[a].answered = false;
    }

    //$200 questions -------------------------------->
    questions[0].value = 200;
    strcpy(questions[0].question, "When life gives you lemons...");
    strcpy(questions[0].answer, "make lemonade");
    strcpy(questions[0].category, categories[0]);

    questions[1].value = 200;
    strcpy(questions[1].question, "A \"Mandalorian\" character is named Grogu & is also called the Child, but viewers dubbed him \"Baby\" this");
    strcpy(questions[1].answer, "Yoda");
    strcpy(questions[1].category, categories[1]);

    questions[2].value = 200;
    strcpy(questions[2].question, "Pu-239 is an isotope of this silvery metal");
    strcpy(questions[2].answer, "plutonium");
    strcpy(questions[2].category, categories[2]);

    //$400 questions -------------------------------->
    questions[3].value = 400;
    strcpy(questions[3].question, "I came, I saw, ...");
    strcpy(questions[3].answer, "I conquered");
    strcpy(questions[3].category, categories[0]);

    questions[4].value = 400;
    strcpy(questions[4].question, "The devil didn't go down to Georgia, he went up to L.A. to open a nightclub & solve murders on this Netflix show");
    strcpy(questions[4].answer, "Lucifer");
    strcpy(questions[4].category, categories[1]);

    questions[5].value = 400;
    strcpy(questions[5].question, "Sir Humphry Davy used electrolysis to isolate it, symbol K");
    strcpy(questions[5].answer, "potassium");
    strcpy(questions[5].category, categories[2]);

    //$600 questions -------------------------------->
    questions[6].value = 600;
    strcpy(questions[6].question, "A legal principle: \"Ignorance of the law is...\"");
    strcpy(questions[6].answer, "no excuse");
    strcpy(questions[6].category, categories[0]);

    questions[7].value = 600;
    strcpy(questions[7].question, "Billy Butcher has some serious issues with superheroes on this Amazon show & confronts them quite directly");
    strcpy(questions[7].answer, "The Boys");
    strcpy(questions[7].category, categories[1]);

    questions[8].value = 600;
    strcpy(questions[8].question, "Atomic No. 20, it's needed for kids' teeth to grow");
    strcpy(questions[8].answer, "calcium");
    strcpy(questions[8].category, categories[2]);

    //$800 questions -------------------------------->
    questions[9].value = 800;
    strcpy(questions[9].question, "Among AFI's 100 Greatest Movie Quotes of All Time:");
    strcpy(questions[9].answer, "phone home");
    strcpy(questions[9].category, categories[0]);

    questions[10].value = 800;
    strcpy(questions[10].question, "An HBO Max series with \"That Damn\" this \"Weekend Update\" co-anchor examines issues like racial profiling & unemployment");
    strcpy(questions[10].answer, "Jaskaran");
    strcpy(questions[10].category, categories[1]);

    questions[11].value = 800;
    strcpy(questions[11].question, "This element makes up about 25% of the mass in your average star");
    strcpy(questions[11].answer, "helium");
    strcpy(questions[11].category, categories[2]);
    for (int x = 0; x < 3; x++){
        printf("------------------------------------\n");
        printf("Catagory: %s \n", categories[x]);
        for (int y = 0; y < 12; y++){
            if (strcmp(categories[x],questions[y].category)){
                printf("Question: %s \n", questions[y].question);
                printf("Value: %d ", questions[y].value);
                printf("\n");
            }
            
        }
    }
    // for(int x = 0; x < 12; x++){
    //     printf("Category: %s ", questions[x].category);
    //     printf("Question: %s ", questions[x].question);
    //     printf("Value: %d ", questions[x].value);
    //     printf("\n");
    // }

}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    for (int x = 0; x < 3; x++) {
        printf("|  %s  ", categories[x]);
    }

    for (int y = 0; y < 12; y++) {
        if (questions[y].answered == false) {
            printf("|  $%d", questions[y].value);
        }
        else {
            printf("|    ");
        }

        if ((y + 1) % 3 == 0) {
            printf("\n");
        }
    }
    
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
    for (int i = 0; i < 12; i++) {
        // if ((questions[i].category == category) && (questions[i].value == value)) {
        //     printf("Question \"%s for $%d\":\n", category, value);
        //     printf("\t%s\n", questions[i].question);
        // }
        if (strcmp(questions[i].category, category) && questions[i].value == value) {
            printf("Question \"%s for $%d\":\n", category, value);
            printf("\t%s\n", questions[i].question);        
        }
    }
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    int q_num = 0;

    for (int i = 0; i < 12; i++) {
        if ((questions[i].category == category) && (questions[i].value == value)) {
            q_num = i;
        }
    }

    // Look into string comparison functions, sets question answered to true
    if (strcmp(answer, questions[q_num].answer)) {
        questions[q_num].answered = true;
        return true;
    }
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    for (int i = 0; i < 12; i++) {
        if (strcmp(questions[i].category, category) && (questions[i].value == value)) {
            if (questions[i].answered == true) {
                return true;
            }
        }
    }
    return false;
}

void track_answered(char *category, int value) {
	for(int i = 0; i < 12; i++) 
		if(questions[i].value == value && strcmp(questions[i].category, category) == 0)
			questions[i].answered = true;
}

int get_question_number(char *category, int value) {
	for(int i = 0; i < 12; i++)
		if(strcmp(questions[i].category, category) == 0 && questions[i].value == value)
			return i;


	return -1;
}

bool answered_status() {
	for(int i = 0; i < 12; i++)
		if(questions[i].answered == false)
			return false;

	return true;
}