/*******************************************************************************
 * Name: unittest2
 * Author: Jacob Carter
 * Description: Tests deck shuffling in Dominion game
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
    printf("Unit Test 2: Deck Shuffling\n");

    struct gameState g;
    struct gameState *gamePointer = &g;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    initializeGame(2, k, 5, &g);

    //will hold the state of the deck before shuffling
    int oldDeck[MAX_DECK];
    int i;
    //total number of cards in hand; will represent the place in which to draw a new card
    int j = numHandCards(&g);
    int counter = 0;

    //save the original deck state before shuffling for comparison
    for (i = 0; i < j; i++)
    {
        oldDeck[0] = gamePointer->deck[0][i];
    }

    //shuffle the player's deck
    shuffle(0, &g);

    //shuffle until the deck is the same size as original deck
    for (i = 0; i < j; i++)
    {
        //if the cards in the respective positions have not changed, increment the counter
        if(oldDeck[i] == gamePointer->deck[0][i])
        {
            counter++;
        }
    }

    //if at least 3 cards did not move, consider the shuffle to be insufficient and fail test
    if (counter >= 3)
    {
        printf("Insufficient shuffle -- too many cards not randomized.\n");
    }
    else
    {
        printf("All tests passed. Deck shuffling working as expected.\n");
    }

    return 0;
}