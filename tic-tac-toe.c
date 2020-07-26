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

  system("clear");
  printLayout(positions);

  if (!winner)
  {
    printf("Its a draw\n");
    return;
  }
  printf("Player %d is the winner. Congrats\n", winner);
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
  int win_patterns[8][3] = {
      {0, 1, 2},
      {3, 4, 5},
      {6, 7, 8},
      {0, 3, 6},
      {1, 4, 7},
      {2, 5, 8},
      {0, 4, 8},
      {2, 4, 6}};
  int i;

  for (i = 0; i < 8; i++)
  {
    if (positions[win_patterns[i][0]] == positions[win_patterns[i][1]] && positions[win_patterns[i][1]] == positions[win_patterns[i][2]])
    {
      winner = (positions[win_patterns[i][0]] == 'x') ? 1 : 2;
      break;
    }
  }

  return winner;
}