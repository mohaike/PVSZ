//
//  XmlManager.h
//  PlantAndZombieMy
//
//  Created by  liwenhao on 14-4-3.
//
//

#ifndef __PlantAndZombieMy__XmlManager__
#define __PlantAndZombieMy__XmlManager__

#include <iostream>

#include "cocos2d.h"
#include "tinystr.h"
#include "tinyxml.h"
using namespace std;
using namespace cocos2d;
enum{
    ChildElementsInDictionary,
    ChildElementsInArray,
    ChildElementsInDictionaryArray,
};


class XmlManager:public CCObject{
public:
    static XmlManager *defaultManager();
    CCDictionary *dictionaryFromZombieXML(const char *fileName);
    CCDictionary *dictionaryFromPlantXML(const char *fileName);
    //递归取出
    CCDictionary *dictionaryFromXML(const char *fileName,int childElementsCategory = ChildElementsInDictionary);
    CCDictionary *dictionaryFromTiXmlElement(TiXmlElement *rootElement);    //子结点以字典形式存入父结点
    CCDictionary *ArrayFromTiXmlElement(TiXmlElement *rootElement);         //子结点以数组形式存入父结点
    CCDictionary *dictionaryArrayFromTiXmlElement(TiXmlElement *rootElement);//子结点以字典套数组形式存父结点
};

#endif /* defined(__PlantAndZombieMy__XmlManager__) */
