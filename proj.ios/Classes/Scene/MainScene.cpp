//
//  MainScene.cpp
//  PlantAndZombie_3
//
//  Created by 雨亭梧桐雪 on 14-4-5.
//
//

#include "MainScene.h"
#include "Animate.h"

CCScene * MainScene::scene(){
    
    CCScene * scene = CCScene::create();
    MainScene * layer = MainScene::create();
    
    scene->addChild(layer);//将层添加到scene上面
    return scene;
}

bool MainScene::init(){
    if (!CCLayer::init()) {
        return false;
    }

    CCSize size = CCDirector::sharedDirector()->getWinSize();//获得主屏幕的尺寸
    sp = CCSprite::create("loginMap.png");//根据图片创建开始游戏的时候欢迎的页面
    sp->setAnchorPoint(CCPoint(0, 0));//设置锚点
    sp->setContentSize(size);//把欢迎页面的尺寸设置为屏幕尺寸
    sp->setTextureRect(CCRectMake(0, 0, size.width, size.height));//这个是在创建精灵的之后设置可视尺寸
    this->addChild(sp);//添加精灵到该层上去

    LoginLineSp = CCSprite::create("loginLine.png");
    CCProgressTimer * timer = CCProgressTimer::create(LoginLineSp);//根据精灵初始化进度条
    timer->setPosition(ccp(300, 200));//这个是设置最后一段的位置
    timer->setType(kCCProgressTimerTypeBar);//可以点进去,用另一个效果看看是什么效果
    timer->setMidpoint(CCPointMake(0, 1));//设置进度样式,可以注释掉再看看是什么效果
    timer->setBarChangeRate(ccp(1, 0));//同上也是进度样式
    CCProgressTo * to = CCProgressTo::create(5, 100);//这两个参数的意思就是会在5秒走完100像素
    timer->runAction(to);//既然是进度,那么肯定会走的,CCProgressTo就是用于让它走起来的
    this->addChild(timer);

    ball = CCSprite::create("sodCollLogin.png");
    ball->setPosition(ccp(-30, 200));
    CCMoveTo * move = CCMoveTo::create(5.0, ccp(630, 200));
    CCRotateBy * rotate = CCRotateBy::create(5.0, 3600);
    CCSpawn * spw = CCSpawn::create(move, rotate, NULL);//边滚边动
    CCCallFunc * callFunc = CCCallFunc::create(this, callfunc_selector(MainScene::loginGame));//CCCallFUnc也是一种动作
    CCSequence * seq = CCSequence::create(spw, callFunc ,NULL);
    ball->runAction(seq);
    this->addChild(ball);
    
    return true;
}

void MainScene::loginGame(){
    ball->setVisible(false);//在滚完了之后就隐藏
    CCMenuItemFont * itemFont = CCMenuItemFont::create("Start Game!", this, menu_selector(MainScene::startGame));
    itemFont->setFontSize(50);
    
    menu = CCMenu::create(itemFont, NULL);//添加按钮
    menu->setPosition(600, 500);
    this->addChild(menu);
}

void MainScene::startGame(CCObject *obj){
    CCScene * scene = Animate::scene();//这个是一个全新的场景,我们要切换到这个场景去
    CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(3.0f, scene));
    //当然是用导演类来切换场景
    
}
