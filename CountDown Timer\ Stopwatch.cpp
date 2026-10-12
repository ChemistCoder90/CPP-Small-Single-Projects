#include <bits/stdc++.h>
using namespace std;
#define NL printf("\n")

void CountDown(int& hours, int& minutes, int& seconds){
    while(hours>0 || minutes>0 || seconds>0){
    // system("clear"); will not work for cross platform. use '\r', flush as line:18
    if(seconds>0) seconds--;
    else{
      seconds=59;
      minutes--;
      if(minutes==-1){
        minutes=59;
        hours--;
      }
    }

    cout<<'\r'<<setfill('0')<<setw(2)<<hours<<":"<<setw(2)<<minutes<<":"<<setw(2)<<seconds<<flush;
    //flush makes the new printed value visible immediately.
    // '\r' moves the cursor back,
    this_thread::sleep_for(chrono::seconds(1));
  }
}

void CountDownInTimeFormat(const string &time){
  int hours = 0, minutes = 0, seconds = 0;
  char sep1 = '\0', sep2 = '\0';
  istringstream iss(time);
  iss>>hours>>sep1>>minutes>>sep2>>seconds;// reads character & convert to int.
                                           // if found non-digit, stops and store in Hour...
                                           //if found non-digit char store in sep1,sep2
  //check if valid string as wanted
  if(hours<0 || minutes<0 || minutes>59 || seconds<0 || seconds>59 || sep1!=':' || sep2!=':'){
    cout<<"Invalid Format. Please Use HH:MM:SS";
    return;
  }
  seconds++; //why? if(seconds>0) seconds--;(line:8) decrease sec then sleep 1 sec.
  CountDown(hours, minutes, seconds);

  cout<<"\nTime Is UP. Thanks for Using.";

}

void CountDownInSecondFormat(int& seconds){
  int hours=seconds/3600;
  // cout<<hours;NL;
  seconds-=(hours*3600);
  int minutes=seconds/60;
  seconds-=(minutes*60);
  seconds++;
  CountDown(hours, minutes, seconds);
  cout<<"\nTime Is UP. Thanks for Using.";
}

int main() {
  cout<<"--------WelCome--------";NL;
  cout<<"Choose Input Type:";NL;
  cout<<"1. HH:MM:SS(Hour:Minute:Second)";NL;
  cout<<"2. In second(Integer)";NL;
  char Input=getchar();
  switch (Input)
  {
  case '1':{
    cout<<"Please Input timer in HH:MM:SS: ";
    string time;
    cin>>time;
    CountDownInTimeFormat(time);
    break;
  }
  case '2':{
    cout<<"Please Input timer in seconds(integer): ";
    int time;
    cin>>time;
    CountDownInSecondFormat(time);
    break;
  }
  default:
    cout<<"Invalid option. PLease Try again.";NL;
    break;
  }

}
