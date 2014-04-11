//
//  BathNodeParent.cpp
//  PlantAndZombie_3
//
//  Created by 雨亭梧桐雪 on 14-4-5.
//
//

#include "BathNodeParent.h"

BathNodeParent * BathNodeParent::createWithFile(const char * fileImage){
    BathNodeParent * batchNode = new BathNodeParent();
    batchNode->initWithFile(fileImage);//根据精灵图片渲染,这个是CCSpriteBathNode的方法
    batchNode->autorelease();
    return batchNode;
}
bool BathNodeParent::initWithFile(const char * fileImage){
    if (!CCSpriteBatchNode::initWithFile(fileImage, kDefaultSpriteBatchCapacity)) {
        return false;
    }
    lock = true;
    //介个又是什么意思???
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    return true;
}
bool BathNodeParent::ccTouchBegan(CCTouch * pTouch, CCEvent * pEvent){
    return true;
}
void BathNodeParent::ccTouchMoved(CCTouch * pTouch, CCEvent * pEvent){
    CCLOG("进入");
    
    CCArray * array = this->getChildren();
    for (int i = array->count()-1; i>= 0; i--) {
        CCSprite * sp = (CCSprite *)array->objectAtIndex(i);
        if (sp->getTag() == SUN_SP_TAG) {
            CCPoint point = pTouch->getLocation();
            if (sp->boundingBox().containsPoint(point)) {
                CCNotificationCenter::sharedNotificationCenter()->postNotification("clickSunSprite", sp);
                return;
            }
        }
    }
    
  
}