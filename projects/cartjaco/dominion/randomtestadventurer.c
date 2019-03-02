/*******************************************************************************
 * Name: randomtestadventurer
 * Author: Jacob Carter
 * Description: Random tester for the Adventurer card in Dominion game
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

int checkAdventurer(int p, struct gameState *pre)
{
    struct gameState post;
    int status = 1;
    memcpy(&post, pre, sizeof(struct gameState));

    playCard(post.handCount[p] - 1, -1, -1, -1, &post);

    if(pre->handCount[p] + 2 != post.handCount[p])
    {
        printf("Test Failed. Expected Hand Size: %d Actual Hand Size: %d\n", pre->handCount[p] + 2, post.handCount[p]);
        status = 0;
    }

    //tests the last two cards drawn to determine if we successfully picked up treasure cards
    for (int i = 1; i < 3; i++)
    {
        if(!(post.hand[p][post.handCount[p] - i] == copper || post.hand[p][post.handCount[p] - i] == silver ||
            post.hand[p][post.handCount[p] - i] == gold))
        {
            printf("Test Failed. Drawn card not a treasure card.\n");
            status = 0;
        }
    }

    if(pre->deckCount[p] - (post.deckCount[p] + 2) != post.discardCount[p])
    {
        printf("Test Failed. Expected Discard Size: %d Actual Discard Size: %d\n",
             pre->deckCount[p] - (post.deckCount[p] + 2), post.discardCount[p]);
        status = 0;
    }

    for (int j = 0; j < post.discardCount[p]; j++)
    {
        if(post.discard[p][j] == copper || post.discard[p][j] == silver ||
            post.discard[p][j] == gold)
        {
            printf("Test Failed: Treasure card discarded\n");
            status = 0;
        }
    }

    return status;
}

int main()
{
    printf("Random Card Test 3: Adventurer\n");

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

            for (m = 5; m < staticHandCount - 1; m++)
            {
                drawCard(j, &pre);
            }

            addCardToHand(j, adventurer, &pre);

            success += checkAdventurer(j, &pre);

            endTurn(&pre);
        }

        memset(&pre, 0, sizeof(struct gameState));
    }

    printf("10000 tests run - %d tests successful\n\n", success);

    return 0;
}