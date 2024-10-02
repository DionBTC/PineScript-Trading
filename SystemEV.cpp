#include <iostream>
using namespace std;

class systemEV{
    float winrate, lossrate, totalR, avgR, EV;
    int trades;
    public:
    void findEV(){
        cout<<"Enter the number of trades taken (Please ensure that it is in integer format)\n";
        cin>>trades;
        cout<<"Enter the winrate percentage of the system\n";
        cin>>winrate;
        cout<<"Enter the total Risk/Reward of the system for the "<<trades<<"trades\n";
        cin>>totalR;
        
        //calculation
        lossrate=100-winrate;
        avgR=(totalR+lossrate)/trades;
        EV=((winrate*avgR)-lossrate)/100;
        
        cout<<"The Expected Value of this system is "<<EV<<endl;
    }
    void writeEV(){
        
    }
    void viewEV(){
        
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
    }while(counter!=4)
    return 0;
}

