#include <bits/stdc++.h>
#include <chrono>
#include <thread>
using namespace std;
#define NL printf("\n")

int main() {
  while (true) {
    system("clear");
    auto tNow = chrono::system_clock::now();
    time_t now = chrono::system_clock::to_time_t(tNow);//convert into human readable number in second since 1970
    tm* localTime = localtime(&now); //break-down the times into years, month, days... sec. can access

    cout << put_time(localTime, "%d-%b-%y  %OI:%M:%S %p") <<'\r'<< flush;NL;
    cout << put_time(localTime, "%r") <<'\r'<< flush;NL;
    cout << '\r'<< localTime->tm_hour << ':'<< localTime->tm_min << ':'  << localTime->tm_sec<<flush;
    this_thread::sleep_for(chrono::seconds(1));
  }
}
