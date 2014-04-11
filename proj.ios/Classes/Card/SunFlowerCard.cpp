//
//  SunFlowerCard.cpp
//  PlantAndZombie_3
//
//  Created by 雨亭梧桐雪 on 14-4-10.
//
//

#include "SunFlowerCard.h"



void SunFlowerCard::initWithPoint(CCPoint point){
    if (CCSprite::init()) {
        propertyity = (CCDictionary *)(XmlManager::defaultManager()->dictionaryFromPlantXML(plantPropertity_xml)->objectForKey("SUN_FLOWER"));
        const char * plantName = propertyity->valueForKey("Plant_Cardh")->getCString();
        CCSpriteFrame * frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(plantName);
        this->setDisplayFrame(frame);
        this->setPosition(point);
        //默认需要的太阳值??
        PlantParentCard::setSunCount(50);
        //默认给卡片没选中的状态
        PlantParentCard::setCardState(NO_SELECTED_CARD);
        CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
        //创建通知
        CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(SunFlowerCard::changeCardState), PlantCardNotificationS, NULL);
        //取消卡片闪烁, 目前没有实现
        CCNotificationCenter::sharedNotificationCenter()->addObserver(this, callfuncO_selector(SunFlowerCard::stopCardAnimate), ChangeCardStateNotificationS, NULL);
    }
}
//停止闪烁
void SunFlowerCard::stopCardAnimate(){
    PlantParentCard::setCardState(NO_SELECTED_CARD);
    this->changeCardState();
}
//改变卡片状态
void SunFlowerCard::changeCardState(){
    if (PlantParentCard::getCardState() == WAIT_CARD_BUFFER) {
        //卡片缓冲直接返回
        return;
    }
    //选中的话
    if (PlantParentCard::getCardState() == SELECTED_CARD) {
        //开始闪烁
        this->animationCard();
    }else{
        //停止动画
        this->stopCardAnimate();
        const char * plantName = NULL;
        
        //没选中的时候的卡片的状态
        if (PlantParentCard::getSunCount() <= PlantParentCard::getCardFrameSp()->getSunCount()) {
            plantName = propertyity->valueForKey("Plant_Card")->getCString();
        }else{
            plantName = propertyity->valueForKey("Plant_Cardh")->getCString();
        }
        CCSpriteFrame * frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(plantName);
        this->setDisplayFrame(frame);
    }
}

void SunFlowerCard::animationCard(){
    CCAnimation * animation = CCAnimation::create();
    const char * plantName = propertyity->valueForKey("Plant_Card")->getCString();
    CCSpriteFrame * frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(plantName);
    animation->addSpriteFrame(frame);
    
    plantName = propertyity->valueForKey("Plant_Cardh")->getCString();
    frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(plantName);
    animation->addSpriteFrame(frame);
    animation->setLoops(-1);
    animation->setDelayPerUnit(0.3f);
    CCAnimate * animate = CCAnimate::create(animation);
    this->runAction(animate);
}

void SunFlowerCard::setCardBufferState(){
    if (PlantParentCard::getCardState() == WAIT_CARD_BUFFER) {
        //停止动画
        this->stopCardAnimate();
        //设置图片
        const char * plantName = propertyity->valueForKey("Plant_Cardh")->getCString();
        CCSpriteFrame * frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(plantName);
        this->setDisplayFrame(frame);
        //亮的图片
        const char * showPlantName = propertyity->valueForKey("Plant_Card")->getCString();
        CCSpriteFrame * showFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(showPlantName);
        CCSprite * showSp = CCSprite::createWithSpriteFrame(showFrame);
        
        //缓冲动画, 额....有点看不大懂
        CCProgressTimer * progress = CCProgressTimer::create(showSp);
        progress->setPosition(this->getPosition());
        progress->setType(kCCProgressTimerTypeBar);
        progress->setMidpoint(CCPointMake(1, 0));
        progress->setBarChangeRate(ccp(0, 1));
        CCProgressTo * to = CCProgressTo::create(5, 100);
        PlantParentCard::getPlantBatchNode()->getParent()->addChild(progress);
        CCCallFuncN * callFunc = CCCallFuncN::create(this, callfuncN_selector(SunFlowerCard::callFuncForBufferFinish));
        CCSequence * sq = CCSequence::create(to, callFunc, NULL);
        progress->runAction(sq);
    }
}
//回调的函数
void SunFlowerCard::callFuncForBufferFinish(CCNode *node){
    node->removeFromParent();
    PlantParentCard::setCardState(NO_SELECTED_CARD);
}

bool SunFlowerCard::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
    if (PlantParentCard::getCardFrameSp()->getSunCount() < PlantParentCard::getSunCount() || PlantParentCard::getCardState() == WAIT_CARD_BUFFER) {
        return false;
    }
    
    CCPoint point = pTouch->getLocation();
    CCRect touchRect = CCRectMake(point.x, point.y, 5, 5);
    if (this->boundingBox().intersectsRect(touchRect)) {//这个是什么意思???
        //停止别的卡片的闪烁状态
        CCNotificationCenter::sharedNotificationCenter()->postNotification(ChangeCardStateNotificationS);
        /*
         //把当前的对象放到单例里面
         CreatePlantShare::shareSaveCard()->setPlantCard(this);
         */
        PlantParentCard::setCardState(SELECTED_CARD);
        this->animationCard();
        return true;
    }
    return false;
}

