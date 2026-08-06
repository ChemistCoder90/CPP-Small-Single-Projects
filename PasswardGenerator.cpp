#include <bits/stdc++.h>
using namespace std;
#define NL printf("\n")

string passwordGenerator(){
    srand(time(0));  // set the global variable(actually an internal state) inside program.
                  //rand() reads and change that everytime we call
                  //time(0) returns the time in sec since 1970
  string const Alphabet="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string const Digit="0123456789";
  string const Symble="!@#$%&*?";
  string password;
  int size = 10;
  while(size--){
    int ChooseArray=rand()%3;
    if(ChooseArray==0){
      int index=rand()%52;
      password+=Alphabet[index];
    }
    else if(ChooseArray==1){
      int index=rand()%10;
      password+=Digit[index];
    }
    else{
      int index=rand()%8;
      password+=Symble[index];
    }
  }
  return password;
  
}

int main() {
  cout<<passwordGenerator();NL;
}

