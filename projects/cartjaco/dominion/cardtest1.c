/*******************************************************************************
 * Name: cardtest1
 * Author: Jacob Carter
 * Description: Tests the Smithy card in Dominion game
 * Notes: many of the card tests are the same, so the first is fully 
 * documented while following tests only have discrepencies documented.
 ******************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <assert.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>

int main()
{
    //print the name of the test
    printf("Card Test 1: Smithy\n");

    //set-up structs to hold the current state of the game
    struct gameState g, test;

    //set-up kingdom cards for the game
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    //initialize both gameState structs
    initializeGame(2, k, 5, &g);
    initializeGame(2, k, 5, &test);

    //clear memory for both gameState structs
    memcpy(&g, &test, sizeof(struct gameState));

    //add the passed card to the first player's hand
    addCardToHand(0, smithy, &test);

    //play the card that was just drawn and will be tested
    playCard(test.handCount[0] - 1, -1, -1, -1, &test);

    //check that the player's actual hand count is as expected by the rules of Dominion
    if(g.handCount[0] + 3 == test.handCount[0])
    {
        printf("Test Passed: Hand size as expected.\n");
    }
    else
    {
        printf("Test Failed.\nExpected Hand Size: %d Actual Hand Size: %d\n", g.handCount[0] + 3, test.handCount[0]);
    }

    return 0;
}