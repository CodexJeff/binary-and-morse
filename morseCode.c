#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 500 //Setting the max sentece length

int main() {
  char toConvert[MAX_STR];
  printf("Please enter a sentence in ENGLISH, then hit ENTER to have the sentence\nconverted to Morse code. (SENTENCE MUST BE LESS THAN 250 CHARACTERS):\n");
  scanf("%[^'\n']s", toConvert);
  printf("Here is your sentence in Morse Code:\n");
  char alpha[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' '};
  char *morse[] = {".- ", "-... ","-.-. ","-.. ",". ","..-. ","--. ",".... ",".. ",".--- ","-.- ",".-.. ","-- ","-. ","--- ",".--. ","--.- ",".-. ","... ","- ","..- ","...- ",".-- ","-..- ","-.-- ","--.. ","  "};
  for (int j = 0; j < strlen(toConvert); j++){ //Nested loops checks user and alphabet
    for (int i = 0; i < 28; i++){
      if((toupper(toConvert[j]) >= 'A' && toupper(toConvert[j]) <= 'Z') || toupper(toConvert[j]) == ' '){ //Determines if its a letter
        if (toupper(toConvert[j]) == alpha[i]){ //Compares user entry and alphabet
          printf("%s", morse[i]); //Prints morse letter if equal on line 19
        }
      }
      else{
        printf("?"); //Prints if not found
        break;
      }
    }
  }
  printf("\n");
  return 0;
}
