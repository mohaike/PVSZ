//
//  PlantParentCard.h
//  PlantAndZombie_3
//
//  Created by 雨亭梧桐雪 on 14-4-10.
//
//

#ifndef __PlantAndZombie_3__PlantParentCard__
#define __PlantAndZombie_3__PlantParentCard__

#include <iostream>

#include "cocos2d.h"
#include "CardFrame.h"
using namespace cocos2d;
enum{
    NO_SELECTED_CARD = 0,
    SELECTED_CARD = 1,
    WAIT_CARD_BUFFER = 2
};
class PlantParentCard:public CCSprite{
public:
    void setPlantBatchNode(CCSpriteBatchNode * _plantBatchNode);
    CCSpriteBatchNode * getPlantBatchNode();
    
    //设置缓冲状态
    virtual void setCardBufferState();
    //设置卡片的状态
    virtual void setCardState(int state);
    int getCardState();
    //设置卡片栏
    void setCardFrameSp(CardFrame * _cardFrameSp);
    CardFrame * getCardFrameSp();
    //卡片栏上的太阳数量
    void setSunCount(int _count);
    int getSunCount();
    /*
     创建植物
     */
//    //初始化方法,根据点的初始化
    virtual void initWithPoint(CCPoint point) = 0;
private:
    int sunCount;
    CardFrame * cardFrameSp;//卡片栏
    int cardState;//卡片状态
    CCSpriteBatchNode * plantBatchNode;//设置分支节点
};

#endif /* defined(__PlantAndZombie_3__PlantParentCard__) */
