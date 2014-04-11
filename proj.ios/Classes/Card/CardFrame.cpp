//
//  CardFrame.cpp
//  PlantAndZombie_3
//
//  Created by 雨亭梧桐雪 on 14-4-8.
//
//

#include "CardFrame.h"
USING_NS_CC;

#pragma mark 单例~~
static CardFrame * cardFrame = NULL;

CardFrame* CardFrame::shareCardFrame(void)
{
    if (! cardFrame)
    {
        cardFrame = new CardFrame();
        cardFrame->init();//仿照系统写的~~
    }
    
    return cardFrame;
}

void CardFrame::initSprite(CCPoint point){
    CCSpriteFrame * frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName("tableView.png");

    this->initWithSpriteFrame(frame);
    this->setPosition(point);
    this->setSunCount(0);//太阳数量开始为零
}

void CardFrame::setSunCount(int _count){
    sunCount = _count;
    CCLog("-----%d----", sunCount);
    
    //???
    char str[1];
    sprintf(str, "%d", sunCount);//貌似是把太阳数量转成字符
    font->setString(str);//设置太阳数量的label
    //发送一个我不知道的通知
    CCNotificationCenter::sharedNotificationCenter()->postNotification(PlantCardNotificationS);
}

int CardFrame::getSunCount(){
    return sunCount;
}