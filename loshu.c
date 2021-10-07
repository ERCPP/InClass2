#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <time.h>

int main () {
    //Correct Lo Shu Creation
    int testSquareCorrect[3][3] = {
        {4,9,2},
        {3,5,7},
        {8,1,6}
    };

    int row1 = testSquareCorrect[0][0] + testSquareCorrect[0][1] + testSquareCorrect[0][2];
    int diag1 = testSquareCorrect[0][0] + testSquareCorrect[1][1] + testSquareCorrect[2][2];
    int diag2 = testSquareCorrect[0][2] + testSquareCorrect[1][1] + testSquareCorrect[2][0];
    int isCorrect = 1;

    //Check rows to see if they add up.
    for (int i = 0; i<3; i++) {
        int total = 0;
        for (int j = 0; j<3; j++) {
            total = total + testSquareCorrect[i][j];
        }
        if (total != row1) {
            isCorrect = 0;
        }
    }

    //Check columns to see if they add up.
    for (int i = 0; i<3; i++) {
        int total = 0;
        for (int j = 0; j<3; j++) {
            total = total + testSquareCorrect[j][i];
        }
        if (total != row1) {
            isCorrect = 0;
        }
    }

    //Check diagnals to see if they add up.
    if ((diag1 != row1) && (diag2 != row1)) {
        isCorrect = 0;
    }

    //Check for duplicate values in rows
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int compared = testSquareCorrect[i][j];
            for (int current = j + 1; current < 3; current++) {
                if (compared == testSquareCorrect[i][current]) {
                    isCorrect = 0;
                }
            }
        }
    }

    //Check for duplicate values in columns
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int compared = testSquareCorrect[j][i];
            for (int current = j + 1; current < 3; current++) {
                if (compared == testSquareCorrect[current][i]) {
                    isCorrect = 0;
                }
            }
        }
    }


    if (isCorrect == 1) {
        printf("The first array is a Lo Shu Magic Square.\n");
    } else {
        printf("The first array is not a Lo Shu Magic Square.\n");
    }



    //Incorrect Lo Shu Creation
    int testSquareIncorrect[3][3] = {
        {47,51,6},
        {1,9,5},
        {6,5,4}
    };

    row1 = testSquareIncorrect[0][0] + testSquareIncorrect[0][1] + testSquareIncorrect[0][2];
    diag1 = testSquareIncorrect[0][0] + testSquareIncorrect[1][1] + testSquareIncorrect[2][2];
    diag2 = testSquareIncorrect[0][2] + testSquareIncorrect[1][1] + testSquareIncorrect[2][0];
    isCorrect = 1;

    //Check rows to see if they add up.
    for (int i = 0; i<3; i++) {
        int total = 0;
        for (int j = 0; j<3; j++) {
            total = total + testSquareIncorrect[i][j];
        }
        if (total != row1) {
            isCorrect = 0;
        }
    }

    //Check columns to see if they add up.
    for (int i = 0; i<3; i++) {
        int total = 0;
        for (int j = 0; j<3; j++) {
            total = total + testSquareIncorrect[j][i];
        }
        if (total != row1) {
            isCorrect = 0;
        }
    }

    //Check diagnals to see if they add up.
    if ((diag1 != row1) && (diag2 != row1)) {
        isCorrect = 0;
    }

    //Check for duplicate values in rows
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int compared = testSquareIncorrect[i][j];
            for (int current = j + 1; current < 3; current++) {
                if (compared == testSquareIncorrect[i][current]) {
                    isCorrect = 0;
                }
            }
        }
    }

    //Check for duplicate values in columns
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int compared = testSquareIncorrect[j][i];
            for (int current = j + 1; current < 3; current++) {
                if (compared == testSquareIncorrect[current][i]) {
                    isCorrect = 0;
                }
            }
        }
    }

    if (isCorrect == 1) {
        printf("The second array is a Lo Shu Magic Square.\n");
    } else {
        printf("The second array is not a Lo Shu Magic Square.\n");
    }

    int randomIsCorrect = 0;
    int attemptCount = 0;
    time_t t;
    srand((unsigned) time(&t));
    int randomSquare[3][3];
    while (randomIsCorrect != 1) {
        attemptCount++;
        for (int index1 = 0; index1 < 3; index1++) {
            for(int index2 = 0; index2 < 3; index2++) {
                int randomNum = rand() % 9;
                randomNum++;
                randomSquare[index1][index2] = randomNum;
            }
        }
        
        row1 = randomSquare[0][0] + randomSquare[0][1] + randomSquare[0][2];
        diag1 = randomSquare[0][0] + randomSquare[1][1] + randomSquare[2][2];
        diag2 = randomSquare[0][2] + randomSquare[1][1] + randomSquare[2][0];
        isCorrect = 1;
        
        //Check rows to see if they add up.
        for (int i = 0; i<3; i++) {
            int total = 0;
            for (int j = 0; j<3; j++) {
                total = total + randomSquare[i][j];
            }
            if (total != row1) {
                isCorrect = 0;
            }
        }

        //Check columns to see if they add up.
        for (int i = 0; i<3; i++) {
            int total = 0;
            for (int j = 0; j<3; j++) {
                total = total + randomSquare[j][i];
            }
            if (total != row1) {
                isCorrect = 0;
            }
        }

        //Check diagnals to see if they add up.
        if ((diag1 != row1) && (diag2 != row1)) {
            isCorrect = 0;
        }

        //Check for duplicate values in rows
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int compared = randomSquare[i][j];
                for (int current = j + 1; current < 3; current++) {
                    if (compared == randomSquare[i][current]) {
                        isCorrect = 0;
                    }
                }
            }
        }

        //Check for duplicate values in columns
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int compared = randomSquare[j][i];
                for (int current = j + 1; current < 3; current++) {
                    if (compared == randomSquare[current][i]) {
                        isCorrect = 0;
                    }
                }
            }
        }

        if (isCorrect == 1) {
            randomIsCorrect = 1;
        }
    }

    printf("There were %d generated squares before one was successful.\n", attemptCount);

    for (int index1 = 0; index1 < 3; index1++) {
        printf("[");
        for(int index2 = 0; index2 < 3; index2++) {
            printf("%d ", randomSquare[index1][index2]);
        }
        printf("]\n");
    }
}