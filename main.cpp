#include <iostream>
using namespace std;
#include "class.h";


void person::print(void){
    cout<<"Ali boran buraya yazdı"<<endl;
   
    cout << "deneme234";
}

int main(void){
    int height,width;
    char map[30][30];
    for (size_t i = 0; i < height; i++){
        for (size_t j = 0; j < width; j++){
            if(i==2 && (j%4==0 && j != 0 && j!=20 ) || i==6 && (j%4==0 && j != 0 && j!=20)|| i==10 && (j%4==0 && j != 0 && j!=20)|| i==14 && (j%4==0 && j != 0 && j!=20) || i==18 && (j%4==0 && j != 0 && j!=20)){
                map[i][j] = '|';
            }
            else if(j==2 && (i%4==0 && i != 0 && i!=20 ) || j==6 && (i%4==0 && i != 0 && i!=20)|| j==10 && (i%4==0 && i != 0 && i!=20)|| j==14 && (i%4==0 && i != 0 && i!=20) || j==18 && (i%4==0 && i != 0 && i!=20)){
                map[i][j] = '-';
            }
            else if( i%4 == 0 || j%4 == 0){
                map[i][j] = '#';
            }
            else{
                 map[i][j] = '.';
            }
        }    
    }
    for (size_t i = 0; i < height; i++){
        for (size_t j = 0; j < width; j++){
          cout << map[i][j] << " ";
        }
        cout << endl;   
    }
    //commiy

}
