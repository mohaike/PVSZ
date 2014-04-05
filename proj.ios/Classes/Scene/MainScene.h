//
//  MainScene.h
//  PlantAndZombie_3
//
//  Created by 雨亭梧桐雪 on 14-4-5.
//
//

#ifndef __PlantAndZombie_3__MainScene__
#define __PlantAndZombie_3__MainScene__

#include <iostream>
#include "cocos2d.h"
//#include "<#header#>"
using namespace cocos2d;

class MainScene:public CCLayer{
private:
    CCSprite * sp;
    CCSprite * LoginLineSp;
    CCMenu * menu;
public:
    static CCScene * scene();
    
    virtual bool init();
    void startGame(CCObject * obj);
    void loginGame();
    //创建类的宏
    CREATE_FUNC(MainScene);
};

#endif /* defined(__PlantAndZombie_3__MainScene__) */
