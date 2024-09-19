#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

char front[3][3] = {{'1', '2', '3'},
                  {'4', '5', '6'},
                  {'7', '8', '9'}};


void printFront();
void start();
int checkwin();
void whilegame();
void control();
int isFull(int m);
int againgame();


int main() {
    start();
    return 0;
}

void start(){
    printFront();
    whilegame();
}

void whilegame(){
 
    int x, y;
    int count =0;

    while (true) {  
        int n = 0;  
        int k=0;
        while(k==0){
            cout << "Player 1: ";
            cin >> x;
            n=0;
            for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
               n++;
               if(n==x){
                    if(front[i][j] =='X' || front[i][j]=='O'){
                        printf("Enter a valid dimension!\n");
                        
                    }
                    else{
                        k++;
                    }
               }
                
            }
            }
        }
        
         n=0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                n++;
                if (n==x) {  
                       front[i][j] = 'X';
                        count++;
                       
                    } 
                }

            }
         
        printFront();
        if (isFull(count) || checkwin()) return;
        int r = 0;
        int m = 0;
       while(r==0){
            cout << "Player 2: ";
            cin >> y;
            m=0;
            for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m++;
                if(m==y){
                    if(front[i][j]=='X' || front[i][j]=='O'){
                        printf("Enter a valid dimension!\n");
                    }
                    else{
                        r++;
                    }
                        
                }
                }
                
            }
            }
        

       m=0;
        for (int i = 0; i < 3 ; i++) {
            for (int j = 0; j < 3; j++) {
                m++;
                if (m==y) {  
                         front[i][j] = 'O';
                        count++;
                        
                    } 
                }
            }
        printFront();
        if (isFull(count) || checkwin()) return;
         
    }
}
    


void printFront(){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << front[i][j] << " | ";
        }
        cout << endl;
        if (i < 2) cout << "----------" << endl;  
    }
}

int isFull(int m){
    if(m==9){
       cout<<"Game over! It is a tie!";
        againgame();
    }
    return 0;
}

int againgame(){
    int s;
       cout<<"Would you like to play again? If so enter 1 otherwise enter 2"<<endl;
       cin>>s;
       if(s==1){
        int w=0;
            for (int i = 0; i < 3 ; i++) {
            for (int j = 0; j < 3; j++) {
                w++;
                if(front[i][j]=='O' || front[i][j]=='X'){
                    front[i][j] = w+'0';
                }
            }
            }
        start();
       }
       else{
        printf("Game Over");
        exit(0);
       }
}

int checkwin(){
    
    for (int i = 0; i < 3; i++) {
        if (front[i][0] == front[i][1] && front[i][0] == front[i][2]) {
            if (front[i][0] == 'X') {
                cout << "Player 1 won!" << endl;
                againgame();
            } else if (front[i][0] == 'O') {
                cout << "Player 2 won!" << endl;
                againgame();
            }
        }
        if (front[0][i] == front[1][i] && front[0][i] == front[2][i]) {
            if (front[0][i] == 'X') {
                cout << "Player 1 won!" << endl;
                againgame();
            } else if (front[0][i] == 'O') {
                cout << "Player 2 won!" << endl;
                againgame();
            }
        }
    }
    
    if ((front[0][0] == front[1][1] && front[0][0] == front[2][2]) ||
        (front[2][0] == front[1][1] && front[2][0] == front[0][2])) {
        if (front[1][1] == 'X') {
            cout << "Player 1 won!" << endl;
            againgame();
        } else if (front[1][1] == 'O') {
            cout << "Player 2 won!" << endl;
            againgame();
        }
    }
    return 0;
}