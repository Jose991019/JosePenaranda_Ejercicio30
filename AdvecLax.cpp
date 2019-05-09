#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#define _USE_MATH_DEFINES
using namespace std;
const float m = 100;
const float beta = 0.8;
const float c = 0.8;
const float dx = 1.0/m;
const float dt = beta*dx/c;
const float Tf = 2;
const int n = Tf/dt;

int main(){
    ofstream outfile;
    outfile.open("datos.txt");
    float xi[101][3] = {0};
    for(int i = 0; i < 101; i ++){
        xi[i][0] = 0.05*sin(4*M_PI*i/100);
    }
    for(int i = 0; i < 101; i ++){
        outfile<< xi[i][0] <<" ";
    }
    outfile<<endl;
    for(int i = 1; i < 100; i++){
        xi[i][1] = xi[i][0] - (beta/4)*((xi[i+1][0])*(xi[i+1][0]) - (xi[i-1][0])*(xi[i-1][0])) + (beta*beta/8)*( (xi[i+1][0]+xi[i][0])*(xi[i+1][0]*xi[i+1][0] - xi[i][0]*xi[i][0]) - (xi[i][0]+xi[i-1][0])*(xi[i][0]*xi[i][0] - xi[i-1][0]*xi[i-1][0]) );
    }
    for(int i = 0; i < 101; i ++){
        outfile<< xi[i][1] <<" ";
    }
    outfile<<endl;
    for(int i = 0; i < 199; i ++){
        for(int j = 1;j<100;j++){
            xi[j][2] = xi[j][1] - (beta/4)*((xi[j+1][1])*(xi[j+1][1]) - (xi[j-1][0])*(xi[j-1][1])) + (beta*beta/8)*( (xi[j+1][1]+xi[j][1])*(xi[j+1][1]*xi[j+1][1] - xi[j][1]*xi[j][1]) - (xi[j][1]+xi[j-1][1])*(xi[j][1]*xi[j][1] - xi[j-1][1]*xi[j-1][1]) );
        }
        for(int k = 0; k < 101; k ++){
                outfile<< xi[k][2] <<" ";
            }
        outfile<<endl;
        for(int j = 0;j<101;j++){
            xi[j][0]=xi[j][1];
            xi[j][1]=xi[j][2];
        }
    }
    
    outfile.close();
    
    return 0;
}