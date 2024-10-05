#include <iostream>
#include<fstream>
#include <string>
using namespace std;

class systemEV{
    float winrate, lossrate, totalR, avgR, EV;
    int trades, counter=1;
    public:
    void findEV(){
        cout<<"Enter the number of trades taken (Please ensure that it is in integer format)\n";
        cin>>trades;
        cout<<"Enter the winrate percentage of the system\n";
        cin>>winrate;
        cout<<"Enter the total Risk/Reward of the system for the "<<trades<<" trades\n";
        cin>>totalR;

        //calculation
        lossrate=100-winrate;
        avgR=(totalR+lossrate)/trades;
        EV=((winrate*avgR)-lossrate)/100;

        cout<<"The Expected Value of this system is "<<EV<<endl;
    }
    void writeEV(){
        cout<<"Please enter the EV of the system \n";
        cin>>EV;
        ofstream MyFile("EV_Log.txt");
        MyFile <<"System Log "<<counter<<": EV = "<<EV<<endl;
        MyFile.close();
        counter++;
    }
    void viewEV(){
        string text;
        ifstream MyReadFile("EV_Log.txt");
        while (getline (MyReadFile, text)) {
            cout << text;
        }
        MyReadFile.close();
    }
};

int main() {
    systemEV a;
    int counter=0;
    do{
        cout<<"******MENU******\n";
        cout<<"Select 1 for finding the EV of your system\n";
        cout<<"Select 2 for storing the EV for a system into a file\n";
        cout<<"Select 3 to view all previous EVs\n";
        cout<<"Select 4 to Exit\n";
        cin>>counter;
        if(counter==1)
        a.findEV();
        else if(counter==2)
        a.writeEV();
        else if(counter==3)
        a.viewEV();
        else if(counter==4)
        cout<<"Thank you for using the program\n";
        else
        cout<<"Please enter valid input\n";
    }while(counter!=4);
    return 0;
}


