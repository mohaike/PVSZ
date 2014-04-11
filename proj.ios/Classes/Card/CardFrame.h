//
//  CardFrame.h
//  PlantAndZombie_3
//
//  Created by 雨亭梧桐雪 on 14-4-8.
//
//

#ifndef __PlantAndZombie_3__CardFrame__
#define __PlantAndZombie_3__CardFrame__

#include <iostream>
#include "cocos2d.h"
using namespace cocos2d;

class CardFrame:public::CCSprite{
public:
    CCLabelTTF * font;//显示太阳数量的label??
    void initSprite(CCPoint point);//初始化
    static CardFrame * shareCardFrame();//单例~
    void setSunCount(int _count);//设置太阳数量
    int getSunCount();
private:
    int sunCount;
};


#endif /* defined(__PlantAndZombie_3__CardFrame__) */
