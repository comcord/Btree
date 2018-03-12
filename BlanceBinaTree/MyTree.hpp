//
//  MyTree.hpp
//  BlanceBinaTree
//
//  Created by dutingfu on 2018/3/11.
//  Copyright © 2018年 dutingfu. All rights reserved.
//

#ifndef MyTree_hpp
#define MyTree_hpp

#include <stdio.h>
#include <iostream>
template <class T>
struct NODE {
    T data;
    int height;
    NODE<T> * lf;
    NODE<T> * rf;
    NODE(const T a):data(a),lf(NULL),rf(NULL),height(0){
    }
};
template <class T>
class BTree {
    
    
public:
    NODE<T> * root;
    BTree(){
        this->root = NULL;
    }
    bool Insert(NODE<T>* &t, T x);
    bool Delete(NODE<T> * t,T & x);
    void vist(NODE<T>* &t)
    {
        if (t == NULL) {
            return;
        }
        vist(t->lf);
        
        std::cout<<t->data<<" "<<std::endl;
        vist(t->rf);
    }
    
private:
    
    int getHeiht(NODE<T>* t);
    bool LL(NODE<T>* t);
    bool LR(NODE<T>* t);
    bool RR(NODE<T>* t);
    bool RL(NODE<T>* t);
    
};
#endif /* MyTree_hpp */
