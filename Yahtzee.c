#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define DICE_SIZE 15

bool rollDice(char dice[])
{
  printf("\nPlease enter dice values:\n");
  fgets(dice, DICE_SIZE, stdin);
  dice[strlen(dice) - 1] = '\0';
  for (int i = 0; i < strlen(dice); ++i)
  {
    if (dice[i] != ' ' && i % 2 != 0)
    {
      printf("Incorrect Input Format.");
      return false;
    }
    else if ((dice[i] < '1' || dice[i] > '6') && i % 2 == 0)
    {
      printf("Value Out of Range.");
      return false;
    }
    else if ((dice[i] >= '0') && i > 8)
    {
      printf("Incorrect Number of Values.");
      return false;
    }
  }
  return true;
}

int displayOptions()
{
  printf("\nPlease choose: ");
  printf("\n1 -> Reroll some dice");
  printf("\n2 -> Reroll all dice");
  printf("\n3 -> Keep dice\n\n> ");
  char option = getchar();
  if (option == '1' || option == '2' || option == '3')
  {
    return (int)(option - '0');
  }
  printf("\nInvalid Choice.");
  return 0;
}

void keepDice(char dice[])
{
  int diceFrequency[6] = {0};
  for (int i = 0; i < 6; ++i)
  {
    ++diceFrequency[(int)(dice[i] - '1')];
  }

  printf("Your score options are: ");

  for (int i = 0, count = 0; i < 6; ++i)
  {
  }
}

int main(void)
{
  char dice[DICE_SIZE] = {0};

  if (rollDice(dice))
  {
    if (displayOptions() == 3)
    {
      keepDice(dice);
    }
  }

  return 0;
}