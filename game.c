#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int n)
{
 srand(time(NULL));
 return rand() % n;
}

int greater(char char1, char char2)
{
 if (char1 == char2)
 {
  return -1;
 }
 else if ((char1 == 'r') && (char2 == 's'))
 {
  return 1;
 }
 else if ((char2 == 'r') && (char1 == 's'))
 {
  return 0;
 }

 else if ((char1 == 'p') && (char2 == 'r'))
 {
  return 1;
 }
 else if ((char2 == 'p') && (char1 == 'r'))
 {
  return 0;
 }

 else if ((char1 == 's') && (char2 == 'p'))
 {
  return 1;
 }
 else if
  ((char2 == 's') && (char1 == 'p'))
  {
   return 0;
  }
}

int main()
{
 int playerscore = 0, compscore = 0, temp;
 char playerchar, compchar;
 char dict[] = {'r', 'p', 's'};

 printf("Welcome to Rock,Paper and Scissors Game...!\n");

 for (int i = 0; i < 3; i++)
 {
  // Take player's input
  printf("Player's Turn:\n");
  printf("Choose 1 for Rock,2 for Paper and 3 for Scissors\n");
  scanf("%d", &temp);
  getchar();
  playerchar = dict[temp - 1];
  printf("You choose:%c\n\n", playerchar);

  // Generate Comp's input
  printf("Comp's Turn:\n");
  printf("Choose 1 for Rock,2 for Paper and 3 for Scissors\n");
  temp = generateRandomNumber(3) + 1;
  compchar = dict[temp - 1];
  printf("Computer choose:%c\n\n", compchar);

  // Compares the scores
  if (greater(compchar, playerchar) == 1)
  {
   compscore += 1;
   printf("Comp got it!\n");
  }
  else if (greater(compchar, playerchar) == -1)
  {
   compscore += 1;
   playerscore += 1;
   printf("Draw!\n");
  }
  else
  {
   playerscore += 1;
   printf("You got it!\n");
  }
  printf("Your score:%d\nComp score:%d\n\n", playerscore, compscore);
 }

 if (playerscore > compscore)
 {
  printf("You won the Match\n");
 }

 else if (playerscore < compscore)
 {
  printf("Computer won the Match\n");
 }

 else
 {
  printf("Its a Draw");
 }
 return 0;
}