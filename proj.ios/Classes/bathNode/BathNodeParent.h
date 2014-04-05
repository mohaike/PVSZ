//
//  BathNodeParent.h
//  PlantAndZombie_3
//
//  Created by 雨亭梧桐雪 on 14-4-5.
//
//

#ifndef __PlantAndZombie_3__BathNodeParent__
#define __PlantAndZombie_3__BathNodeParent__

#include <iostream>

#include "cocos2d.h"
//#include ""

using namespace cocos2d;

class BathNodeParent:public CCSpriteBatchNode, public CCTouchDelegate{
private:
    bool lock;
public:
    static BathNodeParent * createWithFile(const char * fileImage);
    virtual bool initWithFile(const char * fileImage);
    virtual bool ccTouchBegan(CCTouch * pTouch, CCEvent * pEvent);
    virtual void ccTouchMoved(CCTouch * pTouch, CCEvent * pEvent);
};

#endif /* defined(__PlantAndZombie_3__BathNodeParent__) */
