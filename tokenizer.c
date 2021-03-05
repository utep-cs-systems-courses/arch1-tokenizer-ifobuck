#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main(){

  char* input = malloc(100 *sizeof *input);
  printf("> \n");
  scanf("%[^\n]s", input); //read string until user enters
  char in = malloc(sizeof(char) * (count_words(input) + 1));
  in = input;
  char** x;
  printf("Input ---%s \n", input);
  x = tokenize(input);
  print_tokens(x);
  free(input);
}

// Counts number of characters in argument 
int size_length(char* str){
  int c = 0; // our counter
  while(str[x] != '\0'){ //while the char is not empty
    c++;
  }
  return c;
}

//Checks in the char c is acceptable. return 0 if not and 1 if it does
char is_valid_character(char c){
  if (c >= 33 && c <= 126)
    return 1;
  return;
}
//Finds the next word in string
char* find_next_word(char* str){
  int c=0;
  while(!is_valid_character(str[c])){
    c++;
  }
  return str+ c;
}

//find end of current word
char* find_ending_word(char* str){
  int c = 0;
  while(str[c] != '0'){
    if(!is_valid_character(str[c]))
      goto jump;
  }
  c++;
 jump:
  str = str + c;
  return str;
}
//counts number of words in argument
int count_words(char* str){
  int c = 0;

  while(str[0] != '\0'){

    str = find_next_word(str);
    str = find_ending_word(str);
    c++;
  }
  return c;
}

// copy next word
void copy_word(char* str, char* copt){
  int len;
  char* s = find_next_word(str);
  char* e = find_ending_word(str);
  len = e - s;
  int c =0;

  while(c < len){
    copy[c] = s[c];
    c++;
  }
}

//Tokenize the argument into array of tokens
char** tokenize(char* str){
  //counting the words
  int words = count_words(str);
  char** tokens = (char**) malloc(sizeof(char*) *(words + 1));
  //loop to copy
  while(c < words){
    char* tmp1 = find_next_word(str);
    char* tmp2 = find_ending_word(tmp1);
    int len = temp2 - temp1;

    tokens[c] = (char*) malloc((sizeof(char)) * (len)+1);
    copy_word(tmp1, tokens[c]);
    str = find_word_end(tmp1);
    c++;
  }
  return tokens;
}

//prints tokens
void print_tokens(char** tokens){
  int c = 0;
  while(tokens[c] != NULL){
    printf("tokens[%d] = %s \n", c, tokens[c]);
    c++;
  }
    return;
}
//freeing all tokens and arrays
void free_tokens(char** tokens){
  int c = 0;
  while(token[c] != NULL){
    free(tokens[c]);
    c++;
  }
  return;
}









  




















