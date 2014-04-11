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
#include "CardFrame.h"
#include "cocos2d.h"
#include "PlantParentCard.h"
using namespace cocos2d;

class Animate:public CCLayer{
public:
    static CCScene * scene();
    virtual bool init();
    CREATE_FUNC(Animate);
    
    void mapAnimate();//刚刚进来的时候的动画
    //开场地图动画结束以后的回调函数
    void mapAnimateCallFunc();
    //卡片栏
    void createCardFrameSprite();
    
private:
    CCSpriteBatchNode * plantBathNode;
    CCSpriteBatchNode * zombieBathNode;
    CCSpriteBatchNode * bulletBathNode;
    CCSprite * map;//创建一个地图精灵
    CardFrame * cardFrameSp;//植物卡片栏精灵
};

#endif /* defined(__PlantAndZombie_3__Animate__) */
