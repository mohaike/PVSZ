//
//  MainScene.cpp
//  PlantAndZombie_3
//
//  Created by 雨亭梧桐雪 on 14-4-5.
//
//

#include "MainScene.h"

CCScene * MainScene::scene(){
    
    MainScene * layer = MainScene::create();
    CCScene * scene = CCScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool MainScene::init(){
    if (!CCLayer::init()) {
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    sp = CCSprite::create("loginMap.png");
    sp->setAnchorPoint(CCPoint(0, 0));
    sp->setContentSize(size);
    sp->setTextureRect(CCRectMake(0, 0, size.width, size.height));
    this->addChild(sp);
    
    LoginLineSp = CCSprite::create("loginLine.png");
    CCProgressTimer * timer = CCProgressTimer::create(LoginLineSp);
    timer->setPosition(ccp(300, 200));
    timer->setType(kCCProgressTimerTypeBar);
    timer->setBarChangeRate(ccp(5, 100));
    CCProgressTo * to = CCProgressTo::create(5, 100);
    timer->runAction(to);
    this->addChild(timer);
    
    CCSprite * ball = CCSprite::create("sodCollLogin.png");
    ball->setPosition(ccp(-30, 230));
    CCMoveTo * move = CCMoveTo::create(5.0, ccp(600, 230));
    CCRotateBy * rotate = CCRotateBy::create(5.0, 3600);
    CCSpawn * spw = CCSpawn::create(move, rotate, NULL);
    CCCallFunc * callFunc = CCCallFunc::create(this, callfunc_selector(MainScene::loginGame));
    CCSequence * seq = CCSequence::create(spw, callFunc, NULL);
    ball->runAction(seq);
    this->addChild(ball);
    
    return true;
}

void MainScene::loginGame(){
    CCMenuItemFont * itemFont = CCMenuItemFont::create("Start Game!", this, menu_selector(MainScene::startGame));
    itemFont->setFontSize(50);
    
    menu = CCMenu::create(itemFont, NULL);
    menu->setPosition(600, 500);
    this->addChild(menu);
}

void MainScene::startGame(CCObject *obj){
//    CCScene * scene = Animate::scene();
    
}
