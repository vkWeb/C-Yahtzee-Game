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

int sumOfAllDice(int diceFrequency[])
{
  int diceSum = 0;
  for (int i = 0; i < 6; ++i)
    diceSum += (diceFrequency[i] * (i + 1));
  return diceSum;
}

void keepDice(char dice[])
{
  int diceFrequency[6] = {0};
  int scoreOptions[7] = {0};

  for (int i = 0; i < strlen(dice); ++i)
  {
    if (dice[i] != ' ')
      ++diceFrequency[(int)(dice[i] - '1')];
  }

  printf("\nYour score options are: ");

  int option = 0;
  for (int i = 0, consecutiveCount = 0; i < 6; ++i)
  {
    if (diceFrequency[i] == 1 || diceFrequency[i] == 2)
      ++consecutiveCount;
    if (diceFrequency[i] >= 3)
    {
      scoreOptions[option] = sumOfAllDice(diceFrequency);
      printf("\n%d -> Three of a Kind (%d points)", (option + 1), scoreOptions[option]);
      ++option;
    }
    if (diceFrequency[i] >= 4)
    {
      scoreOptions[option] = sumOfAllDice(diceFrequency);
      printf("\n%d -> Four of a Kind (%d points)", (option + 1), scoreOptions[option]);
      ++option;
    }
    if (diceFrequency[i] == 3)
    {
      for (int j = 0; j < 6; ++i)
      {
        if (diceFrequency[j] == 2)
        {
          scoreOptions[option] = 25;
          printf("\n%d -> Full House (%d points)", (option + 1), scoreOptions[option]);
          ++option;
        }
      }
    }
    if (consecutiveCount == 4 && consecutiveCount != 5)
    {
      scoreOptions[option] = 30;
      printf("\n%d -> Small Straight (%d points)", (option + 1), scoreOptions[option]);
      ++option;
    }
    if (consecutiveCount == 5)
    {
      scoreOptions[option] = 40;
      printf("\n%d -> Straight (%d points)", (option + 1), scoreOptions[option]);
      ++option;
    }
    if (diceFrequency[i] == 5)
    {
      scoreOptions[option] = 50;
      printf("\n%d -> Yahtzee (%d points)", (option + 1), scoreOptions[option]);
      ++option;
    }
  }
  scoreOptions[option] = sumOfAllDice(diceFrequency);
  printf("\n%d -> Chance (%d points)", (option + 1), scoreOptions[option]);
  ++option;
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
  printf("\n");
  return 0;
}
