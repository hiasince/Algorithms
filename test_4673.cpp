//
//  4673_test.cpp
//  algorithm_test
//
//  Created by 한병익 on 2016. 12. 28..
//  Copyright © 2016년 한병익. All rights reserved.
//

#include <iostream>
using namespace std;

int selffunc(int num);

int main() {
    int arr[10035];
    for(int i = 0 ; i < 10035 ; i++) {
        arr[i] = i+1;
    }
    
    for( int num = 1 ; num <= 10000 ; num++) {
        arr[selffunc(num)-1] = 0;
    }
    
    for ( int i = 0 ; i < 10000 ; i++) {
        if(arr[i] != 0)
            cout << arr[i] << endl;
    }
    
    return 0;
}

int selffunc(int num) {
    return num + num%10 + (num%100)/10 + (num%1000)/100 + num/1000;
}
