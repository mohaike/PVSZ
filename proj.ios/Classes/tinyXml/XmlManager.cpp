//
//  XmlManager.cpp
//  PlantAndZombie_3
//
//  Created by 雨亭梧桐雪 on 14-4-5.
//
//

#include "XmlManager.h"
USING_NS_CC;

XmlManager * XmlManager::defaultManager(){
    static XmlManager * manager = NULL;
    if (manager == NULL) {
        manager = new XmlManager();
    }
    return manager;
}

//下面这个方法就是便利出特定类型的xml,得到字典
CCDictionary * XmlManager::dictionaryFromFile(const char *fileName){
    unsigned long size;
    const char *pFileContent = (char *)CCFileUtils::sharedFileUtils()->getFileData(fileName, "r", &size);
    TiXmlDocument *doc = new TiXmlDocument;
    doc->Parse(pFileContent,0,TIXML_ENCODING_UTF8);
    
    TiXmlPrinter printer;//提供工具类，目的是将xml的数据按格式输出
    doc->Accept(&printer);
    cout << printer.CStr() << endl;
    
    TiXmlElement *rootElement = doc->RootElement();//根节点
    TiXmlElement *element = rootElement->FirstChildElement();//子节点
    CCDictionary *dic = new CCDictionary();
    while (element) {//节点不空的话
        TiXmlAttribute *attribute = element->FirstAttribute();//取出该节点的第一个属性
        const char *attributeValue = attribute->Value();//取出该属性的值
        TiXmlElement *childElement = element->FirstChildElement();//取出它的第一个子节点
        CCDictionary *elementDictionary = CCDictionary::create();
        while (childElement) {
            TiXmlElement *c_childElement = childElement->FirstChildElement();
            const char *childElementName = childElement->Value();//属性值
            CCDictionary *c_cDic = CCDictionary::create();
            while (c_childElement) {
                const char *childElementName = c_childElement->Value();//这个被设定为键
                const char *childElementValue = c_childElement->GetText();//在第三层取出 //设置字典的键,值
                c_cDic->setObject(CCString::createWithFormat("%s",childElementValue), childElementName);
                c_childElement = c_childElement->NextSiblingElement();
            }
            const char *childElementValue;
            if (c_cDic->count() == 0) {
                childElementValue = childElement->GetText();
                elementDictionary->setObject(CCString::createWithFormat("%s",childElementValue), childElementName);
            }else{
                elementDictionary->setObject(c_cDic, childElementName);
            }
            childElement = childElement->NextSiblingElement();
        }
        dic->setObject(elementDictionary, attributeValue);
        element = element->NextSiblingElement();
    }
    return (CCDictionary *)dic->autorelease();
}
