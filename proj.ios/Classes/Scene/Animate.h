//
//  Animate.h
//  PlantAndZombie_3
//
//  Created by 雨亭梧桐雪 on 14-4-5.
//
//

#ifndef __PlantAndZombie_3__Animate__
#define __PlantAndZombie_3__Animate__

#include <iostream>

#include "cocos2d.h"
using namespace cocos2d;

class Animate:public CCLayer{
public:
    static CCScene * scene();
    virtual bool init();
    CREATE_FUNC(Animate);
    
    void mapAnimate();//刚刚进来的时候的动画
private:
    CCSprite * map;//创建一个地图精灵
};

#endif /* defined(__PlantAndZombie_3__Animate__) */
