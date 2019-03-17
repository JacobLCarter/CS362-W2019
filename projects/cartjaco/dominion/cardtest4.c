/*******************************************************************************
 * Name: cardtest4
 * Author: Jacob Carter
 * Description: Tests the Village card in Dominion game
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
    printf("Card Test 4: Village\n");

    struct gameState g, test;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    initializeGame(2, k, 5, &g);
    initializeGame(2, k, 5, &test);

    memcpy(&g, &test, sizeof(struct gameState));

    addCardToHand(0, village, &test);

    playCard(test.handCount[0] - 1, -1, -1, -1, &test);

    if(g.handCount[0] + 1 == test.handCount[0])
    {
        printf("Test Passed: Hand size as expected.\n");
    }
    else
    {
        printf("Test Failed.\nExpected Hand Size: %d Actual Hand Size: %d\n", g.handCount[0] + 1, test.handCount[0]);
    }

    //test if the player was awarded an additional action by playing the Village card
    if(g.numActions + 1 == test.numActions)
    {
        printf("Test Passed: Actions as expected.\n");
    }
    else
    {
        printf("Test Failed.\nExpected Actions: %d Actual Actions: %d\n", g.numActions + 1, test.numActions);
    }

    return 0;
}