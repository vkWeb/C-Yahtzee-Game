#include <stdio.h>
#include <string.h>

#define DICE_SIZE 20

void rollDice(char Dice[])
{
  printf("Please enter the dice values: \n");
  fgets(Dice, DICE_SIZE, stdin);
  Dice[strlen(Dice) - 1] = '\0';
}

void errorCheck(const char Dice[])
{
  for (int i = 0, length = strlen(Dice); i < length; ++i)
  {
    if (i % 2 != 0 && Dice[i] != ' ')
    {
      printf("Incorrect Input Format.");
      break;
    }
    else if (i % 2 == 0 && (Dice[i] < '0' || Dice[i] > '6'))
    {
      printf("Value Out of Range.");
      break;
    }
    else if (i > 8)
    {
      printf("Incorrect Number of Values.");
      break;
    }
  }
}

int main()
{
  char Dice[DICE_SIZE] = {0};
  rollDice(Dice);
  errorCheck(Dice);

  return 0;
}
