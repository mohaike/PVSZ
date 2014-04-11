//
//  SunFlowerCard.h
//  PlantAndZombie_3
//
//  Created by 雨亭梧桐雪 on 14-4-10.
//
//

#ifndef __PlantAndZombie_3__SunFlowerCard__
#define __PlantAndZombie_3__SunFlowerCard__

#include <iostream>
#include "PlantParentCard.h"
#include "cocos2d.h"
#include "XmlManager.h"
using namespace cocos2d;
class SunFlowerCard:public PlantParentCard, public CCTouchDelegate{
public:
    virtual void initWithPoint(CCPoint point);//初始化方法
    void stopCardAnimate();//停止闪烁动画
    void changeCardState();//改变卡片的状态
    void animationCard();//开始闪烁
    virtual void setCardBufferState();//设置缓冲状态
    void callFuncForBufferFinish(CCNode * node);//缓冲状态时候要用到的回调函数
    //创建单击事件
    virtual bool ccTouchBegan(CCTouch * pTouch, CCEvent * pEvent);

    /*
     //以及这个创建植物的函数
     virtual PlantInterface* getPlantObj(CCPoint point);
     */
private:
    //植物信息表
    CCDictionary * propertyity;
};
#endif /* defined(__PlantAndZombie_3__SunFlowerCard__) */
