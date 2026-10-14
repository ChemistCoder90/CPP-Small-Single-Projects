#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
#define NL printf("\n")

// Text Color functions
//Idea from Tahsin coder(Utube)
void Red()          { cout << "\033[38;2;255;0;0m"; }
void Yellow()       { cout << "\033[38;2;255;255;0m"; }
void Blue()          { cout << "\033[38;2;0;0;255m"; }
void Green()         { cout << "\033[38;2;0;255;0m"; }
void Purple()        { cout << "\033[38;2;128;0;128m"; }
void White()         { cout << "\033[38;2;255;255;255m"; }
void Cyan()          { cout << "\033[38;2;0;255;255m"; }
void ResetTextColor(){ cout << "\033[0m"; }

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
      string fileName;
      cout<<"Please enter the file name for the Questions: ";
      cin>>fileName;
      fstream files(fileName);
      if(!files.is_open()){
        Red();
        cout<<"Unable to read questions from Your given file. Question will be provided from Default QuizApp.txt.";NL;NL;
        files.clear();
        files.open("QuizApp.txt");
      }
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
        Red();
        cout<<"\nFaild to open  File. Please try again. Thanks.\n";
        ResetTextColor();
        files.close();
        exit(EXIT_FAILURE); // if failed to open file, program will terminate immediately. #include <cstdlib> required.
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
      cout<<"-----------------------------------------------------";NL;
      Purple();
      cout<<"Your Total Score is: "<<score<<" Out of "<<QusList.size();NL;
      cout<<"Thanks for Joining to the Quiz Test. Have a nice day.";NL;
      ResetTextColor();
      cout<<"-----------------------------------------------------";NL;
    }    
};


int main() {
  QuizApp quiz;
  quiz.ShowQuestions();
  quiz.PrintScore();
}
