
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unistd.h>
#include <stdio.h>
#include <iomanip>
using namespace std;

char aha ='X';
const char* laughingEmoji= "\U0001F600";
int randRage (int low, int high)
{
    return rand() % (high-low)+ low;
}

void printArray (char arr[24])
{
    for(int i=0; i<=24; i++)
    {
        if (arr[i]!='X'&& arr[i]!='O' && arr[i]!='Y')
        {
            cout <<" ";
        }
        if(i%5==0)
        {
            cout <<" ";
            cout <<endl;
            cout <<"+------------------+"<<endl;
            cout <<"|";
            if(arr[i]!='X'&& arr[i]!='O'&& arr[i]!='Y')
            {
                cout <<" ";
            }
        }
        if(arr[i] == ' ')
        {
            cout <<arr[i];
        }
        else cout <<arr[i]<< " ";
        cout <<"|"<<" ";
    }

    cout <<endl;
    cout <<"+------------------+";
    cout <<endl;
}


int main()
{
    int indicator=0, leftMoves=21;
    int maxScore=0;
    char move;
    string confirm;
    int score=0;
    char arr[24];
    for(int i = 0; i < 24; i++)
    {
        arr[i] = ' ';
    }
    srand (time(NULL));
    int galinis=0;
    for(int i=0; i<25; i++)
    {
        int naujas =randRage(1, 24);
        galinis =randRage(20,24);
        if(naujas%3==0||naujas%4==0)
        {
            arr[i]='O';
            maxScore++;
        }
    }
    arr[indicator]=aha;
    arr[galinis]='Y';
cout <<"----------------------------------------------------------------------------------------------"<<endl;
cout<<"game explanation:"<<endl;
cout <<"----------------------------------------------------------------------------------------------"<<endl;
    cout <<"Your goal is from X to Y score as many points as you can without redoing the same move"<<endl;
    cout <<"You can move with keys -A- (left) -W- (up) -S- (down) -D- (right)"<<endl;
    cout <<"Type 'yes' if it's clear and you wish to start"<<laughingEmoji<<" :";
    cin >>confirm;
    if (confirm=="yes")
    {

        cout << "Okey...Starting up";
        for(int i=0; i<6; i++)
        {
            cout << "." <<flush;
            sleep(1);
            i++;
        }
        printArray(arr);
        cout <<endl;
        for(int i=0; i<22; i++)
        {
            cin >>move;
            if(move=='D')
            {
                indicator++;
                if(arr[indicator]=='O')
                {
                    score++;
                }
                if(arr[indicator]=='Y')
                {
                    cout <<"-------------------------------------------------"<<endl;
                    cout <<"You succeeded! Final score is: "<<setprecision(2)<<((float)score/maxScore)*100<<"%"<<endl;
                    cout <<"-------------------------------------------------"<<endl;
                    break;
                }
                if(indicator%5==0)
                {
                    indicator--;
                    leftMoves--;
                    cout <<"---------------"<<endl;
                    cout <<"negali eit ten"<<endl;
                    cout <<"left moves: "<<leftMoves<<endl;
                    cout <<"---------------"<<endl;
                    printArray(arr);
                }
                if(arr[indicator]==aha)
                {
                    cout <<"-------------------------------------------------"<<endl;
                    cout <<"GAME OVER"<<endl;
                    cout <<"-------------------------------------------------"<<endl;
                    break;
                }
                else
                {
                    arr[indicator]=aha;
                    printArray(arr);
                    leftMoves--;
                }
            }


            else if (move =='A')
            {
                indicator--;
                if(arr[indicator]==aha|| indicator<0)
                {
                    cout <<"-------------------------------------------------"<<endl;
                    cout <<"GAME OVER"<<endl;
                    cout <<"-------------------------------------------------"<<endl;
                    break;
                }
                if(arr[indicator]=='O')
                {
                    score++;
                }
                if(indicator==4 || indicator==9||indicator==14||indicator==19||indicator==24)
                {
                    leftMoves--;
                    cout <<"---------------"<<endl;
                    cout <<"negali eit ten"<<endl;
                    cout <<"left moves: "<<leftMoves<<endl;
                    cout <<"---------------"<<endl;
                    printArray(arr);
                }
                if(arr[indicator]=='Y')
                {
                    cout <<"-------------------------------------------------"<<endl;
                    cout <<"You succeeded! Final score is: "<<setprecision(2)<<((float)score/maxScore)*100<<"%"<<endl;
                    cout <<"-------------------------------------------------"<<endl;

                    break;
                }
                arr[indicator]=aha;
                printArray(arr);
                leftMoves--;

            }
            else if(move =='W')
            {
                if(indicator<5)
                {
                    cout <<"-------------------------------------------------"<<endl;
                    cout <<"GAME OVER"<<endl;
                    cout <<"-------------------------------------------------"<<endl;
                    break;
                }
                else indicator =indicator-5;
                if(arr[indicator]=='O')
                {
                    score++;
                }
                if(arr[indicator]=='Y')
                {
                    cout <<"-------------------------"<<endl;
                    cout <<"You succeeded! Final score is: "<<setprecision(2)<<((float)score/maxScore)*100<<"%"<<endl;
                    cout <<"-------------------------------------------------"<<endl;

                    break;
                }
                arr[indicator]=aha;
                printArray(arr);
                leftMoves--;

            }
            else if (move =='S')
            {
                if (indicator>19)
                {
                    cout <<"-------------------------------------------------"<<endl;
                    cout <<"GAME OVER"<<endl;
                    cout <<"-------------------------------------------------"<<endl;
                    break;
                }

                else indicator=indicator+5;
                if(arr[indicator]=='O')
                {
                    score++;
                }
                if(arr[indicator]=='Y')
                {
                    cout <<"-------------------------------------------------"<<endl;

                    cout <<"You succeeded! Final score is: "<<setprecision(2)<<((float)score/maxScore)*100<<"%"<<endl;
                    cout <<"-------------------------------------------------"<<endl;

                    break;
                }
                arr[indicator]=aha;
                printArray(arr);
                leftMoves--;

            }
            else if (move!='S'&& move!='A'&&move!='W'&&move!='D')
            {
                cout <<"----------------------------------"<<endl;
                cout <<"you can't play with those keys, try again:)"<<endl;
                leftMoves--;
                cout <<"left moves: "<<leftMoves<<endl;
                cout <<"----------------------------------"<<endl;

            }
        }

    }

    else cout <<"Okey then, don't play:/"<<endl;
    return 0;
}


