//
//  test_2839.cpp
//  algorithm_test
//
//  Created by 한병익 on 2016. 12. 28..
//  Copyright © 2016년 한병익. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int suger;
    float fkg = 0;
    float tkg = 0;
    
    cin >> suger;
    
    for(int i = 0 ; i < suger/5+1 ; i++) {
        if((suger-5*(i))%3==0) {
            fkg = i;
            tkg = (suger-5*i)/3;
        }
    }
    
    if (suger - tkg*3 - fkg*5 != 0)
        cout << -1 << endl;
    else
        cout << fkg + tkg << endl;
}
