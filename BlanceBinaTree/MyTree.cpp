//
//  MyTree.cpp
//  BlanceBinaTree
//
//  Created by dutingfu on 2018/3/11.
//  Copyright © 2018年 dutingfu. All rights reserved.
//

#include "MyTree.hpp"
#include <math.h>
template <class T>
bool BTree<T>::Insert(NODE<T>* &n, T t)
{
    if (n == NULL) {
        n = new NODE<T>(t);
    }else if (t < n->data) {
        bool inseret  = Insert(n->lf, t);
        if (inseret) {
            int lheight = getHeiht(n->lf);
            int rheight = getHeiht(n->rf);
            if (lheight - rheight > 1) {
                // 右旋
               NODE<T> * l = n->lf;
              
                if ( getHeiht(l->lf) > getHeiht(l->rf)) {
                    RR(n);
                }else
                {
                    LR(n);
                    
                }
                // 左右旋
            }
        }else
        {
            
            return false;
        }
        
        return true;
    }else if (t > n->data)
    {
        bool inseret  = Insert(n->rf, t);
        if (inseret) {
            int lheight = getHeiht(n->lf);
            int rheight = getHeiht(n->rf);
            if (rheight - lheight > 1) {
                NODE<T> * rf = n->rf;
                if (getHeiht(rf->lf) > getHeiht(rf->lf)) {
                    RL(n);
                }else
                {
                    LL(n);
                }

            }
        }else
        {
            return false;
        }
        
        return true;
    }else
    {
        return false;
    }
    n->height = max(getHeiht(n->lf),getHeiht(n->rf)) +1;
    
    
    return true;
}


template <class T>
bool BTree<T>::Delete(NODE<T> *t,T& x)
{
    if (t->data == x) {
        // 查到
        if (t->lf == NULL) {
            // 直接连接右子树
        }else
        {
            // 取左子树最大值
            NODE<T> * tem = t->lf;
            NODE<T> * pre = NULL;
            while (tem != NULL) {
                pre = tem;
                tem = tem->rf;
            }
            if (pre != NULL) {
                t->data = pre->data;
                Delete(t->lf, pre->data);

            }
        }
        
        return true;
    }
    if (t == NULL) {
        //未查到
        return false;
    }
    if (t->data < x) {
     bool ret  =  Delete(t->lf, x);
        // 判断是否是平衡状态
        if (ret == true) {
            if (getHeiht(t->lf) - getHeiht(t->rf) < -1) {
                if (getHeiht(t->rf->lf)< getHeiht(t->rf->rf)) {
                    LL(t);
                }else
                {
                    RL(t);
                }
                
            }
            t->height = max(getHeiht(t->lf),getHeiht(t->rf))+1;
            return true;

        }else
        {
            return false;
        }
    }else
    {
      bool ret   =  Delete(t->rf, x);
        
        if (ret == true) {
            
            if (getHeiht(t->lf)- getHeiht(t->rf)>1) {
                if (getHeiht((t->lf)->lf) > getHeiht((t->lf)->rf)) {
                    RR(t);
                }else
                {
                    LR(t);
                }
            }
             t->height = max(getHeiht(t->lf),getHeiht(t->rf))+1;
            return true;
        }else
        {
            return false;
        }
        // 判断是否是平衡状态

    }
    
    return false;
}
template <class T>

int BTree<T>::getHeiht(NODE<T>* t)
{
    if (t == NULL) {
        return 0;
    }else
    {
        return t->height;
    }
    
}
template <class T>
bool BTree<T>::RR(NODE<T> *t)
{
    NODE<T> * lc = t->lf;
    lc->rf  = t;
    t->lf = lc->rf;
    t = lc;
    t->height = max(getHeiht(t->lf),getHeiht(t->rf));
    return true;
}
template <class T>
bool BTree<T>::LL(NODE<T> *t)
{
    NODE<T> * rf = t->rf;
    t->rf = rf->lf;
    rf->lf = t;
    t = rf;
    t->height = max(getHeiht(t->lf),getHeiht(t->rf));
    return true;
}
template <class T>
bool BTree<T>::LR(NODE<T> *t)
{
    NODE<T> * lc = t->lf;
    LL(lc);
    RR(t);
    return true;
}
template <class T>
bool BTree<T>::RL(NODE<T> *t)
{
    NODE<T> * rf = t->rf;
    RR(rf);
    LL(t);
    return true;
}
