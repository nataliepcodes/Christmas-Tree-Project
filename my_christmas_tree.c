#include <stdio.h>
#include <stdlib.h>


int tree_last_row(int tree_level)
{
   int tree_width = 7;// from tree_level 1
   int i = 2; // starting at tree_level 2
   int incrementer = 6;// from tree_level 1 -> 1 + 6 = 7

   while (i <= tree_level)
   {
      // If the tree_level is an odd number, add 2 to the incrementer each time
      if (i % 2 == 1)
      {
         incrementer += 2;
      }

      tree_width += incrementer;
      i++;
   }

   return tree_width;
}


int tree_spaces(int tree_level)
{
   int spaces = tree_last_row(tree_level) / 2;

   if (tree_level == 1)
   {
      spaces = 3;
   }

   return spaces;
}


int tree_stars(int tree_level) 
{
   tree_level = tree_level - 1; // tree_level previous to the curent tree level

   int base = tree_last_row(tree_level); //calculate the base of the previous tree level
   int top = base;

   tree_level = tree_level + 1; // setting the tree level back to the actual tree level

   int decrement = (tree_level / 2) * 2; // calculation for decrementer: every 2 rows decrement by 2 stars
   top -= decrement;

   return top;
}


int tree_trunk_spaces(int tree_level)
{
   int trunk_spaces = 0;
   int incremeter = 3;
   int i = 1;

   // If the tree_level is an even number & i is above 3, add 1 to the incrementer each time
   while (i <= tree_level)
   {
      if (i % 2 == 0 && i > 3)
      {
         incremeter += 1;
      }

      trunk_spaces += incremeter;
   
      i++;
   }

   return trunk_spaces;
}


// Printing the lower part of the Christmas tree
void tree_trunk(int tree_level)
{
   int trunk_spaces = tree_trunk_spaces(tree_level);

   // Print the tree trunk 
   for (int i = 1; i <= tree_level; i++)
   {
      for (int j = 1; j <= trunk_spaces; j++)
      {
         printf(" ");
      }
      for (int k = 1; k <= tree_level; k++)
      {
         printf("|");
      }

      printf("\n");

   }
}


void tree(int tree_level)
{
   int height = 4;
   int i = 1; // to increment the tree_level
   int j; // to increment the rows
   int k; // for spaces
   int l; // for stars
   int stars = 1, incrementer = 1;
   int spaces = tree_spaces(tree_level); // for each tree_size

   // Iterate over tree levels
   while (i <= tree_level)
   {
      // Set the number of spaces required based on the tree level
      if (i == 2)
         {
            spaces += 2;
         }

      if (i % 2 == 0 && i != 1)
         {
            incrementer += 1; // increasing space count by 1 at each level that is an even number
         }

      if (i > 2)
         {
            spaces = spaces + incrementer;
         }

      // Iterate over each row
      for (j = 1; j <= height; j++)
      {
         // Print the spaces
         for (k = 1; k <= spaces; k++)
         {  
            printf(" ");
         }
         // Print the stars
         for (l = 1; l <= stars; l++)
         {
            printf("\033[33;5;5m*\033[0m");
         }

         // After each row, increment stars by 2
         stars += 2;

         // After each row, decrement spaces by 1
         spaces -= 1;
         printf("\n");
      }

      // Increase initial row height of 4 by 1
      height = height + 1;

      // Increment to the next tree level
      i++;

      // Set the number of stars required based on the tree level
      stars = tree_stars(i);

   }

}


int main(int ac, char *av[])
{
   if (ac < 2 || ac > 2)
   {
      printf("Usage: ./my_christmas_tree <size>\n");
      return 0;
   }

   int tree_level = atoi(av[1]);
   printf("\n---------------------------------\ntier number: %d\n---------------------------------\n", tree_level);

   if (tree_level < 0 || tree_level > 10)
   {
      printf("You have entered: %d.\n", tree_level);
      printf("Please enter a positive number from 0 to 10.\n");
      return 0;
   }

   tree(tree_level);
   tree_last_row(tree_level);

   tree_trunk(tree_level);
   
   return 0;
}




