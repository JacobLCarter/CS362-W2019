/*******************************************************************************
 * Name: unittest4
 * Author: Jacob Carter
 * Description: Tests hand count in Dominion game
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
    printf("Unit Test 4: Hand Counting\n");

    struct gameState g;
    struct gameState *gamePointer = &g;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    initializeGame(2, k, 5, &g);

    drawCard(0, gamePointer);

    //check that hand count increased by one after drawing
    if (numHandCards(gamePointer) != 6)
    {
        printf("Test Failed. Hand cards incorrectly counted.\n");  
    }
    else
    {
        printf("All tests passed. Hand counting & drawing working as expected.\n");
    }

    return 0;
}