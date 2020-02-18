//
//  main.cpp
//  PinPi
//
//  Created by Einstein Zheng on 2/11/20.
//  Copyright © 2020 Mocoder Inc. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <random>
using namespace std;

struct pos {
    double x;
    double y;
    pos(double xv,double yv) {
        x=xv;
        y=yv;
    }
    pos() {
        x=0;
        y=0;
    }
};

inline pos generatePosition()
{
    random_device rd("/dev/random");
    return pos((double)rd()/(double)(unsigned int)4294967295,(double)rd()/(double)(unsigned int)4294967295);
}

inline bool isInCircle(pos point)
{
    return ((point.x*point.x+point.y*point.y)<=1)?true:false;
}

inline bool pipe()
{
    return isInCircle(generatePosition());
}

int main(int argc, const char * argv[]) {
    long all=0,in=0;
    for(;all<3000000;++all)
    {
        if(pipe())
            ++in;
    }
    cout<<setprecision(10)<<4.0*(double)in/(double)all<<endl;
    return 0;
}
