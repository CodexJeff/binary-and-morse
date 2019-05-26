#include <stdio.h>
#include <string.h>

#define MAX_STR 250 //Setting the max sentece length

int main() {
    char toConvert[MAX_STR]; //To hold user input
    printf("Enter a MORSE CODE sequence to be converted to an english Sentence.\n(NO MORE THAN 200 CHARACTERS OR 50 WORDS)\n");
    scanf("%[^'\n']s", toConvert);
    printf("Here is your sentence in english:\n");
    char alpha[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char *morse[] = {".-", "-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    char *new = strtok(toConvert, " "); //Splits when a space occurs
    char *finalMorse[50]; //Used to store the split morse letters
    int n = 0; //Counter for the while loop (basically makes it a for loop)
    while(new != NULL){ //Creation of the char array filled with strings
        finalMorse[n] = (new);
        new = strtok(NULL, " "); // Finds NULL's and replaces with space
        n++;
    }
    for (int i = 0; i < n; i++){ //Used counter to letters to get size of all letters
        for (int j = 0; j < 26; j++){ //Size of morse alphabet
            if (strcmp(finalMorse[i], morse[j]) == 0){ //Compares morse and user entry
                printf("%c", alpha[j]); //Prints english alphabet letter if equal on line 26
                break;
            }
            if (strcmp(finalMorse[i], "?") == 0){ //Since prof said to keep "?" characters
                printf("%s",finalMorse[i]); //Prints if "?" is found
                break;
            }
        }
    }
    printf("\n");
    return 0;
}
