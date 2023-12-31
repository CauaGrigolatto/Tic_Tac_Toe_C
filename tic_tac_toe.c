#include <stdio.h>
#include <string.h>

void showGameboard(
    int counterValue,
    char a1, char a2, char a3,
    char b1, char b2, char b3,
    char c1, char c2, char c3
);
void showLine(char cell1, char cell2, char cell3);
int isThereWinner(
  char a1, char a2, char a3,
  char b1, char b2, char b3,
  char c1, char c2, char c3
);
int isDraw(
  char a1, char a2, char a3,
  char b1, char b2, char b3,
  char c1, char c2, char c3
);
int isLineWinner(char cell1, char cell2, char cell3);
void toMark(char *element, int *counterValue);
int isMarked(char cell);


void main()
{
  char decision[2];

  /*
    Initializing markup variables

    They match the line (letter) and
    the number of the column
    a1 -> line 'a' column '1'
  */

  char a1, a2, a3;
  a1 = a2 = a3 = '-';

  char b1, b2, b3;
  b1 = b2 = b3 = '-';

  char c1, c2, c3;
  c1 = c2 = c3 = '-';

  //initializng an infinit loop
  //when game ends -> break

  int counter = 0;

  while (1)
  {
    showGameboard(
        counter,
        a1, a2, a3,
        b1, b2, b3,
        c1, c2, c3
    );

    scanf("%s", &decision);

    if (strcmp(decision, "a1") == 0)
    {
      toMark(&a1, &counter);
    }
    else if (strcmp(decision, "a2") == 0)
    {
      toMark(&a2, &counter);
    }
    else if (strcmp(decision, "a3") == 0)
    {
      toMark(&a3, &counter);
    }
    else if (strcmp(decision, "b1") == 0)
    {
      toMark(&b1, &counter);
    }
    else if (strcmp(decision, "b2") == 0)
    {
      toMark(&b2, &counter);
    }
    else if (strcmp(decision, "b3") == 0)
    {
      toMark(&b3, &counter);
    }
    else if (strcmp(decision, "c1") == 0)
    {
      toMark(&c1, &counter);
    }
    else if (strcmp(decision, "c2") == 0)
    {
      toMark(&c2, &counter);
    }
    else if (strcmp(decision, "c3") == 0)
    {
      toMark(&c3, &counter);
    }

    //win verification
    if (isThereWinner(
      a1, a2, a3, 
      b1, b2, b3, 
      c1, c2, c3
    ))
    {
      printf("\n\n--- Tivemos um vencedor! ---");
      break;
    }

    //draw verification
    if (isDraw(
      a1, a2, a3,
      b1, b2, b3,
      c1, c2, c3
    ))
    {
      printf("\n\n--- Empatou! ---");
      break;
    }

  }

  showGameboard(
        counter,
        a1, a2, a3,
        b1, b2, b3,
        c1, c2, c3
  );
}

//Functions:

//This function will print the Gameboard entirely
void showGameboard(
    int counterValue,
    char a1, char a2, char a3,
    char b1, char b2, char b3,
    char c1, char c2, char c3
)
{
  printf("\n--- Rodada %i ---\n\n", counterValue);
  printf("   1   2   3\n");
  printf("A");
  showLine(a1, a2, a3);
  printf("B");
  showLine(b1, b2, b3);
  printf("C");
  showLine(c1, c2, c3);
}

//This function will print only a line
void showLine(char cell1, char cell2, char cell3)
{
  printf("  %c   %c   %c\n\n", cell1, cell2, cell3);
}

//This function verifies if already have a winner
int isThereWinner(
  char a1, char a2, char a3,
  char b1, char b2, char b3,
  char c1, char c2, char c3
)
{
  if (
    isLineWinner(a1, a2, a3) ||
    isLineWinner(b1, b2, b3) ||
    isLineWinner(c1, c2, c3) ||

    isLineWinner(a1, b1, c1) ||
    isLineWinner(a2, b2, c2) ||
    isLineWinner(a3, b3, c3) ||

    isLineWinner(a1, b2, c3) ||
    isLineWinner(a3, b2, c1)
  )
  {
    return 1;
  }

  return 0;
}

//This function verifies if it is a draw
int isDraw(
  char a1, char a2, char a3,
  char b1, char b2, char b3,
  char c1, char c2, char c3
)
{
  if (
    isMarked(a1) && isMarked(a2) && isMarked(a3) &&
    isMarked(b1) && isMarked(b2) && isMarked(b3) &&
    isMarked(c1) && isMarked(c2) && isMarked(c3) 
  )
  {
    return 1;
  }
  
  return 0;
}

//This function verifies if the line has won
int isLineWinner(char cell1, char cell2, char cell3)
{
  if (isMarked(cell1) && isMarked(cell2) && isMarked(cell3))
  {
    if (cell1 == cell2 && cell2 == cell3)
    {
      return 1;
    }
  }

  return 0;
}

//This function puts a letter into the correct variable
void toMark(char *element, int *counterValue)
{
  //if counter is even, turn of X
  //else (is odd), turno of O
  if (!isMarked(*element))
  {
    if (*counterValue % 2 == 0)
    {
      *element = 'X';
    }
    else
    {
      *element = 'O';
    }

    (*counterValue)++;
  }
}

//This function verifies if the cell is already marked
int isMarked(char cell)
{
  if (cell == '-')
  {
    return 0;
  }

  return 1;
}