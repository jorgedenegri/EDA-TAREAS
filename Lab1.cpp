#include <iostream>
#include<stdlib.h>
#include<time.h>
#include <random>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;

void curse(int n) {
    ofstream outputFile("datos.txt");
    outputFile.is_open();
    

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1.0);

    float** p;
    p = new float* [100];
    for (int i = 0; i < 100; i++) {
        p[i] = new float[n];
        for (int j = 0; j < n; j++) {
            p[i][j] = dis(gen);
        }
    }

    float stor = 0;
    float dist = 0;
    for (int i = 0; i < 100; i++) {
        for (int k = i + 1; k < 99; k++) {
            for (int j = 0; j < n; j++) {
                dist += pow(p[k+1][j] - p[i][j], 2);
            }
            stor = sqrt(dist);
            outputFile << stor << endl;
            dist = 0;


        }
    }

}
int main() {
    curse(10);
}