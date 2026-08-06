#include <bits/stdc++.h>
using namespace std;
#define NL printf("\n")



int main() {
  srand(time(0));  // set the global variable inside program.
                  //rand() reads and change that everytime we call
                  //time(0) returns the time in sec since 1970
  string const s="0123456789";
  int noDigit=6;
  string OTP;
  while(noDigit--){
    int indexNo=rand()%10;
      OTP+=s[indexNo];
  }
  cout<<OTP;NL;
}

