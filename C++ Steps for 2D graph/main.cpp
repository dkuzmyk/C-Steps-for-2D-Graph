#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int coverPoints(vector<int> &A, vector<int> &B) {
    int steps = 0;
    int deltaX;
    int deltaY;
    int deltaXY;
    int distance;

    for(int i = 1; i < A.size(); i++){
        deltaX = 0;
        deltaY = 0;
        deltaXY = 0;
        distance = 0;

        if(A[i-1] != A[i]){
            deltaX = abs(A[i-1] - A[i]);
            //cout << "delta x " << deltaX << endl;
        }
        if(B[i-1] != B[i]){
            deltaY = abs(B[i-1] - B[i]);
            //cout << "delta y " << deltaY << endl;
        }
        cout << "from " << A[i-1] << "," << B[i-1] << " to " << A[i] << "," << B[i] << endl; 
        if(B[i-1] == B[i] && A[i-1] == A[i]){
            continue;
        }

        if(deltaX > 0 && deltaY > 0 ){
            distance = min(deltaX, deltaY);
            steps += distance;
            cout << "distance together " << distance << endl;
            
            deltaXY = abs(deltaX - deltaY);
            steps += deltaXY;
            cout << "distance alone " << deltaXY << endl;
            continue;
        }
        else if (deltaX > 0 && deltaY == 0){
            steps += deltaX;
        }
        else{
            steps += deltaY;
        }
    }
    return steps;

}

int main(){
    vector<int> one = {4, 8, -7, -5, -13, 9, -7, 8};
    vector<int> two = {4, -15, -10, -3, -13, 12, 8, -8};
    int result = coverPoints(one, two);
    
    cout << result;
    
    return 0;
}
