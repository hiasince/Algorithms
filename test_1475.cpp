//
//  main.cpp
//  algorithm_test
//
//  Created by 한병익 on 2016. 12. 27..
//  Copyright © 2016년 한병익. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
    string roomnum;
    float num[9] = {0};
    
    cin >> roomnum;
    
    for( int i = 0 ; i < roomnum.length() ; i++) {
        if (roomnum[i] == '0')
            num[0]++;
        else if (roomnum[i] == '1')
            num[1]++;
        else if (roomnum[i] == '2')
            num[2]++;
        else if (roomnum[i] == '3')
            num[3]++;
        else if (roomnum[i] == '4')
            num[4]++;
        else if (roomnum[i] == '5')
            num[5]++;
        else if (roomnum[i] == '6')
            num[6]++;
        else if (roomnum[i] == '7')
            num[7]++;
        else if (roomnum[i] == '8')
            num[8]++;
        else if (roomnum[i] == '9')
            num[6]++;
    }
    
    num[6] = roundf(num[6]/2);

    int max = 0;
    
    for(int i = 0 ; i < 9 ; i++) {
        if(num[i] > max)
            max = num[i];
    }
    
    cout << max << endl;
    
    return 0;
}
