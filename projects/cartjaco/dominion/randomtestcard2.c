/*******************************************************************************
 * Name: randomtestcard1
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
#include <time.h>
#include <math.h>

int checkVillage(int p, struct gameState *pre)
{
    struct gameState post;
    memcpy(&post, pre, sizeof(struct gameState));

    playCard(post.handCount[p] - 1, -1, -1, -1, &post);

    if(pre->handCount[p] != post.handCount[p])
    {
        printf("Test Failed.\nExpected Hand Size: %d Actual Hand Size: %d\n", pre->handCount[p], post.handCount[p]);
        return 0;
    }

    if(pre->numActions + 1 != post.numActions)
    {
        printf("Test Failed.\nExpected Actions: %d Actual Actions: %d\n", pre->numActions + 1, post.numActions);
    }

    return 1;
}

int main()
{
    printf("Random Card Test 3: Village\n");

    srand(time(NULL));

    int i, j, k, m, staticHandCount, staticDeckCount;
    int seed = 500;
    int success = 0;
    int cards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
    struct gameState pre;
    
    for (i = 0; i < 5000; i++)
    {
        initializeGame(2, cards, seed, &pre);

        for (j = 0; j < 2; j++)
        {
            staticDeckCount = floor(rand() % (MAX_DECK - 1 + 1) + 1);
            staticHandCount = floor(rand() % (staticDeckCount - 1 + 1) + 1);
            pre.deckCount[j] = staticDeckCount;

            for (k = 0; k < staticDeckCount; k++)
            {
                pre.deck[j][k] = rand() % 27;
            }

            for (m = 0; m < staticHandCount - 6; m++)
            {
                drawCard(j, &pre);
            }

            addCardToHand(j, village, &pre);

            success += checkVillage(j, &pre);

            endTurn(&pre);
        }

        memset(&pre, 0, sizeof(struct gameState));
    }

    printf("10000 tests run - %d tests successful\n\n", success);

    return 0;
}