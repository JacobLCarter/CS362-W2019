/*******************************************************************************
 * Name: cardtest3
 * Author: Jacob Carter
 * Description: Tests the Council Room card in Dominion game
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
    printf("Card Test 3: Council Room\n");

    struct gameState g, test;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    initializeGame(2, k, 5, &g);
    initializeGame(2, k, 5, &test);

    memcpy(&g, &test, sizeof(struct gameState));

    addCardToHand(0, council_room, &test);

    playCard(test.handCount[0] - 1, -1, -1, -1, &test);

    if(g.handCount[0] + 4 == test.handCount[0])
    {
        printf("Test Passed: Hand size as expected.\n");
    }
    else
    {
        printf("Test Failed.\nExpected Hand Size: %d Actual Hand Size: %d\n", g.handCount[0] + 4, test.handCount[0]);
    }

    //test if the first player was awarded another buy from the Adventurer card
    if(g.numBuys + 1 == test.numBuys)
    {
        printf("Test Passed: Buys as expected.\n");
    }
    else
    {
        printf("Test Failed.\nExpected Buys: %d Actual Buys: %d\n", g.numBuys + 1, test.numBuys);
    }

    //test if the other player successfully drew a new card
    if(g.handCount[1] + 1 == test.handCount[1])
    {
        printf("Test Passed: Buys as expected.\n");
    }
    else
    {
        printf("Test Failed.\nExpected Buys: %d Actual Buys: %d\n", g.handCount[1] + 1, test.handCount[1]);
    }

    return 0;
}