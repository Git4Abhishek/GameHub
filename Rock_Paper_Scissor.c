// ********** Rock Paper Scissor Game ************
// Author: Abhishek Kumar Rai
// Date: August 2022 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    printf("**** GAME TIME ****\n\n");
    char *ptr;
    ptr = (char *)malloc(24 * sizeof(char));
    printf("Enter player's name :\n");
    gets(ptr);
    printf("\n");
    printf("%s vs Computer\n\n", ptr);
    char p;
    static int Cpts[3];
    static int Ppts[3];
play:
    printf("Press 'r' for Rock\nPress 'p' for paper\nPress 's' for Scissor\n\n");
    for (int i = 0; i < 3; i++)
    {
    again:
        srand(time(NULL));
        int c = rand() % 3;

        switch (c)
        {
        case 0:
            printf("Play your turn :\n");
            scanf("%c", &p);
            getchar();
            if (p == 'r')
            {
                printf("Oops! both choose Rock\n\n");
                goto again;
            }
            if (p == 'p')
            {
                printf("You choose Paper\n");
                Ppts[i] = 1;
            }
            if (p == 's')
            {
                printf("You choose Scissor\n");
                Cpts[i] = 1;
            }
            printf("Computer choose Rock\n\n");

            break;
        case 1:
            printf("Play your turn :\n");
            scanf("%c", &p);
            getchar();
            if (p == 'r')
            {
                printf("You choose Rock\n");
                Cpts[i] = 1;
            }
            if (p == 'p')
            {
                printf("Oops! both choose Paper\n\n");
                goto again;
            }
            if (p == 's')
            {
                printf("You choose Scissor\n");
                Ppts[i] = 1;
            }
            printf("Computer choose Paper\n\n");

            break;
        case 2:
            printf("Play your turn :\n");
            scanf("%c", &p);
            getchar();
            if (p == 'r')
            {
                printf("You choose Rock\n");
                Ppts[i] = 1;
            }
            if (p == 'p')
            {
                printf("You choose Paper\n");
                Cpts[i] = 1;
            }
            if (p == 's')
            {
                printf("Oops! both choose Scissor\n\n");
                goto again;
            }
            printf("Computer choose Scissor\n\n");

            break;

        default:
            break;
        }
    }

    printf("%s's score is %d\nComputer's score is %d\n", ptr, (Ppts[0] + Ppts[1] + Ppts[2]), (Cpts[0] + Cpts[1] + Cpts[2]));

    if ((Ppts[0] + Ppts[1] + Ppts[2]) > (Cpts[0] + Cpts[1] + Cpts[2]))
        printf("Hurray! %s wins.\n", ptr);
    else
        printf("Oops! %s lost.\n", ptr);
    printf("\n");
    int choice;
    printf("Press 1 to play again\nPress 0 to exit\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        getchar();
        printf("\n");
        goto play;
    }
    else
        return 0;
}

