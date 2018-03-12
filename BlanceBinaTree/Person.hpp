//
//  Person.hpp
//  BlanceBinaTree
//
//  Created by dutingfu on 2018/3/11.
//  Copyright © 2018年 dutingfu. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp
#include<iostream>
#include <stdio.h>
struct Stu{
    int num;
    Stu():num(0){
        
    }
    bool operator <(Stu & s){
        if(num <  s.num)
        {
            return true;
        }else
        {
            return false;
        }
    }
    bool operator >(Stu &s ){
        if(num > s.num)
        {
            return true;
        }else
        {
            return false;
        }
    }
    
//    std::ostream & operator<<(std::ostream &out, Stu &obj)
//     {
//         std::cout << this->num<<std::endl;
//        return out;
//    }
    
};
#endif /* Person_hpp */
