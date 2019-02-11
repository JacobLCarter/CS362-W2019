/*******************************************************************************
 * Name: unittest1
 * Author: Jacob Carter
 * Description: Tests turn-switching in Dominion game
 * Notes: many of the unit tests are the same, so the first is fully 
 * documented while following tests only have discrepencies documented.
 ******************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main()
{
    //print the name of the test
    printf("Unit Test 1: Turn-Switching\n");

    //set-up struct to hold the current state of the game
    struct gameState g;

    //set-up pointer-to-struct to pass into functions
    struct gameState *gamePointer = &g;

    //set-up kingdom cards for the game
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    //initialize the gameState struct
    initializeGame(2, k, 5, &g);

    //do two turn switches to check if it goes to the second player and then
    //back to the first successfully
    for(int i = 0; i < 3; i++)
    {
        //modulo will return either 0 or 1 to represent the player's number
        if ((i % 2) == whoseTurn(gamePointer))
        {
            endTurn(gamePointer);
        }
        else
        {
            printf("Test Failed: Turn incorrectly switched\n");
            return -1;
        }
    }

    printf("All tests passed. Turn switching working as expected.\n");

    return 0;
}