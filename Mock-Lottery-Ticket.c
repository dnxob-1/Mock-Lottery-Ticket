#include <float.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Lottery ticket simulation */

int main() {

  srand(time(NULL));

  // variables
  int ballPick1[5];
  int ballPick2[1];
  int Winner[6];
  int getSize1 = sizeof(ballPick1) / sizeof(ballPick1[0]);
  int getSize2 = sizeof(ballPick2) / sizeof(ballPick2[0]);
  int getSize3 = sizeof(Winner) / sizeof(Winner[0]);
  int tempCounter = 0;

  // loop 1 for regBall (1-69)
  for (int i = 0; i < 5; i++) {
    ballPick1[i] = rand() % 69 + 1;
    printf("regBall: %d\n", ballPick1[i]);
  }

  // loop 2 for powerBall (1-25)
  for (int i = 0; i < 1; i++) {
    ballPick2[i] = rand() % 25 + 1;
    printf("powBall: %d\n", ballPick2[i]);
  }

  // randomly make a winner
  for (int i = 0; i < 6; i++) {
    Winner[i] = rand() % 69 + 1;
    printf("trueWin: %d\n", Winner[i]);
  }

  // was meant to count the matches of Winner, ballPick1 and ballpick2
  for (int n = 0; n < getSize3; n++) {
    for (int p = 0; p < getSize1; p++) {
      if (ballPick1[p] == Winner[n]) {
        tempCounter++;
        break;
      }
    }
    for (int r = 0; r < getSize2; r++) {
      if (ballPick2[r] == Winner[n])
        tempCounter++;
      break;
    }
  }

  printf("%d/6", tempCounter);
}
