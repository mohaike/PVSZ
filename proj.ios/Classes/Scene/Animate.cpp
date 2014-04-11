//
//  Animate.cpp
//  PlantAndZombie_3
//
//  Created by 雨亭梧桐雪 on 14-4-5.
//
//

#include "Animate.h"

CCScene * Animate::scene(){
    Animate * animate = Animate::create();//->CREATE_FUNC->init(),它是一个Layer
    CCScene * scene = CCScene::create();
    scene->addChild(animate);
    return scene;
}

bool Animate::init(){
    if (!CCLayer::init()) {
        return false;
    }
    map = CCSprite::create(map_png);//不过地图刚刚进来有一段左右移动的动画,我们写成方法
    map->setAnchorPoint(CCPointZero);
    this->addChild(map);
    this->mapAnimate();//这个时候要把放植物的框框也给添加上去
    
    //创建精灵帧缓冲池,sharedSpriteFrameCache()是个单例方法,也就是共享区
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(plant_plist);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(zombie_plist);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(bullet_plist);
    //一次渲染
    plantBathNode = CCSpriteBatchNode::create(plant_png);
    zombieBathNode = CCSpriteBatchNode::create(zombie_png);
    bulletBathNode = CCSpriteBatchNode::create(bullet_png);
    this->addChild(plantBathNode);
    this->addChild(zombieBathNode);
    this->addChild(bulletBathNode);
    
    return true;
}

void Animate::mapAnimate(){//刚刚进来时候的地图动画
    CCMoveBy * mapMoveBy = CCMoveBy::create(3.0f, ccp(-500, 0));
    CCMoveBy * mapMoveByBack = CCMoveBy::create(3.0f, ccp(500, 0));
    CCCallFunc * callFunc = CCCallFunc::create(this, callfunc_selector(Animate::mapAnimateCallFunc));
    CCSequence * mapMBMBB = CCSequence::create(mapMoveBy, mapMoveByBack, callFunc, NULL);
    map->runAction(mapMBMBB);
}

void Animate::mapAnimateCallFunc(){
    this->createCardFrameSprite();//创建卡片栏
    
    //创建向日葵卡片到卡片栏上面
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    //创建植物卡片的PlantParentCard,再用多态实现各种各样的卡片
    
}

void Animate::createCardFrameSprite(){
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    cardFrameSp = CardFrame::shareCardFrame();//单例
    ccColor3B color;
    color.r = 176;
    color.g = 94;
    color.b = 90;
    CCLabelTTF * font = CCLabelTTF::create("25", "微软雅黑", 30);
    font->setPosition(CCPointMake(265, size.height - 110));
    font->setColor(color);
    //显示太阳数量
    cardFrameSp->font = font;
    cardFrameSp->initSprite(CCPointMake(450, size.height - 80));
    //添加链就是this->plantBath->cardFrameSp
    /*
     也就是先将plantBathNode添加到this上面之后再将cardFrameSp添加到
     plantBathNode上面
     */
    plantBathNode->addChild(cardFrameSp);
    
    this->addChild(font);
}


