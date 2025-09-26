#include<iostream>
using namespace std;

void guess(int target, int player){
    int n;
    cout<<"Player "<<player<<" Enter your guess (1-100): ";
    cin>> n;
    if (n == target){
        cout<<"You have guessed the correct number. Hence player "<<player<<" has won the Game"<<endl;
        return;
    }
    else if(n<target){
        cout<<"your guess is less than the target number"<<endl;
    }
    else if(n>target){
        cout<<"your guess is greater than the target number"<<endl;
    }
    int nextplayer;
    if (player == 1) {
        nextplayer = 2;
    }
    else {
        nextplayer = 1;
    }
    guess(target,nextplayer);

}

int main(){
    srand(time(0));
    int targetnumber = rand()%100 + 1;
    cout<<"\nThis is A Guessing Game. 2 PLAYERS WILL PLAY THIS GAME"<<endl;
    guess(targetnumber, 1);

}