#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//Define
int getDecimal (char str[]);
void flipper (char str[]);
void add (char str[], char str2[]);

int main() {
  //Binary arrays
  char get1[10], get2[10];
  //Variables to get size, check for pos/neg, store decimal val
  int count = 0, first1 = 1, second1 = 1, decA, decB;

  //Line 17 to 82 checking conditions and printing fucntions if passed
  printf("Enter 1st 8-bit sequence: ");
  scanf("%s", get1);
  printf("Enter 2nd 8-bit sequence: ");
  scanf("%s", get2);
  if (strlen(get1) == 8 && strlen(get2) == 8){ 
    for (int i = 0; i < 8; i++){
      if (get1[i] == '0' || get1[i] == '1'){
        if (get2[i] == '0' || get2[i] == '1'){
          count++;
          if (count == 8){
            if(get1[0] == '1'){
              first1 = -1;
              printf("  %s", get1);
              flipper(get1);
              decA = (getDecimal(get1)*first1) - 1;
              printf("  (%d)\n", decA);
              flipper(get1);
            }
            if(get1[0] == '0'){
              printf("  %s", get1);
              decA = getDecimal(get1);
              printf("  (%d)\n", decA);
            }
            if(get2[0] == '1'){
              second1 = -1;
              printf("  %s", get2);
              flipper(get2);
              decB = (getDecimal(get2)*second1) - 1;
              printf("  (%d)\n", decB);
              printf("------------------\n");
              flipper(get2);
              add(get1, get2);
              for (int i = 0; i < 8; i++){
                printf("%c" ,get1[i]);
              }
              printf("  (%d)\n",decA + decB);
              printf("\n");
              return 0;
            }
            if(get2[0] == '0'){
              printf("  %s", get2);
              decB = getDecimal(get2);
              printf("  (%d)\n", decB);
              printf("------------------\n");
              add(get1, get2);
              for (int i = 0; i < 8; i++){
                printf("%c" ,get1[i]);
              }
              printf("  (%d)\n",decA + decB);
              printf("\n");
              return 0;
            }
          }
        }
      }
      else{
        printf("Error: Bit sequence 1 or 2 has non-binary characters\n");
        return 0;
      }
    }
  }
  else{
    printf("Error: You must enter two valid 8-bit string sequences\n");
  }
  return 0;
}
//Creates decimal for binary sequence going through each index
int getDecimal (char str[]){
  int count = 7;
  int second = 0;
  for (int i = 0; i < strlen(str); i++){
    if (str[i] == '1'){
      second += pow(2,count) * 1;
      count--;
    }
    else if (str[i] == '0'){
      second += pow(2,count) * 0;
      count--;
    }
  }
  return second;
}
//Creating algorithim to add in binary
void add (char str[], char str2[]){
  int count = 0;
  for (int i = strlen(str); i > 0; i--){
    if(str[i] == '1' && str2[i] == '1' && count == 0){
      str[i] = '0';
      count++;
    }
    else if(str[i] == '1' && str2[i] == '1' && count >= 1){
      str[i] = '1';
      count++;
    }
    else if(str[i] == '0' && str2[i] == '1' && count >= 1){
      str[i] = '0';
      count++;
    }
    else if(str[i] == '1' && str2[i] == '0' && count >= 1){
      str[i] = '0';
      count++;
    }
    else if(str[i] == '0' && str2[i] == '0' && count >= 1){
      str[i] = '1';
      if (count > 0){
        count=0;
      }
    }
    else if(str[i] == '1' && str2[i] == '1' && count == 0){
      str[i] = '0';
      count++;
    }
    else if(str[i] == '0' && str2[i] == '0' && count == 0){
      str[i] = '0';
      if (count > 0){
        count=0;
      }
    }
    else if(str[i] == '0' && str2[i] == '1' && count == 0){
      str[i] = '1';
      if (count > 0){
        count=0;
      }
    }
    else if(str[i] == '0'){
      str[i] = '0';
    }
    else if(str[i] == '1'){
      str[i] = '1';
    }
  }
}
//Flips binary array when called
void flipper (char str[]){
  char one[] = "1";
  for (int i = 0; i < strlen(str); i++){
    if (str[i] == '1'){
      str[i] = '0';
    }
    else if (str[i] == '0') {
      str[i] = '1';
    }
  }
  add(str, one);   //Adds the 1 after flipped
}
