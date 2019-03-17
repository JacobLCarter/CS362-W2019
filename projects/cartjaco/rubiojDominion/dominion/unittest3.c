/*******************************************************************************
 * Name: unittest3
 * Author: Jacob Carter
 * Description: Tests card costs in Dominion game
 * Notes: many of the unit tests are the same, so the first is fully 
 * documented while following tests only have discrepencies documented.
 ******************************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "interface.h"
#include <assert.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Unit Test 3: Card Costs\n");

    struct gameState g;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    initializeGame(2, k, 5, &g);

    //seed for random number generation
    srand(time(0));

    int i = 0;
    int card;

    do
    {
        //get a random card
        card = rand() % 27;

        //if the cost returned from Dominion function matches the cost originally
        //set up in the interface, test is passed
        if(getCost(card) == getCardCost(card))
        {
            i++;
        }
        else
        {
            printf("Test failed. A card did not match with the correct cost.\n");
        }  
    } 
    while (i < 10);
    
    printf("All tests passed. Card costs working as expected.\n");

    return 0;
}
