#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void printLayout(char *);
int inputPosition(char *, int);
int whoWonTheGame(char *);

void main()
{
  int game_over = 0;
  char positions[10] = "123456789";
  int player1_turn = 1;
  int input_count = 0;
  int winner;

  printf("Hit ENTER to start");
  getchar();

  while (!game_over)
  {
    system("clear");
    printLayout(positions);

    if (!inputPosition(positions, player1_turn))
    {
      printf("Position already taken. Choose again");
      continue;
    }

    player1_turn = !player1_turn;
    input_count++;

    winner = whoWonTheGame(positions);

    if (winner || input_count >= 9)
      game_over = 1;
  }

  if (!winner)
  {
    printf("\nIts a draw");
    return;
  }
  printf("\nPlayer %d is the winner. Congrats", winner);
}

int inputPosition(char *positions, int player1_turn)
{
  int position;
  int player = player1_turn ? 1 : 2;
  char input = (player == 1) ? 'x' : 'o';

  printf("Player %d, input your position", player);
  scanf("%d", &position);

  if (isalpha(positions[position - 1]))
    return 0;

  positions[position - 1] = input;
  return 1;
}

void printLayout(char *positions)
{
  int i;

  for (i = 0; i < 9; i += 3)
  {
    printf("\n %c | %c | %c \n", positions[i], positions[i + 1], positions[i + 2]);
    if (i < 6)
      printf("-----------");
  }
}

int whoWonTheGame(char *positions)
{
  int winner = 0;
  
  if (positions[0] == positions[1] && positions[1] == positions[2])
  {
    winner = (positions[0] == 'x') ? 1 : 2;
  }
  else if (positions[3] == positions[4] && positions[4] == positions[5])
  {
    winner = (positions[3] == 'x') ? 1 : 2;
  }
  else if (positions[6] == positions[7] && positions[7] == positions[8])
  {
    winner = (positions[6] == 'x') ? 1 : 2;
  }
  else if (positions[0] == positions[3] && positions[3] == positions[6])
  {
    winner = (positions[0] == 'x') ? 1 : 2;
  }
  else if (positions[1] == positions[4] && positions[4] == positions[7])
  {
    winner = (positions[1] == 'x') ? 1 : 2;
  }
  else if (positions[2] == positions[5] && positions[5] == positions[8])
  {
    winner = (positions[2] == 'x') ? 1 : 2;
  }
  else if (positions[0] == positions[4] && positions[4] == positions[8])
  {
    winner = (positions[0] == 'x') ? 1 : 2;
  }
  else if (positions[2] == positions[4] && positions[4] == positions[6])
  {
    winner = (positions[2] == 'x') ? 1 : 2;
  }
  return winner;
}