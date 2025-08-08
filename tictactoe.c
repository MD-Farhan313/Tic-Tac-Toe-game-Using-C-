// TIC TAC TOE game
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
char A[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
void check(char, char);

void gamename()
{
    printf("\n\t\t\tTic Tac Toe Game :");
}

void show()
{
    printf("\n\n\t\t\t---|---|---\n");
    printf("\t\t\t %c | %c | %c \n", A[0], A[1], A[2]);
    printf("\t\t\t---|---|---\n");
    printf("\t\t\t %c | %c | %c \n", A[3], A[4], A[5]);
    printf("\t\t\t---|---|---\n");
    printf("\t\t\t %c | %c | %c \n", A[6], A[7], A[8]);
    printf("\t\t\t---|---|---\n");
}

void playersymbol()
{
    printf("\n\n player 1 symbol : x\n");
    printf("\n player 2 symbol : O\n");
}

void start()
{
    char P;
    printf("\n enter who will start the game player 1 or player 2 \n ");
    scanf("%c", &P);
}

int count = 0;

void play()
{
    char p, s;
    printf("\n enter position & symbol for the player :\n ");
    fflush(stdin);
    scanf("%c", &p);
    fflush(stdin);
    scanf("%c", &s);
    count++;
    check(p, s);
}

void check(char P, char S)
{
    int i;
    for (i = 0; i <= 8; i++)
    {
        if (A[i] == P)
        {
            A[i] = S;
        }
    }
}

int end()
{
    if (A[0] == 'x' && A[1] == 'x' && A[2] == 'x' || A[0] == 'x' && A[3] == 'x' && A[6] == 'x' || A[0] == 'x' && A[4] == 'x' && A[8] == 'x')
        return (100);

    else if (A[0] == 'o' && A[1] == 'o' && A[2] == 'o' || A[0] == 'o' && A[3] == 'o' && A[6] == 'o' || A[0] == 'o' && A[4] == 'o' && A[8] == 'o')
        return (200);

    else if (A[1] == 'x' && A[4] == 'x' && A[7] == 'x')
        return (100);

    else if (A[1] == 'o' && A[4] == 'o' && A[7] == 'o')
        return (200);

    else if (A[2] == 'x' && A[5] == 'x' && A[8] == 'x' || A[2] == 'x' && A[4] == 'x' && A[6] == 'x')
        return (100);

    else if (A[2] == 'o' && A[5] == 'o' && A[8] == 'o' || A[2] == 'o' && A[4] == 'o' && A[6] == 'o')
        return (200);

    else if (A[3] == 'x' && A[4] == 'x' && A[5] == 'x')
        return (100);

    else if (A[3] == 'o' && A[4] == 'o' && A[5] == 'o')
        return (200);

    else if (A[6] == 'x' && A[7] == 'x' && A[8] == 'x')
        return (100);

    else if (A[6] == 'o' && A[7] == 'o' && A[8] == 'o')
        return (200);

    return (300);
}

void main()
{
    int k;
    char ch;
labell:
    system("cls");
    gamename();
    show();
    playersymbol();
    start();
    play();

label:
    system("cls");
    show();
    play();
    k = end();
    system("cls");
    show();
    if (count < 9)
    {
        if (k == 100)
        {
            printf("\nplayer 1 won");
            count = 0;
        }

        else if (k == 200)
        {
            printf("\nplayer 2 won");
            count = 0;
        }
        else
            goto label;
    }
    else
    {
        printf("\n Game Draw");
        count = 0;
    }

    printf("\n do you want to play again enter : Y for YES and N for NO :");
    fflush(stdin);
    scanf("%c", &ch);
    if (ch == 'y' || ch == 'Y')
    {
        A[0] = '1';
        A[1] = '2';
        A[2] = '3';
        A[3] = '4';
        A[4] = '5';
        A[5] = '6';
        A[6] = '7';
        A[7] = '8';
        A[8] = '9';

        goto labell;
    }

    getch;
}