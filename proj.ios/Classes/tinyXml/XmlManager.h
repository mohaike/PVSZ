//
//  XmlManager.h
//  PlantAndZombie_3
//
//  Created by 雨亭梧桐雪 on 14-4-5.
//
//

#ifndef __PlantAndZombie_3__XmlManager__
#define __PlantAndZombie_3__XmlManager__

#include <iostream>

#include "cocos2d.h"
#include "tinystr.h"
#include "tinyxml.h"
using namespace std;
using namespace cocos2d;

class XmlManager:public CCObject{
public:
    static XmlManager * defaultManager();
    CCDictionary * dictionaryFromFile(const char * fileName);
};

#endif /* defined(__PlantAndZombie_3__XmlManager__) */
