//
//  Animate.cpp
//  PlantAndZombie_3
//
//  Created by 雨亭梧桐雪 on 14-4-5.
//
//

#include "Animate.h"

CCScene * Animate::scene(){
    Animate * animate = Animate::create();//->CREATE_FUNC->init()
    CCScene * scene = CCScene::create();
    scene->addChild(animate);
    return scene;
}

bool Animate::init(){
    if (!CCLayer::init()) {
        return false;
    }
    map = CCSprite::create("map.png");//不过地图刚刚进来有一段左右移动的动画,我们写成方法
    map->setAnchorPoint(CCPointZero);
    this->addChild(map);
    this->mapAnimate();//这个时候要把放植物的框框也给添加上去
    
    //创建精灵帧缓冲池,sharedSpriteFrameCache()是个单例方法
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("zhiwu.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("zombie.plist");
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("bullet.plist");
    
    CCSpriteBatchNode * a = CCSpriteBatchNode::create("zhiwu.png");
    CCSpriteBatchNode * b = CCSpriteBatchNode::create("zombie.png");
    CCSpriteBatchNode * c = CCSpriteBatchNode::create("bullet.png");
    this->addChild(a);
    this->addChild(b);
    this->addChild(c);
    
    return true;
}

void Animate::mapAnimate(){//刚刚进来时候的地图动画
    CCMoveBy * mapMoveBy = CCMoveBy::create(3.0f, ccp(-500, 0));
    CCMoveBy * mapMoveByBack = CCMoveBy::create(3.0f, ccp(500, 0));
    CCSequence * mapMBMBB = CCSequence::create(mapMoveBy, mapMoveByBack, NULL);
    map->runAction(mapMBMBB);
}