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
};

#endif /* defined(__PlantAndZombie_3__MainScene__) */
