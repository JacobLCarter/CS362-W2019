/*******************************************************************************
 * Name: cardtest2
 * Author: Jacob Carter
 * Description: Tests the Adventurer card in Dominion game
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
    printf("Card Test 2: Adventurer\n");

    struct gameState g, test;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    initializeGame(2, k, 5, &g);
    initializeGame(2, k, 5, &test);

    memcpy(&g, &test, sizeof(struct gameState));

    addCardToHand(0, adventurer, &test);

    playCard(test.handCount[0] - 1, -1, -1, -1, &test);

    if(g.handCount[0] + 2 == test.handCount[0])
    {
        printf("Test Passed: Hand size as expected.\n");
    }
    else
    {
        printf("Test Failed.\nExpected Hand Size: %d Actual Hand Size: %d\n", g.handCount[0] + 2, test.handCount[0]);
    }

    //tests the last two cards drawn to determine if we successfully picked up treasure cards
    for (int i = 1; i < 3; i++)
    {
        if(test.hand[0][test.handCount[0] - i] == copper || test.hand[0][test.handCount[0] - i] == silver ||
            test.hand[0][test.handCount[0] - i] == gold)
        {
            printf("Test Passed: Treasure card drawn from the deck: %d.\n", test.hand[0][test.handCount[0] - i]);
        }
        else
        {
            printf("Test Failed. Drawn card not a treasure card.\n");
        }
    }

    return 0;
}