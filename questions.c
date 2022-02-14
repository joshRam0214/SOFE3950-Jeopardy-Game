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
        question[a].answered = false;
    }

    //$200 questions -------------------------------->
    questions[0].value = 200;
    strcpy(questions[0].question, "When life gives you lemons...");
    strcpy(questions[0].answer, "make lemonade");

    questions[1].value = 200;
    strcpy(questions[1].question, "A \"Mandalorian\" character is named Grogu & is also called the Child, but viewers dubbed him \"Baby\" this");
    strcpy(questions[1].answer, "Yoda");

    questions[2].value = 200;
    strcpy(questions[2].question, "Pu-239 is an isotope of this silvery metal");
    strcpy(questions[2].answer, "plutonium");

    //$400 questions -------------------------------->
    questions[3].value = 400;
    strcpy(questions[3].question, "I came, I saw, ...");
    strcpy(questions[3].answer, "I conquered");

    questions[4].value = 400;
    strcpy(questions[4].question, "The devil didn't go down to Georgia, he went up to L.A. to open a nightclub & solve murders on this Netflix show");
    strcpy(questions[4].answer, "Lucifer");

    questions[5].value = 400;
    strcpy(questions[5].question, "Sir Humphry Davy used electrolysis to isolate it, symbol K");
    strcpy(questions[5].answer, "potassium");

    //$600 questions -------------------------------->
    questions[6].value = 600;
    strcpy(questions[6].question, "A legal principle: \"Ignorance of the law is...\"");
    strcpy(questions[6].answer, "no excuse");

    questions[7].value = 600;
    strcpy(questions[7].question, "Billy Butcher has some serious issues with superheroes on this Amazon show & confronts them quite directly");
    strcpy(questions[7].answer, "The Boys");

    questions[8].value = 600;
    strcpy(questions[8].question, "Atomic No. 20, it's needed for kids' teeth to grow");
    strcpy(questions[8].answer, "calcium");

    //$800 questions -------------------------------->
    questions[9].value = 800;
    strcpy(questions[9].question, "Among AFI's 100 Greatest Movie Quotes of All Time:");
    strcpy(questions[9].answer, "phone home");

    questions[10].value = 800;
    strcpy(questions[10].question, "An HBO Max series with \"That Damn\" this \"Weekend Update\" co-anchor examines issues like racial profiling & unemployment");
    strcpy(questions[10].answer, "Jaskaran");

    questions[11].value = 800;
    strcpy(questions[11].question, "This element makes up about 25% of the mass in your average star");
    strcpy(questions[11].answer, "helium");

}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    for (int x = 0; x < 3; x++) {

    }
        for (int y = 0; y < 12; y++) {
            printf("$ %d", question[y].value)
        }
    
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{

}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    return false;
}
