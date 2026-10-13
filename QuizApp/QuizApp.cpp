#include <bits/stdc++.h>
#include <iostream>
#include<fstream>
using namespace std;
#define NL printf("\n")

// Text Color functions
//copied from Tahsin coder(Utube)
void Red ()          {   cout<<"\033[1;31m";   }
void Yellow()        {   cout<<"\033[1;33m";   }
void Blue()          {   cout<<"\033[0;34m";   }
void Green()         {   cout<<"\033[0;32m";   }
void Purple()        {   cout<<"\033[0;35m";   }
void White()         {   cout<<"\033[0;37m";   }
void Cyan()          {   cout<<"\033[0;36m";   }
void ResetTextColor(){   cout<<"\033[0m";      }

struct QuestionFormat{
  string Qustion;
  string OptionA;
  string OptionB;
  string OptionC;
  string OptionD;
  string CorrectAns;
};

class QuizApp{
  public:
    int score;
    vector<QuestionFormat>QusList;
    QuizApp(){
      score=0;
      LoadFile();
    }
    void LoadFile(){
      fstream files("QuizApp.txt");
      QuestionFormat Question;
      if(files.is_open()){
        while(getline(files, Question.Qustion)){
          getline(files, Question.OptionA);
          getline(files, Question.OptionB);
          getline(files, Question.OptionC);
          getline(files, Question.OptionD);
          getline(files, Question.CorrectAns);
          QusList.push_back(Question);
        }
      }
      else{
        cout<<"\nFaild to open  File. Please try again. Thanks.\n";
      }
      files.close();
    }
    int QusNo=0;
    void ShowQuestions(){
      for(auto& u:QusList){
        QusNo++;
        char ans;
        Blue();
        cout<<"Qus "<<QusNo<<": "<<u.Qustion;NL;
        Cyan();
        cout<<" A : "<<u.OptionA;NL;
        cout<<" B : "<<u.OptionB;NL;
        cout<<" C : "<<u.OptionC;NL;
        cout<<" D : "<<u.OptionD;NL;NL;
        Green();
        cout<<"Please Enter Your answer(A,B,C,D) : ";
        cin>>ans;
        Green();
        CheckAnswer(ans, u);
        ResetTextColor();
      }
    }
    void CheckAnswer(char ans, QuestionFormat& qus){
      if((ans=='A' || ans=='a') && qus.CorrectAns==qus.OptionA){
          cout<<"Correct Answer.";NL;NL;
          score++;
        }
        else if((ans=='B' || ans=='b') && qus.CorrectAns==qus.OptionB){
          cout<<"Correct Answer.";NL;NL;
          score++;
        }
        else if((ans=='C' || ans=='c') && qus.CorrectAns==qus.OptionC){
          cout<<"Correct Answer.";NL;NL;
          score++;
        }
        else if((ans=='D' || ans=='d') && qus.CorrectAns==qus.OptionD){
          cout<<"Correct Answer.";NL;NL;
          score++;
        }
        else{
          ResetTextColor();
          Red();
          cout<<"Wrong Answer.!!!";NL;
          Green();
          cout<<"Correct answer is: "<<qus.CorrectAns;NL;NL;
        }
    }
    void PrintScore(){
      Purple();
      cout<<"Your Total Score is: "<<score<<" Out of "<<QusList.size();NL;
      cout<<"Thanks for Joining to the Quiz Test. Have a nice day.";
      ResetTextColor();
    }    
};


int main() {
  QuizApp quiz;
  quiz.ShowQuestions();
  quiz.PrintScore();
}
